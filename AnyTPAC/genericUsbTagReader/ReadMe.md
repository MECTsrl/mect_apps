# Project **genericUsbTagReader**
***
## Purpose of this Project: Show how to use a generic USB RFID Tag Reader connected as USB Serial Port.  
***
The Tag reader is connected to the panel through the USB port, and is seen by the operating system as a device ***/dev/ttyUSB0*** (serial port emulator on USB interface).  

To manage the serial communication with the reader the project uses the Qt library **QtSerialPort** (v6.5.0, checkout qt4-dev for Qt 4.8), not included in Mect Suite, distributed by Qt under license **LGPL-3.0** (https://github.com/qt/qtserialport).  

The library was compiled externally to the project, starting from the sources, for the i.MX28 platform and included in the project in binary format *(lib/libQtSerialPort.so)* with the necessary include files *(qtserialport/include/QtSerialPort)*.  

The libQtSerialPort.so file is installed on the panel when deploying the application to the */local/root/lib* folder.  

The instructions necessary to indicate to Mect Suite where to find the library file, how to link it, and the includes for compilation have been inserted only in the **genericUsbTagReader.pro** file, keeping the structure of the hmi project unchanged.  

In the project there is only one interface page (**page100**) with graphic elements that indicate if the reader is connected, if a Tag has been detected in the reading area of the reader.  

The core of this project is the ***tagReader*** class. It is a class derived from Qt *QObject*, and inside it uses a ***QSerialPort*** instance to receive data from the generic Serial Tag reader.  

The tagReader class is used through the page100 pointer variable **tagReader \*myReader;** declared in page100.h and instantiated only once within the code of the application Start Page (not in automation.cpp) because to work it must be connected to the Qt Event Loop.  

- The tagReader object is created after all the application pages have been created, inside the UpdateData code of the Start Page of the application, because the Qt Event Loop must already be active. The activation steps of the class must occur in the same creation thrad (see *page100::updateData()*)
- The first step is to verify that the file associated with the USB Device (*/dev/ttyUSB0)* exists (myStatus == 0)
- Then the device can be opened with the method openSerialPort() (myStatus == 1)  
- Then you can connect the class signals with the page slots (myStatus == 2)
- If you use class signals attached to page100 slots, the handling slots must be written so that they can also be used in other pages of your code (through the use of a global variables or Crosstables and without requiring page100 repaint), because it is not possible to disconnect the tagReader signals with the call of ***tagReader->disconnect()***, and reconnect them to slots of other pages, because the tagReader object belongs to the Thread of page100 and cannot be connected to other Threads (this is a problem related to the architecture of the Mect Suite Threads and the Qt Event Loop)  

The class exposes some methods for checking reader status, tag presence, getting last Tag ID Found.

### tagReader public methods

- ***tagReader(QObject \*parent = 0)*** Creates the instance of SerialReader Object. 
- ***bool  openSerialPort(QString deviceName)*** Open the serial port *deviceName* associated with the USB reader. The connection parameters are 9600, N, 8, 1 without flow control (usually default values for USB Tag reader)
- ***QString getLastTagID()*** Returns Last Tag ID if a Tag is present or an empty QString
- ***qint64      getElapsedTime()*** Return the time needed to read the last tag (in ms) 
- ***int         getReadLoops()*** Return number of read loops used to read the last tag (iterations of readData() slot associated with the *readyRead()* SIGNAL of **QtSerialPort** class


### tagReader public signals

- ***void        readNewTag(QString newTag);*** Emitted when reading of a Tag is completed

**N.B.: Please check if your tag reader uses an FTDI chip, because you may need to disconnect and reconnect the driver before you can use it (see setup() in automation.cpp)**