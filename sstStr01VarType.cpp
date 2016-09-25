/**********************************************************************
 *
 * sstStrLib - cpp string library for sst
 * Hosted on github
 *
 * Copyright (C) 2015 Uli Rehr
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation.
 * See the COPYING file for more information.
 *
 **********************************************************************/
// sstStr01VarType.cpp    10.05.16  Re.    10.05.16  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include "sstStr01Lib.h"
#include "sstStr01LibInt.h"

//=============================================================================
sstStr01VarTypeCls::sstStr01VarTypeCls()
{

}
//=============================================================================
int sstStr01VarTypeCls::Str2Enm (int                   iKey,
                                 std::string           oTypeStr,
                                 sstStr01VarType_enum *eLocType)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (oTypeStr.length() != 2) return -2;

  // LL, II, FF, DD, CC, BB, DA

  if (strncmp(oTypeStr.c_str(),"LL",2) == 0)
  {
    *eLocType = sstStr01Long;
  }
  else if(strncmp(oTypeStr.c_str(),"UL",2) == 0)
  {
    *eLocType = sstStr01ULong;
  }
  else if(strncmp(oTypeStr.c_str(),"II",2) == 0)
  {
    *eLocType = sstStr01Int;
  }
  else if(strncmp(oTypeStr.c_str(),"UI",2) == 0)
  {
    *eLocType = sstStr01UInt;
  }
  else if(strncmp(oTypeStr.c_str(),"FF",2) == 0)
  {
    *eLocType = sstStr01Float;
  }
  else if(strncmp(oTypeStr.c_str(),"DD",2) == 0)
  {
    *eLocType = sstStr01Double;
  }
  else if(strncmp(oTypeStr.c_str(),"CC",2) == 0)
  {
    *eLocType = sstStr01Char;
  }
  else if(strncmp(oTypeStr.c_str(),"BB",2) == 0)
  {
    *eLocType = sstStr01Bool;
  }
  else if(strncmp(oTypeStr.c_str(),"DA",2) == 0)
  {
    *eLocType = sstStr01Date;
  }
  else
  {
    *eLocType = sstStr01Unknown;
    iStat = -1;
  }
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
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
//int sstStr01VarTypeCls::Str_Row2TypeDS (int           iKey,
//                    std::string  *sFilStr,
//                    std::string  *sErrTxt,
//                    sstStr01VarDefCls *oStrType)
////-----------------------------------------------------------------------------
//{
//  sstStr01VarType_enum eLocType;
//  std::string  sRetStr;
//  char cTrnZ[2]=";";
//  long TPos = 0;
//  int iRet  = 0;
//  int iStat = 0;
////-----------------------------------------------------------------------------
//  if ( iKey != 0) return -1;

//  // Csv ab Position in String konvertieren.
//  // Read System name
//  // iStat = sstStr011_AbPosCsv2Str ( 0, &TPos, sFilStr, sErrTxt, &sRetStr);
//  iStat = sstStr011_AbPos2Str ( 0, &TPos, cTrnZ, sFilStr, sErrTxt, &sRetStr);

//  if(iStat >= 0)
//  {
//    strcpy(oStrType->cSysNam,sRetStr.Txt);
//    // strcpy(oStrType->cObjNam,sRetStr.Txt);
//    // Read Class name
//    // iStat = sstStr011_AbPosCsv2Str ( 0, &TPos, sFilStr, sErrTxt, &sRetStr);
//    iStat = sstStr011_AbPos2Str ( 0, &TPos, cTrnZ, sFilStr, sErrTxt, &sRetStr);
//  }

//  if(iStat >= 0)
//  {
//    strcpy(oStrType->cObjNam,sRetStr.Txt);
//    // strcat(oStrType->cObjNam,"_");
//    // strcat(oStrType->cObjNam,sRetStr.Txt);
//    // Read element name
//    // iStat = sstStr011_AbPosCsv2Str ( 0, &TPos, sFilStr, sErrTxt, &sRetStr);
//    iStat = sstStr011_AbPos2Str ( 0, &TPos, cTrnZ, sFilStr, sErrTxt, &sRetStr);
//  }

//  if(iStat >= 0)
//  {
//    strcpy(oStrType->cEleNam,sRetStr.Txt);
//    // Read element Type
//    // iStat = sstStr011_AbPosCsv2Str ( 0, &TPos, sFilStr, sErrTxt, &sRetStr);
//    iStat = sstStr011_AbPos2Str ( 0, &TPos, cTrnZ, sFilStr, sErrTxt, &sRetStr);
//  }

//  if (iStat >= 0)
//  {
//    iStat = Str2Enm ( 0, sRetStr.Txt, &eLocType);
//  }

//  if(iStat >= 0)
//  {

//    oStrType->eType = eLocType;
//    // Read element width
//    // iStat = sstStr011_AbPosCsv2Int2 ( 0, &TPos, sFilStr, sErrTxt, &iRet);
//    iStat = sstStr011_AbPos2Int ( 0, &TPos, cTrnZ, sFilStr, sErrTxt, &iRet);
//  }

//  if(iStat >= 0)
//  {
//    oStrType->iWidth = iRet;
//    // Read element Dec
//    // iStat = sstStr011_AbPosCsv2Int2 ( 0, &TPos, sFilStr, sErrTxt, &iRet);
//    iStat = sstStr011_AbPos2Int ( 0, &TPos, cTrnZ, sFilStr, sErrTxt, &iRet);
//  }

//  if(iStat >= 0)
//  {
//    oStrType->iDec = iRet;
//  }

//  // Fatal Errors goes to an assert
//  if (iRet < 0)
//  {
//    // Expression (iRet >= 0) has to be fullfilled
//    assert(0);
//  }

//  // Small Errors will given back
//  iRet = iStat;

//  return iRet;
//}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
//int sstStr01VarTypeCls::str_TypeDS2Row (int            iKey,
//                    sstStr01VarDefCls  *oSstType,
//                    std::string   *sErrTxt,
//                    std::string   *sExpStr)
////-----------------------------------------------------------------------------
//{
//  int iRet  = 0;
//  int iStat = 0;
////-----------------------------------------------------------------------------
//  if ( iKey != 0) return -1;

//  // Init Str1 object.
//  iStat = sstStr011_Init ( 0, sExpStr);

//  // convert string value to csv-formatted string and append to string
//  // Insert object name
//  iStat = sstStr011_Char_2Csv ( 0, oSstType->cSysNam, sExpStr, sErrTxt);

//  // convert string value to csv-formatted string and append to string
//  // Insert object name
//  iStat = sstStr011_Char_2Csv ( 0, oSstType->cObjNam, sExpStr, sErrTxt);

//  // convert string value to csv-formatted string and append to string
//  // insert element name
//  iStat = sstStr011_Char_2Csv ( 0, oSstType->cEleNam, sExpStr, sErrTxt);

//  // convert string value to csv-formatted string and append to string
//  // insert variable type information

//  switch (oSstType->eType)
//  {
//  case myFloat:
//  {
//      iStat = sstStr011_Char_2Csv ( 0, (char*) "FF", sExpStr, sErrTxt);
//    break;
//  }
//  case myDouble:
//  {
//      iStat = sstStr011_Char_2Csv ( 0, (char*) "DD", sExpStr, sErrTxt);
//    break;
//  }
//  case myInt:
//  {
//      iStat = sstStr011_Char_2Csv ( 0, (char*) "II", sExpStr, sErrTxt);
//    break;
//  }
//  case myLong:
//  {
//      iStat = sstStr011_Char_2Csv ( 0, (char*) "LL", sExpStr, sErrTxt);
//    break;
//  }
//  case myChar:
//  {
//      iStat = sstStr011_Char_2Csv ( 0, (char*) "CC", sExpStr, sErrTxt);
//    break;
//  }
//  case myDate:
//  {
//      iStat = sstStr011_Char_2Csv ( 0, (char*) "DA", sExpStr, sErrTxt);
//    break;
//  }
//  case myBool:
//  {
//    iStat = sstStr011_Char_2Csv ( 0, (char*) "BB", sExpStr, sErrTxt);
//    break;
//  }
//  default:
//  {
//    break;
//  }
//  }

//  iStat = sstStr011_Int2_2Csv ( 0, oSstType->iWidth, sExpStr, sErrTxt);

//  iStat = sstStr011_Int2_2Csv ( 0, oSstType->iDec, sExpStr, sErrTxt);

//  // Fatal Errors goes to an assert
//  if (iRet < 0)
//  {
//    // Expression (iRet >= 0) has to be fullfilled
//    assert(0);
//  }

//  // Small Errors will given back
//  iRet = iStat;

//  return iRet;
//}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstStr01VarTypeCls::Enm2FullStr (int           iKey,
                      sstStr01VarType_enum  eCppType,
                      std::string         *oTypeChar)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  switch (eCppType)
  {
  case sstStr01Int:    *oTypeChar ="int";break;
  case sstStr01UInt:    *oTypeChar ="unsigned int";break;
  case sstStr01Long:   *oTypeChar = "long";break;
  case sstStr01ULong:   *oTypeChar = "unsigned long";break;
  case sstStr01Char:   *oTypeChar = "char";break;
  case sstStr01Float:  *oTypeChar = "float";break;
  case sstStr01Double: *oTypeChar = "double";break;
  case sstStr01Bool:   *oTypeChar = "bool";break;
  // case myDate:   strcpy(cTypeChar,"sstDate_stru");break;
  case sstStr01Date:   *oTypeChar = "char";break;  // for example "20040506"
    default: *oTypeChar = "";break;
  }

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
int sstStr01VarTypeCls::Enm2Str (int                    iKey,
                                 sstStr01VarType_enum   eCppType,
                                 std::string           *oTypeStr)
//-----------------------------------------------------------------------------
{
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  switch (eCppType)
  {
  case sstStr01Int:    *oTypeStr = "II"; break;
  case sstStr01UInt:   *oTypeStr = "UI"; break;
  case sstStr01Long:   *oTypeStr = "LL"; break;
  case sstStr01ULong:  *oTypeStr = "UL"; break;
  case sstStr01Char:   *oTypeStr = "CC"; break;
  case sstStr01Float:  *oTypeStr = "FF"; break;
  case sstStr01Double: *oTypeStr = "DD"; break;
  case sstStr01Bool:   *oTypeStr = "BB"; break;
  case sstStr01Date:   *oTypeStr = "DA"; break;
  default: *oTypeStr = ""; iStat = -2; break;
  }

  return iStat;
}
//=============================================================================
int sstStr01VarTypeCls::Enm2ShortStr (int                    iKey,
                                      sstStr01VarType_enum   eCppType,
                                      std::string           *oTypeStr)
//-----------------------------------------------------------------------------
{
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  switch (eCppType)
  {
  case sstStr01Int:    *oTypeStr = "i"; break;
  case sstStr01UInt:    *oTypeStr = "ui"; break;
  case sstStr01Long:   *oTypeStr = "l"; break;
  case sstStr01ULong:   *oTypeStr = "ul"; break;
  case sstStr01Char:   *oTypeStr = "c"; break;
  case sstStr01Float:  *oTypeStr = "f"; break;
  case sstStr01Double: *oTypeStr = "d"; break;
  case sstStr01Bool:   *oTypeStr = "b"; break;
  default: *oTypeStr = "";iStat = -1; break;
  }

  return iStat;
}
//=============================================================================

