sstStr01Lib - sst String Processing Lib

Import and Export of csv format files.
Import and Export of fix column width (fcw) format files.

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

More Examples see Lib Test project.

This Library is created with QtCreator 4.5.2 and gcc 7.3.0.

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
16.08.2016: Version 1.12: DefType Class with additional Infos Strings for Doxygen.  <BR>
25.09.2016: Version 1.13: More improvements for DefType Class.  <BR>
30.09.2016: Version 1.14: New Import/Export class fix colums width format. <BR>
                          Its prototype and totally untested. <BR>
27.10.2016: Version 1.15: Set decimal places for double/float csv writing. <BR>
31.10.2016: Version 1.16: new function -getReadPosition- in string. <BR>
13.01.2017: Version 1.17: Full test of fix column width functions. <BR>
                          New function split csv string into parts and return as vector. <BR>
                          New function -GetSeparator- . <BR>
16.01.2017: Version 1.18: New VarDefTyp function -GetNameExt- <BR>
                          More VarDefTyp Test functions. <BR>
09.04.2017: Version 1.19: Write-Functions with format info for fix-column-width class. <BR>
18.04.2017: Version 1.20: Expand / Rework UNDEF-Behaviour. <BR>
20.04.2017: Version 1.21: Fix column width class: Expand behavior with NoInformation Chars. <BR>
11.08.2017: Version 1.22: New function -get_TypeStr- for class VarDef. <BR>
                          Better support of std::string type.  <BR>
08.09.2017: Version 1.23: Small changes in intern function sstStr011Cat. <BR>
15.02.2018: Version 1.24: Setlocale for convert float/double functions.  <BR>
02.05.2018: Version 1.25: Extend interface for ReadFloat Csv. <BR>
14.09.2018: Version 1.26: Update to QtCreator 4.5.2 and gcc 7.3.0. <BR>
23.09.2018: Version 1.27: Fixed problem writing variable separator char. <BR>
26.09.2018: Version 1.28: Fixed problem with beginning/ending blanks in string. <BR>
22.04.2019: Version 1.29: Fixed problems reading char string in Fcw Format. <BR>
16.05.2020: Version 1.30: Copy Constructor, copy operator for class sstStr01Cls added. <BR>
                          File -TestTypes.def- added. Generated Code added. <BR>
24.07.2020: Version 1.31: New Method -clear- of class sstStr01VarDefCls. <BR>
18.12.2020: Version 1.32: Patched some Doxygen problems. Closed some warnings. <BR>


