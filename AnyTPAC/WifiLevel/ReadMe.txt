Purpose of this Project: Show usage of new Networking functions introduced with Mect Suite 3.4.0

In automation.cpp you will find one cpp function:

u_int32_t getMSVersion()

The result of this function is the Mect Suite version number installed on taget (parsed form system file /rootfs_version)
in hex form. Eg, for version 3.3.9 the result is 0x00030309

The purpose of this function is to prevent page100.cpp from using the new functions if a version of Mect Suite prior to 3.3.10 is present on the target.

To use the new functions you must add in your code:
#include "global_functions.h"

The new function introduced with Mect Suite 3.4.0 are:

bool check_wifi_board();                // returns true if wifi board wlan0 is present
bool check_usb_wan_board();             // returns true if wan board usb_wwan is present
bool get_wifi_signal_level(int &nQuality, int &nSignalLevel);   // Returns true if wlan0 is present and Signal Quality (0..100) and Signal Level (dbm)
bool getBoardGateway(const char * board_name, unsigned &boardGW);   // returns the ip address as unsigned of default gateway for board <board_name>
bool checkNetAddr(char * ipaddr);       // Check format of an IP Address
QString getMacAddr(QString interface);  // Returns MAC Address for board <interface> as a QString
bool    getBoardIPInfo(QString interface, QNetworkAddressEntry &netAddr)   // Returns first IP address info for board <interface> as a QNetworkAddressEntry
QString getIPAddr(QString interface);   // Returns IP Address for board <interface>
bool isWlanOn(void);                    // returns true if wifi board wlan0 is up and connected to an AP
bool isWanOn(void);                     // returns true if WLan ppp0 board is up and connected


