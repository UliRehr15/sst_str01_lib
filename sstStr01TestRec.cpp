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
// sstStr01TestRec.cpp    20.05.16  Re.    20.05.16  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include "sstStr01Lib.h"
#include "sstStr01LibInt.h"

//=============================================================================
sstStr01TestRecSmallCls::sstStr01TestRecSmallCls()
{
  // memset ( this, 0, sizeof(*this));
}

int sstStr01TestRecSmallCls::getIVal() const
{
return iVal;
}

void sstStr01TestRecSmallCls::setIVal(int value)
{
iVal = value;
}


char* sstStr01TestRecSmallCls::getCVal()
{
  return this->cVal;
}

void sstStr01TestRecSmallCls::setCVal(const char *value)
{
 strncpy(this->cVal,value,21);
}
//=============================================================================
sstStr01TestRecSmallFncCls::sstStr01TestRecSmallFncCls()
{
  memset ( this, 0, sizeof(*this));
}
//=============================================================================
int sstStr01TestRecSmallFncCls::WrtCsv( int               iKey,
                              sstStr01Cls *oFrmtTyp,
                              std::string      *sErrStr,
                              sstStr01TestRecSmallCls    *oCsvSet,
                              std::string      *sResult_Row)
{
  int iStat = 0;
  char cFrmtStrDbl[20];
  char cFrmtStrFlt[20];
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  strncpy(cFrmtStrFlt,"%# 06.1f",20);
  // strncpy(cFrmtStrDbl,"%# 015.4f",20);
  strncpy(cFrmtStrDbl,"%# 15.2f",20);

  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_Int2_2String ( 0, oCsvSet->getIVal(), sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_Char_2String ( 0, oCsvSet->getCVal(), sResult_Row);

  if (iStat < 0)
  {
    *sErrStr = oFrmtTyp->GetErrorString();
  }
  return iStat;
}
//=============================================================================
//int iRetInt;              //!< Return Value Integer
//long lRetLong;            //!< Return Value Long Integer
//unsigned int uiRetInt;    //!< Return Value unsigned Integer
//unsigned long ulRetLong;  //!< Return Value unsigned Long Integer
//double dRetDouble;        //!< Return Value Double
//float fRetFloat;          //!< Return Value Float
//std::string sRetStr;      //!< Return Value String Ds
//char cRetStr[21];         //!< Return Value Char String
//bool bRetStr;             //!< Return Value Bool
//=============================================================================
int sstStr01TestRecSmallFncCls::ReadCsv( int iKey,
                               sstStr01Cls *oFrmtTyp,
                               std::string   *sTstTxt,
                               std::string   *sErrTxt,
                               sstStr01TestRecSmallCls *oCsvSet)
{
  // unsigned long lTxtPos = 0;
  int iTmpVal;
  char cTmpVal[21];
  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (iStat >= 0)
  {
    iStat = oFrmtTyp->CsvString2_Int2( 0, sTstTxt, &iTmpVal);
    oCsvSet->setIVal(iTmpVal);
  }

  if (iStat >= 0)
  {
    iStat = oFrmtTyp->CsvString2_Char( 0, sTstTxt, cTmpVal, 21);
    oCsvSet->setCVal(cTmpVal);
  }

  if (iStat < 0)
  {
    *sErrTxt = oFrmtTyp->GetErrorString();
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
sstStr01TestRecFullCls::sstStr01TestRecFullCls()
{
  // memset ( this, 0, sizeof(*this));
}

int sstStr01TestRecFullCls::getIVal() const
{
return iVal;
}

void sstStr01TestRecFullCls::setIVal(int value)
{
iVal = value;
}

long sstStr01TestRecFullCls::getLVal() const
{
return lVal;
}

void sstStr01TestRecFullCls::setLVal(long value)
{
lVal = value;
}

unsigned int sstStr01TestRecFullCls::getUiVal() const
{
return uiVal;
}

void sstStr01TestRecFullCls::setUiVal(unsigned int value)
{
uiVal = value;
}

unsigned long sstStr01TestRecFullCls::getUlVal() const
{
return ulVal;
}

void sstStr01TestRecFullCls::setUlVal(unsigned long value)
{
ulVal = value;
}

double sstStr01TestRecFullCls::getDVal() const
{
return dVal;
}

void sstStr01TestRecFullCls::setDVal(double value)
{
dVal = value;
}

float sstStr01TestRecFullCls::getFVal() const
{
return fVal;
}

void sstStr01TestRecFullCls::setFVal(float value)
{
fVal = value;
}

std::string sstStr01TestRecFullCls::getSVal() const
{
return sVal;
}

void sstStr01TestRecFullCls::setSVal(const std::string &value)
{
sVal = value;
}

char* sstStr01TestRecFullCls::getCVal()
{
  return this->cVal;
}

void sstStr01TestRecFullCls::setCVal(const char *value)
{
 strncpy(this->cVal,value,21);
}

bool sstStr01TestRecFullCls::getBVal() const
{
return bVal;
}

void sstStr01TestRecFullCls::setBVal(bool value)
{
bVal = value;
}
//=============================================================================
sstStr01TestRecFullFncCls::sstStr01TestRecFullFncCls()
{
  memset ( this, 0, sizeof(*this));
}
//=============================================================================
int sstStr01TestRecFullFncCls::WrtCsv( int               iKey,
                              sstStr01Cls *oFrmtTyp,
                              std::string      *sErrStr,
                              sstStr01TestRecFullCls    *oCsvSet,
                              std::string      *sResult_Row)
{
  int iStat = 0;
  char cFrmtStrDbl[20];
  char cFrmtStrFlt[20];
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  strncpy(cFrmtStrFlt,"%# 06.1f",20);
  // strncpy(cFrmtStrDbl,"%# 015.4f",20);
  strncpy(cFrmtStrDbl,"%# 15.2f",20);

  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_Int2_2String ( 0, oCsvSet->getIVal(), sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_Int4_2String ( 0, oCsvSet->getLVal(), sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_UInt2_2String ( 0, oCsvSet->getUiVal(), sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_UInt4_2String ( 0, oCsvSet->getUlVal(), sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_DblFrmt_2String ( 0, cFrmtStrDbl, oCsvSet->getDVal(), sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_Real_2String ( 0, cFrmtStrFlt, oCsvSet->getFVal(), sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_Str_2String ( 0, oCsvSet->getSVal(), sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_Char_2String ( 0, oCsvSet->getCVal(), sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_Bool_2String ( 0, oCsvSet->getBVal(), sResult_Row);

  if (iStat < 0)
  {
    *sErrStr = oFrmtTyp->GetErrorString();
  }
  return iStat;
}
//=============================================================================
//int iRetInt;              //!< Return Value Integer
//long lRetLong;            //!< Return Value Long Integer
//unsigned int uiRetInt;    //!< Return Value unsigned Integer
//unsigned long ulRetLong;  //!< Return Value unsigned Long Integer
//double dRetDouble;        //!< Return Value Double
//float fRetFloat;          //!< Return Value Float
//std::string sRetStr;      //!< Return Value String Ds
//char cRetStr[21];         //!< Return Value Char String
//bool bRetStr;             //!< Return Value Bool
//=============================================================================
int sstStr01TestRecFullFncCls::ReadCsv( int iKey,
                               sstStr01Cls *oFrmtTyp,
                               std::string   *sTstTxt,
                               std::string   *sErrTxt,
                               sstStr01TestRecFullCls *oCsvSet)
{
  // unsigned long lTxtPos = 0;
  int iTmpVal;
  long lTmpVal;
  unsigned int uiTmpVal;
  unsigned long ulTmpVal;
  double dTmpVal;
  float fTmpVal;
  std::string sTmpVal;
  char cTmpVal[21];
  bool bTmpVal;
  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (iStat >= 0)
  {
    iStat = oFrmtTyp->CsvString2_Int2( 0, sTstTxt, &iTmpVal);
    oCsvSet->setIVal(iTmpVal);
  }

  if (iStat >= 0)
  {
    iStat = oFrmtTyp->CsvString2_Int4( 0, sTstTxt, &lTmpVal);
    oCsvSet->setLVal(lTmpVal);
  }

  if (iStat >= 0)
  {
    iStat = oFrmtTyp->CsvString2_UInt2( 0, sTstTxt, &uiTmpVal);
    oCsvSet->setUiVal(uiTmpVal);
  }

  if (iStat >= 0)
  {
    iStat = oFrmtTyp->CsvString2_UInt4( 0, sTstTxt, &ulTmpVal);
    oCsvSet->setUlVal(ulTmpVal);
  }

  if (iStat >= 0)
  {
    iStat = oFrmtTyp->CsvString2_Dbl( 0, sTstTxt, &dTmpVal);
    oCsvSet->setDVal(dTmpVal);
  }

  if (iStat >= 0)
  {
    iStat = oFrmtTyp->CsvString2_Flt( 0, sTstTxt, &fTmpVal);
    oCsvSet->setFVal(fTmpVal);
  }

  if (iStat >= 0)
  {
    iStat = oFrmtTyp->CsvString2_Str( 0, sTstTxt, &sTmpVal);
    oCsvSet->setSVal(sTmpVal);
  }

  if (iStat >= 0)
  {
    iStat = oFrmtTyp->CsvString2_Char( 0, sTstTxt, cTmpVal, 21);
    oCsvSet->setCVal(cTmpVal);
  }

  if (iStat >= 0)
  {
    iStat = oFrmtTyp->CsvString2_Bool( 0, sTstTxt, &bTmpVal);
    oCsvSet->setBVal(bTmpVal);
  }

  if (iStat < 0)
  {
    *sErrTxt = oFrmtTyp->GetErrorString();
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


