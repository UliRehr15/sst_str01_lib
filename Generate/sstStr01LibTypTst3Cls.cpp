//  sstStr01LibTypTst3Cls.cpp   21.03.18  Re.   21.03.18  Re.
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
sstStr01LibTypTst3ClsCls::sstStr01LibTypTst3ClsCls()
{
 
}
 
// Get Number of Class member
unsigned int sstStr01LibTypTst3ClsCls::getMemberNumber()
{
  unsigned int uiStat = 0;
  uiStat = 3;
  return uiStat;
}
 
// Get Csv-String with all Class member names
std::string sstStr01LibTypTst3ClsCls::getStringName()
{
  std::string oStat;
  oStat = "cVal;bVal;daVal";
  return oStat;
}
 
// Get Csv-String with all Class member definition types
std::string sstStr01LibTypTst3ClsCls::getStringType()
{
  std::string oStat;
  oStat = "CC6.0;BB1.0;DA8.0";
  return oStat;
}
 
// Csv Read Function
int sstStr01LibTypTst3ClsCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstStr01Lib_Str)
{
  int iStat = 0;
//  sstStr01Cls sErrTxt;
  sstStr01Cls oCsvRow;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
 
  iStat = oCsvRow.SetReadPositon(0,0);
 
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Char( 0, ssstStr01Lib_Str, this->cVal,7);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Bool( 0, ssstStr01Lib_Str, &this->bVal);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Char( 0, ssstStr01Lib_Str, this->daVal,9);
 
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
int sstStr01LibTypTst3ClsCls::Csv_Write(int iKey , std::string *ssstStr01Lib_Str)
{
  int iStat = 0;
  sstStr01Cls oCsvRow;
  int iRet  = 0;
  if ( iKey != 0) return -1;
 
  iStat = oCsvRow.SetReadPositon(0,0);
 
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Char_2String ( 0, this->cVal, ssstStr01Lib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Bool_2String ( 0, this->bVal, ssstStr01Lib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Char_2String ( 0, this->daVal, ssstStr01Lib_Str);
 
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
