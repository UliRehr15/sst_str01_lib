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
#include <string>
#include <assert.h>

#include <sstStr01Lib.h>

#include "sstStr01LibTest.h"

int main ()
//=============================================================================
{
  std::string oTestString;
  std::string oErrorStr;
  std::string oResultStr;
  int iResult = 0;
  unsigned long ulResult = 0;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------

  printf("Test Str01Lib Start. \n");

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
  printf("Checked\n");

  printf("Test Class sstStr01VarDefFncCls.");
  sstStr01VarDefFncCls oVarDefFnc;
  std::string oVarDefStr;
  std::string oErrStr;
  oVarDefFnc.WriteCSV(0,oVarDef,&oErrStr, &oVarDefStr);
  assert( oVarDefStr.compare("TestLib;TestClass;VarName;DD;6;2") == 0);

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
  printf("Checked\n");

  // Do some intern sstStr01 Tests
  iStat = sstStr01_DoSomeInternTests (0);

  { // Test decimal floating point or comma
    sstStr01Cls oSstStr;
    std::string oRetStr;
    int iDecType = oSstStr.getDecType();
    assert (iDecType==0);  // default is decimal comma
    iStat = oSstStr.Csv_Dbl_2String(0,22.2,&oRetStr);
    assert( oRetStr.compare("22,200") == 0);
    oSstStr.setDecType(1); // set decimal point
    oRetStr.clear();
    iStat = oSstStr.Csv_Dbl_2String(0,22.2,&oRetStr);
    assert( oRetStr.compare("22.200") == 0);
  }

  {
    sstStr01Cls oSstStr;
    std::string oRetStr;
    oSstStr.SetBracket(0,(char*)"\x22");  // quotes
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

  // === Test CSV Reading 1
  oTestString = "  800 ; xx '31;00'  ;Aufnahmepunkt;.T.";

  // Information 1
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Str ( 0, &oTestString, &oResultStr);
  assert( strcmp(oResultStr.c_str(),"800") == 0);
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
  oTestString = ";3100;Aufnahmepunkt";
  oStringMan.ClearAll();
  oResultStr.clear();

  // Information 1
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Str ( 0, &oTestString, &oResultStr);
  assert( strcmp(oResultStr.c_str(),"") == 0);
  // Information 2
  if(iStat >= 0)  iStat = oStringMan.CsvString2_Int2 ( 0, &oTestString, &iResult);
  assert( iResult == 3100);
  // Information 3
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

  // === Test CSV Reading 4 with delimiters
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
    iStat = oStringMan.Csv_Real_2String ( 0, cFrmtStrFlt, 234.1, &sResult_Row);
  if (iStat >= 0)
    iStat = oStringMan.Csv_Str_2String ( 0, oInput_Row, &sResult_Row);
  if (iStat >= 0)
    iStat = oStringMan.Csv_Char_2String ( 0, (char*)"nn nn", &sResult_Row);
  if (iStat >= 0)
    iStat = oStringMan.Csv_Bool_2String ( 0, 1, &sResult_Row);

  iStat = sResult_Row.find("22;-6666666;63000;88888888;-23456,66;234,1;'abcdefg';'nn nn';.T.",0);
  assert(iStat == 0);

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
