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
// sstStr01.cpp    25.11.15  Re.    25.11.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include "sstStr01Lib.h"
#include "sstStr01LibInt.h"

//==============================================================================
sstStr01Cls::sstStr01Cls()
{
  poStr01Intern = new sstStr01IntCls();
}
//==============================================================================
sstStr01Cls::~sstStr01Cls() {
    delete(poStr01Intern);
}
//==============================================================================
int sstStr01Cls::CsvString2_Int2 ( int          iKey,
                 //        unsigned long        *TPos,
                         std::string *Zeile,
                   //      std::string *ErrTxt,
                         int         *iRetVal)
//-----------------------------------------------------------------------------
{
//  return this->poStr01Intern->CsvString2_Int2(iKey,TPos,Zeile,ErrTxt,iRetVal);
  return this->poStr01Intern->CsvString2_Int2(iKey,Zeile,iRetVal);
}
//=============================================================================
int sstStr01Cls::CsvString2_UInt2 ( int          iKey,
                   //       unsigned long          *TPos,
                          std::string   *Zeile,
                     //     std::string   *ErrTxt,
                          unsigned int  *uiRetVal)
//-----------------------------------------------------------------------------
{
  // return this->poStr01Intern->CsvString2_UInt2(iKey,TPos,Zeile,ErrTxt,uiRetVal);
  return this->poStr01Intern->CsvString2_UInt2(iKey,Zeile,uiRetVal);
}
//=============================================================================
int sstStr01Cls::CsvString2_Int4 ( int          iKey,
                    //     unsigned long        *TPos,
                         std::string *Zeile,
                    //     std::string *ErrTxt,
                         long        *lRetVal)
//-----------------------------------------------------------------------------
{
  // return this->poStr01Intern->CsvString2_Int4(iKey,TPos,Zeile,ErrTxt,lRetVal);
  return this->poStr01Intern->CsvString2_Int4(iKey,Zeile,lRetVal);
}
//=============================================================================
int sstStr01Cls::CsvString2_UInt4 ( int               iKey,
                    //      unsigned long             *TPos,
                          std::string      *Zeile,
                      //    std::string      *ErrTxt,
                          unsigned long    *ulRetVal)
//-----------------------------------------------------------------------------
{
  // return this->poStr01Intern->CsvString2_UInt4(iKey,TPos,Zeile,ErrTxt,ulRetVal);
  return this->poStr01Intern->CsvString2_UInt4(iKey,Zeile,ulRetVal);
}
//=============================================================================
int sstStr01Cls::CsvString2_Dbl ( int          iKey,
                   //     unsigned long        *TPos,
                        std::string *Zeile,
                   //     std::string *ErrTxt,
                        double      *dRetVal)
//-----------------------------------------------------------------------------
{
  // return this->poStr01Intern->CsvString2_Dbl(iKey,TPos,Zeile,ErrTxt,dRetVal);
  return this->poStr01Intern->CsvString2_Dbl(iKey,Zeile,dRetVal);
}
//=============================================================================
int sstStr01Cls::CsvString2_Flt ( int          iKey,
                 //       unsigned long        *TPos,
                        std::string *Zeile,
                 //       std::string *ErrTxt,
                        float       *fRetVal)
//-----------------------------------------------------------------------------
{
  // return this->poStr01Intern->CsvString2_Flt(iKey,TPos,Zeile,ErrTxt,fRetVal);
  return this->poStr01Intern->CsvString2_Flt(iKey,Zeile,fRetVal);
}
//=============================================================================
int sstStr01Cls::CsvString2_Str ( int               iKey,
                //        unsigned long             *TPos,
                        std::string      *Zeile,
                //        std::string      *ErrTxt,
                        std::string      *sRetStr)
//-----------------------------------------------------------------------------
{
  // return this->poStr01Intern->CsvString2_Str(iKey,TPos,Zeile,ErrTxt,sRetStr);
  return this->poStr01Intern->CsvString2_Str(iKey,Zeile,sRetStr);
}
//=============================================================================
int sstStr01Cls::CsvString2_Bool ( int          iKey,
               //          unsigned long        *TPos,
                         std::string *sZeile,
              //           std::string *sErrTxt,
                         bool         *bRetVal)
//-----------------------------------------------------------------------------
{
  // return this->poStr01Intern->CsvString2_Bool(iKey,TPos,sZeile,sErrTxt,bRetVal);
  return this->poStr01Intern->CsvString2_Bool(iKey,sZeile,bRetVal);
}
//=============================================================================
int sstStr01Cls::CsvString2_Char ( int          iKey,
                //         unsigned long        *TPos,
                         std::string *sZeile,
                //         std::string *sErrTxt,
                         char        *cRetVal,
                         unsigned long         lRetValLen)
//-----------------------------------------------------------------------------
{
  // return this->poStr01Intern->CsvString2_Char(iKey,TPos,sZeile,sErrTxt,cRetVal,lRetValLen);
  return this->poStr01Intern->CsvString2_Char(iKey,sZeile,cRetVal,lRetValLen);
}
//==============================================================================
int sstStr01Cls::Csv_Int2_2String  (int               iKey,
                                    int               iVal,
                                    std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->Csv_Int2_2String(iKey,iVal,sst_str);
}
//==============================================================================
int sstStr01Cls::Csv_UInt2_2String  (int               iKey,
                                     unsigned int      uiVal,
                                     std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->Csv_UInt2_2String(iKey,uiVal,sst_str);
}
//==============================================================================
int sstStr01Cls::Csv_Int4_2String (int               iKey,
                                   long              lVal,
                                   std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->Csv_Int4_2String( iKey,lVal,sst_str);
}
//==============================================================================
int sstStr01Cls::Csv_UInt4_2String (int               iKey,
                                    unsigned long     ulVal,
                                    std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->Csv_UInt4_2String(iKey,ulVal,sst_str);
}
//==============================================================================
int sstStr01Cls::Csv_Dbl_2String ( int               iKey,
                                   double            dVal,
                                   std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->Csv_Dbl_2String( iKey,dVal,sst_str);
}
//==============================================================================
int sstStr01Cls::Csv_Real_2String (int               iKey,
                                   char             *cFmtStr,
                                   float             fVal,
                                   std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->Csv_Real_2String(iKey,cFmtStr,fVal,sst_str);
}
//==============================================================================
int sstStr01Cls::Csv_DblFrmt_2String (int               iKey,
                                      char             *cFmtStr,
                                      double            dVal,
                                      std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->Csv_DblFrmt_2String( iKey,cFmtStr,dVal,sst_str);
}
//==============================================================================
int sstStr01Cls::Csv_Str_2String (int               iKey,
                                  std::string       sVal,
                                  std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->Csv_Str_2String( iKey,sVal,sst_str);
}
//==============================================================================
int sstStr01Cls::Csv_Char_2String (int               iKey,
                                   char             *cVal,
                                   std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->Csv_Char_2String( iKey,cVal,sst_str);
}
//==============================================================================
int sstStr01Cls::Csv_Bool_2String (int               iKey,
                                   bool              bVal,
                                   std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->Csv_Bool_2String( iKey,bVal,sst_str);
}
//==============================================================================
int sstStr01Cls::SetBracket(int iKey, char *cBracket)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->SetBracket(iKey,cBracket);
}
//==============================================================================
int sstStr01Cls::SetSeparator(int iKey, char *cSeparator)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->SetSeparator(iKey,cSeparator);
}
//==============================================================================
int sstStr01Cls::SetNoInfoChar(int iKey, char *cNoInfoChar)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->SetNoInfoChar(iKey,cNoInfoChar);
}
//==============================================================================
int sstStr01Cls::SetReadPositon(int iKey, unsigned long lStartReadPos)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->SetReadPositon(iKey,lStartReadPos);
}
//==============================================================================
int sstStr01Cls::SetSeparatorTyp(int iKey, int iSeparatorTyp)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->SetSeparatorTyp(iKey,iSeparatorTyp);
}
//==============================================================================
int sstStr01Cls::SetBoolTyp(int iKey, int iBoolTyp)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->SetBoolTyp( iKey,iBoolTyp);
}
//==============================================================================
int sstStr01Cls::GetSeparatorTyp()
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->GetSeparatorTyp();
}
//==============================================================================
int sstStr01Cls::GetBoolTyp()
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->GetBoolTyp();
}
//==============================================================================
std::string sstStr01Cls::GetErrorString()
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->GetErrorString();
}
//==============================================================================
void sstStr01Cls::ClearAll()
//-----------------------------------------------------------------------------
{
  this->poStr01Intern->ClearAll();
}
//==============================================================================
int sstStr01Cls::GetNextBrakeInfo (int             iKey,
                                   std::string    *StrInfo,
                                   std::string    *sTag)
//-----------------------------------------------------------------------------
{
  return this->poStr01Intern->GetNextBrakeInfo(iKey,StrInfo,sTag);
}
//==============================================================================
int sstStr01Cls::getDecType() const
{
  return this->poStr01Intern->getDecType();
}
//==============================================================================
void sstStr01Cls::setDecType(int value)
{
  this->poStr01Intern->setDecType(value);
}
//=============================================================================
unsigned int sstStr01Cls::getUiDec() const
{
  return this->poStr01Intern->getUiDec();
}
//=============================================================================
void sstStr01Cls::setUiDec(unsigned int value)
{
  this->poStr01Intern->setUiDec(value);
}
//=============================================================================
unsigned long sstStr01Cls::getReadPosition() const
{
  return this->poStr01Intern->getReadPosition();
}
//=============================================================================

