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
// sstStr01Test.cpp    11.12.15  Re.    11.12.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include "sstStr01Lib.h"
#include "sstStr01LibInt.h"

//=============================================================================
int sstStr01_DoSomeInternTests (int iKey)
//-----------------------------------------------------------------------------
{
  sstStr01Cls oFrmtTyp;
//  long TPos=0;
  std::string oZeile;
  std::string oErrTxt;
  sstStr01TestRecFullCls oCsvSet;
//  int iRetVal=0;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Do more intern Tests
  iStat = sstStr011_Test_FuncInt ( 0);
  assert(iStat >= 0);

  oCsvSet.setBVal(0);
  oCsvSet.setCVal("s");
  oCsvSet.setDVal(26437484.33);
  oCsvSet.setFVal(23.3);
  oCsvSet.setIVal(-4);
  oCsvSet.setLVal(-33333333);
  oCsvSet.setSVal("sfasalfa");
  oCsvSet.setUiVal(444);
  oCsvSet.setUlVal(666666666);

  oZeile ="  800 ;  3100  ; 23,5;  -345,576; Aufnahmepunkt";

  iStat = sstStr011_Csv_Test ( 0, &oZeile, &oErrTxt, &oCsvSet);
  assert(iStat >= 0);
  assert(oCsvSet.getIVal() == 800);
  assert(oCsvSet.getLVal() == 3100);

  sstStr01TestRecFullFncCls oTestCsv;
  std::string oCsvTestStr;
  std::string oErrStr;
  std::string oResultStr;


  //int iRetInt;              //!< Return Value Integer
  //long lRetLong;            //!< Return Value Long Integer
  //unsigned int uiRetInt;    //!< Return Value unsigned Integer
  //unsigned long ulRetLong;  //!< Return Value unsigned Long Integer
  //double dRetDouble;        //!< Return Value Double
  //float fRetFloat;          //!< Return Value Float
  //std::string sRetStr;      //!< Return Value String Ds
  //char cRetStr[21];         //!< Return Value Char String
  //bool bRetStr;             //!< Return Value Bool

  oCsvTestStr = "22;-6666666;63000;88888888;-23456.66;234.1;abcdefg;nn nn;.T.";

  oFrmtTyp.SetBoolTyp(0,2);

  iStat = oTestCsv.ReadCsv( 0, &oFrmtTyp, &oCsvTestStr, &oErrStr, &oCsvSet);
  assert(iStat >= 0);
  assert(oCsvSet.getIVal() == 22);
  assert(oCsvSet.getLVal() == -6666666);

  oFrmtTyp.SetBoolTyp(0,2);  // .T.

  iStat = oTestCsv.WrtCsv( 0, &oFrmtTyp, &oErrStr, &oCsvSet, &oResultStr);
  assert(iStat >= 0);
  iStat = oResultStr.find("22;-6666666;63000;88888888;-23456,66;234,1;'abcdefg';'nn nn';.T.",0);
  assert(iStat == 0);


  // Csv ab Position in Integer konvertieren  <BR>
  // iStat = oFrmtTyp.CsvString2_Int2 ( 0, &TPos, &Zeile, &ErrTxt, &iRetVal);

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================

