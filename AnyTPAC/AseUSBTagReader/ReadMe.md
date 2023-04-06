# Project **AseUSBTagReader**
***
## Purpose of this Project: Show how to use **ASE A2M31H** USB RFID Tag Reader using *ASE TWN4 Simple Protocol*.  
***
The Tag reader is connected to the panel through the USB port, and is seen by the operating system as a device ***/dev/ttyUSB1*** (serial port emulator on USB interface).  

To manage the serial communication with the reader the project uses the Qt library **QtSerialPort** (v6.5.0, checkout qt4-dev for Qt 4.8), not included in Mect Suite, distributed by Qt under license **LGPL-3.0** (https://github.com/qt/qtserialport).  

The library was compiled externally to the project, starting from the sources, for the i.MX28 platform and included in the project in binary format *(lib/libQtSerialPort.so)* with the necessary include files *(qtserialport/include/QtSerialPort)*.  

The libQtSerialPort.so file is installed on the panel when deploying the application to the */local/root/lib* folder.  

The instructions necessary to indicate to Mect Suite where to find the library file, how to link it, and the includes for compilation have been inserted only in the **AseUSBTagReader.pro** file, keeping the structure of the hmi project unchanged.  

The project uses **ICODE SLI-S Tags** (Iso 15693) with 64 bit TAG IDs and a 2048 bit user memory area (316 User Bytes in 79 4B Blocks) or **ISO14443A/MIFARE Tags** with 56 bit TAG IDs (144 User Bytes in 36 4B Blocks, starting from page 0x04).  
Documentation on the different types of tags can be found in the *Doc* folder, ***ICODE_SLIX2***.pdf for *ISO15693* and ***NTAG213_215_216***.pdf for *ISO14443A/MIFARE*.

The commands sent to the reader are described in the file ***doc/TWN4_Simple_Protocol_DocRev25.pdf*** *(paragraph 1.5.12. API ISO15693 and paragraph 1.5.10. API MIFARECLASSIC in the document)*.  

In the project there is only one interface page (**page100**) with graphic elements that indicate if the reader is connected, if a Tag has been detected in the reading area of the reader, and two buttons for reading and writing a user data structure on the current Tag.  

The core of this project is the ***SerialReader*** class. It is a class derived from Qt *QObject*, and inside it uses a ***QSerialPort*** instance to send and receive data from the ASE Tag reader.  

The SerialReader class must be used through the global pointer variable **SerialReader \*tagReader;** declared in automation.cpp and instantiated only once within the code of the application Start Page (not in automation.cpp) because to work it must be connected to the Qt Event Loop.  
automation.cpp uses another thread, independent from the Qt Event loop.  

- It is preferable to create the SerialReader object when all the application pages have been created, inside the UpdateData code of the Start Page of the application, because the Qt Event Loop must already be active. The activation steps of the class must occur in the same creation thrad (see *page100::updateData()*)
- The first step is to verify that the file associated with the USB Device (*/dev/ttyUSB1)* exists (myStatus == 0)
- The class must be created specifying the name of the device it will use and then the device can be opened with the method openSerialPort() (myStatus == 1)  
- Then you can set the operating parameters (setCRCEnabled() and setTagPollingIntervalms())  and eventually connect the class signals with the page slots (myStatus == 2)
- If you use class signals attached to page100 slots, the handling slots must be written so that they can also be used in other pages of your code (through the use of global variables or Crosstables and without requiring page100 repaint), because it is not possible to disconnect the tagReader signals with the call of ***tagReader->disconnect()***, and reconnect them to slots of other pages, because the tagReader object belongs to the Thread of page100 and cannot be connected to other Threads (this is a problem related to the architecture of the Mect Suite Threads and the Qt Event Loop)  

The class exposes some methods for checking reader status, tag presence and type, reading and writing the tag user memory, which can be called only if a Tag has been detected within the range of the reader

### SerialReader public methods

- ***SerialReader(QString myDevice, QObject \*parent = 0)*** Creates the instance of SerialReader Object. Parameter *myDevice* is the device name of reader USB interface
- ***bool  openSerialPort()*** Open the serial port associated with the USB reader. The connection parameters are 9600, N, 8, 1 without flow control (defaults for ASE Tag reader)
- ***void  setCRCEnabled(bool addCRC)*** If addCRC is true, a 2 byte CRC is added to the stored user data when writing to the Tag and checked when reading from the Tag  
- ***void  setTagPollingIntervalms(int pollInterval_ms)*** Set the Tag search time interval in milliseconds (default is 2000ms). The value must not be less than 500ms  
- ***u_int16_t  calculateCRC(unsigned char \*userArea, int nBytes)***  Computes the CRC of a byte buffer, one byte at a time
- ***bool  readTagMemory(unsigned char \*userArea, int nBytes)***   Read User Memory Area of Current Tag for nBytes. Returns true if Tag is present and reading is ok
- ***bool  writeTagMemory(unsigned char \*userArea, int nBytes)***  Write User Memory Area of Current Tag for nBytes. Returns true if Tag is present and Writing is ok
- ***bool  isBusy()*** Returns true if a Read or Write Tag command is pending
- ***bool  isTagPresent()*** Returns true if Tag is present
- ***QString lastTagID()*** Returns Last Tag ID if a Tag is present or an empty QString
- ***uint  getTagType()*** Returns Last Tag Type found (0x82 for ISO15693 and 0x80 for ISO14443A/MIFARE) or 0

There are also some public methods to get internal tagReader status, current pending command, status and command description.

### SerialReader public signals

- ***tagFound(QString tagID)*** Tag found with ID == tagID 
- ***noTag()*** No Tag foung (searchTag() failed)
- ***tagMemoryRead(bool readOK)*** readTagMemory result
- ***tagMemoryWrite(bool writeOK)*** writeTagMemory result
