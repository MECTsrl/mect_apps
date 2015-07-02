# mect\_apps
Mect Apps: the Mect Suite example applications (CFG, HMI, PLC)

Some application examples (both HMI and PLC) are bound to the Mect Suite software: those examples are useful for describing the system features.
For using the example you need to:

1. create a "MectApps" folder in C:\
2. copy the example tree in C:\MectApps\

For each project there are several folders to be opened by different software:
project\_HMI contains the HMI graphic application, use QtCreator 
project\_PLC contains the PLC application, use ATCMcontrol Engineering
project\_CFG contains the general configuration, use MECT Configurator
project\_CAN contains the optional CANopen configuration, use ATCM CanBuilder

The application examples are sorted in folders according to the target panels: TP1043, TPAC1007, TPAC1008 … and in AnyTPAC the generic ones.
- AnyTPAC:
  - Empty\_PLC: default PLC application, it is the one used with StarterKit
  - Simulation\_PLC: PLC application example that simulates some analog and digital inputs
  - ModbusTCPserver\_PLC:  PLC application example that implements a Modbus TCP server (the client is in TP1043_TCP)
- [TP1043\_CAN] (http://www.mect.it/en/products/control-and-automation/operator-panels/tp1043/):
  - ModbusTCPclient\_CFG, \_CAN, \_HMI, \_PLC: example of client access to a Modbus TCP device (see the manual 
- [TP1043\_RTU] (http://www.mect.it/en/products/control-and-automation/operator-panels/tp1043/):
  - ModbusRTUclient\_CFG, \_HMI, \_PLC: example of client access to a Modbus RTU device (see the manual ME7041\_06\_QuickStart.pdf)
- [TP1043\_TCP] (http://www.mect.it/en/products/control-and-automation/operator-panels/tp1043/):
  - ModbusTCPclient\_CFG, \_HMI, \_PLC: example of client access to a Modbus TCP server device (see the manual ME7041\_06\_QuickStart.pdf), it can be used with a panel runnig ModbusTCPserver\_PLC.
- [TPAC1006] (http://www.mect.it/en/products/control-and-automation/operator-panels-with-plcpac/tpac1006/):
  - Collaudo\_CFG, \_CAN, \_HMI, \_PLC: activation and testing of all TPAC1006 I/O
  - QuickStart\_HMI: QuickStart\_StarterKit example, already configured for TPAC1006 
- [TPAC1007] (http://www.mect.it/en/products/control-and-automation/operator-panels-with-plcpac/tpac1007/):
  - Collaudo\_CFG, \_HMI, \_PLC:  activation and testing of all TPAC1007 I/O
  - QuickStart\_HMI: QuickStart\_StarterKit example, already configured for TPAC1007
- [TPAC1008] (http://www.mect.it/en/products/control-and-automation/operator-panels-with-plcpac/tpac1008/):
  - Collaudo\_CFG, \_CAN, \_HMI, \_PLC:  activation and testing of all TPAC1008 I/O
  - QuickStart\_HMI: QuickStart\_StarterKit example, already configured for TPAC1008
  - RemoteControl\_CFG, \_HMI: example used to drive the [excavator] (https://github.com/MECTsrl/mect_apps/blob/master/TPAC1008/RemoteControl_HMI/img/escav1.png) and [crane] (https://github.com/MECTsrl/mect_apps/blob/master/TPAC1008/RemoteControl_HMI/img/gru1.png) at [SPS 2015] (http://www.spsitalia.it/94/id_20/mect-srl.html)
