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
// sstStr01Int3.cpp    24.11.15  Re.    24.11.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include "sstStr01Lib.h"
#include "sstStr01LibInt.h"


//=============================================================================
int Str1_GetNextInfo (int            iKey,
                      std::string   *Zeile,
                      long          *lStrPos,
                      char          *cDelimit,
                      char          *cBrakeOpen,
                      char          *cBrakeClose,
                      std::string   *sTag)
//-----------------------------------------------------------------------------
{
  long lLen = 0;
  long ii = 0;
  int iBrakeOpen = 0;
  std::string   ErrTxt;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  lLen = Zeile->length();

  for ( ii = *lStrPos; ii <= lLen; ii++)
  {
      if ( Str1i_IsBrakeOpen( 0, Zeile, ii, cBrakeOpen))
      {

          iBrakeOpen++;
      }

      else if ( Str1i_IsBrakeClose ( 0, Zeile, ii, cBrakeClose))
      {

          iBrakeOpen--;
      }

      else if ( iBrakeOpen==0 && Str1i_IsDelimiter ( 0, Zeile, ii, cDelimit))
      {

          break;
      }
      else
      {

      }
  }

  // Teil von String1 nach String2 kopieren.
  iStat = Str1_Zeile2Str ( 0, *lStrPos, ii, Zeile, &ErrTxt, sTag);

  *lStrPos = ii +1;

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
int Str1_GetNextPosBracket (int            iKey,
                            std::string   *Zeile,
                            unsigned long          *lStrPos,
                            char          *cDelimit,
                            char          *cBrakeOpen,
                            char          *cBrakeClose)
//-----------------------------------------------------------------------------
{
  unsigned long lLen = 0;
  unsigned long ii = 0;
  int iBrakeOpen = 0;
  // std::string   ErrTxt;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  lLen = Zeile->length();

  for ( ii = *lStrPos; ii <= lLen; ii++)
  {
      if ( Str1i_IsBrakeOpen( 0, Zeile, ii, cBrakeOpen))
      {

          iBrakeOpen++;
      }

      else if ( Str1i_IsBrakeClose ( 0, Zeile, ii, cBrakeClose))
      {

          iBrakeOpen--;
      }

      else if ( iBrakeOpen==0 && Str1i_IsDelimiter ( 0, Zeile, ii, cDelimit))
      {

          break;
      }
      else
      {

      }
  }

  // Teil von String1 nach String2 kopieren.
  // iStat = Str1_Zeile2Str ( 0, *lStrPos, ii, Zeile, &ErrTxt, sTag);

  *lStrPos = ii +1;

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
int Str1_GetNextPosSBracket (int            iKey,
                             std::string   *Zeile,
                             unsigned long          *lStrPos,
                             char          *cDelimit,
                             char          *cBrakeOpen)
//-----------------------------------------------------------------------------
{
  unsigned long lLen = 0;
  unsigned long ii = 0;
  int iInsideBracket = 0;
  int iDelimitFound = 0;
  // std::string   ErrTxt;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  lLen = Zeile->length();

  for ( ii = *lStrPos; ii <= lLen; ii++)
  {
      if ( Str1i_IsBrakeOpen( 0, Zeile, ii, cBrakeOpen))
      {

          if ( Str1i_IsBrakeOpen( 0, Zeile, ii+1, cBrakeOpen))
          {

              if (iInsideBracket == 0)
              {  // double bracketchar and we are outside bracket
                 // Start bracket and stop bracket
                  iInsideBracket = 0;
                  ii++;
              }
              else
              {  // iInsideBracket == 1
                  iInsideBracket = 1;
                  ii++;
              }
          }
          else
          {

              if (iInsideBracket == 0) iInsideBracket = 1;
              else iInsideBracket = 0;
          }

      }

      else if ( Str1i_IsDelimiter ( 0, Zeile, ii, cDelimit) && iInsideBracket == 0)
      {
          // if delimiter found and not inside brackets
          iDelimitFound = 1;
          break;
      }
      else
      {

      }
  }

  // Teil von String1 nach String2 kopieren.
  // iStat = Str1_Zeile2Str ( 0, *lStrPos, ii, Zeile, &ErrTxt, sTag);

  if (iDelimitFound == 1)
  {
      *lStrPos = ii;
  }
  else
  {
      // + 1: virtual delimiter
      // + 2: next char after delimiter
      *lStrPos = lLen+2;
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
int Str1_GetNextBrakeInfo (int             iKey,
                           std::string    *StrInfo,
                           unsigned long  *lStrPos,
                           char           *cBrakeOpen,
                           char           *cBrakeClose,
                           std::string    *sTag)
//-----------------------------------------------------------------------------
{
  unsigned long lLen = 0;
  unsigned long ii = 0;
  unsigned long lStartBreak = 0;
  int iBrakeOpen = 0;
  std::string   ErrTxt;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey < 0 || iKey > 1) return -1;

  lLen = StrInfo->length();

  for ( ii = *lStrPos; ii <= lLen; ii++)
  {
      if ( Str1i_IsBrakeOpen( 0, StrInfo, ii, cBrakeOpen))
      {

          iBrakeOpen++;
          if (iBrakeOpen==1) lStartBreak=ii;
      }

      else if ( Str1i_IsBrakeClose ( 0, StrInfo, ii, cBrakeClose))
      {

          iBrakeOpen--;
          if (iBrakeOpen == 0) break;
      }

      else
      {

      }
  }


  if (iKey == 0)
  // Teil von String1 nach String2 kopieren.
      iStat = Str1_Zeile2Str ( 0, lStartBreak, ii, StrInfo, &ErrTxt, sTag);
  else
      iStat = Str1_Zeile2Str ( 0, lStartBreak+1, ii-1, StrInfo, &ErrTxt, sTag);


  *lStrPos = ii+1;

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
int Str1_GetNextSBrakeInfo (int            iKey,
                            std::string   *StrInfo,
                            unsigned long          *lStrPos,
                            char          *cSBrake,
                            std::string   *sTag)
//-----------------------------------------------------------------------------
{
  unsigned long lLen = 0;
  unsigned long ii = 0;
  unsigned long lStartBracket = 0;
  unsigned long lStopBracket = 0;
  int iBracketOpen = 0;
  int iBracketFound = 0;
  std::string   ErrTxt;
  std::string NewTxt;
  std::string OldTxt;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if (iKey < 0 || iKey > 1) return -1;

  lLen = StrInfo->length();

  if (lLen <= 0) return -2;

  // if Small Brakets are empty, nothing could be calculated
  int iLen = strlen(cSBrake);
  if (iLen <= 0)
  {
    *sTag = *StrInfo;
    return 0;
  }

  // strcpy(NewTxt,"\"");
  NewTxt = "\"";

  for ( ii = *lStrPos; ii <= lLen; ii++)
  {
      if ( Str1i_IsBrakeOpen( 0, StrInfo, ii, cSBrake))
      {

          if ( Str1i_IsBrakeOpen( 0, StrInfo, ii+1, cSBrake))
          {

              if (iBracketOpen == 0)
              {  // double bracketchar and we are outside bracket
                 // Start bracket and stop bracket
                  lStartBracket=ii;
                  lStopBracket=ii+1;
                  iBracketFound = true;
                  break;
              }
              else
              {  // iInsideBracket == 1
                 // iBracketOpen = 1;
                  // In String durch Adresse und Länge bezeichneten Substring austauschen.

                // iStat = Str_SubS_Tausch ( 0, StrInfo->Txt, dSTR1_TEXTLEN, &StrInfo->Txt[ii-1], 2, NewTxt);
                OldTxt = *StrInfo;
                OldTxt.erase(1,ii);
                iStat = Str_SubS_Tausch ( 0, StrInfo, &OldTxt, &NewTxt);

                  ii++;
              }
          }
          else
          {

              if (iBracketOpen == 0)
              {
                  iBracketOpen = 1;
                  iBracketFound  = 1;
                  lStartBracket=ii;

              }
              else
              {
                  iBracketOpen = 0;
                  lStopBracket=ii;
                  break;
              }
          }
      }
      else
      {

      }
  }

  // no brackets found at all
  if(!iBracketFound)
  {
    *sTag = *StrInfo;
    return 0;
  }

  if (iKey == 1)
  {
      // do not copy bracket chars
      lStartBracket++;
      lStopBracket--;
  }

  // Teil von String1 nach String2 kopieren.
  iStat = Str1_Zeile2Str ( 0, lStartBracket, lStopBracket, StrInfo, &ErrTxt, sTag);

  *lStrPos = ii;

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
int Str1_CopyStr (int            iKey,
                  std::string   *StrInfo,
                  char          *CopyStr)
//-----------------------------------------------------------------------------
{
  long lStrLen = 0;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  lStrLen = strlen(CopyStr);

  if (lStrLen > dSTR1_TEXTLEN) return -2;

  *StrInfo = CopyStr;  // ->Txt,CopyStr);
  // StrInfo->AktLen = lStrLen;

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
int Str1Cpy (int            iKey,
             std::string   *StrInfo,
             char          *CopyStr)
//-----------------------------------------------------------------------------
{
  long lStrLen = 0;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  lStrLen = strlen(CopyStr);

  if (lStrLen < 0) return -2;
  if (lStrLen >= dSTR1_TEXTLEN) return -3;

  *StrInfo = CopyStr; // , dSTR1_TEXTLEN-1);
  // StrInfo->AktLen = lStrLen;
  // StrInfo->AktLen = strlen(StrInfo->Txt);

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
int Str1Cat (int            iKey,
             std::string   *StrInfo,
             const char          *cCatChar)
//-----------------------------------------------------------------------------
{
  long lStrLen = 0;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  lStrLen = strlen(cCatChar);

  if (lStrLen <= 0) return -2;
  // if ((StrInfo->AktLen+lStrLen) >= dSTR1_TEXTLEN) return -3;

  // strncat(StrInfo->Txt, cCatChar, dSTR1_TEXTLEN-1);
  *StrInfo = *StrInfo + cCatChar;  // , dSTR1_TEXTLEN-1);
  // StrInfo->AktLen = StrInfo->AktLen + lStrLen;
  // StrInfo->AktLen = strlen(StrInfo->Txt);

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
int Str1_AbPos2StrBrk (int            iKey,
                       std::string   *Zeile,
                       unsigned long          *lStrPos,
                       char          *cDelimit,
                       char          *cBrakeOpen,
                       char          *cBrakeClose,
                       std::string   *sTag)
//-----------------------------------------------------------------------------
{
  // std::string   sPart;
  std::string   sErrTxt;
  unsigned long          lStrPosStart=0;
  unsigned long          lStrPosStop=0;
  // long          lTPos = 1;
//  long          lStrPosNeu=0;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  lStrPosStart = *lStrPos;

  // Return next informationstring and ignore contents inside of brakes
  // iStat = Str1_GetNextInfo ( 0, Zeile, lStrPos, cDelimit, cBrakeOpen, cBrakeClose, sTag);
  iStat = Str1_GetNextPosBracket ( 0, Zeile, lStrPos, cDelimit, cBrakeOpen, cBrakeClose);

  lStrPosStop = *lStrPos;

  // Teil von String1 nach String2 kopieren.
  iStat = Str1_Zeile2Str ( 0, lStrPosStart, lStrPosStop-2, Zeile, &sErrTxt, sTag);

  // Return from next informationstring contents inside of brakes
  // iStat = Str1_GetNextBrakeInfo ( 1, &sPart, &lTPos, cBrakeOpen, cBrakeClose, sTag);

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
int Str1_AbPos2IntBrk (int            iKey,
                       std::string   *Zeile,
                       unsigned long          *lStrPos,
                       char          *cDelimit,
                       char          *cBrakeOpen,
                       char          *cBrakeClose,
                       int           *iReturn)
//-----------------------------------------------------------------------------
{
  std::string   sTag;
  std::string   sPart;
  std::string   sErrTxt;
  // long          lStrPosNeu=0;
  // long          lTPos = 1;
  unsigned long          lStrPosStart=0;
  unsigned long          lStrPosStop=0;
  unsigned long          lTPos = 1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  lStrPosStart = *lStrPos;

  // Return next informationstring and ignore contents inside of brakes
  // iStat = Str1_GetNextInfo ( 0, Zeile, lStrPos, cDelimit, cBrakeOpen, cBrakeClose, sTag);
  iStat = Str1_GetNextPosBracket ( 0, Zeile, lStrPos, cDelimit, cBrakeOpen, cBrakeClose);

  lStrPosStop = *lStrPos;

  // Teil von String1 nach String2 kopieren.
  iStat = Str1_Zeile2Str ( 0, lStrPosStart, lStrPosStop-2, Zeile, &sErrTxt, &sPart);

  // Return from next informationstring contents inside of brakes
  iStat = Str1_GetNextBrakeInfo ( 1, &sPart, &lTPos, cBrakeOpen, cBrakeClose, &sTag);

  // Nächste Information aus Text-Zeile in Int2 umwandeln.
  lTPos = 1;
  iStat = Str1_AbPos2Int ( 0, &lTPos, cDelimit, &sTag, &sErrTxt, iReturn);


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
int Str1_AbPos2Int4Brk (int            iKey,
                        std::string   *Zeile,
                        unsigned long          *lStrPos,
                        char          *cDelimit,
                        char          *cBrakeOpen,
                        char          *cBrakeClose,
                        long          *lReturn)
//-----------------------------------------------------------------------------
{
  std::string   sTag;
  std::string   sPart;
  std::string   sErrTxt;
  unsigned long          lStrPosStart=0;
  unsigned long          lStrPosStop=0;
  unsigned long          lTPos = 1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  lStrPosStart = *lStrPos;

  // Return next informationstring and ignore contents inside of brakes
  // iStat = Str1_GetNextInfo ( 0, Zeile, lStrPos, cDelimit, cBrakeOpen, cBrakeClose, sTag);
  iStat = Str1_GetNextPosBracket ( 0, Zeile, lStrPos, cDelimit, cBrakeOpen, cBrakeClose);

  lStrPosStop = *lStrPos;

  // Teil von String1 nach String2 kopieren.
  iStat = Str1_Zeile2Str ( 0, lStrPosStart, lStrPosStop-2, Zeile, &sErrTxt, &sPart);

  // Return from next informationstring contents inside of brakes
  iStat = Str1_GetNextBrakeInfo ( 1, &sPart, &lTPos, cBrakeOpen, cBrakeClose, &sTag);

  // Nächste Information aus Text-Zeile in Int2 umwandeln.
  lTPos = 1;
  iStat = Str1_AbPos2Int4 ( 0, &lTPos, cDelimit, &sTag, &sErrTxt, lReturn);


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
int Str1_AbPos2StrSBrk (int            iKey,
                        std::string   *Zeile,
                        unsigned long          *lStrPos,
                        char         *cDelimit,
                        char         *cSBrake,
                        std::string   *sTag)
//-----------------------------------------------------------------------------
{
  std::string   sPart;
  std::string   sErrTxt;
  unsigned long          lStrPosStart=0;
  unsigned long          lStrPosStop=0;
  unsigned long          lStrPosLoc = 1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  lStrPosStart = *lStrPos;  // Delimiter
  *lStrPos = *lStrPos +1;   // Open Brake

  iStat = Str1_Init(0,&sPart);
  iStat = Str1_Init(0,&sErrTxt);

  // Return next informationstring and ignore contents inside of small brackets
  iStat = Str1_GetNextPosSBracket ( 0, Zeile, lStrPos, cDelimit, cSBrake);

  lStrPosStop = *lStrPos;  // Delimiter

  // Teil von String1 nach String2 kopieren.
  // lStrPosNeu is next position after Delimiter
  // lStrPosNeu-1 is Delimiter
  // lStrPosNeu-2 is last Informatin before Delimiter
  iStat = Str1_Zeile2Str ( 0, lStrPosStart+1, lStrPosStop-1, Zeile, &sErrTxt, &sPart);

  // Return from next informationstring contents inside of small brackets
  // For Example 'Text'
  iStat = Str1_GetNextSBrakeInfo ( 1, &sPart, &lStrPosLoc, cSBrake, sTag);

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
int Str1_AbPos2IntSBrk (int            iKey,
                        std::string   *Zeile,
                        unsigned long          *lStrPos,
                        char          *cDelimit,
                        char          *cSBrake,
                        int           *iReturn)
//-----------------------------------------------------------------------------
{
  std::string   sTag;
  std::string   sPart;
  std::string   sErrTxt;
  unsigned long          lStrPosStart=0;
  unsigned long          lStrPosStop=0;
  unsigned long          lTPos = 1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  lStrPosStart = *lStrPos;  // Delimiter
  *lStrPos = *lStrPos +1;   // Open Brake

  // Return next informationstring and ignore contents inside of small brackets
  iStat = Str1_GetNextPosSBracket ( 0, Zeile, lStrPos, cDelimit, cSBrake);

  lStrPosStop = *lStrPos;

  // Teil von String1 nach String2 kopieren.
  // lStrPosNeu is next position after Delimiter
  // lStrPosNeu-1 is Delimiter
  // lStrPosNeu-2 is last Informatin before Delimiter
  iStat = Str1_Zeile2Str ( 0, lStrPosStart+1, lStrPosStop-1, Zeile, &sErrTxt, &sPart);

  // Return from next informationstring contents inside of small brackets
  // iKey=1: Remove Brackets
  iStat = Str1_GetNextSBrakeInfo ( 1, &sPart, &lTPos, cSBrake, &sTag);

  // Nächste Information aus Text-Zeile in Int2 umwandeln.
  lTPos = 0;
  iStat = Str1_AbPos2Int ( 0, &lTPos, cDelimit, &sTag, &sErrTxt, iReturn);

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
int Str1_AbPos2Int4SBrk (int            iKey,
                         std::string   *Zeile,
                         unsigned long          *lStrPos,
                         char          *cDelimit,
                         char          *cSBrake,
                         long          *lReturn)
//-----------------------------------------------------------------------------
{
  std::string   sTag;
  std::string   sPart;
  std::string   sErrTxt;
  unsigned long          lStrPosStart=0;
  unsigned long          lStrPosStop=0;
  unsigned long          lTPos = 1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  lStrPosStart = *lStrPos;  // Delimiter
  *lStrPos = *lStrPos +1;   // Open Brake

  // Return next informationstring and ignore contents inside of small brackets
  iStat = Str1_GetNextPosSBracket ( 0, Zeile, lStrPos, cDelimit, cSBrake);

  lStrPosStop = *lStrPos;

  // Teil von String1 nach String2 kopieren.
  // lStrPosNeu is next position after Delimiter
  // lStrPosNeu-1 is Delimiter
  // lStrPosNeu-2 is last Informatin before Delimiter
  iStat = Str1_Zeile2Str ( 0, lStrPosStart+1, lStrPosStop-1, Zeile, &sErrTxt, &sPart);

  // Return from next informationstring contents inside of small brackets
  // iKey=1: Remove Brackets
  iStat = Str1_GetNextSBrakeInfo ( 1, &sPart, &lTPos, cSBrake, &sTag);

  // Nächste Information aus Text-Zeile in Int2 umwandeln.
  lTPos = 0;
  iStat = Str1_AbPos2Int4 ( 0, &lTPos, cDelimit, &sTag, &sErrTxt, lReturn);


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
int Str1_AbPos2DblSBrk (int            iKey,
                        std::string   *Zeile,
                        unsigned long          *lStrPos,
                        char          *cDelimit,
                        char          *cSBrake,
                        double        *dReturn)
//-----------------------------------------------------------------------------
{
  std::string   sTag;
  std::string   sPart;
  std::string   sErrTxt;
  unsigned long          lStrPosStart=0;
  unsigned long          lStrPosStop=0;
  unsigned long          lTPos = 1;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  lStrPosStart = *lStrPos;  // Delimiter
  *lStrPos = *lStrPos +1;   // Open Brake

  // Return next informationstring and ignore contents inside of small brackets
  iStat = Str1_GetNextPosSBracket ( 0, Zeile, lStrPos, cDelimit, cSBrake);

  lStrPosStop = *lStrPos;

  // Teil von String1 nach String2 kopieren.
  // lStrPosNeu is next position after Delimiter
  // lStrPosNeu-1 is Delimiter
  // lStrPosNeu-2 is last Informatin before Delimiter
  iStat = Str1_Zeile2Str ( 0, lStrPosStart+1, lStrPosStop-1, Zeile, &sErrTxt, &sPart);

  // Return from next informationstring contents inside of small brackets
  // iKey=1: Remove Brackets
  iStat = Str1_GetNextSBrakeInfo ( 1, &sPart, &lTPos, cSBrake, &sTag);

  lTPos = 0;
  iStat = Str1_AbPos2Dbl ( 0, &lTPos, cDelimit, &sTag, &sErrTxt, dReturn);

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
int Str1_Init (int            iKey,
               std::string   *sZeile)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // memset(sZeile->Txt,0,dSTR1_TEXTLEN);
  sZeile->clear();
  // sZeile->Txt[0] = 0;
  // sZeile->AktLen = 0;

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

