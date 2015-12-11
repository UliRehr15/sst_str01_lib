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
// sstStr01Int1.cpp    24.11.15  Re.    24.11.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include "sstStr01Lib.h"
#include "sstStr01LibInt.h"

//=============================================================================
int Str1_AbPosCsv2Int2 ( int          iKey,
                         unsigned long        *TPos,
                         std::string *Zeile,
                         std::string *ErrTxt,
                         int         *iRetVal)
//-----------------------------------------------------------------------------
{
  char TrnZ[3];

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  strcpy( TrnZ,"; ");
  iStat = Str1_AbPos2Int ( 0, TPos, TrnZ, Zeile, ErrTxt, iRetVal);

  // Heavy Errors goes to an assert
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
int Str1_AbPosCsv2Int4 ( int          iKey,
                         unsigned long        *TPos,
                         std::string *Zeile,
                         std::string *ErrTxt,
                         long        *lRetVal)
//-----------------------------------------------------------------------------
{
  char TrnZ[3];

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  strcpy( TrnZ,"; ");
  iStat = Str1_AbPos2Int4 ( 0, TPos, TrnZ, Zeile, ErrTxt, lRetVal);

  // Heavy Errors goes to an assert
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
int Str1_AbPosCsv2Dbl ( int          iKey,
                        unsigned long        *TPos,
                        std::string *Zeile,
                        std::string *ErrTxt,
                        double      *dRetVal)
//-----------------------------------------------------------------------------
{
  char TrnZ[3];

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  strcpy( TrnZ,"; ");
  iStat = Str1_AbPos2Dbl ( 0, TPos, TrnZ, Zeile, ErrTxt, dRetVal);

  // Heavy Errors goes to an assert
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
int Str1_AbPosCsv2Flt ( int          iKey,
                        unsigned long        *TPos,
                        std::string *Zeile,
                        std::string *ErrTxt,
                        float       *fRetVal)
//-----------------------------------------------------------------------------
{
  char TrnZ[3];

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  strcpy( TrnZ,"; ");
  iStat = Str1_AbPos2Real ( 0, TPos, TrnZ, Zeile, ErrTxt, fRetVal);

  // Heavy Errors goes to an assert
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
int Str1_AbPosCsv2Str ( int          iKey,
                        unsigned long        *lTPos,
                        std::string *sZeile,
                        std::string *sErrTxt,
                        std::string *sRetStr)
//-----------------------------------------------------------------------------
{
  std::string sLocStr;
  char cTrnZ[2];
  char cNoInfo[2] = " ";
  char cBegrzZ[3] = "";  // no brackets

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  // if ( iKey != 0) return -1;
  if ( iKey < 0 || iKey > 1) return -1;
  if (iKey == 1) strncpy(cBegrzZ,"\"",3);
  iStat = Str1_Init( 0, &sLocStr);
  iStat = Str1_Init( 0, sRetStr);

  strncpy(cTrnZ,";",2);
  // iStat = Str1_AbPosS2Str ( 0, TPos, cBegrzZ, TrnZ, Zeile, ErrTxt, sRetStr);
  // iStat = Str1_AbPos2StrSBrk ( 0, sZeile, lTPos, cTrnZ, cBegrzZ, sRetStr);
  iStat = Str1_AbPos2StrSBrk ( 0, sZeile, lTPos, cTrnZ, cBegrzZ, &sLocStr);
  if(sLocStr.length() <= 0) return 0;

  long lPosStart = Str1i_StartOfInfo ( 0, 0, cNoInfo, &sLocStr);
  long lPosStop = Str1i_EndOfInfo ( 1, sLocStr.length(), cNoInfo, &sLocStr);

  iStat = Str1_Zeile2Str ( 0, lPosStart, lPosStop, &sLocStr, sErrTxt, sRetStr);

  // Heavy Errors goes to an assert
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
int sstStr01IntCls::CsvString2_Int2 ( int          iKey,
                               //            unsigned long        *TPos,
                                           std::string *sZeile,
                               //            std::string *sErrTxt,
                                           int         *iRetVal)
//-----------------------------------------------------------------------------
{
  char cDelimit[2];
  std::string sResult;
  unsigned long ulTPos = 0;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;

  iStat = Str1_Init ( 0, &sResult);

  iStat = this->CsvString2_Str ( 0, sZeile, &sResult);
  if(iStat < 0)
  {
    return iStat;
  }
  if(sResult.length() <= 0)
  {
    return 0;
  }

  // Nächste Information aus Text-Zeile in Int2 umwandeln.
  ulTPos = 0;
  strncpy( cDelimit, this->cSeparator, 2);
  iStat = Str1_AbPos2Int ( 0, &ulTPos, cDelimit, &sResult, &this->oErrStr, iRetVal);

  // Heavy Errors goes to an assert
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
int sstStr01IntCls::CsvString2_UInt2 ( int          iKey,
                                //            unsigned long           *TPos,
                                            std::string    *sZeile,
                                  //          std::string    *sErrTxt,
                                            unsigned int   *uiRetVal)
//-----------------------------------------------------------------------------
{
  char cDelimit[2];
  std::string sResult;
  unsigned long ulTPos = 0;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;

  iStat = Str1_Init ( 0, &sResult);

  iStat = this->CsvString2_Str ( 0, sZeile, &sResult);
  if(iStat < 0)
  {
    return iStat;
  }
  if(sResult.length() <= 0)
  {
    return 0;
  }

  // Nächste Information aus Text-Zeile in Int2 umwandeln.
  ulTPos = 0;
  strncpy( cDelimit, this->cSeparator, 2);
  iStat = Str1_AbPos2UInt ( 0, &ulTPos, cDelimit, &sResult, &this->oErrStr, uiRetVal);

  // Heavy Errors goes to an assert
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
int sstStr01IntCls::CsvString2_Int4 ( int          iKey,
                          //                 unsigned long        *TPos,
                                           std::string *sZeile,
                            //               std::string *ErrTxt,
                                           long        *lRetVal)
//-----------------------------------------------------------------------------
{
  // char TrnZ[3];

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;

  // call function
  iStat = Str1_AbPos2Int4 ( 0, &this->ulPos, this->cSeparator, sZeile, &this->oErrStr, lRetVal);

  // Heavy Errors goes to an assert
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
int sstStr01IntCls::CsvString2_UInt4 ( int              iKey,
                       //                     unsigned long             *TPos,
                                            std::string      *sZeile,
                         //                   std::string      *ErrTxt,
                                            unsigned long    *ulRetVal)
//-----------------------------------------------------------------------------
{
  // char TrnZ[3];

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;

  // call function
  iStat = Str1_AbPos2UInt4 ( 0, &this->ulPos, this->cSeparator, sZeile, &this->oErrStr, ulRetVal);

  // Heavy Errors goes to an assert
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
int sstStr01IntCls::CsvString2_Dbl ( int          iKey,
                    //                      unsigned long        *TPos,
                                          std::string *sZeile,
                      //                    std::string *ErrTxt,
                                          double      *dRetVal)
//-----------------------------------------------------------------------------
{
  // char TrnZ[3];

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;

  // strcpy( TrnZ,"; ");
  // iStat = Str1_AbPos2Dbl ( 0, TPos, TrnZ, Zeile, ErrTxt, dRetVal);
  iStat = Str1_AbPos2Dbl ( 0, &this->ulPos, this->cSeparator, sZeile, &this->oErrStr, dRetVal);

  // Heavy Errors goes to an assert
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
int sstStr01IntCls::CsvString2_Flt ( int          iKey,
                    //                      unsigned long        *TPos,
                                          std::string *sZeile,
                      //                    std::string *ErrTxt,
                                          float       *fRetVal)
//-----------------------------------------------------------------------------
{
  char TrnZ[3];

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;

  strcpy( TrnZ,"; ");
  iStat = Str1_AbPos2Real ( 0, &this->ulPos, TrnZ, sZeile, &this->oErrStr, fRetVal);

  // Heavy Errors goes to an assert
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
int sstStr01IntCls::CsvString2_Str ( int          iKey,
                    //                      unsigned long        *lTPos,
                                          std::string *sZeile,
                      //                    std::string *sErrTxt,
                                          std::string *sRetStr)
//-----------------------------------------------------------------------------
{
  std::string sLocStr;
  char cTrnZ[3];
  char cNoInfo[2] = " ";
  char cBegrzZ[2] = "";

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // if ( iKey < 0 || iKey > 1) return -1;
  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;


  iStat = Str1_Init( 0, &sLocStr);
  iStat = Str1_Init( 0, sRetStr);

  // if (iKey == 1) strncpy(cBegrzZ,"\"",2);
  strncpy( cBegrzZ, this->cBracket, 3);
  strncpy( cTrnZ, this->cSeparator, 2);
  strncpy( cNoInfo, this->cNoInfo, 2);

  // iStat = Str1_AbPosS2Str ( 0, TPos, cBegrzZ, TrnZ, Zeile, ErrTxt, sRetStr);
  // iStat = Str1_AbPos2StrSBrk ( 0, sZeile, lTPos, cTrnZ, cBegrzZ, sRetStr);
  iStat = Str1_AbPos2StrSBrk ( 0, sZeile, &this->ulPos, cTrnZ, cBegrzZ, &sLocStr);
  if(sLocStr.length() <= 0) return 0;

  long lPosStart = Str1i_StartOfInfo ( 0, 0, cNoInfo, &sLocStr);
  long lPosStop = Str1i_EndOfInfo ( 1, sLocStr.length(), cNoInfo, &sLocStr);

  iStat = Str1_Zeile2Str ( 0, lPosStart, lPosStop, &sLocStr, &this->oErrStr, sRetStr);

  // Heavy Errors goes to an assert
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
int sstStr01IntCls::CsvString2_Bool ( int          iKey,
                      //                     unsigned long        *TPos,
                                           std::string *sZeile,
                        //                   std::string *sErrTxt,
                                           bool         *bRetVal)
//-----------------------------------------------------------------------------
{
  std::string sResult;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;

  iStat = Str1_Init ( 0, &sResult);

  iStat = this->CsvString2_Str ( 0, sZeile, &sResult);
  if(iStat < 0)
  {
    return iStat;
  }
  if(sResult.length() <= 0)
  {
    return 0;
  }

  //iStat = strncmp(sResult.Txt,".F.",3);
  iStat = sResult.find(".F.",0);
  if (iStat == 0)
  {
    *bRetVal = 0;
    return 0;
  }
  // iStat = strncmp(sResult.Txt,".T.",3);
  iStat = sResult.find(".T.",0);
  if (iStat == 0)
  {
    *bRetVal = 1;
    return 0;
  }

  *bRetVal = 0;
  iStat = -2;

  // Heavy Errors goes to an assert
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
int sstStr01IntCls::CsvString2_Char ( int          iKey,
                       //                    unsigned long        *TPos,
                                           std::string *sZeile,
                         //                  std::string *sErrTxt,
                                           char        *cRetVal,
                                           long         lRetValLen)
//-----------------------------------------------------------------------------
{
  std::string sResult;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;

  iStat = Str1_Init ( 0, &sResult);
  memset(cRetVal,0,lRetValLen);

  iStat = this->CsvString2_Str ( 0, sZeile, &sResult);
  if(iStat < 0)
  {
    return iStat;
  }
  if(sResult.length() <= 0)
  {
    return 0;
  }

  // strncpy( cRetVal, sResult.Txt, lRetValLen);
  strncpy( cRetVal, sResult.c_str(), lRetValLen);

  // Heavy Errors goes to an assert
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
int Str1_Int2_2Csv (int iKey,int iVal, std::string *sst_str, std::string *ErrTxt)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
      // sst_str->AktLen = strlen(sst_str->Txt);
  }
  // convert integer to string
  iStat = Str1_Int2Zeile ( 0, 1, dSTR1_TEXTLEN, iVal, &locStr1);

  if (iStat < 0) *ErrTxt = "Convert_Error";

  // append str1 to line
  // strcat(sst_str->Txt, locStr1.Txt);
  *sst_str = *sst_str + locStr1;
  // sst_str->AktLen = strlen(sst_str->Txt);

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
int Str1_UInt2_2Csv (int iKey,unsigned int uiVal, std::string *sst_str, std::string *ErrTxt)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //  sst_str->AktLen = strlen(sst_str->Txt);
  }
  // convert integer to string
  iStat = Str1_Int2Zeile ( 0, 1, dSTR1_TEXTLEN, uiVal, &locStr1);

  if (iStat < 0) *ErrTxt = "Convert_Error";

  // append str1 to line
  // strcat(sst_str->Txt, locStr1.Txt);
  *sst_str = *sst_str + locStr1;
  // sst_str->AktLen = strlen(sst_str->Txt);

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
int Str1_Int4_2Csv (int iKey, long lVal, std::string *sst_str, std::string *ErrTxt)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
      // sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert integer to string
  iStat = Str1_Int4Zeile ( 0, 1, dSTR1_TEXTLEN, lVal, &locStr1);

  if (iStat < 0) *ErrTxt = "Convert_Error";

  // append str1 to line
  // strcat(sst_str->Txt, locStr1.Txt);
  *sst_str = *sst_str + locStr1;
  // sst_str->AktLen = strlen(sst_str->Txt);

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
int Str1_UInt4_2Csv (int iKey, unsigned long ulVal, std::string *sst_str, std::string *ErrTxt)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
      // sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert integer to string
  iStat = Str1_UInt4Zeile ( 0, 1, dSTR1_TEXTLEN, ulVal, &locStr1);

  if (iStat < 0) *ErrTxt = "Convert_Error";

  // append str1 to line
  // strcat(sst_str->Txt, locStr1.Txt);
  *sst_str = *sst_str + locStr1;
  // sst_str->AktLen = strlen(sst_str->Txt);

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
int Str1_Dbl_2Csv (int iKey,double dVal, std::string *sst_str, std::string *ErrTxt)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
      // sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert double to string (floating comma value: KeyBit1=1)
  iStat = Str1_Dbl2Zeile ( 2, 1, dSTR1_TEXTLEN, dVal, 3, &locStr1);

  if (iStat < 0) *ErrTxt = "Convert_Error";

  // append str1 to line
  // strcat(sst_str->Txt, locStr1.Txt);
  *sst_str = *sst_str + locStr1;
  // sst_str->AktLen = strlen(sst_str->Txt);

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
int Str1_Char_2Csv (int iKey,char *cVal, std::string *sst_str, std::string *ErrTxt)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
      // sst_str->AktLen = strlen(sst_str->Txt);
  }

  // strcat(locStr1.Txt,cVal);
  locStr1 = locStr1 + cVal;
  // locStr1.AktLen = strlen(locStr1.Txt);

  if (iStat < 0) *ErrTxt = "Convert_Error";

  // append str1 to line
  // strcat(sst_str->Txt, locStr1.Txt);
  *sst_str = *sst_str + locStr1;
  // sst_str->AktLen = strlen(sst_str->Txt);

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
int sstStr01IntCls::Csv_Int2_2String (int               iKey,
                                      int               iVal,
                                      std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //  sst_str->AktLen = strlen(sst_str->Txt);
  }
  // convert integer to string
  iStat = Str1_Int2Zeile ( 0, 1, dSTR1_TEXTLEN, iVal, &locStr1);

  if (iStat < 0) this->oErrStr = "Convert_Error";

  // append str1 to line
  // strcat(sst_str->Txt, locStr1.Txt);
  *sst_str = *sst_str + locStr1;
  // sst_str->AktLen = strlen(sst_str->Txt);

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
int sstStr01IntCls::Csv_UInt2_2String (int               iKey,
                                       unsigned int      uiVal,
                                       std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //   sst_str->AktLen = strlen(sst_str->Txt);
  }
  // convert integer to string
  iStat = Str1_UInt2Zeile ( 0, 1, dSTR1_TEXTLEN, uiVal, &locStr1);

  if (iStat < 0) this->oErrStr = "Convert_Error";

  // append str1 to line
  // strcat(sst_str->Txt, locStr1.Txt);
  *sst_str = *sst_str + locStr1;
  // sst_str->AktLen = strlen(sst_str->Txt);

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
int sstStr01IntCls::Csv_Int4_2String (int               iKey,
                                      long              lVal,
                                      std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //  sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert integer to string
  iStat = Str1_Int4Zeile ( 0, 1, dSTR1_TEXTLEN, lVal, &locStr1);

  if (iStat < 0) this->oErrStr = "Convert_Error";

  // append str1 to line
  // strcat(sst_str->Txt, locStr1.Txt);
  *sst_str = *sst_str + locStr1;
  // sst_str->AktLen = strlen(sst_str->Txt);

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
int sstStr01IntCls::Csv_UInt4_2String (int               iKey,
                                       unsigned long     ulVal,
                                       std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //  sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert integer to string
  iStat = Str1_UInt4Zeile ( 0, 1, dSTR1_TEXTLEN, ulVal, &locStr1);

  if (iStat < 0) this->oErrStr = "Convert_Error";

  // append str1 to line
  // strcat(sst_str->Txt, locStr1.Txt);
  *sst_str = *sst_str + locStr1;
  // sst_str->AktLen = strlen(sst_str->Txt);

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
int sstStr01IntCls::Csv_Dbl_2String (int               iKey,
                                     double            dVal,
                                     std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //   sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert double to string (floating comma value: KeyBit1=1)
  iStat = Str1_Dbl2Zeile ( 2, 1, dSTR1_TEXTLEN, dVal, 3, &locStr1);

  if (iStat < 0) this->oErrStr = "Convert_Error";

  // append str1 to line
  // strcat(sst_str->Txt, locStr1.Txt);
  *sst_str = *sst_str + locStr1;
  // sst_str->AktLen = strlen(sst_str->Txt);

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
int sstStr01IntCls::Csv_Real_2String (int               iKey,
                                      char             *cFmtStr,
                                      float             fVal,
                                      std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //  sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert double to string (floating comma value: KeyBit1=1)
  iStat = Str1_Real2ZeileFmt( 2, 1, dSTR1_TEXTLEN, fVal, cFmtStr, &locStr1);

  if (iStat < 0) this->oErrStr = "Convert_Error";

  // append str1 to line
  // strcat(sst_str->Txt, locStr1.Txt);
  *sst_str = *sst_str + locStr1;
  // sst_str->AktLen = strlen(sst_str->Txt);

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
int sstStr01IntCls::Csv_DblFrmt_2String (int               iKey,
                                         char             *cFmtStr,
                                         double            dVal,
                                         std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //  sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert double to string (floating comma value: KeyBit1=1)
  iStat = Str1_Dbl2ZeileFmt( 2, 1, dSTR1_TEXTLEN, dVal, cFmtStr, &locStr1);

  if (iStat < 0) this->oErrStr = "Convert_Error";

  // append str1 to line
  // strcat(sst_str->Txt, locStr1.Txt);
  *sst_str = *sst_str + locStr1;
  // sst_str->AktLen = strlen(sst_str->Txt);

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
int sstStr01IntCls::Csv_Str_2String (int               iKey,
                                     std::string      *sVal,
                                     std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strncat( sst_str->Txt, this->cSeparator, dSTR1_TEXTLEN);
    *sst_str = *sst_str + this->cSeparator;
    // strcat(sst_str->Txt,";");
    // sst_str->AktLen = strlen(sst_str->Txt);
  }

  if (iStat < 0) this->oErrStr = "Convert_Error";

  // strncat(locStr1.Txt, this->cBracket, dSTR1_TEXTLEN);
  locStr1 = locStr1 + this->cBracket;
  // strncat(locStr1.Txt, cVal, dSTR1_TEXTLEN);
  iStat = Str1Cat(0,&locStr1, sVal->c_str());
  // strncat( locStr1.Txt, this->cBracket, dSTR1_TEXTLEN);
  locStr1 = locStr1 + this->cBracket;
  // locStr1.AktLen = strlen(locStr1.Txt);

  // append local string to result string
  iStat = Str1Cat(0,sst_str, locStr1.c_str());

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
int sstStr01IntCls::Csv_Char_2String (int               iKey,
                                      char             *cVal,
                                      std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strncat( sst_str->Txt, this->cSeparator, dSTR1_TEXTLEN);
    *sst_str = *sst_str + this->cSeparator;
    // strcat(sst_str->Txt,";");
    // sst_str->AktLen = strlen(sst_str->Txt);
  }

  if (iStat < 0) this->oErrStr = "Convert_Error";

  // strncat(locStr1.Txt, this->cBracket, dSTR1_TEXTLEN);
  // strncat(locStr1.Txt, cVal, dSTR1_TEXTLEN);
  // strncat(locStr1.Txt, this->cBracket, dSTR1_TEXTLEN);
  locStr1 = locStr1 + this->cBracket + cVal + this->cBracket;
  // locStr1.AktLen = strlen(locStr1.Txt);

  // append local string to result string
  iStat = Str1Cat(0,sst_str, locStr1.c_str());

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
int sstStr01IntCls::Csv_Bool_2String (int               iKey,
                                      bool              bVal,
                                      std::string      *sst_str)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  std::string locStr2;
  char cLocBracket[3];

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  if (this->GetSeparatorTyp() == 2)
    strncpy( cLocBracket, this->cBracket, 3);
  else
    strncpy(cLocBracket,"",3);

  // Init Str1-Structure
  iStat = Str1_Init ( 0, &locStr1);
  iStat = Str1_Init ( 0, &locStr2);

  if (sst_str->length() > 0)
  {
      // build csv-format
    iStat = Str1Cat(0,sst_str, this->cSeparator);
    // strncat( sst_str->Txt, oFrmtTyp->cSeparator, dSTR1_TEXTLEN);
    // strcat(sst_str->Txt,";");
    // sst_str->AktLen = strlen(sst_str->Txt);
  }

  //Bool in einen String konvertieren und in Zeilenbereich kopieren.
  iStat = Str1_Bool2Zeile (0, this->GetBoolTyp(), 1, 4, &bVal, &locStr2);

  if (iStat < 0) this->oErrStr = "Convert_Error";

  iStat = Str1Cpy(0,&locStr1, cLocBracket);
  iStat = Str1Cat(0,&locStr1, locStr2.c_str());
  iStat = Str1Cat(0,&locStr1, cLocBracket);
  // locStr1.AktLen = strlen(locStr1.Txt);

  // append local string to result string
  iStat = Str1Cat(0,sst_str, locStr1.c_str());

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
StrDs_Csv_Cls::StrDs_Csv_Cls()
{
  // memset ( this, 0, sizeof(*this));
}
//=============================================================================
StrDs_CsvFnc_Cls::StrDs_CsvFnc_Cls()
{
  memset ( this, 0, sizeof(*this));
}
//=============================================================================
int StrDs_CsvFnc_Cls::WrtCsv( int               iKey,
                              sstStr01IntCls *oFrmtTyp,
                              std::string      *sErrStr,
                              StrDs_Csv_Cls    *oCsvSet,
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
    iStat = oFrmtTyp->Csv_Int2_2String ( 0, oCsvSet->iRetInt, sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_Int4_2String ( 0, oCsvSet->lRetLong, sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_UInt2_2String ( 0, oCsvSet->uiRetInt, sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_UInt4_2String ( 0, oCsvSet->ulRetLong, sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_DblFrmt_2String ( 0, cFrmtStrDbl, oCsvSet->dRetDouble, sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_Real_2String ( 0, cFrmtStrFlt, oCsvSet->fRetFloat, sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_Str_2String ( 0, &oCsvSet->sRetStr, sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_Char_2String ( 0, oCsvSet->cRetStr, sResult_Row);
  if (iStat >= 0)
    iStat = oFrmtTyp->Csv_Bool_2String ( 0, oCsvSet->bVal, sResult_Row);

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
int StrDs_CsvFnc_Cls::ReadCsv( int iKey,
                               sstStr01IntCls *oFrmtTyp,
                               std::string   *sTstTxt,
                               std::string   *sErrTxt,
                               StrDs_Csv_Cls *oCsvSet)
{
  // unsigned long lTxtPos = 0;
  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (iStat >= 0)
    iStat = oFrmtTyp->CsvString2_Int2( 0, sTstTxt, &oCsvSet->iRetInt);

  if (iStat >= 0)
    iStat = oFrmtTyp->CsvString2_Int4( 0, sTstTxt, &oCsvSet->lRetLong);

  if (iStat >= 0)
    iStat = oFrmtTyp->CsvString2_UInt2( 0, sTstTxt, &oCsvSet->uiRetInt);

  if (iStat >= 0)
    iStat = oFrmtTyp->CsvString2_UInt4( 0, sTstTxt, &oCsvSet->ulRetLong);

  if (iStat >= 0)
    iStat = oFrmtTyp->CsvString2_Dbl( 0, sTstTxt, &oCsvSet->dRetDouble);

  if (iStat >= 0)
    iStat = oFrmtTyp->CsvString2_Flt( 0, sTstTxt, &oCsvSet->fRetFloat);

  if (iStat >= 0)
    iStat = oFrmtTyp->CsvString2_Str( 0, sTstTxt, &oCsvSet->sRetStr);

  if (iStat >= 0)
    iStat = oFrmtTyp->CsvString2_Char( 0, sTstTxt, oCsvSet->cRetStr, 21);

  if (iStat >= 0)
    iStat = oFrmtTyp->CsvString2_Bool( 0, sTstTxt, &oCsvSet->bVal);

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
int Str1_Csv_Test (int            iKey,
                   std::string   *sTstTxt,
                   std::string   *sErrTxt,
                   StrDs_Csv_Cls *oCsvSet)
//-----------------------------------------------------------------------------
{
  unsigned long lTxtPos = 0;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (iStat >= 0)
    iStat = Str1_AbPosCsv2Int2 ( 0, &lTxtPos, sTstTxt, sErrTxt, &oCsvSet->iRetInt);

  if (iStat >= 0)
    iStat = Str1_AbPosCsv2Int4 ( 0, &lTxtPos, sTstTxt, sErrTxt, &oCsvSet->lRetLong);

  if (iStat >= 0)
    iStat = Str1_AbPosCsv2Dbl ( 0, &lTxtPos, sTstTxt, sErrTxt, &oCsvSet->dRetDouble);

  if (iStat >= 0)
    iStat = Str1_AbPosCsv2Flt ( 0, &lTxtPos, sTstTxt, sErrTxt, &oCsvSet->fRetFloat);

  if (iStat >= 0)
    iStat = Str1_AbPosCsv2Str ( 0, &lTxtPos, sTstTxt, sErrTxt, &oCsvSet->sRetStr);

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
sstStr01IntCls::sstStr01IntCls()
{
  memset(this->cSeparator,0,2);
  memset(this->cNoInfo,0,2);
  memset(this->cBracket,0,3);
  this->ulPos = 0;
  this->iFormatKenn = 0;
  this->iDecType = 0;
  strncpy(this->cSeparator,";",2);
  strncpy(this->cBracket,"'",3);
  strncpy(this->cNoInfo," ",2);
  iSeparatorTyp = 0;
  iBoolTyp = 0;
}
//=============================================================================
int sstStr01IntCls::SetBracket(int iKey, char *cBracket)
{
  if ( iKey != 0) return -1;
  strncpy (this->cBracket, cBracket, 3);
  return 0;
}
//=============================================================================
int sstStr01IntCls::SetSeparator(int iKey, char *cSeparator)
{
  if ( iKey != 0) return -1;
  strncpy ( this->cSeparator, cSeparator, 2);
  return 0;
}
//=============================================================================
int sstStr01IntCls::SetReadPositon(int iKey, unsigned long ulTmpPos)
{
  if ( iKey != 0) return -1;
  this->ulPos = ulTmpPos;
  return 0;
}
//=============================================================================
int sstStr01IntCls::SetSeparatorTyp(int iKey, int iTmpSeparatorTyp)
{
  if ( iKey != 0) return -1;
  this->iSeparatorTyp = iTmpSeparatorTyp;
  return 0;
}
//=============================================================================
int sstStr01IntCls::SetBoolTyp(int iKey, int iTmpBoolTyp)
{
  if ( iKey != 0) return -1;
  this->iBoolTyp = iTmpBoolTyp;
  return 0;
}
//=============================================================================
int sstStr01IntCls::GetSeparatorTyp()
{
  return this->iSeparatorTyp;
}
//=============================================================================
int sstStr01IntCls::GetBoolTyp()
{
  return this->iBoolTyp;
}
//=============================================================================
char* sstStr01IntCls::GetNoInfoChar()
{
  return this->cNoInfo;
}
//=============================================================================
std::string sstStr01IntCls::GetErrorString()
{
  return this->oErrStr;
}
//=============================================================================
void sstStr01IntCls::ClearAll()
{
  this->ulPos = 0;
  this->oErrStr.clear();
}
//=============================================================================

