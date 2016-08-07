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
// sstStr01Int4.cpp    24.11.15  Re.    24.11.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include "sstStr01Lib.h"
#include "sstStr01LibInt.h"


//=============================================================================
int sstStr011i_LesTxtNach ( int          Key,     // v  -> Vorerst immer 0
                       std::string *Zeile,   //   <-> Bearbeitungszeile
                       char        *TrennZ,  //   <-> String mit Trennzeichen
                       std::string *SuchStr, //   <-> Such-String
                       std::string *FindStr) //   <-> Result-String
//.............................................................................
{
  // char *ZeilAdr;
  unsigned long SuchAdr;
  // long  LenZeil;
  long  LenSuch;
  std::string  ErrTxt;
  // char  NoInfoStr[10];  // String mit NoInfo-Definition

  // int  Von;
  unsigned long  ii;
  int   iStat = 0;
//.............................................................................
  if (Key != 0) return -1;

  LenSuch = SuchStr->length();
  if(LenSuch <= 0) return -2;

  // Interne Funktion, keine Prüfung der Stringparameter

  // Suchstring in Zeile lokalisieren
  // SuchAdr = strstr ( Zeile->Txt, SuchStr->Txt);
  SuchAdr = Zeile->find( *SuchStr, 1);
  if( SuchAdr == 0) return -1;  // Kein Suchstring gefunden
  // ZeilAdr = Zeile->Txt;
  // LenZeil = strlen(Zeile->Txt);

  // Position des Suchstrings ermitteln
  ii = 0;
  iStat = sstStr011i_AdrHasPos ( 0, &ii, Zeile, SuchStr);
  if (ii <= 0) return -1;

  // strcpy(NoInfoStr," (");  // Blank und KlammerAuf sind NoInfos

  // Nächste Information aus Text-Zeile in String umwandeln
  LenSuch = SuchStr->length();
  ii = ii + LenSuch;  // Position hinter Suchstring
  iStat = sstStr011_AbPos2Str ( 0, &ii, TrennZ, Zeile, &ErrTxt, FindStr);

  return iStat;// sstStr011i_PosHasInfo
}
//=============================================================================
int sstStr011i_PosHasInfo ( int          Key,       // v  -> Vorerst immer 0
                            std::string *TstStr,    //   <-> Bearbeitungszeile
                            unsigned long         Pos,       // v <-> Position im TstStr 1..n
                            char *NoInfoStr) //   <-> String mit NoInfo-Angaben
//-----------------------------------------------------------------------------
{
  // long LenTstStr;
  unsigned long LenInfoStr;

  unsigned long ii;
  // int istat;
//-----------------------------------------------------------------------------
  if (Key != 0) return -1;
  // istat = 0;

  // Interne Funktion, keine Prüfung der Stringparameter

  // Logik-Prüfung Pos
  // LenTstStr  = strlen(TstStr->Txt);
  if (Pos <= 0) return -2;
  // if (Pos > TstStr->length()) return -2;

  LenInfoStr = strlen ( NoInfoStr);
  if (LenInfoStr <= 0) return 1;  // Nichts ist "Keine Information"

  // Schleife über alle NoInformation-Zeichen
  ii = 1;
  do
  {
    // if( TstStr->Txt[Pos-1] == NoInfoStr[ii-1])
    if( TstStr->at(Pos-1) == NoInfoStr[ii-1])
    {
      return 0;  // An Position steht "No Information", mit Null zurück
    }
    ii++;
  } while (ii <= LenInfoStr);

  return 1;
}
//=============================================================================
int sstStr011i_PosIsZch ( int          Key,       // v  -> Vorerst immer 0
                     std::string *TstStr,    //   <-> Bearbeitungszeile
                     unsigned long         Pos,       // v <-> Position im TstStr 1..n
                     char        *ZchStr)    //   <-> String mit Zeichen
//-----------------------------------------------------------------------------
{
  // long LenTstStr;
  long LenInfoStr;

  long ii;
  // int istat;
//-----------------------------------------------------------------------------
  if (Key != 0) return -1;
  // istat = 0;

  // Interne Funktion, keine Prüfung der Stringparameter

// Logik-Prüfung Pos
  // LenTstStr  = strlen(TstStr->Txt);
  if (Pos <= 0) return -2;
  if (Pos > TstStr->length()) return -2;

  LenInfoStr = strlen ( ZchStr);
  if (LenInfoStr <= 0) return 0;  // Nichts kann nicht gefunden werden

  // Schleife über alle NoInformation-Zeichen
  ii = 1;
  do
  {
    // if( TstStr->Txt[Pos-1] == ZchStr[ii-1])
    if( TstStr->at(Pos-1) == ZchStr[ii-1])
    {
      return 1;  // Ja, an Position steht eins der übergebenen Zeichen
    }
    ii++;
  } while (ii <= LenInfoStr);

  return 0;      // Nein, keins der übergebenen Zeichen gefunden
}
//=============================================================================
int sstStr011i_AdrHasPos ( int          Key,    // v  -> Vorerst immer 0
                      unsigned long        *TPos,   //   <-> Position in Textzeile
                      std::string *Zeile,  //   <-> Textzeile
                      std::string *TAdr)   //   <-> Adresse in dieser Textzeile
{
  std::string LocZeile;  // Adresse lokal erzeugen

  unsigned long ii;
  int iStat = 0;
//.............................................................................
  if (Key != 0) return -1;

  // Interne Funktion, keine Prüfung der Stringparameter

  LocZeile = *Zeile;  // Adresse lokal erzeugen
  // LenZeil = strlen(Zeile->Txt);
  // Startposition des Suchstrings ermitteln
  ii = 0;
//  do
//  {
//    if (LocZeile == *TAdr) break;
//    LocZeile++;
//    ii++;
//  } while (ii <= Zeile->AktLen);
//  ii++;  // Positionen werden von 1..n gezählt

  ii = Zeile->find(*TAdr,0);

  if ( ii <= Zeile->length())
  {  // Adresse gefunden
    *TPos = ii+1;
    iStat = 1;
  }
  else
  {  // Adresse nicht gefunden
    *TPos = 0;
    iStat = 0;

  }


  return iStat;
}
//=============================================================================
int sstStr011i_AbPos_Int ( int          Key,    // v  -> Vorerst immer 0
                      std::string *TAdr,   //   <-> Lesen ab Adresse in Zeile
                      // std::string *Zeile,  //   <-> Lese-String
                      std::string *ErrTxt, //   <-> Read-Error -bei Errtxt-
                      int         *iRet)   //   <-> Result-Int2
//.............................................................................
{
  std::string tRet;   // String mit ZwischenResult

  long  TxtLen;     // Länge eines Textes

  long  ii;
  int  istat;
//.............................................................................
  if (Key != 0) return -1;
  istat = 0;

  // Interne Funktion, keine Prüfung der Stringparameter

  // Zahlen größer 5-stellig sinnlos,
  // Result Int2 max. 32767
  TxtLen = TAdr->length();
  if(TxtLen > 5) TxtLen = 5;

  for( ii=0; ii<TxtLen; ii++)
  {

//    tRet.Txt[ii] = *(TAdr+ii);  // Neuer Zwischenwert bereitstellen
//    tRet.Txt[ii+1] = '\0';    // Zwischenwert abschliessen
//    tRet.AktLen = strlen(tRet.Txt);
    tRet = tRet + TAdr->at(ii);

    // String direkt in Int2 konvertieren
    istat = sstStr011i_Txt2Int ( 0, &tRet, iRet);
    if (istat < 0) break;  // Text konnte nicht mehr interpretiert werden
  }

  if(istat >= 0)
  { // Der gesamte Text ist Integer
    // tRet.Txt[ii] = '\0';  // Result abschliessen
  }
  else
  {
    // Nur Teil des Textes ist Integer, Result abschliessen
    // tRet.Txt[ii] = '\0';
    // tRet.AktLen = strlen(tRet.Txt);
    // String direkt in Int2 konvertieren
    istat = sstStr011i_Txt2Int ( 0, &tRet, iRet);
  }

  if(ii <= 0)
  {
    *iRet = 0;
    return -1;
  }

  // wo lag das Problem, zurück für Protokoll
  // Gab es keine Probleme, ZwischenResult trotzdem sichern
  // strcpy ( ErrTxt->Txt, tRet.Txt);
  *ErrTxt = tRet;

  return istat;
}
//=============================================================================
int sstStr011i_AbPos_Dbl ( int          Key)    // v  -> Vorerst immer 0
//                      char        *TAdr,   //   <-> Lesen ab Adresse
//                      std::string *Zeile,  //   <-> Lese-String
//                      std::string *ErrTxt, //   <-> Read-Error -bei Errtxt-
//                      int         *dRet)   //   <-> Result-Dble
//.............................................................................
{
  int istat;
//.............................................................................
  if (Key != 0) return -1;
  istat = -1;
  return istat;
}
//=============================================================================
int sstStr011_SubS_Tausch ( int          Key,       // v  -> Vorerst immer 0
                       std::string *Text,      //   <-> Zu bearbeitender String
                       // int          TextLen,   // v  -> Speichergröße String
                       std::string     *SubStrAdr, // v  -> Anfang des Substrings
                       unsigned long      SubStrLen, // v  -> Länge des Substrings
                       std::string *NewT)      //   <-> Austausch-String
//.............................................................................
{
//  char  *RestTxtAdr;          // Rest hinter SubString
//  unsigned long  RestTxtLen;          // Länge Rest hinter SubString

//  unsigned long NewT_Len;

//  unsigned long LenDiff;               // Längen-Unterschied alter,neuer Substring
//  unsigned long TxtLen;
  int istat;
//.............................................................................
  if (Key != 0) return -1;
  istat = 0;

  Text->replace(Text->find(*SubStrAdr), SubStrLen, *NewT);

//  // Interne Funktion, keine Prüfung der Stringparameter

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

//  NewT_Len = strlen(NewT->Txt);  // Länge des Austauschtextes

//  // Nach Austausch darf Text nicht größer als Speicher sein
//  if( (TxtLen-SubStrLen+NewT_Len) >= TextLen) return -1;

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

//    if ( (TxtLen+LenDiff) >= TextLen) return -1;

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
int sstStr011_Char_Replace_c (int          Key,       // v  -> Vorerst immer 0
                         char         OldChar,   //    -> Zu ersetzendes Zeichen
                         char         NewChar,   //    -> Ersatzzeichen
                         std::string *Text)      //   <-> Zu bearbeitender String
//-----------------------------------------------------------------------------
{
  int TxtLen, ii;

  int iRet;
  int iStat;
//-----------------------------------------------------------------------------
  if (Key != 0) return -1;
  iRet = 0;

  // Interne Funktion, keine Prüfung der Stringparameter

  // if( OldChar <= 31 || OldChar >= 128) return -1;  // Ist Austauschzeichen sinnvoll ?
  // if( NewChar <= 31 || NewChar >= 128) return -1;  // Ist Ersatzzeichen sinnvoll ?

  if (OldChar == NewChar) return 0;                // Soll was Sinnvolles getan werden ?

  iStat = 0;

  TxtLen = Text->length();
  if (TxtLen <= 0 || TxtLen >= 32000) return -1;

  for ( ii=1; ii<=TxtLen; ii++)
  {
    // if (Text->Txt[ii-1] == OldChar)
    if (Text->at(ii-1) == OldChar)
    {
      Text[ii-1] = NewChar;
      iStat++;
    }
  }

  // Übele Geschichten gleich behandeln
  if (iRet < 0)
  {
    // Expression (iRet >= 0) muß erfüllt sein, sonst assert
    //_ASSERT_MSG( iRet >= 0,  "Fehler in Funktion: Str_Char_Replace_c");
  }

  // Kleinere Übeleien zurückgeben
  iRet = iStat;

//  Uprintf ( 99, "ButtonPtr: %x, Button ID: %d, Text: %s", this, GetID(), txt);

  return iRet;
}
//=============================================================================
long sstStr011i_TrnZFind ( int          iKey,     // v  -> Vorerst immer 0
                      unsigned long         Pos,      //   <-> Suchen ab Position
                      char        *TrnZ,     //   <-> Trennzeichen
                      std::string *Text)     //   <-> Prüf-Text
//-----------------------------------------------------------------------------
{
  // long LenTxt;
  unsigned long StartPos;

  unsigned long ii;
  int iStat;
//.............................................................................
  if (iKey != 0) return -1;
  iStat = 0;

  // Interne Funktion, keine Prüfung der Stringparameter

  if (Pos <= 0 || Pos > Text->length()) return -2;

  // Länge des Prüftextes ermitteln
  // LenTxt = strlen(Text->Txt);
  // if(LenTxt <= 0) return -1;

  // Schleife über alle Buchstaben
  for ( ii = Pos; ii <= Text->length(); ii++)
  {
    // Steht im String an Position eins der übergebenen Zeichen?
    iStat = sstStr011i_PosIsZch ( 0, Text, ii, TrnZ);
    if ( iStat == 1)
    {
      break;  // Begrenzungszeichen gefunden, Ende der Suche
    }
  }

  if (ii > Text->length())  return 0;   // keine Information im String

  StartPos = ii;  // Result

  return StartPos;
}
//=============================================================================
unsigned long sstStr011i_EndOfInfo ( int          Key,      // v  -> 0 oder 1
                       unsigned long         Pos,      //   <-> Suchen ab Position
                       char        *NoInfoZ,  //   <-> NoInformation-Zeichen
                       std::string *Text)     //   <-> Prüf-Text
//-----------------------------------------------------------------------------
{
  // long LenTxt;
  unsigned long EndPos;

  unsigned long ii;
  // int  iStat = 0;
//.............................................................................
  if (Key < 0 || Key > 1) return -1;
  if(Pos <= 0 || Pos > Text->length()) return -2;

  // Interne Funktion, keine Prüfung der Stringparameter

  // LenTxt = strlen(Text->Txt);
  // if(LenTxt <= 0) return -1;


  if ( Key == 0)
  { // Übergebene Position soll Anfang einer Information sein.
    // Jetzt vorwärts suchen bis zum Ende der Informtion

    if (Text->at(Pos-1) == *NoInfoZ)
    {
      // Look for End of Information
      // Found End of Information
      // Information must be before
      return Pos-1;
    }


    EndPos = Text->length();        // vorläufig

    // im String text vorwärts Trennzeichen suchen
    for( ii = Pos; ii <= Text->length(); ii++)
    {
      if (sstStr011i_PosHasInfo ( 0, Text, ii, NoInfoZ) < 1) break;
    }

    if (ii > Text->length() + 1)  return -1;   // keine Information im String

    EndPos = ii-1;  // Result

  }
  else
  { // Ist an übergebener Position Information, wird diese direkt zurückgegeben,
    // ansonsten wird so lange rückwärts gesucht, bis Information gefunden wird.

    EndPos = 0;        // keine Information mehr gefunden

    // im String text vorwärts Trennzeichen suchen
    for( ii = Pos; ii >= 1; ii--)
    {
      if ( sstStr011i_PosHasInfo ( 0, Text, ii, NoInfoZ) == 1) break;
    }

    if (ii < 1)  return -1;   // keine Information im String

    EndPos = ii;  // Result
  }
  return EndPos;
}
//=============================================================================
long sstStr011i_EndOfInfo2 ( int          Key,      // v  -> 0 oder 1
                             unsigned long         Pos,      //   <-> Suchen ab Position
                             char        *NoInfoZ,  //   <-> NoInformation-Zeichen
                             std::string *Text)     //   <-> Prüf-Text
//-----------------------------------------------------------------------------
{
  // long LenTxt;
  unsigned long EndPos;

  unsigned long ii;
  // int  iStat = 0;
//.............................................................................
  if (Key < 0 || Key > 1) return -1;
  if(Pos <= 0 || Pos > Text->length()) return -2;

  // Interne Funktion, keine Prüfung der Stringparameter

  // LenTxt = strlen(Text->Txt);
  // if(LenTxt <= 0) return -1;


  if ( Key == 0)
  { // Übergebene Position soll Anfang einer Information sein.
    // Jetzt vorwärts suchen bis zum Ende der Informtion

    // if (Text->at(Pos-1) == *NoInfoZ)
    if (Text->at(Pos-1) == NoInfoZ[0])
    {
      // Look for End of Information
      // Found End of Information
      // Information must be before
      return Pos-1;
    }


    EndPos = Text->length();        // vorläufig

    // im String text vorwärts Trennzeichen suchen
    for( ii = Pos; ii <= Text->length(); ii++)
    {
      if (sstStr011i_PosHasInfo ( 0, Text, ii, NoInfoZ) < 1) break;
    }

    if (ii > Text->length()+1)  return -1;   // keine Information im String

    EndPos = ii-1;  // Result

  }
  else
  { // Ist an übergebener Position Information, wird diese direkt zurückgegeben,
    // ansonsten wird so lange rückwärts gesucht, bis Information gefunden wird.

    EndPos = 0;        // keine Information mehr gefunden

    // im String text vorwärts Trennzeichen suchen
    for( ii = Pos; ii >= 1; ii--)
    {
      if ( sstStr011i_PosHasInfo ( 0, Text, ii, NoInfoZ) == 1) break;
    }

    if (ii < 1)  return -1;   // keine Information im String

    EndPos = ii;  // Result
  }
  return EndPos;
}
//=============================================================================
long sstStr011i_StartOfInfo ( int          iKey,
                         unsigned long         Pos,
                         char *TrnZ,
                         std::string *Text)
//-----------------------------------------------------------------------------
{
  // long LenTxt;
  unsigned long StartPos;

  unsigned long ii;
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;
  if (Pos > Text->length()) return -2;

  // Interne Funktion, keine Prüfung der Stringparameter

  // if (Pos==0) return -2;

  // Länge des Prüftextes ermitteln
  // LenTxt = strlen(Text->Txt);
  // if(LenTxt <= 0) return -1;

//  if (Text->at(Pos-1) == *TrnZ)
//  {
//    // Look for Start of Information
//    // Found End of Information
//    // Immediate return
//    return Pos;
//  }

  // Schleife über alle Buchstaben
  for ( ii = Pos; ii <= Text->length(); ii++)
  {
    iStat = sstStr011i_PosHasInfo ( 0, Text, ii, TrnZ);
    if (iStat == 1)
    {
      break;
    }
  }

  if (ii > Text->length())  return -3;   // keine Information im String

  StartPos = ii;  // Result

  return StartPos;
}
//=============================================================================
long sstStr011i_StartOfInfo2 ( int          iKey,
                               unsigned long         Pos,
                               char        *TrnZ,
                               std::string *Text)
//-----------------------------------------------------------------------------
{
   // long LenTxt;
   unsigned long StartPos;

   unsigned long ii;
   int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;
  if (Pos > Text->length()) return -2;

//  if (Pos == 0)
//  {
//    return 1;
//  }

//  if (sstStr011i_PosHasInfo ( 0, Text, Pos, TrnZ) == 1) return Pos;
//  else return Pos+1;

  // Interne Funktion, keine Prüfung der Stringparameter

  // Länge des Prüftextes ermitteln
  // LenTxt = strlen(Text->Txt);
  // if(LenTxt <= 0) return -1;

  // Schleife über alle Buchstaben
  for ( ii = Pos; ii <= Text->length(); ii++)
  {
    iStat = sstStr011i_PosHasInfo ( 0, Text, ii, TrnZ);
    if (iStat == 1)
    {
      break;
    }
  }

  if (ii > Text->length())  return -3;   // keine Information im String

  StartPos = ii;  // Result

  return StartPos;
}
//=============================================================================
int sstStr011i_IsDigit ( int   Key,
                    char *Zeichen)
//-----------------------------------------------------------------------------
{
//-----------------------------------------------------------------------------
  if (Key != 0) return -1;

  if ( ( Zeichen[0] >= '0') && (Zeichen[0] <= '9')) return 1;

  return 0;
}
//=============================================================================
int sstStr011i_Txt2Int ( int          Key,     // v  -> Vorerst immer 0
                    std::string *LocInt,  //   <-> Konvertierungstext
                    int         *iRet)    //   <-> Result-Int2
//-----------------------------------------------------------------------------
{
  int iStat = 0;
//.............................................................................
  if (Key != 0) return -1;

  *iRet = 0;

  if (LocInt->length() <= 0 || LocInt->length() > 5) return -3;  // Zahlenstring zu lang/zu kurz!

  // Interne Funktion, keine Prüfung der Stringparameter

  // Is String to Int/LongInt convertible?
  iStat = sstStr011i_IntConvertible ( 0, LocInt);

  if (iStat == 1)
  {
    *iRet = atoi( LocInt->c_str());  // Fehlerbehandlung ??
    iStat = 0;
  }
  else
    iStat = -2;

  return iStat;
}
//=============================================================================
int sstStr011i_Txt2UInt ( int            Key,      // v  -> Vorerst immer 0
                     std::string   *LocInt,   //   <-> Konvertierungstext
                     unsigned int  *uiRet)    //   <-> Result-Int2
//-----------------------------------------------------------------------------
{
  int iStat = 0;
//.............................................................................
  if (Key != 0) return -1;

  *uiRet = 0;

  if (LocInt->length() <= 0 || LocInt->length() > 5) return -3;  // Zahlenstring zu lang/zu kurz!

  // Interne Funktion, keine Prüfung der Stringparameter

  // Is String to Int/LongInt convertible?
  iStat = sstStr011i_IntConvertible ( 0, LocInt);

  if (iStat == 1)
  {
    *uiRet = atoi( LocInt->c_str());  // Fehlerbehandlung ??
    iStat = 0;
  }
  else
    iStat = -2;

  return iStat;
}
//=============================================================================
int sstStr011i_Txt2Int4 ( int          Key,     // v  -> Vorerst immer 0
                     std::string *LocInt,  //   <-> Konvertierungstext
                     long        *lRet)    //   <-> Result-Int2
//-----------------------------------------------------------------------------
{
  int iStat = 0;
//.............................................................................
  if (Key != 0) return -1;

  // Interne Funktion, keine Prüfung der Stringparameter

  *lRet = 0;

  if (LocInt->length() <= 0 || LocInt->length() > 10) return -3;  // Zahlenstring zu lang/zu kurz!

  // Interne Funktion, keine Prüfung der Stringparameter

  // Is String to Int/LongInt convertible?
  iStat = sstStr011i_IntConvertible ( 0, LocInt);

  if (iStat == 1)
  {
    *lRet = atol( LocInt->c_str());  // Fehlerbehandlung ??
    iStat = 0;
  }
  else
    iStat = -2;

  return iStat;
}
//=============================================================================
int sstStr011i_Txt2UInt4 ( int             iKey,
                      std::string    *LocInt,
                      unsigned long  *ulRet)
//-----------------------------------------------------------------------------
{
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  // Interne Funktion, keine Prüfung der Stringparameter

  *ulRet = 0;

  if (LocInt->length() <= 0 || LocInt->length() > 10) return -3;  // Zahlenstring zu lang/zu kurz!

  // Interne Funktion, keine Prüfung der Stringparameter

  // Is String to Int/LongInt convertible?
  iStat = sstStr011i_IntConvertible ( 0, LocInt);

  if (iStat == 1)
  {
    *ulRet = atol( LocInt->c_str());  // Fehlerbehandlung ??
    iStat = 0;
  }
  else
    iStat = -2;

  return iStat;
}
//=============================================================================
int sstStr011i_Txt2Real ( int          Key,
                          std::string *LocReal,
                          float       *rRet)
//-----------------------------------------------------------------------------
{
  char *enz;  // Zeiger auf Konvertierungs-Fehler
  // std::string::size_type sz;     // alias of size_t
  // char cTmpChar[10];

  // double LocFlt;

  int iStat =  0;
//.............................................................................
  if (Key != 0) return -1;

  *rRet = 0.0;

  if (LocReal->length() <= 0) return -3;  // Zahlenstring zu lang/zu kurz!

  // Interne Funktion, keine Prüfung der Stringparameter

  // Is String to Float/Double convertible?
  iStat  = sstStr011_FloatConvertible ( 0, LocReal);
  // iStat = 1;
  if(iStat == 1)
  {
    // String is convertible, go on!
    iStat = 0;
  }
  else
  {
    return -2;
  }

  char *saved_locale;
  saved_locale = setlocale(LC_NUMERIC, "C");
  /* do your strtod thing */
  *rRet = strtof( LocReal->c_str(), &enz);
  setlocale(LC_NUMERIC, saved_locale);

  if ( strlen(enz) != 0)
  {
    *rRet = 0.0;  // Return-Wert zurücksetzen
    return -2;
  }

  return iStat;
}
//=============================================================================
int sstStr011i_Txt2Dbl ( int          Key,     // v  -> Vorerst immer 0
                    std::string *LocDbl,  //   <-> Konvertierungstext
                    double      *dRet)    //   <-> Result-Double
//.............................................................................
{
  char *enz;  // Zeiger auf Konvertierungs-Fehler

  int iStat = 0;
//.............................................................................
  if (Key != 0) return -1;

  *dRet = 0.0;  // Return-Wert zurücksetzen

  if (LocDbl->length() <= 0) return -3;  // Zahlenstring zu lang/zu kurz!

  // Interne Funktion, keine Prüfung der Stringparameter

  // Is String to Float/Double convertible?
  iStat  = sstStr011_FloatConvertible ( 0, LocDbl);
  if(iStat == 1)
  {
    // String is convertible, go on!
    iStat = 0;
  }
  else
  {
    return -2;
  }

  // Kein Routine, die auch mit Komma funktioniert ??
  *dRet = strtod( LocDbl->c_str(), &enz);
  if ( strlen(enz) != 0)
  {
    *dRet = 0.0;  // Return-Wert zurücksetzen
    return -2;
  }

  return iStat;
}
//=============================================================================
long sstStr011i_BeGrzFind ( int          Key,     // v  -> Vorerst immer 0
                       unsigned long         Pos,     //   <-> Suchen ab Position
                       char        *BeGrzZ,  //   <-> Begrenzungszeichen
                       std::string *Text)    //   <-> Prüf-Text
//.............................................................................
{
  // long LenTxt;
  unsigned long StartPos;

  unsigned long ii;
  int  iStat = 0;
//.............................................................................
  if (Key != 0) return -1;

  if(Pos < 1 || Pos > Text->length()) return -2;

  // Interne Funktion, keine Prüfung der Stringparameter

  // Länge des Prüftextes ermitteln
  // LenTxt = strlen(Text->Txt);
  // if(LenTxt <= 0) return -1;

  // Schleife über alle Buchstaben
  for ( ii = Pos; ii <= Text->length(); ii++)
  {
    // Steht im String an Position eins der übergebenen Zeichen?
    iStat = sstStr011i_PosIsZch ( 0, Text, ii, BeGrzZ);
    if ( iStat == 1)
    {
      break;  // Begrenzungszeichen gefunden, Ende der Suche
    }
  }

  if (ii > Text->length())  return -3;   // keine Information im String

  StartPos = ii;  // Result

  return StartPos;
}
//=============================================================================
int sstStr011i_IntConvertible (int          iKey,
                          std::string *LocInt)
//-----------------------------------------------------------------------------
{
  int DigitFound;  // = 0: Noch kein Zahlenzeichen gefunden
  // int DeziFound;   // = 0: Noch kein +/- gefunden

//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  DigitFound = 0;   // Default noch kein Zahlenzeichen gefunden
  // DeziFound  = 0;   // Default noch kein +/- gefunden


  for ( unsigned long ii=1; ii<=LocInt->length(); ii++)
  {
    if ( !(sstStr011i_IsDigit( 0, &LocInt->at(ii-1)) ) )
    {
      // Nicht-Zahl gefunden
      if ( (LocInt->at(ii-1) != '+') &&
           (LocInt->at(ii-1) != '-') )
      {
        // Nicht-Zahl ist auch kein Vorzeichen, Abbruch
        return 0;
      }
      else
      {  // Zeichen ist +/-
        if ( DigitFound)
        {
          // +/- gefunden, aber es sind schon Zahlen da -> FALSCH
          return 0;
        }
        else
        {
          // DeziFound = 1;   // +/- gefunden
        }
      }
    }
    else
    {
      DigitFound = 1;  // Zahlenzeichen gefunden
    }
  }
  return 1;
}
//=============================================================================
int sstStr011_FloatConvertible (int          iKey,
                           std::string *LocReal)
//-----------------------------------------------------------------------------
{
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  for (unsigned long ii=1; ii<=LocReal->length(); ii++)
  {
    if ( !(sstStr011i_IsDigit( 0, &LocReal->at(ii-1)) ) )
    {
      // Nicht-Zahl gefunden
        if ( LocReal->at(ii-1) == ',')
        {
           LocReal->at(ii-1) = '.';
        }
        if ( (LocReal->at(ii-1) != '.') &&
           (LocReal->at(ii-1) != '+') &&
           (LocReal->at(ii-1) != '-') )
      {
        // Nicht-Zahl ist auch kein Dezimal-Zeichen, Abbruch
        return 0;
      }
    }
  }

  return 1;
}
//=============================================================================



