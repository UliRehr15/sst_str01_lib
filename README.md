sstStr01Lib - sst String Processing Lib

Import and Export of csv format files.

for example create user record:
double myDouble
int    myInt
char   myChar

Create user csv import function:
   sstStr01Import_to_double (record.mydouble)
   sstStr01Import_to_int(record.myInt)
   sstStr01Import_to_char(record.myChar)

Create user csv Export function:
   sstStr01Export_from_double (record.mydouble)
   sstStr01Export_from_int(record.myInt)
   sstStr01Export_from_char(record.myChar)

Compile with QT 5.2 and QTCreator 3.0

Structure of coding projects should be:

.. [libs]
   [sstStr01Lib]

11.12.2015: Version 1.0: CSV Reading/Writing functions. <BR>
18.12.2015: Version 1.1: Small corrections. <BR>
                         Lib Name, Error behavior. <BR>
12.02.2016: Version 1.2: Extend doxygen documentation.  <BR>
                         New function: Get String inside Brackets. <BR>
04.03.2016: Version 1.3: Output select decimal floating point or comma.  <BR>
21.03.2016: Version 1.4: Patch error in intern function sstStr011_GetNextSBrakeInfo.  <BR>
17.05.2016: Version 1.5: Type definitions integer, double, char and so on.  <BR>
                         Class/Member definitions: name class, name member, type, width and Dec.  <BR>
19.05.2016: Version 1.6: Improvements in namespace sstStr01.  <BR>
20.05.2016: Version 1.7: More improvements in namespace sstStr01.  <BR>
                         Add small and full test record classes.  <BR>
13.06.2016: Version 1.8: Better Handling of NAN Values.  <BR>
                         Patch error reading bracket strings <BR>
17.06.2016: Version 1.9: Better Handling of empty Values.  <BR>
                         Extend working with bool values.  <BR>
11.07.2016: Version 1.10: Better Handling of extreme double Values.  <BR>
07.08.2016: Version 1.11: Setlocale for convert float/double functions.  <BR>
                          Extend test convert string to CSV. <BR>

