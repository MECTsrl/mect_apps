#ifndef TAGREADER_H
#define TAGREADER_H

#define THE_DEVICE "/dev/ttyUSB1"

// #define MAX_COMMAND_LEN     128
// #define MAX_ANSWER_LEN]     1024

// Return Code form Tag Reader Commands
#define TAG_ERR_UNDEF -1
#define TAG_ERR_NONE 0
#define TAG_ERR_UNKNOWN_FUNCTION 1
#define TAG_ERR_MISSING_PARAMETER 2
#define TAG_ERR_UNUSED_PARAMETERS 3
#define TAG_ERR_INVALID_FUNCTION 4
#define TAG_ERR_PARSER 5

// USB Device Status
#define USB_DEVICE_STATE_NOTINIT        0
#define USB_DEVICE_STATE_DEFAULT        1
#define USB_DEVICE_STATE_ADDRESSED      2
#define USB_DEVICE_STATE_CONFIGURED     3
#define USB_DEVICE_STATE_SUSPENDED      4

extern int      ttyUSB1;                // Handle to device file pointer
extern bool     cardFound;              // True if Card Reader is Open
extern int      readerStatus;           // reader Status (result of last command)


bool    openReader();                   // Opening the USB device of the reader
bool    resetReader();                  // Reader reset, causes a closure of the Device
int     getUSBType();                   // Get Reader USB Interface Type (should be 1)
int     getDeviceType();                // Get Device Type (should be 0B 11)
int     getLastError();                 // Get Last Error from reader

#endif // TAGREADER_H
