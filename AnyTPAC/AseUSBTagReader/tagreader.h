#ifndef TAGREADER_H
#define TAGREADER_H


//------------------------------------------------------------
// Return Code form Tag Reader Commands
//------------------------------------------------------------
#define TAG_ERR_UNDEF -1
#define TAG_ERR_NONE 0
#define TAG_ERR_UNKNOWN_FUNCTION 1
#define TAG_ERR_MISSING_PARAMETER 2
#define TAG_ERR_UNUSED_PARAMETERS 3
#define TAG_ERR_INVALID_FUNCTION 4
#define TAG_ERR_PARSER 5

//------------------------------------------------------------
// USB Device Status
//------------------------------------------------------------
#define USB_DEVICE_STATE_NOTINIT        0
#define USB_DEVICE_STATE_DEFAULT        1
#define USB_DEVICE_STATE_ADDRESSED      2
#define USB_DEVICE_STATE_CONFIGURED     3
#define USB_DEVICE_STATE_SUSPENDED      4

//------------------------------------------------------------
// Tag Types
//------------------------------------------------------------
#define NOTAG               0
// LF Tags
#define LFTAG_EM4102        0x40    // "EM4x02/CASI-RUSCO" (aka IDRO_A)
#define LFTAG_HITAG1S       0x41    // "HITAG 1/HITAG S"   (aka IDRW_B)
#define LFTAG_HITAG2        0x42    // "HITAG 2"           (aka IDRW_C)
#define LFTAG_EM4150        0x43    // "EM4x50"            (aka IDRW_D)
#define LFTAG_AT5555        0x44    // "T55x7"             (aka IDRW_E)
#define LFTAG_ISOFDX        0x45    // "ISO FDX-B"         (aka IDRO_G)
#define LFTAG_EM4026        0x46    // N/A                 (aka IDRO_H)
#define LFTAG_HITAGU        0x47    // N/A                 (aka IDRW_I)
#define LFTAG_EM4305        0x48    // "EM4305"            (aka IDRW_K)
#define LFTAG_HIDPROX       0x49	// "HID Prox"
#define LFTAG_TIRIS         0x4A	// "ISO HDX/TIRIS"
#define LFTAG_COTAG         0x4B	// "Cotag"
#define LFTAG_IOPROX        0x4C	// "ioProx"
#define LFTAG_INDITAG       0x4D	// "Indala"
#define LFTAG_HONEYTAG      0x4E	// "NexWatch"
#define LFTAG_AWID      	0x4F	// "AWID"
#define LFTAG_GPROX      	0x50	// "G-Prox"
#define LFTAG_PYRAMID      	0x51	// "Pyramid"
#define LFTAG_KERI      	0x52	// "Keri"
#define LFTAG_DEISTER		0x53	// "Deister"
#define LFTAG_CARDAX		0x54	// "Cardax"
#define LFTAG_NEDAP			0x55	// "Nedap"
#define LFTAG_PAC			0x56	// "PAC"
#define LFTAG_IDTECK		0x57	// "IDTECK"
#define LFTAG_ULTRAPROX		0x58	// "UltraProx"
#define LFTAG_ICT			0x59	// "ICT"
#define LFTAG_ISONAS		0x5A	// "Isonas"
// HF Tags
#define HFTAG_MIFARE        0x80	// "ISO14443A/MIFARE"
#define HFTAG_ISO14443B     0x81	// "ISO14443B"
#define HFTAG_ISO15693      0x82	// "ISO15693"
#define HFTAG_LEGIC         0x83	// "LEGIC"
#define HFTAG_HIDICLASS     0x84	// "HID iCLASS"
#define HFTAG_FELICA        0x85	// "FeliCa"
#define HFTAG_SRX           0x86	// "SRX"
#define HFTAG_NFCP2P        0x87	// "NFC Peer-to-Peer"
#define HFTAG_BLE        	0x88	// "Bluetooth Low Energy"
#define HFTAG_TOPAZ         0x89    // "Topaz"
#define HFTAG_CTS           0x8A    // "CTS256 / CTS512"
#define HFTAG_BLELC        	0x8B	// "Bluetooth Low Energy LEGIC Connect"

#define TAGMASK(Tagtype)    (1 << (Tagtype & 0x1F))

#define ALL_LFTAGS          0xFFFFFFFF
#define ALL_HFTAGS          0xFFFFFFFF

#define TAG_ID_LEN          32
//------------------------------------------------------------
// Tag Reader public management variables
//------------------------------------------------------------
extern int          readerStatus;           // reader Status (result of last command)
extern u_int32_t    readerError;            // reader Last Error
extern char         lastTag[];    // Last Read Tag
//------------------------------------------------------------
// Tag Reader exported public functions
//------------------------------------------------------------
bool        openReader();                   // Opening the USB device of the reader
int         getUSBType();                   // Get Reader USB Interface Type (should be 1)
int         getDeviceType();                // Get Device Type (should be 0B 11)
int         getUSBDeviceState();            // Get USB Device Status (should be 03)
bool        searchTag(int &nTagType, int &nTagBits, char *tagID);       // Search Tag: Return true if found, tag Type
u_int32_t   getLastError();                 // Get Last Error from reader

#endif // TAGREADER_H
