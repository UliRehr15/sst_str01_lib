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
// sstStr01Int5.cpp    26.11.15  Re.    26.11.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include "sstStr01Lib.h"
#include "sstStr01FixColWidth.h"
#include "sstStr01LibInt.h"

//=============================================================================
int sstStr011i_IsBrakeOpen (int            iKey,
                            std::string   *Zeile,
                            unsigned long  ulPos,
                            char          *cBrakeOpen)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  if ( ulPos > Zeile->length()) return 0;

  if (Zeile->at(ulPos-1) == cBrakeOpen[0])
      return 1;
  else
      return 0;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstStr011i_IsBrakeClose (int            iKey,
                        std::string   *Zeile,
                        unsigned long  ulPos,
                        char          *cBrakeClose)
//-----------------------------------------------------------------------------
{
  // int iRet  = 0;
  // int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (Zeile->at(ulPos-1) == cBrakeClose[0])
      return 1;
  else
      return 0;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstStr011i_IsDelimiter (int            iKey,
                       std::string   *Zeile,
                       unsigned long           lPos,
                       char          *cDelimit)
//-----------------------------------------------------------------------------
{
  // int iRet  = 0;
  // int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (Zeile->at(lPos-1) == cDelimit[0])
      return 1;
  else
      return 0;

}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstStr011i_RemoveEndingSpaces (int               iKey,
                              sstStr01FcwCls *oFmtInfo,
                              std::string      *sZeile)
//-----------------------------------------------------------------------------
{
  unsigned long LenT1;     // Länge Quell-String

  // char TrnZ[2];   // Trennzeichen
  // char *txt2;
  // long ii;
  unsigned long jj;
  int iStat=0;
  int iRet=0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // strcpy(TrnZ," ");      // Trennzeichen Leer

  LenT1 = sZeile->length();  // Länge von Text 1
  if (LenT1 < 1) return -1;  // no text


  // ii = sstStr01_StartOfInfo ( 0, 1, oFmtInfo->cNoInfo, sZeile->Txt);
  // if (ii>LenT1) return -1;  // Text complete empty

  // seach backwarts from LenT1
  // jj = sstStr01_EndOfInfo ( 1, LenT1, oFmtInfo->cNoInfo, sZeile->Txt);
  // jj = sstStr011i_EndOfInfo ( 1, LenT1, oFmtInfo->cNoInfo, sZeile);
  jj = sstStr011i_EndOfInfo ( 1, LenT1, oFmtInfo->GetNoInfoChar(), sZeile);

  if (jj < LenT1)
  {
    sZeile->erase(jj,sZeile->length()-jj);
  }

  // txt2 = (char*) malloc(LenT1+1);
  // strcpy(txt2,sZeile->Txt);

  // strcpy(txt1,&txt2[ii-1]);  // Deleting starting spaces

  // sZeile->Txt[jj] = '\0';      // Deleting ending space
  // sZeile->AktLen = strlen(sZeile->Txt);

  // free(txt2);

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
int sstStr01i_RemoveSpaces (int          iKey,
                            std::string *txt1)    //   <-> Quelle ) // v  -> For the moment 0
//-----------------------------------------------------------------------------
{
  unsigned long LenT1;     // Länge Quell-String

  char TrnZ[2];   // Trennzeichen
  // std::string txt2;
  unsigned long ii;
  //  long jj;
  int iStat=0;
  int iRet=0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  strcpy(TrnZ," ");      // Trennzeichen Leer

  LenT1 = txt1->length();  // Länge von Text 1
  if (LenT1 < 1) return -1;  // no text

  ii = sstStr01_StartOfInfo ( 0, 1, TrnZ, txt1);
  if (ii>LenT1) return -1;  // Text complete empty

  // strcpy(txt1,&txt2[ii-1]);  // Deleting starting spaces
  if (ii > 1) txt1->erase(0,ii-1);

  LenT1 = txt1->length();  // Länge von Text 1
  if (LenT1 < 1) return -1;  // no text

  // seach backwarts from LenT1
  unsigned long int ulEnd = sstStr01_EndOfInfo ( 1, LenT1, TrnZ, txt1);

  // txt1[jj-ii+1] = '\0';      // Deleting ending space
  if (ulEnd < LenT1) txt1->erase(ulEnd,LenT1-1);

  // free(txt2);

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
//$DA
//$TOPIC sstStr01_StartOfInfo
unsigned long sstStr01_StartOfInfo ( int  iKey,    // v  -> Vorerst immer 0
                                unsigned long  Pos,     //   <-> Suchen ab Position
                                char *TrnZ,    //   <-> Trennzeichen
                                std::string *Text)    //   <-> Prüf-Text
                           //
                           //   <- Rückgabe Funktion
                           //      0 = Index Beginn der Information
                           //     <0 = allgemeiner Fehler
//
//  Erstellt: 11.07.00   UR
//  Geändert: 11.03.03   UR
//
//$KAT str_lib
//$KT  Beginn der Information in einem String ab Position Pos feststellen
//
// Ist der String leer, wird Fehler zurückgegeben
// Die Position wird im Bereich 1..n berechnet.
//
// 11.03.03: Speichergröße jetzt Int4.  UR
//
//$DE
//.............................................................................
{
  unsigned long LenTxt;
  unsigned long StartPos;

  unsigned long ii;
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  // Länge des Prüftextes ermitteln
  LenTxt = Text->length();
  if(LenTxt <= 0) return -1;

  // Schleife über alle Buchstaben
  for ( ii = Pos; ii <= LenTxt; ii++)
  {
    iStat = sstStr01_PosHasInfo ( 0, Text, ii, TrnZ);
    if (iStat == 1)
    {
      break;
    }
  }

  if (ii > LenTxt)  return -1;   // keine Information im String

  StartPos = ii;  // Result

  return StartPos;
}
//=============================================================================
/**
* @brief Ende der Information in einem String feststellen
*
* Ab Position Pos wird vorwärts im String Text das Ende gesucht.
* Ende kann sein ein NoInformation-Zeichen oder '\0'.
* Ist ein Ende gefunden, wird rückwärts bis zur nächsten Information
* gegangen. Diese Position wird zurückgegeben.
* Ist der String leer, wird Fehler zurückgegeben
* Die Position wird im Bereich 1..n berechnet.
*
* Changed: 03.07.09  Re.
*
* 26.04.01: Wenn bis zum Ende gesucht wird, muß das Result das Ende
*           vom Text sein.   UR
* 11.03.03: Speichergröße jetzt Int4.  UR
* 24.09.04: Key = 1 für Rückwärts-Suche.  UR
* 03.07.09: Rückwärts-Suche bei Ein-Zeichen-Texten korrigiert.  Re.
*
* @ingroup sstStr01IntLib
*
* @param iKey:    [in] 0 = vorwärts, 1 = rückwärts
* @param lPos:    [in] Suchen ab Position
* @param NoInfoZ: [in] NoInformation-Zeichen
* @param Text:    [in] Prüf-Text
*
* @return Errorstate
*
* @retval   = X: Ende der Information
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 14.07.00
*/
//-----------------------------------------------------------------------------
unsigned long sstStr01_EndOfInfo ( int   iKey,     // v  -> 0 oder 1
                     unsigned long  lPos,     // v  -> Suchen ab Position
                     char *NoInfoZ,  //   <-> NoInformation-Zeichen
                     std::string *Text)     //   <-> Prüf-Text
//-----------------------------------------------------------------------------
{
  unsigned long LenTxt;
  unsigned long EndPos;

  unsigned long ii;
  // int istat;
//.............................................................................
  if (iKey < 0 || iKey > 1) return -1;
  // istat = 0;

  LenTxt = Text->length();
  if(LenTxt <= 0) return -1;


  if ( iKey == 0)
  { // Übergebene Position soll Anfang einer Information sein.
    // Jetzt vorwärts suchen bis zum Ende der Informtion

    EndPos = LenTxt;        // vorläufig

    // im String text vorwärts Trennzeichen suchen
    for( ii = lPos; ii <= LenTxt; ii++)
    {
      if (sstStr01_PosHasInfo ( 0, Text, ii, NoInfoZ) < 1) break;
    }

    if (ii > LenTxt+1)  return -1;   // keine Information im String

    EndPos = ii-1;  // Result

  }
  else
  { // Ist an übergebener Position Information, wird diese direkt zurückgegeben,
    // ansonsten wird so lange rückwärts gesucht, bis Information gefunden wird.

    EndPos = 0;        // keine Information mehr gefunden

    // im String text vorwärts Trennzeichen suchen
    for( ii = lPos; ii >= 1; ii--)
    {
      if ( sstStr01_PosHasInfo ( 0, Text, ii, NoInfoZ) == 1) break;
    }

    // if (ii <= 1)  return -1;   // keine Information im String
    if (ii < 1)  return -1;   // keine Information im String   03.07.09  Re.

    EndPos = ii;  // Result
  }
  return EndPos;
}
//=============================================================================
//=============================================================================
/**
* @brief Steht an Position Information im String ?
*
* Es wird der zu untersuchende String übergeben.
* Dazu eine Positionsangabe zum String.
* Außerdem ist eine Angabe notwendig, was eigentlich
* Information sein soll.
*
* Geändert: 27.08.04  UR
*
* 11.03.03: String-Speicher jetzt Int4.  UR
* 27.08.04: Wenn Info-Angabe leer, ist alles Information
*
* @ingroup sstStr01IntLib
*
* @param Key:     [in] Vorerst immer 0
* @param TstStr:  [in] Bearbeitungszeile
* @param Pos:     [in] Position im TstStr 1..n
* @param InfoStr: [in] String mit Info-Angaben
*
* @return Fehlerstatus
*
* @retval   =1: An Position im String steht Information
* @retval   =0: Keine Information an Position im String
* @retval   <0: Allgemeiner Fehler
*
* @author ur
*
* @date 08.09.00
*/
//-----------------------------------------------------------------------------
int sstStr01_PosHasInfo ( int  Key,       // v  -> Vorerst immer 0
                       std::string *TstStr,    //   <-> Bearbeitungszeile
                       unsigned long  Pos,       // v <-> Position im TstStr 1..n
                       char *NoInfoStr) //   <-> String mit NoInfo-Angaben
//-----------------------------------------------------------------------------
{
  unsigned long LenTstStr;
  unsigned long LenInfoStr;

  unsigned long ii;
  // int istat;
//-----------------------------------------------------------------------------
  if (Key != 0) return -1;
  // istat = 0;

  // Logik-Prüfung Pos
  LenTstStr  = TstStr->length();
  if (Pos <= 0) return -1;
  if (Pos > LenTstStr) return -1;

  LenInfoStr = strlen ( NoInfoStr);
  if (LenInfoStr <= 0) return 1;  // Nichts ist "Keine Information"

  // Schleife über alle NoInformation-Zeichen
  ii = 1;
  do
  {
    if( TstStr->at(Pos-1) == NoInfoStr[ii-1])
    {
      return 0;  // An Position steht "No Information", mit Null zurück
    }
    ii++;
  } while (ii <= LenInfoStr);

  return 1;
}
//=============================================================================
int sstStr01_SubS_Tausch ( int    iKey,      // v  -> Vorerst immer 0
                      std::string  *Text,      //   <-> Zu bearbeitender String
                      // int    TextLen,   // v  -> Speichergröße String
                      std::string  *SubStrAdr, // v  -> Anfang des Substrings
                      // unsigned long    SubStrLen, // v  -> Länge des Substrings
                      std::string  *NewT)      //   <-> Austausch-String
//-----------------------------------------------------------------------------
{
//  char  *RestTxtAdr;          // Rest hinter SubString
//  unsigned long   RestTxtLen;           // Länge Rest hinter SubString

//  unsigned long NewT_Len;

//  unsigned long LenDiff;               // Längen-Unterschied alter,neuer Substring
//  unsigned long TxtLen;
  int istat;
//.............................................................................
  if (iKey != 0) return -1;
  istat = 0;

  Text->replace(Text->find(*SubStrAdr),SubStrAdr->length(),*NewT);

//  TxtLen = Text->length();

//  // Warum Probleme, wenn String gleich Max-Länge von String ??  23.07.04  UR
//  // if(TxtLen > TextLen) return -1;  // Problem mit Benutzerangaben
//  // if(TxtLen >= TextLen) return -1;  // Problem mit Benutzerangaben

//  RestTxtLen = SubStrAdr - SubStrLen +1;

//  if (RestTxtLen > 0)
//  {
//    RestTxtAdr = SubStrAdr + SubStrLen;
//  }
//  else
//  {
//    RestTxtAdr = NULL;
//  }

//  NewT_Len = strlen(NewT);  // Länge des Austauschtextes

//  // Nach Austausch darf Text nicht größer als Speicher sein
//  // if( (TxtLen-SubStrLen+NewT_Len) >= TextLen) return -1;
//  if( (TxtLen-SubStrLen+NewT_Len) >= TextLen) return -4;

//  if(NewT_Len == 0)
//  {
//    // Kein Austauschtext, Substring wird aus Text entfernt,
//    if(RestTxtLen >0)
//    {
//      // indem der Resttext im Speicher nach vorn wandert
//      memmove( SubStrAdr, RestTxtAdr, RestTxtLen);
//    }
//    else
//    {
//      // indem das Textende nach vorn wandert
//      SubStrAdr[0] = '\0';
//    }
//  }
//  else
//  {
//    LenDiff = NewT_Len - SubStrLen;

//    // if ( (TxtLen+LenDiff) >= TextLen) return -1;
//    if ( (TxtLen+LenDiff) > TextLen) return -1;

//    if (LenDiff != 0)
//    {
//      // Der neue Text ist kürzer oder länger als der Alte
//      // Speicherbereich für Substring anpassen
//      memmove( SubStrAdr+NewT_Len, RestTxtAdr, RestTxtLen);
//    }

//    // Austauschtext an Platz kopieren
//    memcpy( SubStrAdr, NewT, NewT_Len);

//  }
  return istat;
}
//=============================================================================
