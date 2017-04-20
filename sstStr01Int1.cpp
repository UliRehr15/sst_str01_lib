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
#include <vector>

#include "sstStr01Lib.h"
#include "sstStr01FixColWidth.h"
#include "sstStr01LibInt.h"

//=============================================================================
int sstStr011_AbPosCsv2Int2 ( int          iKey,
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
  iStat = sstStr011_AbPos2Int ( 0, TPos, TrnZ, Zeile, ErrTxt, iRetVal);

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
int sstStr011_AbPosCsv2Int4 ( int          iKey,
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
  iStat = sstStr011_AbPos2Int4 ( 0, TPos, TrnZ, Zeile, ErrTxt, lRetVal);

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
int sstStr011_AbPosCsv2Dbl ( int          iKey,
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
  iStat = sstStr011_AbPos2Dbl ( 0, TPos, TrnZ, Zeile, ErrTxt, dRetVal);

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
int sstStr011_AbPosCsv2Flt ( int          iKey,
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
  iStat = sstStr011_AbPos2Real ( 0, TPos, TrnZ, Zeile, ErrTxt, fRetVal);

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
int sstStr011_AbPosCsv2Str ( int          iKey,
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
  iStat = sstStr011_Init( 0, &sLocStr);
  iStat = sstStr011_Init( 0, sRetStr);

  strncpy(cTrnZ,";",2);
  // iStat = sstStr011_AbPosS2Str ( 0, TPos, cBegrzZ, TrnZ, Zeile, ErrTxt, sRetStr);
  // iStat = sstStr011_AbPos2StrSBrk ( 0, sZeile, lTPos, cTrnZ, cBegrzZ, sRetStr);
  iStat = sstStr011_AbPos2StrSBrk ( 0, sZeile, lTPos, cTrnZ, cBegrzZ, &sLocStr);
  if(sLocStr.length() <= 0) return 0;

  long lPosStart = sstStr011i_StartOfInfo ( 0, 0, cNoInfo, &sLocStr);
  long lPosStop = sstStr011i_EndOfInfo ( 1, sLocStr.length(), cNoInfo, &sLocStr);

  iStat = sstStr011_Zeile2Str ( 0, lPosStart, lPosStop, &sLocStr, sErrTxt, sRetStr);

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
                                      std::string *sZeile,
                                      int         *iRetVal)
//-----------------------------------------------------------------------------
{
  std::string oRetStr;

  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;

  *iRetVal = dSSTSTR01_CINT2_MAX;

  iStat = this->CsvString2_Str(0,sZeile,&oRetStr);

  if( iStat != 0)
  {
    return -1;
  }

  if(oRetStr.length() <= 0) return 0;

  // String direkt in Double konvertieren
  iStat = sstStr011i_Txt2Int( 0, &oRetStr, iRetVal);

  return iStat;

}
//=============================================================================
int sstStr01IntCls::CsvString2_UInt2 ( int          iKey,
                                       std::string    *sZeile,
                                       unsigned int   *uiRetVal)
//-----------------------------------------------------------------------------
{
  std::string oRetStr;

  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;

  *uiRetVal = dSSTSTR01_CUINT2_MAX;

  iStat = this->CsvString2_Str(0,sZeile,&oRetStr);

  if( iStat != 0)
  {
    return -1;
  }

  if(oRetStr.length() <= 0) return 0;

  // String direkt in Double konvertieren
  iStat = sstStr011i_Txt2UInt( 0, &oRetStr, uiRetVal);

  return iStat;

}
//=============================================================================
int sstStr01IntCls::CsvString2_Int4 ( int          iKey,
                                      std::string *sZeile,
                                      long        *lRetVal)
//-----------------------------------------------------------------------------
{
  std::string oRetStr;

  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;

  *lRetVal = dSSTSTR01_CINT4_MAX;

  iStat = this->CsvString2_Str(0,sZeile,&oRetStr);

  if( iStat != 0)
  {
    return -1;
  }

  if(oRetStr.length() <= 0) return 0;

  // String direkt in Double konvertieren
  iStat = sstStr011i_Txt2Int4( 0, &oRetStr, lRetVal);

  return iStat;

}
//=============================================================================
int sstStr01IntCls::CsvString2_UInt4 ( int              iKey,
                                       std::string      *sZeile,
                                       unsigned long    *ulRetVal)
//-----------------------------------------------------------------------------
{
  std::string oRetStr;

  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;

  *ulRetVal = dSSTSTR01_CUINT4_MAX;

  iStat = this->CsvString2_Str(0,sZeile,&oRetStr);

  if( iStat != 0)
  {
    return -1;
  }

  if(oRetStr.length() <= 0) return 0;

  // String direkt in Double konvertieren
  iStat = sstStr011i_Txt2UInt4( 0, &oRetStr, ulRetVal);

  return iStat;

}
//=============================================================================
int sstStr01IntCls::CsvString2_Dbl ( int          iKey,
                                     std::string *sZeile,
                                     double      *dRetVal)
//-----------------------------------------------------------------------------
{
  std::string oRetStr;

  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;

  *dRetVal = dSSTSTR01_UNDEF_R8;

  iStat = this->CsvString2_Str(0,sZeile,&oRetStr);

  if( iStat != 0)
  {
    return -1;
  }

  if(oRetStr.length() <= 0) return 0;

  // String direkt in Double konvertieren
  iStat = sstStr011i_Txt2Dbl ( 0, &oRetStr, dRetVal);

  return iStat;
}
//=============================================================================
int sstStr01IntCls::CsvString2_Flt ( int          iKey,
                                     std::string *sZeile,
                                     float       *fRetVal)
//-----------------------------------------------------------------------------
{
  std::string oRetStr;

  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // If Interpretation position is greater than actual string, return error
  if (this->ulPos > sZeile->length()) return -1;

  *fRetVal = dSSTSTR01_UNDEF_R4;

  iStat = this->CsvString2_Str(0,sZeile,&oRetStr);

  if( iStat != 0)
  {
    return -1;
  }

  if(oRetStr.length() <= 0) return 0;

  // String direkt in Double konvertieren
  iStat = sstStr011i_Txt2Real( 0, &oRetStr, fRetVal);

  return iStat;

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


  iStat = sstStr011_Init( 0, &sLocStr);
  iStat = sstStr011_Init( 0, sRetStr);

  // if (iKey == 1) strncpy(cBegrzZ,"\"",2);
  strncpy( cBegrzZ, this->cBracket, 2);
  strncpy( cTrnZ, this->cSeparator, 2);
  strncpy( cNoInfo, this->cNoInfo, 2);

  // Get Info until next delimiter and interpret info inside small brackets as string
  iStat = sstStr011_AbPos2StrSBrk ( 0, sZeile, &this->ulPos, cTrnZ, cBegrzZ, &sLocStr);
  if(sLocStr.length() <= 0) return 0;

  long lPosStart = sstStr011i_StartOfInfo ( 0, 0, cNoInfo, &sLocStr);
  long lPosStop = sstStr011i_EndOfInfo ( 1, sLocStr.length(), cNoInfo, &sLocStr);

  iStat = sstStr011_Zeile2Str ( 0, lPosStart, lPosStop, &sLocStr, &this->oErrStr, sRetStr);

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

  iStat = sstStr011_Init ( 0, &sResult);

  iStat = this->CsvString2_Str ( 0, sZeile, &sResult);
  if(iStat < 0)
  {
    return iStat;
  }
  if(sResult.length() <= 0)
  {
    return 0;
  }

  //  0=0/1, 1=F/T,2=.F./.T.
  switch (this->iBoolTyp)
  {
  case 0:
  {
    iStat = sResult.find("0",0);
    if (iStat == 0)
    {
      *bRetVal = 0;
      return 0;
    }
    iStat = sResult.find("1",0);
    if (iStat == 0)
    {
      *bRetVal = 1;
      return 0;
    }
  }
    break;
  case 1:
  {
    iStat = sResult.find("F",0);
    if (iStat == 0)
    {
      *bRetVal = 0;
      return 0;
    }
    iStat = sResult.find("T",0);
    if (iStat == 0)
    {
      *bRetVal = 1;
      return 0;
    }
  }
    break;
  case 2:
  {
    iStat = sResult.find(".F.",0);
    if (iStat == 0)
    {
      *bRetVal = 0;
      return 0;
    }
    iStat = sResult.find(".T.",0);
    if (iStat == 0)
    {
      *bRetVal = 1;
      return 0;
    }
  }
    break;
  default:
    assert(0);
    break;
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

  iStat = sstStr011_Init ( 0, &sResult);
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
int sstStr01IntCls::CsvString2_VectorAll ( int                  iKey,
                                           const std::string    oCsvRow,
                                           std::vector<std::string> *data)
{
  if ( iKey != 0) return -1;

  // vector<std::string> data;
//  data->push_back("aaa");
//  data->push_back("");
//  data->push_back("ccc");

  // int ii = data->size();

  std::string oTmpCsvStr;
  std::string oTmpStr;

 //  myStr = data->at(1);

  unsigned long ulTmpPos = this->getReadPosition();

  this->SetReadPositon(0,0);
  oTmpCsvStr = oCsvRow;

  int iStat1 = this->CsvString2_Str( 0, &oTmpCsvStr, &oTmpStr);

  while (iStat1 >= 0)
  {
    data->push_back(oTmpStr);
    iStat1 = this->CsvString2_Str(0,&oTmpCsvStr,&oTmpStr);
  }


  this->SetReadPositon(0,ulTmpPos);
  return 0;
}
//=============================================================================
int sstStr011_Int2_2Csv (int iKey,int iVal, std::string *sst_str, std::string *ErrTxt)
//-----------------------------------------------------------------------------
{
  sstStr01FcwCls oFcw;
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = sstStr011_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
      // sst_str->AktLen = strlen(sst_str->Txt);
  }
  // convert integer to string
  iStat = sstStr011_Int2Zeile ( 0, &oFcw,1, dSSTSTR01_TEXTLEN, iVal, &locStr1);

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
int sstStr011_UInt2_2Csv (int iKey,unsigned int uiVal, std::string *sst_str, std::string *ErrTxt)
//-----------------------------------------------------------------------------
{
  sstStr01FcwCls oFcw;
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = sstStr011_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //  sst_str->AktLen = strlen(sst_str->Txt);
  }
  // convert integer to string
  iStat = sstStr011_Int2Zeile ( 0, &oFcw, 1, dSSTSTR01_TEXTLEN, uiVal, &locStr1);

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
int sstStr011_Int4_2Csv (int iKey, long lVal, std::string *sst_str, std::string *ErrTxt)
//-----------------------------------------------------------------------------
{
  sstStr01FcwCls oFcw;
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = sstStr011_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
      // sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert integer to string
  iStat = sstStr011_Int4Zeile ( 0, &oFcw, 1, dSSTSTR01_TEXTLEN, lVal, &locStr1);

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
int sstStr011_UInt4_2Csv (int iKey, unsigned long ulVal, std::string *sst_str, std::string *ErrTxt)
//-----------------------------------------------------------------------------
{
  sstStr01FcwCls oFcw;
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = sstStr011_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
      // sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert integer to string
  iStat = sstStr011_UInt4Zeile ( 0, &oFcw, 1, dSSTSTR01_TEXTLEN, ulVal, &locStr1);

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
int sstStr011_Dbl_2Csv (int iKey,double dVal, std::string *sst_str, std::string *ErrTxt)
//-----------------------------------------------------------------------------
{
  sstStr01FcwCls oFcw;
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = sstStr011_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
      // sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert double to string (floating comma value: KeyBit1=1)
  iStat = sstStr011_Dbl2Zeile ( 2, &oFcw, 1, dSSTSTR01_TEXTLEN, dVal, 3, &locStr1);

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
int sstStr011_Char_2Csv (int iKey,char *cVal, std::string *sst_str, std::string *ErrTxt)
//-----------------------------------------------------------------------------
{
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = sstStr011_Init ( 0, &locStr1);

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
  sstStr01FcwCls oFcw;
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = sstStr011_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //  sst_str->AktLen = strlen(sst_str->Txt);
  }
  // convert integer to string
  iStat = sstStr011_Int2Zeile ( 0, &oFcw, 1, dSSTSTR01_TEXTLEN, iVal, &locStr1);

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
  sstStr01FcwCls oFcw;
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = sstStr011_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //   sst_str->AktLen = strlen(sst_str->Txt);
  }
  // convert integer to string
  iStat = sstStr011_UInt2Zeile ( 0, &oFcw, 1, dSSTSTR01_TEXTLEN, uiVal, &locStr1);

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
  sstStr01FcwCls oFcw;
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = sstStr011_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //  sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert integer to string
  iStat = sstStr011_Int4Zeile ( 0, &oFcw, 1, dSSTSTR01_TEXTLEN, lVal, &locStr1);

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
  sstStr01FcwCls oFcw;
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = sstStr011_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //  sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert integer to string
  iStat = sstStr011_UInt4Zeile ( 0, &oFcw, 1, dSSTSTR01_TEXTLEN, ulVal, &locStr1);

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
  sstStr01FcwCls oFcw;
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = sstStr011_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //   sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert double to string (floating comma value: KeyBit1=1)
  if (this->iDecType == 0)
    // iStat = sstStr011_Dbl2Zeile ( 2, 1, dSSTSTR01_TEXTLEN, dVal, 3, &locStr1);
    iStat = sstStr011_Dbl2Zeile ( 2, &oFcw, 1, dSSTSTR01_TEXTLEN, dVal, this->uiDec, &locStr1);
  else
    // iStat = sstStr011_Dbl2Zeile ( 0, 1, dSSTSTR01_TEXTLEN, dVal, 3, &locStr1);
    iStat = sstStr011_Dbl2Zeile ( 0, &oFcw, 1, dSSTSTR01_TEXTLEN, dVal, this->uiDec, &locStr1);

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
  sstStr01FcwCls oFcw;
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = sstStr011_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //  sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert double to string (floating comma value: KeyBit1=1)
  iStat = sstStr011_Real2ZeileFmt( 2, &oFcw, 1, dSSTSTR01_TEXTLEN, fVal, cFmtStr, &locStr1);

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
  sstStr01FcwCls oFcw;
  std::string locStr1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  // cZeile[0] = 0;

  // Init Str1-Structure
  iStat = sstStr011_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strcat(sst_str->Txt,";");
    *sst_str = *sst_str + ";";
    //  sst_str->AktLen = strlen(sst_str->Txt);
  }

  // convert double to string (floating comma value: KeyBit1=1)
  iStat = sstStr011_Dbl2ZeileFmt( 2, &oFcw, 1, dSSTSTR01_TEXTLEN, dVal, cFmtStr, &locStr1);

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
                                     std::string       sVal,
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
  iStat = sstStr011_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    *sst_str = *sst_str + this->cSeparator;
  }

  if (iStat < 0) this->oErrStr = "Convert_Error";

  if (this->iSeparatorTyp > 0)
  {
    locStr1 = locStr1 + this->cBracket;
  }

  iStat = sstStr011Cat(0,&locStr1, sVal.c_str());

  if (this->iSeparatorTyp > 0)
  {
    locStr1 = locStr1 + this->cBracket;
  }

  // append local string to result string
  iStat = sstStr011Cat(0,sst_str, locStr1.c_str());

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
  iStat = sstStr011_Init ( 0, &locStr1);

  if (sst_str->length() > 0)
  {
      // build csv-format
    // strncat( sst_str->Txt, this->cSeparator, dSSTSTR01_TEXTLEN);
    *sst_str = *sst_str + this->cSeparator;
    // strcat(sst_str->Txt,";");
    // sst_str->AktLen = strlen(sst_str->Txt);
  }

  if (iStat < 0) this->oErrStr = "Convert_Error";

  // strncat(locStr1.Txt, this->cBracket, dSSTSTR01_TEXTLEN);
  // strncat(locStr1.Txt, cVal, dSSTSTR01_TEXTLEN);
  // strncat(locStr1.Txt, this->cBracket, dSSTSTR01_TEXTLEN);
  locStr1 = locStr1 + this->cBracket + cVal + this->cBracket;
  // locStr1.AktLen = strlen(locStr1.Txt);

  // append local string to result string
  iStat = sstStr011Cat(0,sst_str, locStr1.c_str());

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
  sstStr01FcwCls oFcw;

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
  iStat = sstStr011_Init ( 0, &locStr1);
  iStat = sstStr011_Init ( 0, &locStr2);

  if (sst_str->length() > 0)
  {
      // build csv-format
    iStat = sstStr011Cat(0,sst_str, this->cSeparator);
    // strncat( sst_str->Txt, oFrmtTyp->cSeparator, dSSTSTR01_TEXTLEN);
    // strcat(sst_str->Txt,";");
    // sst_str->AktLen = strlen(sst_str->Txt);
  }

  //Bool in einen String konvertieren und in Zeilenbereich kopieren.
  iStat = sstStr011_Bool2Zeile (0, &oFcw, this->GetBoolTyp(), 1, 4, &bVal, &locStr2);

  if (iStat < 0) this->oErrStr = "Convert_Error";

  iStat = sstStr011Cpy(0,&locStr1, cLocBracket);
  iStat = sstStr011Cat(0,&locStr1, locStr2.c_str());
  iStat = sstStr011Cat(0,&locStr1, cLocBracket);
  // locStr1.AktLen = strlen(locStr1.Txt);

  // append local string to result string
  iStat = sstStr011Cat(0,sst_str, locStr1.c_str());

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
int sstStr011_Csv_Test (int            iKey,
                   std::string   *sTstTxt,
                   std::string   *sErrTxt,
                   sstStr01TestRecFullCls *oCsvSet)
//-----------------------------------------------------------------------------
{
  unsigned long lTxtPos = 0;
  int iTmpVal=0;
  long lTmpVal=0;
  double dTmpVal=0.0;
  float fTmpVal=0.0;
  std::string sTmpVal;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (iStat >= 0)
  {
    iStat = sstStr011_AbPosCsv2Int2 ( 0, &lTxtPos, sTstTxt, sErrTxt, &iTmpVal);
    oCsvSet->setIVal(iTmpVal);
  }

  if (iStat >= 0)
  {
    iStat = sstStr011_AbPosCsv2Int4 ( 0, &lTxtPos, sTstTxt, sErrTxt, &lTmpVal);
    oCsvSet->setLVal(lTmpVal);
  }

  if (iStat >= 0)
  {
    iStat = sstStr011_AbPosCsv2Dbl ( 0, &lTxtPos, sTstTxt, sErrTxt, &dTmpVal);
    oCsvSet->setDVal(dTmpVal);
  }

  if (iStat >= 0)
  {
    iStat = sstStr011_AbPosCsv2Flt ( 0, &lTxtPos, sTstTxt, sErrTxt, &fTmpVal);
    oCsvSet->setFVal(fTmpVal);
  }

  if (iStat >= 0)
  {
    iStat = sstStr011_AbPosCsv2Str ( 0, &lTxtPos, sTstTxt, sErrTxt, &sTmpVal);
    oCsvSet->setSVal(sTmpVal);
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
sstStr01IntCls::sstStr01IntCls()
{
  memset(this->cSeparator,0,2);
  memset(this->cNoInfo,0,2);
  memset(this->cBracket,0,2);
  memset(this->cBracketOpen,0,2);
  memset(this->cBracketClose,0,2);
  this->ulPos = 0;
  this->iFormatKenn = 0;
  this->iDecType = 0;
  strncpy(this->cSeparator,";",2);
  strncpy(this->cBracket,"'",2);
  strncpy(this->cNoInfo," ",2);
  this->iSeparatorTyp = 0;
  this->iBoolTyp = 0;
  this->uiDec = 3;
}
//=============================================================================
int sstStr01IntCls::SetBracket(int iKey, char *cTmpBracket)
{
  if ( iKey != 0) return -1;
  // strncpy (this->cBracket, cTmpBracket, 3);
  this->cBracket[0] = cTmpBracket[0];
  this->cBracket[1] = 0;
  this->cBracketOpen[0] = cTmpBracket[0];
  this->cBracketOpen[1] = 0;
  this->cBracketClose[0] = cTmpBracket[1];
  this->cBracketClose[1] = 0;
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
std::string sstStr01IntCls::GetSeparator()
{
  return this->cSeparator;
}
//=============================================================================
int sstStr01IntCls::SetNoInfoChar(int iKey, char *cNoInfoChar)
{
  if ( iKey != 0) return -1;
  strncpy ( this->cNoInfo, cNoInfoChar, 2);
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
char* sstStr01IntCls::GetBraketOpen()
{
  return this->cBracketOpen;
}
//=============================================================================
char* sstStr01IntCls::GetBraketClose()
{
  return this->cBracketClose;
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
int sstStr01IntCls::GetNextBrakeInfo (int             iKey,
                                      std::string    *StrInfo,
                                      std::string    *sTag)
//-----------------------------------------------------------------------------
{
  int iStat = 0;
  if (this->ulPos == 0) this->ulPos = 1;
  iStat = sstStr011_GetNextBrakeInfo(iKey,StrInfo, &this->ulPos,this->GetBraketOpen(),
                                                           this->GetBraketClose(),
                                                           sTag);
  return iStat;
}
//=============================================================================
int sstStr01IntCls::getDecType() const
{
return iDecType;
}
//=============================================================================
void sstStr01IntCls::setDecType(int value)
{
iDecType = value;
}
//=============================================================================
unsigned int sstStr01IntCls::getUiDec() const
{
return uiDec;
}
//=============================================================================
void sstStr01IntCls::setUiDec(unsigned int value)
{
uiDec = value;
}
//=============================================================================
unsigned long sstStr01IntCls::getReadPosition() const
{
return ulPos;
}
//=============================================================================

