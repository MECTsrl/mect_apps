Purpose of this Project: Demonstrate the ability to save and restore the values of a block of CrossTable variables in a binary file 


In automation.cpp you will find two cpp functions:

bool dumpVariables(int nStart, int nVariables, QString &szFile2Dump);
// nStart:          Starting Cross Table Index of first Variable to be dumped
// nVariables:      Number of Items to be dumped
// szFile2Dump:     File to be dumped

bool restoreVariables(int nStart, int nVariables, QString &szFile2Restore)
// nStart:          Starting Cross Table Index of first Variable to be restored
// nVariables:      Number of Items to be restored
// szFile2Restore:  File to be restored

For both functions [nStart] is the Cross Table Index (= Row Number in Cross Table File) of the first variable to be Dumped/Restored
nVariables is the number of variables to be Dumped/Restored
szFile2Restore is the file name where dump or restore from values.

The file must be in local partition and the application must have the access rigths to read and write this file

Both functions access the Cross Table variables buffer starting from [nStart] Index for [nVariables] adjacent items.
Unused or undefined variables will be dumped or restored as Zero filled items

The value of [nStart] must be between 1 and  4999 (Last User Cross Table Variable)
The value of [nStart] + [nVariables] must not exceed 4999 (Last User Cross Table Variable)

In this example [nStart] is 2001, the row of variable [HMI_1_Start_H_1], and [nVariables] is equal to 40, so 40 adjacent values are saved, from 2001 to 2040
The crosstable row of a variable can be found in file "crosstable.h" that is generated from CrossTable at compile time, as a [#define] C directive with the same name of the variable preceded by [ID_]
