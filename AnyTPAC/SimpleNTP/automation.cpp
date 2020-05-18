#include "crosstable.h"
#include "automation.h"

#include <byteswap.h>
#include <netdb.h> // getaddrinfo()
#include <arpa/inet.h> // inet_ntop()
page100 *thePagePtr;

void ntpClientProcedure();
int64_t getTimestamp();
void setTimestamp(int64_t TargetTimestamp);

void setup(void)
{
    thePagePtr = NULL;
}

void loop(void)
{
    if (thePagePtr) {
        thePagePtr->erase();
        ntpClientProcedure();
        thePagePtr = NULL;
    }
}

// -------------------------------------------------------------------------

void syncTime(page100 *pagePtr)
{
    if (! thePagePtr) {
        thePagePtr = pagePtr;
    }
}

void append(const char *fmt, ...)
{
    char buffer[1024];
    va_list 	va;

    va_start(va, fmt);
    vsprintf(buffer, fmt, va);
    va_end(va);

    thePagePtr->append(buffer);
}

// -------------------------------------------------------------------------

#pragma pack(push, 1)

struct NtpPacketHeader {
    uint8_t Mode : 3;
    uint8_t VN : 3;
    uint8_t LI : 2;
    uint8_t Stratum;
    uint8_t Poll;
    uint8_t Precision;
    uint32_t RootDelay;
    uint32_t RootDispersion;
    uint32_t ReferenceIdentifier;
    int64_t ReferenceTimestamp;
    int64_t OriginateTimestamp;
    int64_t ReceiveTimestamp;
    int64_t TransmitTimestamp;
    uint32_t KeyIdentifier;
    uint32_t MessageDigest[4];
};

#pragma pack(pop)

void swapPacket(const struct NtpPacketHeader &from, struct NtpPacketHeader &to)
{
    to.Mode = from.Mode;
    to.VN = from.VN;
    to.LI = from.LI;
    to.Stratum = from.Stratum;
    to.Poll = from.Poll;
    to.Precision = from.Precision;
    to.RootDelay = bswap_32(from.RootDelay);
    to.RootDispersion = bswap_32(from.RootDispersion);
    to.ReferenceIdentifier = bswap_32(from.ReferenceIdentifier);
    to.ReferenceTimestamp = bswap_64(from.ReferenceTimestamp);
    to.OriginateTimestamp = bswap_64(from.OriginateTimestamp);
    to.ReceiveTimestamp = bswap_64(from.ReceiveTimestamp);
    to.TransmitTimestamp = bswap_64(from.TransmitTimestamp);
    to.KeyIdentifier = bswap_32(from.KeyIdentifier);
    for (int i = 0; i < 4; ++i) {
        to.MessageDigest[i] = from.MessageDigest[i]; // no swap
    }
}

int64_t getTimestamp()
{
    int64_t retval;
    struct timespec now;
    time_t seconds;
    uint32_t fraction;

    clock_gettime(CLOCK_REALTIME, &now);

    // NTP date from 1900-01-01 <---> UNIX date from 1970-01-01
    seconds = now.tv_sec + 2208988800;

    // NTP fixed point [s/2^32] <---> POSIX fixed point [ns=s/10^9]
    fraction = (uint32_t)(now.tv_nsec * 4.294967296); // ns / 1000000000.0 * 4294967296.0
    retval = ((int64_t)seconds << 32) + fraction;

    append("get time = 0x%08lx s, ntp 0x%016llx\n", now.tv_sec, retval);
    return retval;
}

void setTimestamp(int64_t TargetTimestamp)
{
    struct timespec target;
    time_t seconds;
    uint32_t fraction;

    // NTP fixed point [s/2^32] <---> POSIX fixed point [ns=s/10^9]
    seconds = TargetTimestamp >> 32;
    fraction = TargetTimestamp & 0xFFFFffff;
    target.tv_nsec = (uint32_t)(fraction / 4.294967296);

    // NTP date from 1900-01-01 <---> UNIX date from 1970-01-01
    target.tv_sec = seconds - 2208988800;

    append("set time = 0x%08lx s, ntp 0x%016llx\n", target.tv_sec, TargetTimestamp);

    // time zone correction
    target.tv_sec += 3600 * TimeZone;

    // set time
    clock_settime(CLOCK_REALTIME, &target);
}

#define THE_NTP_SERVER     "tempo.ien.it"
#define THE_NTP_PORT       123
#define THE_NTP_TIMEOUT_ms 9000
#define THE_MAX_TRIPTIME_s 1LL

void ntpClientProcedure()
{
    struct NtpPacketHeader request, reply;
    int packetSize = sizeof(struct NtpPacketHeader);
    int theUdpSocket = -1;

    /*
     * creazione pacchetti dati NTP
     */
    request.VN = 4; // SNTP/NTP version number
    request.Mode = 3; // client
    request.TransmitTimestamp = getTimestamp();

    /*
     * creazione del socket UDP
     */
    theUdpSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (theUdpSocket == -1) {
        append("ERROR: cannot create socket\n");
        goto exit_function;
    }

    /*
     * creazione degli indirizzi IP, con porte
     */
    {
        struct sockaddr_in ntpServerAddr;
        struct sockaddr_in localAddr;
        int sentBytes = -1;

        memset(&localAddr, 0, sizeof(localAddr));
        memset(&ntpServerAddr, 0, sizeof(ntpServerAddr));

        localAddr.sin_family = AF_INET;
        localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        localAddr.sin_port = htons(THE_NTP_PORT);

        char ntpServerName[42];
        if (thePagePtr->ntpServer(ntpServerName, 42) == NULL) {
            append("ERROR: cannot get server name\n");
            goto exit_function;
        }
        append("ntp server: %s { ", ntpServerName);
        {
            struct addrinfo hints;
            struct addrinfo *addresses, *address;
            int resolv_error;

            memset(&hints, 0, sizeof(struct addrinfo));
            hints.ai_family = AF_INET; // AF_UNSPEC
            hints.ai_socktype = SOCK_DGRAM;
            hints.ai_flags = 0;
            hints.ai_protocol = 0;
            resolv_error = getaddrinfo(ntpServerName, "ntp", &hints, &addresses);
            if (resolv_error != 0 || addresses == NULL) {
                append("cannot resolve ntp server name (%s)\n", gai_strerror(resolv_error));
                goto exit_function;
            }
            for (address = addresses; address != NULL; address = address->ai_next) {
                char buf[INET6_ADDRSTRLEN];

                if (inet_ntop(address->ai_family, &((struct sockaddr_in *)address->ai_addr)->sin_addr, buf, INET6_ADDRSTRLEN)) {
                    append(" %s", buf);
                }
            }
            address = addresses; // the first
            memcpy(&ntpServerAddr.sin_addr.s_addr, &((struct sockaddr_in *)address->ai_addr)->sin_addr, address->ai_addrlen);
            ntpServerAddr.sin_family = address->ai_family;

            freeaddrinfo(addresses);
        }
        append("}\n");
        ntpServerAddr.sin_port = htons(THE_NTP_PORT);

        /*
         * aggancio del socket in ricezione
         */
        if (bind(theUdpSocket, (struct sockaddr *)&localAddr, sizeof(localAddr)) < 0) {
            append("ERROR: cannot receive on %d/udp port\n", THE_NTP_PORT);
            goto exit_function;
        }

        /*
         * spedizione della richiesta
         */
        {
            struct NtpPacketHeader buffer;

            swapPacket(request, buffer);
            sentBytes = sendto(theUdpSocket, &buffer, packetSize,
                               0, (struct sockaddr *)&ntpServerAddr, sizeof(struct sockaddr_in));
            if (sentBytes != packetSize) {
                append("ERROR: cannot send request(error = %d)\n", sentBytes);
                goto exit_function;
            }
            append("...");
        }
    }

    /*
     * attesa risposta, con timeout
     */
    {
        fd_set recv_set;
        struct timeval timeout;
        int selectStatus;

        FD_ZERO(&recv_set);
        FD_SET(theUdpSocket, &recv_set);
        timeout.tv_sec = THE_NTP_TIMEOUT_ms / 1000;
        timeout.tv_usec = (THE_NTP_TIMEOUT_ms % 1000) * 1000;
        selectStatus = select(theUdpSocket + 1, &recv_set, NULL, NULL, &timeout);
        append("\n");
        if (selectStatus == 0) {
            append("ERROR: cannot receive reply (timeout %d ms)\n", THE_NTP_TIMEOUT_ms);
            goto exit_function;
        } else if (selectStatus < 0) {
            append("ERROR: cannot receive reply (error = %d)\n", selectStatus);
            goto exit_function;
        }
    }

    /*
     * lettura risposta
     */
    {
        struct NtpPacketHeader buffer;
        int receivedBytes;
        int64_t DestinationTimestamp;
        int64_t TripTimestamp;
        int64_t TargetTimestamp;

        receivedBytes = recv(theUdpSocket, &buffer, packetSize, 0);
        DestinationTimestamp = getTimestamp(); // <---= asap
        swapPacket(buffer, reply);

        if (receivedBytes < (packetSize - 16)) {
            append("ERROR: received wrong reply (%d < %d)\n", receivedBytes, (packetSize - 16));
            goto exit_function;
        }
        if (reply.VN != request.VN
         || reply.Mode != 4
         || reply.Stratum == 0 || reply.Stratum > 15) {
            append("ERROR: received wrong reply (vn = %d, mode = %d, stratum = %d)\n",
                    reply.VN, reply.Mode, reply.Stratum);
            goto exit_function;
        }
        if (reply.OriginateTimestamp != request.TransmitTimestamp) {
            append("ERROR: received wrong reply (0x%016llx != 0x%016llx)\n",
                    reply.OriginateTimestamp, request.TransmitTimestamp);
            goto exit_function;
        }

        /*
         * interpretazione risposta
         */
        TripTimestamp = (DestinationTimestamp - reply.OriginateTimestamp) / 2;
        if (TripTimestamp > (THE_MAX_TRIPTIME_s << 32)) {
            append("ERROR: trip time too high (0x%016llx)\n", TripTimestamp);
            goto exit_function;
        }
        append("server time =                0x%016llx\n", reply.TransmitTimestamp);
        append("trip time   =                0x%016llx\n", TripTimestamp);

        /*
         * cambio data e ora
         */
        TargetTimestamp = reply.TransmitTimestamp + TripTimestamp;
        append("target time =                0x%016llx\n", TargetTimestamp);
        setTimestamp(TargetTimestamp);

        /*
         * salvataggio in RTC
         */
        // system("hwclock --systohc");
    }

exit_function:
    if (theUdpSocket != -1) {
        shutdown(theUdpSocket, SHUT_RDWR);
        close(theUdpSocket);
        theUdpSocket = -1;
    }
}

// -------------------------------------------------------------------------
