# Project **AseUSBTagReader**
***
Purpose of this Project: Show how to use **ASE A2M31H** USB RFID Tag Reader using *ASE TWN4 Simple Protocol*.  
***
The Tag reader is connected to the panel through the USB port, and is seen by the operating system as a device ***/dev/ttyUSB1*** (serial port emulator on USB interface).  

To manage the serial communication with the reader the project uses the Qt library **QtSerialPort** (v6.5.0, checkout qt4-dev for Qt 4.8), not included in Mect Suite, distributed by Qt under license **LGPL-3.0** (https://github.com/qt/qtserialport).  

The library was compiled externally to the project, starting from the sources, for the i.MX28 platform and included in the project in binary format *(lib/libQtSerialPort.so)* with the necessary include files *(qtserialport/include/QtSerialPort)*.  

The libQtSerialPort.so file is installed on the panel when deploying the application to the */local/root/lib* folder.  

The instructions necessary to indicate to Mect Suite where to find the library file, how to link it, and the includes for compilation have been inserted only in the **AseUSBTagReader.pro** file, keeping the structure of the hmi project unchanged.  

The project uses **ICODE SLI-S Tags** (Iso 15693) with 64 bit TAG IDs and a 2048 bit user memory area (316 User Bytes in 79 4K Blocks) or **ISO14443A/MIFARE Tags** (144 User Bytes in 36 4K Blocks, starting from page 0x04).

The commands sent to the reader are described in the file *doc/TWN4_Simple_Protocol_DocRev25.pdf* (paragraph 1.5.12. API ISO15693 and paragraph 1.5.10. API MIFARECLASSIC in the document).  

In the project there is only one interface page (**page100**) with graphic elements that indicate if the reader is connected, if a Tag has been detected in the reading area of the reader, and two buttons for reading and writing a user data structure on the current Tag.  

