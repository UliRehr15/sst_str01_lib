//  sstStr01LibTypTst2Cls.cpp   21.03.18  Re.   21.03.18  Re.
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
sstStr01LibTypTst2ClsCls::sstStr01LibTypTst2ClsCls()
{
 
}
 
// Get Number of Class member
unsigned int sstStr01LibTypTst2ClsCls::getMemberNumber()
{
  unsigned int uiStat = 0;
  uiStat = 2;
  return uiStat;
}
 
// Get Csv-String with all Class member names
std::string sstStr01LibTypTst2ClsCls::getStringName()
{
  std::string oStat;
  oStat = "dVal;fVal";
  return oStat;
}
 
// Get Csv-String with all Class member definition types
std::string sstStr01LibTypTst2ClsCls::getStringType()
{
  std::string oStat;
  oStat = "DD10.2;FF6.2";
  return oStat;
}
 
// Csv Read Function
int sstStr01LibTypTst2ClsCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstStr01Lib_Str)
{
  int iStat = 0;
//  sstStr01Cls sErrTxt;
  sstStr01Cls oCsvRow;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
 
  iStat = oCsvRow.SetReadPositon(0,0);
 
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstStr01Lib_Str, &this->dVal);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Flt( 0, ssstStr01Lib_Str, &this->fVal);
 
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
int sstStr01LibTypTst2ClsCls::Csv_Write(int iKey , std::string *ssstStr01Lib_Str)
{
  int iStat = 0;
  sstStr01Cls oCsvRow;
  int iRet  = 0;
  if ( iKey != 0) return -1;
 
  iStat = oCsvRow.SetReadPositon(0,0);
 
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, this->dVal, ssstStr01Lib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Real_2String ( 0, this->fVal, ssstStr01Lib_Str);
 
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
