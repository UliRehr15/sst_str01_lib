//  sstStr01LibTypBase.cpp   21.03.18  Re.   21.03.18  Re.
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
sstStr01LibTypBaseCls::sstStr01LibTypBaseCls()
{
 
}
 
// Get Number of Class member
unsigned int sstStr01LibTypBaseCls::getMemberNumber()
{
  unsigned int uiStat = 0;
  uiStat = 1;
  return uiStat;
}
 
// Get Csv-String with all Class member names
std::string sstStr01LibTypBaseCls::getStringName()
{
  std::string oStat;
  oStat = "sstStr01Cls oCsvCnvt";
  return oStat;
}
 
// Get Csv-String with all Class member definition types
std::string sstStr01LibTypBaseCls::getStringType()
{
  std::string oStat;
  oStat = "0.0";
  return oStat;
}
 
// Csv Read Function
int sstStr01LibTypBaseCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstStr01Lib_Str)
{
  int iStat = 0;
//  sstStr01Cls sErrTxt;
  sstStr01Cls oCsvRow;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
 
  iStat = oCsvRow.SetReadPositon(0,0);
 
  if (iStat >= 0)
  iStat = -2;
  // iStat = Str1_AbPos2 ... Error
 
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
int sstStr01LibTypBaseCls::Csv_Write(int iKey , std::string *ssstStr01Lib_Str)
{
  int iStat = 0;
  sstStr01Cls oCsvRow;
  int iRet  = 0;
  if ( iKey != 0) return -1;
 
  iStat = oCsvRow.SetReadPositon(0,0);
 
  if (iStat >= 0)
  iStat = -2;
  // iStat = Str1_AbPos2 ... Error
 
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
