//  sstStr01LibTypTst1Cls.cpp   21.03.18  Re.   21.03.18  Re.
//
//  Functions for Class "sstStr01Lib"
//
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
#include <string>
 
#include <sstStr01Lib.h>
//#include <sstMath01Lib.h>
//#include <sstMisc01Lib.h>
//#include <sstRec04Lib.h>
 
#include "sstStr01LibTypLib.h"
 
// Constructor
sstStr01LibTypTst1ClsCls::sstStr01LibTypTst1ClsCls()
{
 
}
 
// Get Number of Class member
unsigned int sstStr01LibTypTst1ClsCls::getMemberNumber()
{
  unsigned int uiStat = 0;
  uiStat = 4;
  return uiStat;
}
 
// Get Csv-String with all Class member names
std::string sstStr01LibTypTst1ClsCls::getStringName()
{
  std::string oStat;
  oStat = "iVal;uiVal;lVal;ulVal";
  return oStat;
}
 
// Get Csv-String with all Class member definition types
std::string sstStr01LibTypTst1ClsCls::getStringType()
{
  std::string oStat;
  oStat = "II3.0;UI3.0;LL8.0;UL8.0";
  return oStat;
}
 
// Csv Read Function
int sstStr01LibTypTst1ClsCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstStr01Lib_Str)
{
  int iStat = 0;
//  sstStr01Cls sErrTxt;
  sstStr01Cls oCsvRow;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
 
  iStat = oCsvRow.SetReadPositon(0,0);
 
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Int2( 0, ssstStr01Lib_Str, &this->iVal);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt2( 0, ssstStr01Lib_Str, &this->uiVal);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Int4( 0, ssstStr01Lib_Str, &this->lVal);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstStr01Lib_Str, &this->ulVal);
 
  *sErrTxt = oCsvRow.GetErrorString();
 
  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }
 
  // Small Errors will given back
  iRet = iStat;
 
  return iStat;
}
 
// Csv Write Function
int sstStr01LibTypTst1ClsCls::Csv_Write(int iKey , std::string *ssstStr01Lib_Str)
{
  int iStat = 0;
  sstStr01Cls oCsvRow;
  int iRet  = 0;
  if ( iKey != 0) return -1;
 
  iStat = oCsvRow.SetReadPositon(0,0);
 
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, this->iVal, ssstStr01Lib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt2_2String ( 0, this->uiVal, ssstStr01Lib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int4_2String ( 0, this->lVal, ssstStr01Lib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String ( 0, this->ulVal, ssstStr01Lib_Str);
 
  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }
 
  // Small Errors will given back
  iRet = iStat;
 
  return iStat;
}
