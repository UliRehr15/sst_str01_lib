/**********************************************************************
 *
 * sstStr01LibTest - Testframe for sstStrLib
 * Hosted on github
 *
 * Copyright (C) 2015 Hans Ulrich Rehr
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 **********************************************************************/
// sstStr01LibTest.cpp    11.12.15  Re.    24.11.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <iostream>
#include <string>
#include <vector>


#include <sstStr01Lib.h>
#include <sstStr01FixColWidth.h>

#include "sstStr01LibTest.h"

int main ()
//=============================================================================
{
  std::string oTestString;
  // std::string oErrorStr;
  std::string oResultStr;
  int iResult = 0;
  double dResult = 0.0;
  unsigned long ulResult = 0;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------

  printf("Test Str01Lib Start. \n");

  // Do some intern sstStr01 Tests
  iStat = sstStr01_DoSomeInternTests (0);

  // Test Variable definition type classes and functions
  iStat = Test_VarDefType_Functions ( 0);
  assert(iStat==0);

  { // Test decimal floating point or comma
    sstStr01Cls oSstStr;
    std::string oRetStr;
    int iDecType = oSstStr.getDecType();
    assert (iDecType==0);  // default is decimal comma
    iStat = oSstStr.Csv_Dbl_2String(0,22.2,&oRetStr);
    assert( oRetStr.compare("22,200") == 0);
    oRetStr.clear();
    oSstStr.setUiDec(4);
    iStat = oSstStr.Csv_Dbl_2String(0,22.23456,&oRetStr);
    assert( oRetStr.compare("22,2346") == 0);
    oSstStr.setDecType(1); // set decimal point
    oSstStr.setUiDec(3);
    oRetStr.clear();
    iStat = oSstStr.Csv_Dbl_2String(0,22.2,&oRetStr);
    assert( oRetStr.compare("22.200") == 0);
    sstStr01Cls oCopyStr;
    oCopyStr = oSstStr;
    oRetStr.clear();
    iStat = oCopyStr.Csv_Dbl_2String(0,22.2,&oRetStr);
    assert( oRetStr.compare("22.200") == 0);
  }

  { // Test decimal floating point or comma
    sstStr01Cls* poSstStr = new (sstStr01Cls);

    std::string oRetStr;
    int iDecType = poSstStr->getDecType();
    assert (iDecType==0);  // default is decimal comma
    iStat = poSstStr->Csv_Dbl_2String(0,22.2,&oRetStr);
    assert( oRetStr.compare("22,200") == 0);
    oRetStr.clear();
    poSstStr->setUiDec(4);
    iStat = poSstStr->Csv_Dbl_2String(0,22.23456,&oRetStr);
    assert( oRetStr.compare("22,2346") == 0);
    poSstStr->setDecType(1); // set decimal point
    poSstStr->setUiDec(3);
    oRetStr.clear();
    iStat = poSstStr->Csv_Dbl_2String(0,22.2,&oRetStr);
    assert( oRetStr.compare("22.200") == 0);
    delete (poSstStr);
  }

  {
    sstStr01Cls oSstStr;
    std::string oRetStr;
    oSstStr.SetBracket(0,(char*)"\x22");  // quotes
    oSstStr.SetSeparatorTyp(0,1);
    iStat = oSstStr.Csv_Str_2String(0,"Test",&oRetStr);
    iStat = oSstStr.Csv_Str_2String(0,"Test",&oRetStr);
    assert( oRetStr.compare("\x22Test\x22;\x22Test\x22") == 0);
  }

  {
    sstStr01Cls oSstStr;
    oSstStr.SetBracket(0,(char*)"()");
    oTestString = "  (MyTest) 800 ; xx '31;00'  ;Aufnahmepunkt;.T.";
    iStat = oSstStr.GetNextBrakeInfo( 1, &oTestString, &oResultStr);
    assert( strcmp(oResultStr.c_str(),"MyTest") == 0);
  }

  sstStr01Cls oStringMan;  // sst String manager

  oStringMan.SetBoolTyp(0,2);

  // === Test CSV Reading 1
  oTestString = "  800 ; xx '31;00'  ;Aufnahmepunkt;.T.";

  // Information 1
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Str ( 0, &oTestString, &oResultStr);
  assert( strcmp(oResultStr.c_str(),"800") == 0);
  unsigned long ulPos = oStringMan.getReadPosition();
  assert(ulPos == 7);  // Position 7 is semicolon
  // Information 2
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Str ( 0, &oTestString, &oResultStr);
  assert( strcmp(oResultStr.c_str(),"31;00") == 0);
  // Information 3
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Str ( 0, &oTestString, &oResultStr);
  assert( strcmp(oResultStr.c_str(),"Aufnahmepunkt") == 0);
  bool bRetVal = 0;
  if(iStat >= 0) iStat = oStringMan.CsvString2_Bool ( 0, &oTestString, &bRetVal);
  assert( bRetVal == 1);  // Result should be true

  // === Test CSV Reading 2
  oTestString = ";3100;;Aufnahmepunkt";
  oStringMan.ClearAll();
  oResultStr.clear();

  // Information 1
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Str ( 0, &oTestString, &oResultStr);
  assert( strcmp(oResultStr.c_str(),"") == 0);
  // Information 2
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Int2 ( 0, &oTestString, &iResult);
  assert( iResult == 3100);
  // Information 3
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Dbl ( 0, &oTestString, &dResult);
  assert( dResult == dSSTSTR01_UNDEF_R8);
  // Information 4
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Str ( 0, &oTestString, &oResultStr);
  assert( strcmp(oResultStr.c_str(),"Aufnahmepunkt") == 0);

  // === Test CSV Reading 3
  oTestString = "800;;Aufnahmepunkt";
  oStringMan.ClearAll();

  // Information 1
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Str ( 0, &oTestString, &oResultStr);
  assert( strcmp(oResultStr.c_str(),"800") == 0);
  // Information 2
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Str ( 0, &oTestString, &oResultStr);
  assert( strcmp(oResultStr.c_str(),"") == 0);
  // Information 3
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Str ( 0, &oTestString, &oResultStr);
  assert( strcmp(oResultStr.c_str(),"Aufnahmepunkt") == 0);

  // === Test CSV Reading 4
  oTestString = "800;3100;";
  oStringMan.ClearAll();

  // Information 1
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Str ( 0, &oTestString, &oResultStr);
  assert( strcmp(oResultStr.c_str(),"800") == 0);
  // Information 2
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Str ( 0, &oTestString, &oResultStr);
  assert( strcmp(oResultStr.c_str(),"3100") == 0);
  // Information 3
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Str ( 0, &oTestString, &oResultStr);
  assert( strcmp(oResultStr.c_str(),"") == 0);

  // === Test CSV Reading 5 with delimiters
  oTestString = "800;'3100'";
  oStringMan.ClearAll();
  oStringMan.SetBracket(0,(char*) "'");

  // Information 1
  if(iStat >= 0)  iStat = oStringMan.CsvString2_UInt4( 0, &oTestString, &ulResult);
  assert( ulResult == 800);
  // Information 2
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Str ( 0, &oTestString, &oResultStr);
  assert( strcmp(oResultStr.c_str(),"3100") == 0);

  // === Test CSV Writing 1
  oStringMan.ClearAll();

  oStringMan.SetBoolTyp(0,2);  // Output .F./.T.
  oStringMan.SetSeparatorTyp(0,1);

  char cFrmtStrDbl[20];
  char cFrmtStrFlt[20];
  std::string sResult_Row;
  std::string oInput_Row = "abcdefg";

  strncpy(cFrmtStrFlt,"%# 06.1f",20);
  // strncpy(cFrmtStrDbl,"%# 015.4f",20);
  strncpy(cFrmtStrDbl,"%# 15.2f",20);

  if (iStat >= 0)
    iStat = oStringMan.Csv_Int2_2String ( 0, 22, &sResult_Row);
  if (iStat >= 0)
    iStat = oStringMan.Csv_Int4_2String ( 0, -6666666, &sResult_Row);
  if (iStat >= 0)
    iStat = oStringMan.Csv_UInt2_2String ( 0, 63000, &sResult_Row);
  if (iStat >= 0)
    iStat = oStringMan.Csv_UInt4_2String ( 0, 88888888, &sResult_Row);
  if (iStat >= 0)
    iStat = oStringMan.Csv_DblFrmt_2String ( 0, cFrmtStrDbl, -23456.66, &sResult_Row);
  if (iStat >= 0)
    iStat = oStringMan.Csv_RealFrmt_2String ( 0, cFrmtStrFlt, 234.1, &sResult_Row);
  if (iStat >= 0)
    iStat = oStringMan.Csv_Str_2String ( 0, oInput_Row, &sResult_Row);
  if (iStat >= 0)
    iStat = oStringMan.Csv_Char_2String ( 0, (char*)"nn nn", &sResult_Row);
  if (iStat >= 0)
    iStat = oStringMan.Csv_Bool_2String ( 0, 1, &sResult_Row);

  iStat = sResult_Row.find("22;-6666666;63000;88888888;-23456,66;234,1;'abcdefg';'nn nn';.T.",0);
  assert(iStat == 0);

  // Test String to CSV functions
  iStat = Test_String2CSV ( 0);

  // Test fcw class and functions
  iStat = Test_FixColumnWidthSystem ( 0);


  printf("Test Str01Lib Success. \n");

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int Test_String2CSV (int iKey)
//-----------------------------------------------------------------------------
{

  std::string oTestStr;
  sstStr01Cls oCsvConvert;

  int iVal = 0;
  long lVal = 0;
  unsigned int uiVal = 0;
  unsigned long ulVal = 0;
  float fVal = 0.0;
  double dVal = 0.0;
  bool bVal = false;
  std::string oStrVal;
  char cVal[10];

  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

 printf("Test Functions CSV-String to Value. ");
 oTestStr = "22;-6666666;63000;88888888;-23456,66;1,10;'  abcdefg';'nn nn';.T.";

 std::vector<std::string> data;
 oCsvConvert.CsvString2_VectorAll(0,oTestStr, &data);

  oCsvConvert.SetBoolTyp(0,2);  // .F. + .T.
  // oCsvConvert.SetNoInfoChar(0,(char*)"");

  oCsvConvert.CsvString2_Int2( 0, &oTestStr, &iVal);
  assert(iVal == 22);
  oCsvConvert.CsvString2_Int4( 0, &oTestStr, &lVal);
  assert(lVal == -6666666);

  oCsvConvert.CsvString2_UInt2( 0, &oTestStr, &uiVal);
  assert(uiVal == 63000);
  oCsvConvert.CsvString2_UInt4( 0, &oTestStr, &ulVal);
  assert(ulVal == 88888888);

  oCsvConvert.CsvString2_Dbl( 0, &oTestStr, &dVal);
  assert(dVal == -23456.66);
  oCsvConvert.CsvString2_Flt( 0, &oTestStr, &fVal);
  assert(fVal > 1.1 && fVal < 1.2);

  oCsvConvert.CsvString2_Str( 0, &oTestStr, &oStrVal);
  assert(oStrVal == "abcdefg");
  oCsvConvert.CsvString2_Char( 0, &oTestStr, cVal, 10);
  iStat = strncmp(cVal,"nn nn",10);
  assert(iStat == 0);

  oCsvConvert.CsvString2_Bool( 0, &oTestStr, &bVal);
  assert(bVal == true);

  printf("Checked. \n");

  // Fatal Errors goes to an assert

  // Pipe |
  // Smaller <
  // Greater >

  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int Test_FixColumnWidthSystem (int iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  {
    sstStr01FcwCls oFcwCnvt;
    int iColWidth = 2;
    std::string oFcwStr = "12345678901234567890";
    std::string oStrVal;
    int iVal = 0;
    long lVal = 0;
    double dVal = 0;
    float fVal = 0;

    assert (oFcwCnvt.GetReadPosition()== 1);

    // read next data from oFcwStr as string
    iStat = oFcwCnvt.String2Str ( 0, iColWidth, oFcwStr, &oStrVal);
    int iPos = oStrVal.compare("12");
    assert(iPos == 0);
    assert (oFcwCnvt.GetReadPosition()== 3);

    // read next data from oFcwStr as string
    iStat = oFcwCnvt.String2Str ( 0, iColWidth, oFcwStr, &oStrVal);
    iPos = oStrVal.compare("34");
    assert(iPos == 0);
    assert (oFcwCnvt.GetReadPosition()== 5);

    // read next data from oFcwStr as int
    iStat = oFcwCnvt.String2Int ( 0, iColWidth, oFcwStr, &iVal);
    assert(iVal == 56);
    assert (oFcwCnvt.GetReadPosition()== 7);

    // read next data from oFcwStr as long
    iStat = oFcwCnvt.String2Long ( 0, iColWidth, oFcwStr, &lVal);
    assert(lVal == 78);
    assert (oFcwCnvt.GetReadPosition()== 9);

    // read next data from oFcwStr as double
    iStat = oFcwCnvt.String2Dbl ( 0, iColWidth, oFcwStr, &dVal);
    assert(dVal == 90);
    assert (oFcwCnvt.GetReadPosition()== 11);

    // read next data from oFcwStr as float
    iStat = oFcwCnvt.String2Float ( 0, iColWidth, oFcwStr, &fVal);
    assert(fVal == 12);
    assert (oFcwCnvt.GetReadPosition()== 13);
  }
  {
    sstStr01FcwCls oFcwCnvt;
    int iColWidth = 8;
    std::string oFcwStr = "12  34  56";
    std::string oStrVal;

    assert (oFcwCnvt.GetReadPosition()== 1);

    // read next data from oFcwStr as string
    iStat = oFcwCnvt.String2Str ( 0, iColWidth, oFcwStr, &oStrVal);
    int iPos = oStrVal.compare("12  34");
    assert(iPos == 0);
    assert (oFcwCnvt.GetReadPosition()== 9);

    // read next data from oFcwStr as string
    iColWidth = 2;
    iStat = oFcwCnvt.String2Str ( 0, iColWidth, oFcwStr, &oStrVal);
    iPos = oStrVal.compare("56");
    assert(iPos == 0);
    assert (oFcwCnvt.GetReadPosition()== 11);
  }
  {

    sstStr01FcwCls oFcwCnvt;
    int iColWidth = 2;
    std::string oFcwStr;
    std::string oStrVal;
    char cVal[10] = "ab";
    int iVal = 4;
    long lVal = 67;
    double dVal = 33;
    float fVal = 11;

    assert (oFcwCnvt.GetReadPosition()== 1);

    iStat = oFcwCnvt.Char2String(0,iColWidth,cVal,&oFcwStr);
    int iPos = oFcwStr.compare("ab");
    assert(iPos == 0);
    assert (oFcwCnvt.GetReadPosition()== 3);

    strncpy(cVal,"12",10);
    iStat = oFcwCnvt.Char2String(0,iColWidth,cVal,&oFcwStr);
    iPos = oFcwStr.compare("ab12");
    assert(iPos == 0);
    assert (oFcwCnvt.GetReadPosition()== 5);

    iStat = oFcwCnvt.Int2String(1,iColWidth,iVal,&oFcwStr);
    iPos = oFcwStr.compare("ab12 4");
    assert(iPos == 0);
    assert (oFcwCnvt.GetReadPosition()== 7);

    iStat = oFcwCnvt.Long2String(0,iColWidth,lVal,&oFcwStr);
    iPos = oFcwStr.compare("ab12 467");
    assert(iPos == 0);
    assert (oFcwCnvt.GetReadPosition()== 9);

    iStat = oFcwCnvt.Dbl2String(0,iColWidth,dVal,&oFcwStr);
    iPos = oFcwStr.compare("ab12 46733");
    assert(iPos == 0);
    assert (oFcwCnvt.GetReadPosition()== 11);

    iStat = oFcwCnvt.Float2String(0,iColWidth,fVal,&oFcwStr);
    iPos = oFcwStr.compare("ab12 4673311");
    assert(iPos == 0);
    assert (oFcwCnvt.GetReadPosition()== 13);

    strncpy(cVal,"12 ",10);
    oFcwCnvt.SetNoInfoChar(0,(char*)"");
    iStat = oFcwCnvt.Char2String(0,3,cVal,&oFcwStr);
    iPos = oFcwStr.compare("ab12 467331112 ");
    assert(iPos == 0);
    assert (oFcwCnvt.GetReadPosition()== 16);
  }

  {
    sstStr01FcwCls oFcwCnvt;
    // int iColWidth = 2;
    std::string oFcwStr;
    // std::string oStrVal;
    // char cVal[10] = "ab";
    int iVal = 4;
    // long lVal = 67;
    double dVal = 3.03;
    // float fVal = 11;

    oFcwCnvt.SetReadPositon(0,10);
    // insert int value into string from position 10 to 14 right aligned
    oFcwCnvt.Int2String(1,5,iVal,&oFcwStr);
    //                          123456789-----56
    int iPos = oFcwStr.compare("             4");
    assert(iPos == 0);
    assert (oFcwCnvt.GetReadPosition()== 15);

    oFcwCnvt.SetReadPositon(0,2);
    // insert double value into string from position 2 to 7 right aligned
    oFcwCnvt.Dbl2String(1,6,dVal,&oFcwStr);
    //                      1------89-----56
    iPos = oFcwStr.compare(" 3.0300      4");
    assert(iPos == 0);
    assert (oFcwCnvt.GetReadPosition()== 8);
  }

  {
    sstStr01FcwCls oFcwCnvt;
    // int iColWidth = 2;
    std::string oFcwStr;
    std::string oFrmtStr= "%03i";
    // char cFmtStr[10] = "%03i";
    // std::string oStrVal;
    // char cVal[10] = "ab";
    int iVal = 4;
    // long lVal = 67;
    // double dVal = 3.03;
    // float fVal = 11;

    oFcwCnvt.SetReadPositon(0,10);
    // insert int value into string from position 10 to 14 right aligned
    oFcwCnvt.IntFrmt2String(1,5,iVal, oFrmtStr, &oFcwStr);
    //                          123456789-----56
    int iPos = oFcwStr.compare("           004");
    assert(iPos == 0);
    assert (oFcwCnvt.GetReadPosition()== 15);

  }

  printf("Test Class sstStr01FcwCls Checked. \n");


  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int Test_VarDefType_Functions (int iKey)
//-----------------------------------------------------------------------------
{
  // int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // test sstStr01VarTypeCls class

  printf("Test Class sstStr01VarTypeCls.");
  sstStr01VarType_enum eVarType = sstStr01Double;  // VarType is double
  sstStr01VarTypeCls oVarType;
  std::string oVarTypeStr;

  // convert type enum to cpp var type full string int,double,char ...
  oVarType.Enm2FullStr( 0, eVarType, &oVarTypeStr);
  assert( oVarTypeStr.compare("double") == 0);

  // convert type enum to cpp var type string II, DD, CC ...
  oVarType.Enm2Str( 0, eVarType, &oVarTypeStr);
  assert( oVarTypeStr.compare("DD") == 0);

  // convert type enum to cpp var type small string i, d, c ...
  oVarType.Enm2ShortStr( 0, eVarType, &oVarTypeStr);
  assert( oVarTypeStr.compare("d") == 0);

  oVarType.Str2Enm(0,"II",&eVarType);
  assert(eVarType == sstStr01Int);
  printf("Checked. \n");

  printf("Test Class sstStr01VarDefCls.");
  sstStr01VarDefCls oVarDef;
  oVarDef.Set_SysNam("TestLib");     // group of classes
  oVarDef.Set_ObjNam("TestClass");   // class name
  oVarDef.Set_EleNam("VarName");     // variable name
  oVarDef.Set_Type(sstStr01Double);  // type int, double, char ...
  oVarDef.Set_Width(6);              // total width with decimal point and decimal precision
  oVarDef.Set_Dec(2);                // decimal precision

  // Get extended element name with type,width and dec as string
  std::string oEleNamStr = oVarDef.Get_EleNamExt();
  assert( oEleNamStr.compare("VarName[DD;6;2]") == 0);

  printf("Checked\n");

  printf("Test Class sstStr01VarDefFncCls.");
  sstStr01VarDefFncCls oVarDefFnc;
  std::string oVarDefStr;
  std::string oErrStr;
  oVarDefFnc.WriteCSV(0,oVarDef,&oErrStr, &oVarDefStr);
  assert( oVarDefStr.compare("TestLib;TestClass;VarName;DD;6;2;;;") == 0);

  oVarDefStr = "TestLib2;TestClass3;VarNam8;CC;8;0";
  iStat = oVarDefFnc.ReadCSV( 0, &oVarDefStr, &oErrStr, &oVarDef);
  assert( iStat == 0);
  std::string oCompareStr;
  oCompareStr = oVarDef.Get_SysNam();
  assert( oCompareStr.compare("TestLib2") == 0);
  oCompareStr = oVarDef.Get_ObjNam();
  assert( oCompareStr.compare("TestClass3") == 0);
  oCompareStr = oVarDef.Get_EleNam();
  assert( oCompareStr.compare("VarNam8") == 0);
  assert( oVarDef.Get_Type() == sstStr01Char);
  assert( oVarDef.Get_Width() == 8);
  assert( oVarDef.Get_Dec() == 0);

  std::vector<std::string> oStrVec;
  sstStr01Cls oStrCnvt;
  iStat = oStrCnvt.CsvString2_VectorAll(0,oVarDefStr,&oStrVec);
  assert(iStat == 0);
  assert(oStrVec.at(0).compare("TestLib2") == 0);
  assert(oStrVec.at(1).compare("TestClass3") == 0);
  assert(oStrVec.at(2).compare("VarNam8") == 0);
  assert(oStrVec.at(3).compare("CC") == 0);
  assert(oStrVec.at(4).compare("8") == 0);
  assert(oStrVec.at(5).compare("0") == 0);

  printf("Checked\n");

  return iStat;
}
//=============================================================================

