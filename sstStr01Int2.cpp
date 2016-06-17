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
// sstStr01Int2.cpp    24.11.15  Re.    24.11.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include <string>

// #include "sstStr01Kern.h"
#include "sstStr01Lib.h"
#include "sstStr01LibInt.h"



#define DIFF_R 0.00001
#define DIFF_D 0.000000001

//=============================================================================
int sstStr011_Zeile2Str ( int          Key,    // v  -> Vorerst immer 0
                     unsigned long         Von,    // v  -> von Textposition
                     unsigned long         Bis,    // v  -> bis Textposition
                     std::string *txt1,   //   <-> Quelle
                     std::string *ErrTxt, //   <-> Read-Error -bei Errtxt-
                     std::string *txt2)   //   <-  Resultstring
//-----------------------------------------------------------------------------
{
  unsigned long LenT1;     // Länge Quell-String

  char TrnZ[2];   // Trennzeichen
  unsigned long iiVon;
  unsigned long ii;
  unsigned long jj;
  int istat;
//-----------------------------------------------------------------------------
  // if (Key != 0) return -1;
  if (Key < 0 || Key > 1) return -1;

  istat = 0;
  // strcpy( ErrTxt->Txt,"\0");  // default Fehlertext leer
  // strcpy( txt2->Txt,"\0");    // default Result leer
  ErrTxt->clear(); // default Fehlertext leer
  txt2->clear();   // default Result leer
  if (Key == 0)  memset(TrnZ,0,2);    // Trennzeichen Leer
  else           strncpy(TrnZ," ",2);   // Trennzeichen Blank, warum auch immer

  LenT1 = txt1->length();  // Länge von Text 1
  if(LenT1 <= 0) return -2;

  // txt1->AktLen = LenT1;

  ii = sstStr011i_StartOfInfo ( 0, Von, TrnZ, txt1);
  if (ii <= 0) return -1;


  if (ii > Bis)  return 0;   // keine Information im String

  iiVon = ii;
  if (Bis > LenT1) Bis = LenT1;

  // Zeichen übertragen bis Ende der Information
  // strcpy(TrnZ,"\0");      // kein Trennzeichen, auch Blanks werden kopiert
  jj = 0;
  for( ii = iiVon; ii<=Bis; ii++)
  {
    if ( sstStr011i_PosHasInfo ( 0, txt1, ii, TrnZ) == 1)
    {
      // txt2->Txt[jj] = txt1->Txt[ii-1];
      *txt2 = *txt2 + txt1->at(ii-1);
      jj = jj +1;
    }
    else
    {
      break;  // keine weitere Information
    }
  }
  // txt2->Txt[jj] = '\0';  // Result-String abschließen
  // txt2->AktLen = strlen(txt2->Txt);
  // ErrTxt[11] = '\0';
  // strcpy( ErrTxt->Txt,txt2->Txt);  // wo lag das Problem, zurück für Protokoll
  *ErrTxt = *txt2;  // wo lag das Problem, zurück für Protokoll

  // ErrTxt->AktLen = txt2->AktLen;
  // *ErrTxt = *txt2;

  return istat;
}
//=============================================================================
int sstStr011_Zeile2Int ( int          Key,    // v  -> Vorerst immer 0
                     unsigned long         Von,    // v  -> von Textposition
                     unsigned long         Bis,    // v  -> bis Textposition
                     std::string *txt,    //   <-> Quelle
                     std::string *ErrTxt, //   <-> Read-Error -bei Errtxt-
                     int         *iRet)   //   <-> Ziel
{
  std::string LocInt;
  unsigned long TLen;

  int istat;
//.............................................................................
  if (Key != 0) return -1;
  istat = 0;

  istat = sstStr011_Zeile2Str ( 0, Von, Bis, txt, ErrTxt, &LocInt);

  TLen = LocInt.length();
  if(TLen <= 0)
  {
    *iRet = 0;
    return -1;
  }

  // String direkt in Int2 konvertieren
  istat = sstStr011i_Txt2Int ( Key, &LocInt, iRet);

  if(istat < 0)
  {
    *iRet = 0;
    // LocInt.Txt[11] = '\0';
    // strcpy ( ErrTxt->Txt, LocInt.Txt);  // wo lag das Problem, zurück für Protokoll
    *ErrTxt = LocInt;  // wo lag das Problem, zurück für Protokoll
    return -1;
  }
  return istat;
}
//=============================================================================
int sstStr011_Zeile2Int4 ( int          Key,    // v  -> Vorerst immer 0
                      unsigned long         Von,    // v  -> von Textposition
                      unsigned long         Bis,    // v  -> bis Textposition
                      std::string *txt,    //   <-> Quelle
                      std::string *ErrTxt, //   <-> Read-Error -bei Errtxt-
                      long        *lRet)   //   <-> Ziel
{
  std::string LocInt;
  unsigned long TLen;

  int istat;
//.............................................................................
  if (Key != 0) return -1;
  istat = 0;

  istat = sstStr011_Zeile2Str ( 0, Von, Bis, txt, ErrTxt, &LocInt);

  TLen = LocInt.length();
  if(TLen <= 0)
  {
    *lRet = 0;
    return -1;
  }

  // String direkt in Int4 konvertieren
  istat = sstStr011i_Txt2Int4 ( Key, &LocInt, lRet);

  if(istat < 0)
  {
    *lRet = 0;
    // LocInt.Txt[11] = '\0';
    // strcpy ( ErrTxt->Txt, LocInt.Txt);  // wo lag das Problem, zurück für Protokoll
    *ErrTxt = LocInt;  // wo lag das Problem, zurück für Protokoll
    return -1;
  }
  return istat;
}
//=============================================================================
int sstStr011_Zeile2Dbl ( int          Key,    // v  -> Vorerst immer 0
                     unsigned long         Von,    // v  -> von Textposition
                     unsigned long         Bis,    // v  -> bis Textposition
                     std::string *txt,    //   <-> Quelle
                     std::string *ErrTxt, //   <-> Read-Error -bei Errtxt-
                     double      *dRet)   //   <-> Ziel
{
  std::string LocDbl;
  // char *enz;

  unsigned long TLen;  // Text-Länge in LocDbl
  int istat;
//.............................................................................
  if (Key != 0) return -1;
  istat = 0;

  // enz = NULL;  // Zeiger auf Read-Error

  istat = sstStr011_Zeile2Str ( 0, Von, Bis, txt, ErrTxt, &LocDbl);

  TLen = LocDbl.length();
  if ( TLen <= 0)
  {
    // String leer, keine Umformung möglich
    *dRet = 0.0;  // Return-Wert zurücksetzen
    return -1;
  }

  // String direkt in Double konvertieren
  istat = sstStr011i_Txt2Dbl ( 0, &LocDbl, dRet);

  if (istat < 0)
  {
    *dRet = 0.0;
    // LocDbl.Txt[11] = '\0';
    // strcpy ( ErrTxt->Txt, LocDbl.Txt);  // wo lag das Problem, zurück für Protokoll
    *ErrTxt = LocDbl;  // wo lag das Problem, zurück für Protokoll
    return -1;
  }

  return istat;
}
//=============================================================================
int sstStr011_Str2Zeile ( int          Key,     // v  -> 0 oder 1
                     unsigned long         Von,     // v  -> von Textposition im Zielstring
                     unsigned long         Bis,     // v  -> bis Textposition im Zielstring
                     std::string *sWert,   //   <-> Quelle
                     std::string *Zeile)   //   <-> Ziel
//-----------------------------------------------------------------------------
{
  unsigned long sWertBis;   // Länge sWert
  unsigned long sWertVon;   // Infomation in sWert beginnt bei Position sWertVon

  unsigned long sWertLen;   // Netto-Länge des Einfügetextes -sWert-
  unsigned long IZeilLen;   // Länge des angemeldeten Einfüge-Platzes in Zeile
  unsigned long LenDiff;    // Differenz Bedarf und Angebot
  char TrnZ[2];    // Trennzeichen

  unsigned long AktZeilLen; // Aktuelle Länge des Zielstrings

  sstStr01IntCls oFmtInfo;

  unsigned long ii;
  unsigned long jj;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if (Key != 0 && Key != 1) return -1;

  strcpy(TrnZ," ");     // kein Trennzeichen

  // Eingangsparameter auswerten: Teil 1
  if ( Bis > dSSTSTR01_TEXTLEN) return -1;       // Platzbedarf in -Zeile- zu groß
  if ( Von > Bis) return -1;           // Parameter unlogisch

  AktZeilLen = Zeile->length();          // Aktuelle Länge des Zielstrings
  if(AktZeilLen > dSSTSTR01_TEXTLEN) return -1;  // Zielstring ist länger als erlaubt

  // Beginn und Ende der Information im Eingabe-String feststellen
  sWertBis = sWert->length();
  sWertVon = sstStr011i_StartOfInfo ( 0, 1, TrnZ, sWert);
  if (sWertVon <= 0) return -1;

  // Speicherbedarf auswerten
  IZeilLen = Bis      - Von      +1;      // Platzangebot in Zeile
  sWertLen = sWertBis - sWertVon +1;      // Länge des Einfügestrings
  LenDiff  = IZeilLen - sWertLen;         // Differenz Angebot/Bedarf

  // Eingangsparameter auswerten: Teil 2
  // if( LenDiff < 0) return -1;    // zu wenig Einfügeplatz

  // Wenn aktuelle Zeile kürzer als Einfügeposition
  if (AktZeilLen < Bis)
  {
    for( ii = AktZeilLen; ii <= Bis-1; ii++)
    {
      *Zeile = *Zeile + " ";  // Blanks !!
      // *Zeile = *Zeile + " ";  // Blanks !!
    }
    // Zeile->Txt[ii-1] = '\0';  // Information abschließen
  }

  // Einfüge-Start in Zeile feststellen
  if(Key == 0)
  {
    // linksbündig
    jj = Von;
  }
  else
  {
    // rechtsbündig
    jj = Von + LenDiff;  // Text kürzer als Platzhalter ?
  }

  // Zeile->replace(sWertVon-1,sWertLen, *sWert);
  Zeile->replace(jj-1,sWertLen, *sWert);

  // Text übertragen
//  for( ii = sWertVon; ii<=sWertBis; ii++)
//  {
//    // if ( sWert->Txt[ii-1] != '\0')  // Blanks im einzufügenden String sollen erlaubt sein ?!
//    // {
//      // Zeile->Txt[jj-1] = sWert->Txt[ii-1];
//      // *Zeile = *Zeile + sWert->at(ii-1);
//      jj = jj +1;
//      if (jj > Bis) break;  // Ende von -Zeile- erreicht
////    }
////    else
////    {
////      break;  // keine weitere Information
////    }
//  }

  // Zeile->AktLen = Zeile->length();

  // Remove ending spaces from string
  iStat = sstStr011i_RemoveEndingSpaces ( 0, &oFmtInfo, Zeile);


  return iStat;
}
//=============================================================================
int sstStr011_Char2Zeile ( int          iKey,    // v  -> 0 oder 1
                      unsigned long         Von,     // v  -> von Textposition im Zielstring
                      unsigned long         Bis,     // v  -> bis Textposition im Zielstring
                      char        *cWert,   //   <-> Quelle
                      std::string *Zeile)   //   <-> Ziel
//-----------------------------------------------------------------------------
{
  std::string sWert;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if (iKey != 0 && iKey != 1) return -1;

  // String in String-Struktur kopieren.
  iStat = sstStr011_StrSet ( 0, cWert, &sWert, strlen(cWert));
  if (iStat < 0) return -2;

  // Kopieren eines String in einen Zeilenbereich.
  iStat = sstStr011_Str2Zeile ( 0, Von, Bis, &sWert, Zeile);

  return iStat;
}
//=============================================================================
int sstStr011_Int2Zeile ( int          Key,     // v  -> 0 oder 1
                     unsigned long         Von,     // v  -> von Textposition
                     unsigned long         Bis,     // v  -> bis Textposition
                     int          iWert,   //   <-> Quelle
                     std::string *Zeile)   //   <-> Ziel (initialisiert!)
//-----------------------------------------------------------------------------
{
  std::string LocStr;
  // char *StrAdr;
  char TrnZ[2];    // String of no Information
  char cLocChar[5];  // local char for formatting
  unsigned long Pos1;
  // long Pos2;
  int  iStat=0;
//-----------------------------------------------------------------------------
  if (Key != 0 && Key != 1) return -1;

  strcpy(TrnZ," ");     // Blank is no Information

  // Init LocStr-Structure
  iStat = sstStr011_Init ( 0, &LocStr);

  // StrAdr = LocStr.Txt;
  // StrAdr = itoa( iWert, LocStr.Txt, 10);  // Fehlerbehandlung ??
  sprintf(cLocChar,"%d",iWert);
  LocStr = cLocChar;
  // LocStr.AktLen = strlen(LocStr.Txt);

  // Hier wäre auch sprintf möglich
  //  sprintf ( LocStr,"%02i", Num);      // zweistellig, linksbündig, mit Nullen auffüllen

  iStat = sstStr011_Str2Zeile ( Key, Von, Bis, &LocStr, Zeile);

  // Abschließende Spaces in String löschen
  // Ende der Information in einem String rückwärts suchen
  Pos1 = Zeile->length();
  sstStr011i_EndOfInfo ( 1, Pos1, TrnZ, Zeile);
  // Zeile->Txt[Pos2] = '\0';
  // Zeile->AktLen = strlen(Zeile->Txt);

  return iStat;
}
//=============================================================================
int sstStr011_UInt2Zeile ( int          Key,     // v  -> 0 oder 1
                     unsigned long          Von,     // v  -> von Textposition
                     unsigned long          Bis,     // v  -> bis Textposition
                     unsigned int  uiWert,   //   <-> Quelle
                     std::string  *Zeile)   //   <-> Ziel (initialisiert!)
//-----------------------------------------------------------------------------
{
  std::string LocStr;
  // char *StrAdr;
  char TrnZ[2];    // String of no Information
  char cLocChar[50];
  unsigned long Pos1;
  // long Pos2;
  int  iStat=0;
//-----------------------------------------------------------------------------
  if (Key != 0 && Key != 1) return -1;

  strcpy(TrnZ," ");     // Blank is no Information

  // Init LocStr-Structure
  iStat = sstStr011_Init ( 0, &LocStr);

  // StrAdr = LocStr.Txt;
  // StrAdr = itoa( uiWert, LocStr.Txt, 10);  // Fehlerbehandlung ??
  sprintf(cLocChar,"%d",uiWert);
  LocStr = cLocChar;
  // LocStr.AktLen = strlen(LocStr.Txt);

  // Hier wäre auch sprintf möglich
  //  sprintf ( LocStr,"%02i", Num);      // zweistellig, linksbündig, mit Nullen auffüllen

  iStat = sstStr011_Str2Zeile ( Key, Von, Bis, &LocStr, Zeile);

  // Abschließende Spaces in String löschen
  // Ende der Information in einem String rückwärts suchen
  Pos1 = Zeile->length();
  sstStr011i_EndOfInfo ( 1, Pos1, TrnZ, Zeile);
  // Zeile->Txt[Pos2] = '\0';
  // Zeile->AktLen = strlen(Zeile->Txt);

  return iStat;
}
//=============================================================================
int sstStr011_Int2ZeileFmt ( int          iKey,    // v  -> 0 oder 1
                        unsigned long         Von,     // v  -> von Textposition
                        unsigned long         Bis,     // v  -> bis Textposition
                        int          iWert,   //   <-> Quelle
                        char        *cFmtStr,
                        std::string *Zeile)   //   <-> Ziel (initialisiert!)
//-----------------------------------------------------------------------------
{
  std::string LocStr;
  // char *StrAdr;
  char TrnZ[2];    // String of no Information
  char cLocChar[50];
  unsigned long Pos1;
  //long Pos2;
  int  iStat=0;
//-----------------------------------------------------------------------------
  if (iKey != 0 && iKey != 1) return -1;

  strcpy(TrnZ," ");     // Blank is no Information

  // Init LocStr-Structure
  iStat = sstStr011_Init ( 0, &LocStr);

  // StrAdr = LocStr.Txt;
  // StrAdr = itoa( iWert, LocStr.Txt, 10);  // Fehlerbehandlung ??
  // LocStr.AktLen = strlen(LocStr.Txt);

  // Hier wäre auch sprintf möglich
  sprintf ( cLocChar,cFmtStr, iWert);      // zweistellig, linksbündig, mit Nullen auffüllen
  LocStr = cLocChar;     // zweistellig, linksbündig, mit Nullen auffüllen
  // LocStr.AktLen = strlen(LocStr.Txt);

  iStat = sstStr011_Str2Zeile ( iKey, Von, Bis, &LocStr, Zeile);

  // Abschließende Spaces in String löschen
  // Ende der Information in einem String rückwärts suchen
  Pos1 = Zeile->length();
  sstStr011i_EndOfInfo ( 1, Pos1, TrnZ, Zeile);
  // Zeile->Txt[Pos2] = '\0';
  // Zeile->AktLen = strlen(Zeile->Txt);

  return iStat;
}
//=============================================================================
int sstStr011_Int4Zeile ( int          Key,     // v  -> 0 oder 1
                     unsigned long         Von,     // v  -> von Textposition
                     unsigned long         Bis,     // v  -> bis Textposition
                     long         lWert,   //   <-> Quelle
                     std::string *Zeile)   //   <-> Ziel
//-----------------------------------------------------------------------------
{
  std::string LocStr;
  // char *StrAdr;
  char TrnZ[2];    // String of no Information
  char cLocChar[50];
  unsigned long Pos1;
  // long Pos2;

  int iStat=0;
//.............................................................................
  if (Key != 0 && Key != 1) return -1;

  strcpy(TrnZ," ");     // Blank is no Information

  // Init LocStr-Structure
  iStat = sstStr011_Init ( 0, &LocStr);

  // StrAdr = LocStr.Txt;
  // StrAdr = ltoa(  lWert, LocStr.Txt, 10);  // Fehlerbehandlung ??
  // snprintf(cLocChar,dSSTSTR01_TEXTLEN,"%lu",lWert);
  snprintf(cLocChar,dSSTSTR01_TEXTLEN,"%ld",lWert);
  LocStr = cLocChar;
  // LocStr.AktLen = strlen(LocStr.Txt);

  iStat = sstStr011_Str2Zeile ( Key, Von, Bis, &LocStr, Zeile);

  // Abschließende Spaces in String löschen
  // Ende der Information in einem String rückwärts suchen
  Pos1 = Zeile->length();
  sstStr011i_EndOfInfo ( 1, Pos1, TrnZ, Zeile);
  // Zeile->Txt[Pos2] = '\0';
  // Zeile->AktLen = strlen(Zeile->Txt);

  return iStat;
}
//=============================================================================
int sstStr011_UInt4Zeile ( int             Key,     // v  -> 0 oder 1
                      unsigned long            Von,     // v  -> von Textposition
                      unsigned long            Bis,     // v  -> bis Textposition
                      unsigned long   ulWert,   //   <-> Quelle
                      std::string    *Zeile)   //   <-> Ziel

//-----------------------------------------------------------------------------
{
  std::string LocStr;
  // char *StrAdr;
  char TrnZ[2];    // String of no Information
  char cLocChar[50];
  unsigned long Pos1;
  // long Pos2;

  int iStat=0;
//.............................................................................
  if (Key != 0 && Key != 1) return -1;

  strcpy(TrnZ," ");     // Blank is no Information

  // Init LocStr-Structure
  iStat = sstStr011_Init ( 0, &LocStr);

  // StrAdr = LocStr.Txt;
  // StrAdr = ltoa(  ulWert, LocStr.Txt, 10);  // Fehlerbehandlung ??
  snprintf(cLocChar,dSSTSTR01_TEXTLEN,"%lu",ulWert);
  LocStr = cLocChar;
  // LocStr.AktLen = strlen(LocStr.Txt);

  iStat = sstStr011_Str2Zeile ( Key, Von, Bis, &LocStr, Zeile);

  // Abschließende Spaces in String löschen
  // Ende der Information in einem String rückwärts suchen
  Pos1 = Zeile->length();
  sstStr011i_EndOfInfo ( 1, Pos1, TrnZ, Zeile);
  // Zeile->Txt[Pos2] = '\0';
  // Zeile->AktLen = strlen(Zeile->Txt);

  return iStat;
}
//=============================================================================
int sstStr011_Real2ZeileFmt ( int          iKey,
                         unsigned long         Von,
                         unsigned long         Bis,
                         float        fWert,
                         char        *cFmtStr,
                         std::string *Zeile)
//-----------------------------------------------------------------------------
{
  // char Buffer[10];
  // char Format[8];
  std::string LocStr;

  char TrnZ[2];    // String of no Information
  char cLocChar[50];
  unsigned long Pos1;
  // long Pos2;

  // char *pLocStr;

  int iStat;
//.............................................................................
  // if (iKey != 0 && iKey != 1) return -1;
  if (iKey < 0 || iKey > 3) return -1;
  iStat = 0;

  if (isnan(fWert)== true)
  {
    Zeile->clear();
    return 0;
  }

  // Init LocStr-Structure
  iStat = sstStr011_Init ( 0, &LocStr);

  // -gcvt- funktioniert nicht so besonders, da Nullstellen nicht aufgefüllt
  // werden. -sprintf- ist besser, aber Format-String wäre variabel zu
  // programmieren.

  // Format-Anweisung zusammenstellen
  // strcpy(Format,"%# 07.");
  // strcat(Format, itoa( NachKo, Buffer, 10) );
  // strcat(Format,"f");

  // Convert Float to string with format string
  sprintf( cLocChar, cFmtStr, fWert);
  LocStr = cLocChar;

  //Remove starting and ending spaces from string
  // iStat = sstStr01i_RemoveSpaces ( 0, LocStr.Txt);
  iStat = sstStr01i_RemoveSpaces ( 0, &LocStr);
  // LocStr.AktLen = strlen(LocStr.Txt);

  // iStat = sstStr011_Str2Zeile ( iKey, Von, Bis, &LocStr, Zeile, ZeilLen);

  if (iKey == 2 || iKey == 3)
  {
    // pLocStr = strchr(LocStr.Txt,'.');  // Zeichen Punkt in String suchen
    unsigned long ulPos = LocStr.find(".");  // Zeichen Punkt in String suchen
    LocStr.replace(ulPos,1,",");  // Zeichen Punkt in String suchen
    // pLocStr[0] = ',';
  }

  if (iKey == 0 || iKey == 2)
    iStat = sstStr011_Str2Zeile ( 0, Von, Bis, &LocStr, Zeile);
  else
    iStat = sstStr011_Str2Zeile ( 1, Von, Bis, &LocStr, Zeile);

  // Abschließende Spaces in String löschen
  // Ende der Information in einem String rückwärts suchen
  strcpy(TrnZ," ");     // Blank is no Information

  Pos1 = Zeile->length();
  sstStr011i_EndOfInfo ( 1, Pos1, TrnZ, Zeile);
  // Zeile->Txt[Pos2] = '\0';
  // Zeile->AktLen = strlen(Zeile->Txt);

  return iStat;

}
//=============================================================================
int sstStr011_Real2Zeile ( int          iKey,    // v  -> 0 oder 1
                      unsigned long         Von,     // v  -> von Textposition
                      unsigned long         Bis,     // v  -> bis Textposition
                      float        fWert,   //   <-> Quelle
                      int          NachKo,  // v  -> Nachkomma
                      std::string *Zeile)   //   <-> Ziel
//-----------------------------------------------------------------------------
{
  // char Buffer[10];
  char Format[8];
  std::string LocStr;

  char TrnZ[2];    // String of no Information
  char cLocChar[50];
  unsigned long Pos1;
  // long Pos2;

  // char *pLocStr;

  int iStat;
//.............................................................................
  // if (iKey != 0 && iKey != 1) return -1;
  if (iKey < 0 || iKey > 3) return -1;
  iStat = 0;

  if (isnan(fWert)== true)
  {
    Zeile->clear();
    return 0;
  }

  // Init LocStr-Structure
  iStat = sstStr011_Init ( 0, &LocStr);
  // sprintf(LocStr.Txt, "%d", NachKo);
  sprintf(cLocChar, "%d", NachKo);
  LocStr = cLocChar;

  // -gcvt- funktioniert nicht so besonders, da Nullstellen nicht aufgefüllt
  // werden. -sprintf- ist besser, aber Format-String wäre variabel zu
  // programmieren.

  // Format-Anweisung zusammenstellen
  strncpy(Format,"%6.",8);
  // strcat(Format, itoa( NachKo, Buffer, 10) );
  strncat(Format, LocStr.c_str(),8);
  strncat(Format,"lf",8);

  // Convert Float to string with format string
  iStat = sstStr011_Init ( 0, &LocStr);
  // sprintf(LocStr.Txt, Format, fWert);
  sprintf(cLocChar, Format, fWert);
  LocStr = cLocChar;

  //Remove starting and ending spaces from string
  iStat = sstStr01i_RemoveSpaces ( 0, &LocStr);
  // LocStr.AktLen = strlen(LocStr.Txt);

  // iStat = sstStr011_Str2Zeile ( iKey, Von, Bis, &LocStr, Zeile, ZeilLen);

  if (iKey == 2 || iKey == 3)
  {
    // pLocStr = strchr(LocStr.Txt,'.');  // Zeichen Punkt in String suchen
    unsigned long ulPos = LocStr.find(".");  // Zeichen Punkt in String suchen
    // pLocStr[0] = ',';
    LocStr.replace(ulPos,1,",");
  }

  if (iKey == 0 || iKey == 2)
    iStat = sstStr011_Str2Zeile ( 0, Von, Bis, &LocStr, Zeile);
  else
    iStat = sstStr011_Str2Zeile ( 1, Von, Bis, &LocStr, Zeile);

  // Abschließende Spaces in String löschen
  // Ende der Information in einem String rückwärts suchen
  strcpy(TrnZ," ");     // Blank is no Information

  Pos1 = Zeile->length();
  sstStr011i_EndOfInfo ( 1, Pos1, TrnZ, Zeile);
  // Zeile->Txt[Pos2] = '\0';
  // eile->AktLen = strlen(Zeile->Txt);

  return iStat;

}
//=============================================================================
int sstStr011_Dbl2ZeileFmt ( int          iKey,    // v  -> 0 oder 1
                        unsigned long         Von,     // v  -> von Textposition
                        unsigned long         Bis,     // v  -> bis Textposition
                        double       dWert,   //   <-> Quelle
                        char        *cFmtStr,
                        std::string *Zeile)   //   <-> Ziel
//-----------------------------------------------------------------------------
{
  // char Buffer[10];
  // char Buffer[11];
  // char Format[8];
  std::string LocStr;

  char TrnZ[2];    // String of no Information
  char cLocChar[50];
  unsigned long Pos1;
  // long Pos2;

  // char *pLocStr;

  int iStat;
//.............................................................................
  // if (iKey != 0 && iKey != 1) return -1;
  if (iKey < 0 || iKey > 3) return -1;
  iStat = 0;

  if (isnan(dWert)== true)
  {
    Zeile->clear();
    return 0;
  }

  // Init LocStr-Structure
  iStat = sstStr011_Init ( 0, &LocStr);

  // -gcvt- funktioniert nicht so besonders, da Nullstellen nicht aufgefüllt
  // werden. -sprintf- ist besser, aber Format-String wäre variabel zu
  // programmieren.

  // Format-Anweisung zusammenstellen
  // strcpy(Format,"%6.");
  // strcpy(Format,"%#07.");  // Führende Nullstellen > 000.12 oder -001.23
  // strcat(Format, itoa( NachKo, Buffer, 10) );
  // strcat(Format, itoa( NachKo, Buffer, 11) );
  // strcat(Format,"lf");

  // Convert double to string wiht format string
  // sprintf(LocStr.Txt, cFmtStr, dWert);
  sprintf(cLocChar, cFmtStr, dWert);
  LocStr = cLocChar;

  //Remove starting and ending spaces from string
  iStat = sstStr01i_RemoveSpaces ( 0, &LocStr);
  // LocStr.AktLen = strlen(LocStr.Txt);

  // iStat = sstStr011_Str2Zeile ( iKey, Von, Bis, &LocStr, Zeile, ZeilLen);

  if (iKey == 2 || iKey == 3)
  {
    // pLocStr = strchr(LocStr.Txt,'.');  // Zeichen Punkt in String suchen
    unsigned long ulPos = LocStr.find(".");  // Zeichen Punkt in String suchen
    // pLocStr[0] = ',';
    LocStr.replace(ulPos,1,",");
  }

  if (iKey == 0 || iKey == 2)
    iStat = sstStr011_Str2Zeile ( 0, Von, Bis, &LocStr, Zeile);
  else
    iStat = sstStr011_Str2Zeile ( 1, Von, Bis, &LocStr, Zeile);

  // Abschließende Spaces in String löschen
  // Ende der Information in einem String rückwärts suchen
  strcpy(TrnZ," ");     // Blank is no Information

  Pos1 = Zeile->length();
  sstStr011i_EndOfInfo ( 1, Pos1, TrnZ, Zeile);
  // Zeile->Txt[Pos2] = '\0';
  // Zeile->AktLen = strlen(Zeile->Txt);

  return iStat;

}
//=============================================================================
int sstStr011_Dbl2ZeileWnk ( int          iKey,    // v  -> 0 oder 1
                        unsigned long         Von,     // v  -> von Textposition
                        unsigned long         Bis,     // v  -> bis Textposition
                        double       dWert,   //   <-> Quelle
                        int          NachKo,  // v  -> Nachkomma
                        std::string *Zeile)   //   <-> Ziel
//-----------------------------------------------------------------------------
{
  // char Buffer[10];
  // char Buffer[11];
  char Format[8];
  std::string LocStr;

  char TrnZ[2];    // String of no Information
  char cLocChar[50];
  unsigned long Pos1;
  // long Pos2;

  // char *pLocStr;

  int iStat;
//.............................................................................
  // if (iKey != 0 && iKey != 1) return -1;
  if (iKey < 0 || iKey > 3) return -1;
  iStat = 0;

  if (isnan(dWert)== true)
  {
    Zeile->clear();
    return 0;
  }

  // Init LocStr-Structure
  iStat = sstStr011_Init ( 0, &LocStr);
  // sprintf(LocStr.Txt, "%d", NachKo);
  sprintf(cLocChar, "%d", NachKo);
  LocStr = cLocChar;

  // -gcvt- funktioniert nicht so besonders, da Nullstellen nicht aufgefüllt
  // werden. -sprintf- ist besser, aber Format-String wäre variabel zu
  // programmieren.

  // Format-Anweisung zusammenstellen
  // strcpy(Format,"%6.");
  strncpy(Format,"%#07.",8);  // Führende Nullstellen > 000.12 oder -001.23
  // strcat(Format, itoa( NachKo, Buffer, 10) );
  strncat(Format, LocStr.c_str(),8);
  // strcat(Format, itoa( NachKo, Buffer, 11) );
  strncat(Format,"lf",8);

  // Convert double to string wiht format string
  iStat = sstStr011_Init ( 0, &LocStr);
  // sprintf(LocStr.Txt, Format, dWert);
  sprintf(cLocChar, Format, dWert);
  LocStr = cLocChar;

  //Remove starting and ending spaces from string
  iStat = sstStr01i_RemoveSpaces ( 0, &LocStr);
  // LocStr.AktLen = strlen(LocStr.Txt);

  // iStat = sstStr011_Str2Zeile ( iKey, Von, Bis, &LocStr, Zeile, ZeilLen);

  if (iKey == 2 || iKey == 3)
  {
    // pLocStr = strchr(LocStr.Txt,'.');  // Zeichen Punkt in String suchen
    unsigned long ulPos = LocStr.find(".");  // Zeichen Punkt in String suchen
    // pLocStr[0] = ',';
    LocStr.replace(ulPos,1,",");
  }

  if (iKey == 0 || iKey == 2)
    iStat = sstStr011_Str2Zeile ( 0, Von, Bis, &LocStr, Zeile);
  else
    iStat = sstStr011_Str2Zeile ( 1, Von, Bis, &LocStr, Zeile);

  // Abschließende Spaces in String löschen
  // Ende der Information in einem String rückwärts suchen
  strcpy(TrnZ," ");     // Blank is no Information

  Pos1 = Zeile->length();
  sstStr011i_EndOfInfo ( 1, Pos1, TrnZ, Zeile);
  // Zeile->Txt[Pos2] = '\0';
  // Zeile->AktLen = strlen(Zeile->Txt);

  return iStat;

}
//=============================================================================
int sstStr011_Dbl2Zeile ( int            iKey,    // v  -> 0 oder 1
                          unsigned long  Von,     // v  -> von Textposition
                          unsigned long  Bis,     // v  -> bis Textposition
                          double         dWert,   //   <-> Quelle
                          int            NachKo,  // v  -> Nachkomma
                          std::string   *Zeile)   //   <-> Ziel
//-----------------------------------------------------------------------------
{
  char Format[8];
  std::string LocStr;

  char TrnZ[2];    // String of no Information
  char cLocChar[50];
  unsigned long Pos1;

  int iStat;
//.............................................................................
  if (iKey < 0 || iKey > 3) return -1;
  iStat = 0;

  if (isnan(dWert)== true)
  {
    Zeile->clear();
    return 0;
  }

  // Init LocStr-Structure
  iStat = sstStr011_Init ( 0, &LocStr);
  sprintf(cLocChar, "%d", NachKo);
  LocStr = cLocChar;

  // -gcvt- funktioniert nicht so besonders, da Nullstellen nicht aufgefüllt
  // werden. -sprintf- ist besser, aber Format-String wäre variabel zu
  // programmieren.

  // Format-Anweisung zusammenstellen
  strncpy(Format,"%7.",8);
  strncat(Format, LocStr.c_str(),8);
  strncat(Format,"lf",8);

  // Convert double to string with format string
  iStat = sstStr011_Init ( 0, &LocStr);
  sprintf(cLocChar, Format, dWert);
  LocStr = cLocChar;

  //Remove starting and ending spaces from string
  iStat = sstStr01i_RemoveSpaces ( 0, &LocStr);

  if (iKey == 2 || iKey == 3)
  {
    unsigned long ulPos = LocStr.find(".");  // Zeichen Punkt in String suchen
    LocStr.replace(ulPos,1,",");
  }

  if (iKey == 0 || iKey == 2)
    iStat = sstStr011_Str2Zeile ( 0, Von, Bis, &LocStr, Zeile);
  else
    iStat = sstStr011_Str2Zeile ( 1, Von, Bis, &LocStr, Zeile);

  // Abschließende Spaces in String löschen
  // Ende der Information in einem String rückwärts suchen
  strcpy(TrnZ," ");     // Blank is no Information

  Pos1 = Zeile->length();
  sstStr011i_EndOfInfo ( 1, Pos1, TrnZ, Zeile);

  return iStat;

}
//=============================================================================
int sstStr011_Bool2Zeile ( int          iKey,
                      long         iStrTyp,
                      unsigned long         lVon,
                      unsigned long         lBis,
                      bool        *bVal,
                      std::string *Zeile)
//-----------------------------------------------------------------------------
{
  // iStrTyp = 0: .F.  .T.
  // iStrTyp = 1: F T
  // iStrTyp = 2: 0 1
  std::string sWert;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if (iKey != 0 && iKey != 1) return -1;
  if (iStrTyp < 0 || iStrTyp > 2) return -2;

  if (*bVal)

    switch (iStrTyp)
    {
    case 0: sstStr011Cpy( 0, &sWert, (char*)"1");break;
    case 1: sstStr011Cpy( 0, &sWert, (char*)"T");break;
    case 2: sstStr011Cpy( 0, &sWert, (char*)".T.");break;
    default: sstStr011Cpy( 0, &sWert, (char*)""); break;
    }

    // iStat = sstStr011Cpy( 0, &sWert, (char*)".T.");
  else
  {
    switch (iStrTyp)
    {
    case 0: sstStr011Cpy( 0, &sWert, (char*)"0");break;
    case 1: sstStr011Cpy( 0, &sWert, (char*)"F");break;
    case 2: sstStr011Cpy( 0, &sWert, (char*)".F.");break;
    default: sstStr011Cpy( 0, &sWert, (char*)""); break;
    }
  }
    // iStat = sstStr011Cpy( 0, &sWert, (char*)".F.");

  // Kopieren eines String in einen Zeilenbereich.
  iStat = sstStr011_Str2Zeile ( iKey, lVon, lBis, &sWert, Zeile);

  return iStat;
}
//=============================================================================
int sstStr011_AbPos2Str ( int          Key,    // v  -> Vorerst immer 0
                     unsigned long        *Pos,    //   <-> Read from position in string
                     char        *TrnZ,   //   <-> Lesen bis Trennzeichen
                     std::string *Zeile,  //   <-> Lese-String
                     std::string *ErrTxt, //   <-> Read-Error -bei Errtxt-
                     std::string *tRet)   //   <-> Result-String
//.............................................................................
{
  // long LenT1;  // Länge Zeile

  unsigned long StartPos;
  unsigned long EndPos;

  int istat;
//.............................................................................
  if (Key != 0) return -1;
  istat = 0;
  // LenT1 = Zeile->length();  // Länge von Text 1

  // Look for Start of Information
  // StartPos = sstStr011i_StartOfInfo ( 0, (*Pos+1), TrnZ, Zeile);
  StartPos = sstStr011i_StartOfInfo2 ( 0, *Pos, TrnZ, Zeile);
  if (StartPos <= 0) return -1;

  // Ende der Information in einem String feststellen
  // EndPos = sstStr011i_EndOfInfo ( 0, StartPos, TrnZ, Zeile);
  EndPos = sstStr011i_EndOfInfo2 ( 0, StartPos, TrnZ, Zeile);
  if ( EndPos <= 0) return -1;

  // Teil von String1 nach String2 kopieren
  istat = sstStr011_Zeile2Str ( 0, StartPos, EndPos, Zeile, ErrTxt, tRet);
  if ( istat != 0) return -1;

  // If String length is zero, StartPos is greater than EndPos
  if(StartPos > EndPos) *Pos = StartPos;
    else *Pos = EndPos+1;
  // else *Pos = EndPos+2;  // TrnZ is already interpreted

  return istat;
}
//=============================================================================
int sstStr011_AbPos2Char ( int          Key,    // v  -> Vorerst immer 0
                      unsigned long        *TPos,    //   <-> Read from position in string
                      char        *TrnZ,   //   <-> Lesen bis Trennzeichen
                      std::string *Zeile,  //   <-> Lese-String
                      std::string *ErrTxt, //   <-> Read-Error -bei Errtxt-
                      char        *cRet,   //   <-> Result-String
                      int          iCRetLen)
//-----------------------------------------------------------------------------
{
  std::string tRet;

  int iStat = 0;
//.............................................................................
  if (Key != 0) return -1;

  // Nächste Information aus Text-Zeile in String umwandeln.
  iStat = sstStr011_AbPos2Str ( 0, TPos, TrnZ, Zeile, ErrTxt, &tRet);

  strncpy(cRet,tRet.c_str(),iCRetLen);

  return iStat;
}
//=============================================================================
int sstStr011_AbPos2Int ( int          Key,    // v  -> Vorerst immer 0
                     unsigned long        *TPos,   //   <-> Read from position in string
                     char        *TrnZ,   //   <-> Lesen bis Trennzeichen
                     std::string *Zeile,  //   <-> Lese-String
                     std::string *ErrTxt, //   <-> Read-Error -bei Errtxt-
                     int         *iRet)   //   <-> Result-Int2
//.............................................................................
{
  std::string tRet;   // String mit ZwischenResult
  long  LenT;       // Textlänge des ZwischenResult

  int istat;
//.............................................................................
  if (Key != 0) return -1;
  istat = 0;

  // nächste Information in Zeile ab TPos bis TrennZeichen nach tRet kopieren
  istat = sstStr011_AbPos2Str ( 0, TPos, TrnZ, Zeile, ErrTxt, &tRet);
  if( istat != 0)
  {
    return -1;
  }

  LenT = tRet.length();
  if(LenT <= 0)
  {
    *iRet = 0;
    return -1;
  }

  // String direkt in Int2 konvertieren
  istat = sstStr011i_Txt2Int ( 0, &tRet, iRet);

  if(istat < 0)
  {
    *iRet = 0;
    // tRet.Txt[11] = '\0';        // String kürzen
    *ErrTxt = tRet;    // wo lag das Problem, zurück für Protokoll
    return -1;
  }
  return istat;
}
//=============================================================================
int sstStr011_AbPos2UInt ( int             Key,    // v  -> Vorerst immer 0
                      unsigned long           *TPos,   //   <-> Read from position in string
                      char           *TrnZ,   //   <-> Lesen bis Trennzeichen
                      std::string    *Zeile,  //   <-> Lese-String
                      std::string    *ErrTxt, //   <-> Read-Error -bei Errtxt-
                      unsigned int   *uiRet)   //   <-> Result-Int2
//.............................................................................
{
  std::string tRet;   // String mit ZwischenResult
  unsigned long  LenT;       // Textlänge des ZwischenResult

  int istat;
//.............................................................................
  if (Key != 0) return -1;
  istat = 0;

  // nächste Information in Zeile ab TPos bis TrennZeichen nach tRet kopieren
  istat = sstStr011_AbPos2Str ( 0, TPos, TrnZ, Zeile, ErrTxt, &tRet);
  if( istat != 0)
  {
    return -1;
  }

  LenT = tRet.length();
  if(LenT <= 0)
  {
    *uiRet = 0;
    return -1;
  }

  // String direkt in Int2 konvertieren
  istat = sstStr011i_Txt2UInt ( 0, &tRet, uiRet);

  if(istat < 0)
  {
    *uiRet = 0;
    // tRet.Txt[11] = '\0';        // String kürzen
    *ErrTxt = tRet;    // wo lag das Problem, zurück für Protokoll
    return -1;
  }
  return istat;
}
//=============================================================================
int sstStr011_AbPos2Int4 ( int          iKey,    // v  -> For the moment 0
                      unsigned long        *TPos,    //   <-> Read from position in string
                      char        *TrnZ,    //   <-> Lesen bis Trennzeichen
                      std::string *Zeile,   //   <-> Lese-String
                      std::string *ErrTxt,  //   <-> Read-Error -bei Errtxt-
                      long        *iRet4)   //   <-> Result-Int4
//-----------------------------------------------------------------------------
{
  std::string tRet;   // String mit ZwischenResult
  unsigned long  LenT;       // Textlänge des ZwischenResult

  int iRet;
  int iStat;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  iRet = 0;
  iStat = 0;

  // nächste Information in Zeile ab TPos bis TrennZeichen nach tRet kopieren
  iStat = sstStr011_AbPos2Str ( 0, TPos, TrnZ, Zeile, ErrTxt, &tRet);
  if( iStat != 0)
  {
    return -1;
  }

  LenT = tRet.length();
  if(LenT <= 0)
  {
    *iRet4 = 0;
    return -1;
  }

  // String direkt in Int2 konvertieren
  iStat = sstStr011i_Txt2Int4 ( 0, &tRet, iRet4);

  if(iStat < 0)
  {
    *iRet4 = 0;
    // tRet.Txt[11] = '\0';        // String kürzen
    *ErrTxt = tRet;    // wo lag das Problem, zurück für Protokoll
    return -1;
  }

  // Heavy Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert("Error in function: xxx");
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstStr011_AbPos2UInt4 ( int             iKey,
                       unsigned long           *TPos,
                       char           *TrnZ,
                       std::string    *Zeile,
                       std::string    *ErrTxt,
                       unsigned long  *uiRet4)
//-----------------------------------------------------------------------------
{
  std::string tRet;   // String mit ZwischenResult
  unsigned long  LenT;       // Textlänge des ZwischenResult

  int iRet;
  int iStat;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  iRet = 0;
  iStat = 0;

  // nächste Information in Zeile ab TPos bis TrennZeichen nach tRet kopieren
  iStat = sstStr011_AbPos2Str ( 0, TPos, TrnZ, Zeile, ErrTxt, &tRet);
  if( iStat != 0)
  {
    return -1;
  }

  LenT = tRet.length();
  if(LenT <= 0)
  {
    *uiRet4 = 0;
    return -1;
  }

  // String direkt in Int2 konvertieren
  iStat = sstStr011i_Txt2UInt4 ( 0, &tRet, uiRet4);

  if(iStat < 0)
  {
    *uiRet4 = 0;
    // tRet.Txt[11] = '\0';        // String kürzen
    *ErrTxt = tRet;    // wo lag das Problem, zurück für Protokoll
    return -1;
  }

  // Heavy Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert("Error in function: xxx");
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstStr011_AbPos2Real ( int          Key,    // v  -> Vorerst immer 0
                      unsigned long        *TPos,   //   <-> Read from position in string
                      char        *TrnZ,   //   <-> Lesen bis Trennzeichen
                      std::string *Zeile,  //   <-> Lese-String
                      std::string *ErrTxt, //   <-> Read-Error -bei Errtxt-
                      float       *rRet)   //   <-> Result-Real
//.............................................................................
{
  std::string tRet;   // String mit ZwischenResult
  long  LenT;       // Textlänge des ZwischenResult
  int  istat;
//.............................................................................
  if (Key != 0) return -1;
  istat = 0;

  *rRet = 0.0;

  // nächste Information in Zeile ab TPos bis TrennZeichen nach tRet kopieren
  istat = sstStr011_AbPos2Str ( 0, TPos, TrnZ, Zeile, ErrTxt, &tRet);
  if( istat != 0)
  {
    return -1;
  }

  LenT = tRet.length();
  if(LenT <= 0) return -1;

  // String direkt in Real konvertieren
  istat = sstStr011i_Txt2Real ( 0, &tRet, rRet);

  if (istat < 0)
  {
    *rRet = 0.0;
    // tRet.Txt[11] = '\0';      // Text kürzen
    *ErrTxt = tRet;  // wo lag das Problem, zurück für Protokoll
    return -1;
  }

  return istat;
}
//=============================================================================
int sstStr011_AbPos2Dbl ( int              Key,    // v  -> Vorerst immer 0
                          unsigned long   *TPos,   //   <-> Read from position in string
                          char            *TrnZ,   //   <-> Lesen bis Trennzeichen
                          std::string     *Zeile,  //   <-> Lese-String
                          std::string     *ErrTxt, //   <-> Read-Error -bei Errtxt-
                          double          *dRet)   //   <-> Result-Double
//.............................................................................
{
  std::string tRet;   // String mit ZwischenResult
  long  LenT;       // Textlänge des ZwischenResult
  int  istat;
//.............................................................................
  if (Key != 0) return -1;
  istat = 0;

  *dRet = dSSTSTR01_UNDEF_DOUBLE;

  // nächste Information in Zeile ab TPos bis TrennZeichen nach tRet kopieren
  istat = sstStr011_AbPos2Str ( 0, TPos, TrnZ, Zeile, ErrTxt, &tRet);
  // iStat = this
  if( istat != 0)
  {
    return -1;
  }

  LenT = tRet.length();
  if(LenT <= 0) return 0;

  // String direkt in Double konvertieren
  istat = sstStr011i_Txt2Dbl ( 0, &tRet, dRet);

  if (istat < 0)
  {
    *dRet = 0.0;
    // tRet.Txt[11] = '\0';      // Text kürzen
    *ErrTxt = tRet;  // wo lag das Problem, zurück für Protokoll
    return -1;
  }

  return istat;
}
//=============================================================================
int sstStr011_AbPos2Bool ( int          iKey,      /**< v  -> Vorerst immer 0         */
                      unsigned long        *TPos,      /**<   <-> Read from position in string       */
                      char        *TrnZ,      /**<   <-> Lesen bis Trennzeichen  */
                      std::string *Zeile,     /**<   <-> Lese-String             */
                      std::string *ErrTxt,    /**<   <-> Read-Error -bei Errtxt- */
                      bool        *bRet)      /**<   <-> Result-String         */
//-----------------------------------------------------------------------------
{
  std::string tRet;   // String mit ZwischenResult
  unsigned long  LenT;       // Textlänge des ZwischenResult

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // nächste Information in Zeile ab TPos bis TrennZeichen nach tRet kopieren
  iStat = sstStr011_AbPos2Str ( 0, TPos, TrnZ, Zeile, ErrTxt, &tRet);
  if( iStat != 0)
  {
    return -1;
  }

  LenT = tRet.length();
  if(LenT <= 0) return 0;

  // iKey = 0: 0/1
  // iKey = 1: F/T
  // iKey = 2: .F./.T.
  // iStat = strncmp(tRet.Txt,".T.",4);
  // iStat = strncmp(tRet.Txt,".F.",4);

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  *bRet = iRet;

  return iRet;
}
//=============================================================================
int sstStr011_AbPosS2Str ( int          iKey,
                      unsigned long        *Pos,
                      char        *BeGrzZ,
                      char        *NoInfZ,
                      std::string *Zeile,
                      std::string *ErrTxt,
                      std::string *tRet)
//-----------------------------------------------------------------------------
{
  unsigned long LenT1;  // Länge Zeile

  unsigned long BeGrzPos;  // Zweite Position der Begrenzung
  unsigned long StartPos;
  unsigned long EndPos;

  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  LenT1 = Zeile->length();  // Länge von Lese-String
  if (LenT1 <= 0) return -2;

  LenT1 = strlen(BeGrzZ);  // Länge von Lese-String
  if (LenT1 <= 0) return -3;

  // if (*Pos <= 0) return -4;
  // if (*Pos < 0) return -4;


    // Position ist Begrenzung
  // if (Zeile->Txt[*Pos-1] == BeGrzZ[0])
  if (Zeile->at(*Pos-1) == BeGrzZ[0])
  { // Übergebene Position ist Begrenzungszeichen
    if(*Pos == 1)
    {  // Position 1 ist Begrenzungszeichen
      tRet->clear();      // Result-String ist leer
      ErrTxt->clear();    // Error-String ist auch leer
        *Pos = *Pos + 1;
        return 0;
    }
    else
    { // Position ist Begrenzungszeichen, aber nicht Position 1
        StartPos = *Pos;
    }
  }
  else
  { // Position ist Information
    StartPos = *Pos -1;
  }


    // Zweite Position der Begrenzung
  BeGrzPos = sstStr011i_TrnZFind ( 0, (StartPos+1), BeGrzZ, Zeile);
  if ( BeGrzPos <= 0) return -4;

  if ( (BeGrzPos - StartPos) < 2)
  {
    tRet->clear();      // Result-String ist leer
    ErrTxt->clear();    // Error-String ist auch leer
    *Pos = BeGrzPos;      // Position ist abgearbeit
    return 0;  // Kein Fehler, aber keine Information zwischen Begrenzern
  }

  // Das Begrenzungszeichen selbst kann keine Information sein,
  // also eine Position weiter...
  StartPos = sstStr011i_StartOfInfo ( 0, (StartPos+1), NoInfZ, Zeile);
  if (StartPos <= 0) return -5;

  // Ende der Information rückwärts in einem String feststellen
  EndPos = sstStr011i_EndOfInfo ( 1, (BeGrzPos-1), NoInfZ, Zeile);
  if ( EndPos <= 0) return -5;

  // Teil von String1 nach String2 kopieren
  iStat = sstStr011_Zeile2Str ( 0, StartPos, EndPos, Zeile, ErrTxt, tRet);
  if ( iStat != 0) return -5;

  *Pos = BeGrzPos;

  return iStat;
}
//=============================================================================
int sstStr011_AbPosK2Str ( int          iKey,
                      unsigned long        *Pos,
                      char        *BeGrzZ,
                      char        *NoInfZ,
                      std::string *Zeile,
                      std::string *ErrTxt,
                      std::string *tRet)
//-----------------------------------------------------------------------------
{
  unsigned long LenT1;  // Länge Zeile

  unsigned long BeGrzPos;  // Zweite Position der Begrenzung
  unsigned long StartPos;
  unsigned long EndPos;

  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  LenT1 = Zeile->length();  // Länge von Lese-String
  if (LenT1 <= 0) return -2;

  LenT1 = strlen(BeGrzZ);  // Länge von Lese-String
  if (LenT1 <= 0) return -3;

  if (*Pos <= 0) return -4;


    // Position ist Begrenzung
  if (Zeile->at(*Pos-1) == BeGrzZ[0])
  { // Übergebene Position ist Begrenzungszeichen
    if(*Pos == 1)
    {  // Position 1 ist Begrenzungszeichen
      tRet->clear();      // Result-String ist leer
      ErrTxt->clear();    // Error-String ist auch leer
        *Pos = *Pos + 1;
        return 0;
    }
    else
    { // Position ist Begrenzungszeichen, aber nicht Position 1
        StartPos = *Pos;
    }
  }
  else
  { // Position ist Information
    StartPos = *Pos -1;
  }


    // Zweite Position der Begrenzung
  BeGrzPos = sstStr011i_TrnZFind ( 0, (StartPos+1), BeGrzZ, Zeile);
  if ( BeGrzPos <= 0) return -4;

  if ( (BeGrzPos - StartPos) < 2)
  {
    tRet->clear();      // Result-String ist leer
    ErrTxt->clear();    // Error-String ist auch leer
    *Pos = BeGrzPos;      // Position ist abgearbeit
    return 0;  // Kein Fehler, aber keine Information zwischen Begrenzern
  }

  // Das Begrenzungszeichen selbst kann keine Information sein,
  // also eine Position weiter...
  StartPos = sstStr011i_StartOfInfo ( 0, (StartPos+1), NoInfZ, Zeile);
  if (StartPos <= 0) return -5;

  // Ende der Information rückwärts in einem String feststellen
  EndPos = sstStr011i_EndOfInfo ( 1, (BeGrzPos-1), NoInfZ, Zeile);
  if ( EndPos <= 0) return -5;

  // Teil von String1 nach String2 kopieren
  iStat = sstStr011_Zeile2Str ( 0, StartPos, EndPos, Zeile, ErrTxt, tRet);
  if ( iStat != 0) return -5;

  *Pos = BeGrzPos;

  return iStat;
}
//=============================================================================
int sstStr011_AbPosK3Str ( int          iKey,
                      unsigned long        *Pos,
                      char        *TrnZ,
                      char        *KlmZ,
                      std::string *Zeile,
                      std::string *ErrTxt,
                      std::string *tRet)
//-----------------------------------------------------------------------------
{
  unsigned long LenT1;  // Länge Zeile

  unsigned long BeGrzPos;  // Zweite Position der Begrenzung
  unsigned long StartPos;
  unsigned long EndPos;

  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  if (*Pos <= 0) return -4;

  LenT1 = Zeile->length();  // Länge von Lese-String
  if (LenT1 <= 0) return -2;

  if (*Pos > LenT1) return -4;

  LenT1 = strlen(TrnZ);        // Trennzeichen muss da sein
  if (LenT1 <= 0) return -3;

  LenT1 = strlen(KlmZ);        // Klammer sollte da sein
  if (LenT1 != 0 && LenT1 != 2) return -3;

  // Beginn suchen
  StartPos = sstStr011i_StartOfInfo ( 0, *Pos, TrnZ, Zeile);
  if (StartPos <= 0) return -5;

  // Position ist Begrenzung
  if (Zeile->at(*Pos-1) == TrnZ[0])
  { // Übergebene Position ist Begrenzungszeichen
    if(*Pos == 1)
    {  // Position 1 ist Begrenzungszeichen
      tRet->clear();      // Result-String ist leer
      ErrTxt->clear();    // Error-String ist auch leer
        *Pos = *Pos + 1;
        return 0;
    }
    else
    { // Position ist Begrenzungszeichen, aber nicht Position 1
        StartPos = *Pos;
    }
  }
  else
  { // Position ist Information
    StartPos = *Pos -1;
  }

    // Zweite Position der Begrenzung
  BeGrzPos = sstStr011i_TrnZFind ( 0, (StartPos+1), TrnZ, Zeile);
  if ( BeGrzPos <= 0) return -4;

  if ( (BeGrzPos - StartPos) < 2)
  {
    tRet->clear();      // Result-String ist leer
    ErrTxt->clear();    // Error-String ist auch leer
    *Pos = BeGrzPos;      // Position ist abgearbeit
    return 0;  // Kein Fehler, aber keine Information zwischen Begrenzern
  }

  // Das Begrenzungszeichen selbst kann keine Information sein,
  // also eine Position weiter...
  StartPos = sstStr011i_StartOfInfo ( 0, (StartPos+1), KlmZ, Zeile);
  if (StartPos <= 0) return -5;

  // Ende der Information rückwärts in einem String feststellen
  EndPos = sstStr011i_EndOfInfo ( 1, (BeGrzPos-1), KlmZ, Zeile);
  if ( EndPos <= 0) return -5;

  // Teil von String1 nach String2 kopieren
  iStat = sstStr011_Zeile2Str ( 0, StartPos, EndPos, Zeile, ErrTxt, tRet);
  if ( iStat != 0) return -5;

  *Pos = BeGrzPos;

  return iStat;
}
//=============================================================================
int sstStr011_Test_FuncInt (int iKey) // v  -> For the moment 0
//-----------------------------------------------------------------------------
{
  // char LocStr[dSSTSTR01_TEXTLEN];
  unsigned long ulPos=0;
  std::string sLocZeile;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  {
    // Get next string inside simple brackets
    char cSBracket[2];
    strncpy(cSBracket,"'",2);
    std::string oStrResult;
    sLocZeile="nnn'cc'33";
    ulPos = 4;
    iStat = sstStr011_GetNextSBrakeInfo ( 1, &sLocZeile, &ulPos, cSBracket, &oStrResult);
    assert(iStat == 1);
    assert(oStrResult.compare("cc") == 0);
    sLocZeile="nnn'cc'";
    ulPos = 4;
    iStat = sstStr011_GetNextSBrakeInfo ( 1, &sLocZeile, &ulPos, cSBracket, &oStrResult);
    assert(iStat == 1);
    assert(oStrResult.compare("cc") == 0);
    sLocZeile="'cc'";
    ulPos = 1;
    iStat = sstStr011_GetNextSBrakeInfo ( 1, &sLocZeile, &ulPos, cSBracket, &oStrResult);
    assert(iStat == 1);
    assert(oStrResult.compare("cc") == 0);
    sLocZeile="''";
    ulPos = 1;
    iStat = sstStr011_GetNextSBrakeInfo ( 1, &sLocZeile, &ulPos, cSBracket, &oStrResult);
    assert(iStat == 1);
    assert(oStrResult.compare("") == 0);
    sLocZeile="xxxxxx";
    ulPos = 1;
    iStat = sstStr011_GetNextSBrakeInfo ( 1, &sLocZeile, &ulPos, cSBracket, &oStrResult);
    assert(iStat == 0);
    assert(oStrResult.compare("xxxxxx") == 0);
    sLocZeile="xxx'xxx";
    ulPos = 1;
    iStat = sstStr011_GetNextSBrakeInfo ( 1, &sLocZeile, &ulPos, cSBracket, &oStrResult);
    assert(iStat == 0);
    assert(oStrResult.compare("xxx'xxx") == 0);
  }

  // Zahl nach String konvertieren
  // iStat = Str_Dbl2Txt ( 1, -22.2, 2, LocStr);
  iStat = sstStr011_Dbl2Zeile( 1, 1,6,-22.2, 2, &sLocZeile);
  ulPos = sLocZeile.find("-22.20",0);
  assert(ulPos==0);

  // Steht im String an Position eins der übergebenen Zeichen?
  int Key = 0;
  std::string TstStr;
  char ZchStr[4];
  strcpy( ZchStr, ";x!");  // Beliebig langer String mit Testzeichen
  iStat = sstStr011_StrSet ( 0, (char*)"Te;t", &TstStr, 10);
  long Pos = 1;
  iStat = sstStr011i_PosIsZch ( Key, &TstStr, Pos, ZchStr);
  assert( iStat == 0);  // Nein, an Position 1 steht keins der das übergebenen Zeichen
  Pos = 3;
  iStat = sstStr011i_PosIsZch ( Key, &TstStr, Pos, ZchStr);
  assert( iStat == 1);  // Ja, an Position 3 steht das übergebene Zeichen Semikolon

  // Übergebene Zeichen in einem String ab Position Pos suchen.
  Key = 0;
  Pos = 1;
  char BeGrzZ[4];
  strcpy(BeGrzZ,";x!");  // Beliebig langer String mit Testzeichen
  std::string Text;
  iStat = sstStr011_StrSet ( 0, (char*)"Te;t", &Text, 10);
  long lPos = sstStr011i_BeGrzFind ( Key, Pos, BeGrzZ, &Text);
  assert( lPos == 3);

  // Find next Trennzeichen from Position Pos
  iKey = 0;
  Pos  = 0;
  char TrnZ[2];
  strcpy (TrnZ, ";");
  iStat = sstStr011_StrSet ( 0, (char*)"Te;t", &Text, 10);
  lPos = sstStr011i_TrnZFind ( iKey, Pos, TrnZ, &Text);
  assert( lPos == -2);  // Übergebene Position falsch
  Pos  = 1;
  lPos = sstStr011i_TrnZFind ( iKey, Pos, TrnZ, &Text);
  assert( lPos == 3);   // Trennzeichen auf Position 3
  Pos  = 3;
  lPos = sstStr011i_TrnZFind ( iKey, Pos, TrnZ, &Text);
  assert( lPos == 3);   // Übergebene Position ist auch Trennzeichen
  Pos  = 4;
  lPos = sstStr011i_TrnZFind ( iKey, Pos, TrnZ, &Text);
  assert( lPos == 0);   // Kein Zeichen gefunden

  // String direkt in Int2 konvertieren.
  Key = 0;
  std::string LocInt;
  iStat = sstStr011_StrSet ( 0, (char*)"123", &LocInt, 10);
  iRet = 0;
  iStat = sstStr011i_Txt2Int ( Key, &LocInt, &iRet);
  assert( iRet == 123 && iStat == 0);
  iStat = sstStr011_StrSet ( 0, (char*)"1n3", &LocInt, 10);
  iStat = sstStr011i_Txt2Int ( Key, &LocInt, &iRet);
  assert( iRet == 0 && iStat == -2);
  iStat = sstStr011_StrSet ( 0, (char*)"-23", &LocInt, 10);
  iStat = sstStr011i_Txt2Int ( Key, &LocInt, &iRet);
  assert( iRet == -23 && iStat == 0);
  iStat = sstStr011_StrSet ( 0, (char*)"+16", &LocInt, 10);
  iStat = sstStr011i_Txt2Int ( Key, &LocInt, &iRet);
  assert( iRet == 16 && iStat == 0);
  iStat = sstStr011_StrSet ( 0, (char*)"12.5", &LocInt, 10);
  iStat = sstStr011i_Txt2Int ( Key, &LocInt, &iRet);
  assert( iRet == 0 && iStat == -2);
  iStat = sstStr011_StrSet ( 0, (char*)"12,5", &LocInt, 10);
  iStat = sstStr011i_Txt2Int ( Key, &LocInt, &iRet);
  assert( iRet == 0 && iStat == -2);
  iStat = sstStr011_StrSet ( 0, (char*)"123456", &LocInt, 10);
  iStat = sstStr011i_Txt2Int ( Key, &LocInt, &iRet);
  assert( iRet == 0 && iStat == -3);  // String zu lang!
  iStat = sstStr011_StrSet ( 0, (char*)"", &LocInt, 10);
  iStat = sstStr011i_Txt2Int ( Key, &LocInt, &iRet);
  assert( iRet == 0 && iStat == -3);  // String zu kurz!
  iStat = sstStr011_StrSet ( 0, (char*)"1+2", &LocInt, 10);
  iStat = sstStr011i_Txt2Int ( Key, &LocInt, &iRet);
  assert( iRet == 0 && iStat == -2);
  iStat = sstStr011_StrSet ( 0, (char*)"12-", &LocInt, 10);
  iStat = sstStr011i_Txt2Int ( Key, &LocInt, &iRet);
  assert( iRet == 0 && iStat == -2);

  // String direkt in Int4 konvertieren
  Key = 0;
  // strcpy( LocInt, "Test");
  long lRet = 0;
  iStat = sstStr011_StrSet ( 0, (char*)"125", &LocInt, 10);
  iStat = sstStr011i_Txt2Int4 ( Key, &LocInt, &lRet);
  assert( lRet == 125 && iStat == 0);
  iStat = sstStr011_StrSet ( 0, (char*)"1n3", &LocInt, 10);
  iStat = sstStr011i_Txt2Int4 ( Key, &LocInt, &lRet);
  assert( lRet == 0 && iStat == -2);
  iStat = sstStr011_StrSet ( 0, (char*)"-23", &LocInt, 10);
  iStat = sstStr011i_Txt2Int4 ( Key, &LocInt, &lRet);
  assert( lRet == -23 && iStat == 0);
  iStat = sstStr011_StrSet ( 0, (char*)"+16", &LocInt, 10);
  iStat = sstStr011i_Txt2Int4 ( Key, &LocInt, &lRet);
  assert( lRet == 16 && iStat == 0);
  iStat = sstStr011_StrSet ( 0, (char*)"12.5", &LocInt, 10);
  iStat = sstStr011i_Txt2Int4 ( Key, &LocInt, &lRet);
  assert( lRet == 0 && iStat == -2);
  iStat = sstStr011_StrSet ( 0, (char*)"12,5", &LocInt, 10);
  iStat = sstStr011i_Txt2Int4 ( Key, &LocInt, &lRet);
  assert( lRet == 0 && iStat == -2);
  iStat = sstStr011_StrSet ( 0, (char*)"123333333456", &LocInt, 20);
  iStat = sstStr011i_Txt2Int4 ( Key, &LocInt, &lRet);
  assert( lRet == 0 && iStat == -3);  // String zu lang!
  iStat = sstStr011_StrSet ( 0, (char*)"", &LocInt, 10);
  iStat = sstStr011i_Txt2Int4 ( Key, &LocInt, &lRet);
  assert( lRet == 0 && iStat == -3);  // String zu kurz!
  iStat = sstStr011_StrSet ( 0, (char*)"1+2", &LocInt, 10);
  iStat = sstStr011i_Txt2Int4 ( Key, &LocInt, &lRet);
  assert( lRet == 0 && iStat == -2);
  iStat = sstStr011_StrSet ( 0, (char*)"12-", &LocInt, 10);
  iStat = sstStr011i_Txt2Int4 ( Key, &LocInt, &lRet);
  assert( lRet == 0 && iStat == -2);

  // String direkt in Double konvertieren.
  Key = 0;
  std::string LocReal;
  iStat = sstStr011_StrSet ( 0, (char*)"12.3", &LocReal, 10);
  float rRet = 0;
  iStat = sstStr011i_Txt2Real ( Key, &LocReal, &rRet);
  assert( rRet > (12.3-DIFF_R) && rRet < (12.3+DIFF_R) && iStat == 0);

  iStat = sstStr011_StrSet ( 0, (char*)"12,3", &LocReal, 10);
  iStat = sstStr011i_Txt2Real ( Key, &LocReal, &rRet);
  // assert( rRet > (0.0-DIFF_R) && rRet < (0.0+DIFF_R) && iStat == -2);
  assert( rRet > (12.3-DIFF_R) && rRet < (12.3+DIFF_R) && iStat == 0);

  iStat = sstStr011_StrSet ( 0, (char*)"12.3.4", &LocReal, 10);
  iStat = sstStr011i_Txt2Real ( Key, &LocReal, &rRet);
  assert( rRet > (0.0-DIFF_R) && rRet < (0.0+DIFF_R) && iStat == -2);
  iStat = sstStr011_StrSet ( 0, (char*)"", &LocReal, 10);
  iStat = sstStr011i_Txt2Real ( Key, &LocReal, &rRet);
  assert( rRet > (0.0-DIFF_R) && rRet < (0.0+DIFF_R) && iStat == -3);

  // String direkt in Double konvertieren.
  Key = 0;
  std::string LocDbl;
  double dRet = 0;
  iStat = sstStr011_StrSet ( 0, (char*)"12.3", &LocDbl, 10);
  iStat = sstStr011i_Txt2Dbl ( Key, &LocDbl, &dRet);
  assert( dRet > (12.3-DIFF_D) && dRet < (12.3+DIFF_D) && iStat == 0);

  iStat = sstStr011_StrSet ( 0, (char*)"12,3", &LocDbl, 10);
  iStat = sstStr011i_Txt2Dbl ( Key, &LocDbl, &dRet);
  // assert( dRet > (0.0-DIFF_D) && dRet < (0.0+DIFF_D) && iStat == -2);
  assert( dRet > (12.3-DIFF_D) && dRet < (12.3+DIFF_D) && iStat == 0);

  iStat = sstStr011_StrSet ( 0, (char*)"12.3.4", &LocDbl, 10);
  iStat = sstStr011i_Txt2Dbl ( Key, &LocDbl, &dRet);
  assert( dRet > (0.0-DIFF_D) && dRet < (0.0+DIFF_D) && iStat == -2);
  iStat = sstStr011_StrSet ( 0, (char*)"", &LocDbl, 10);
  iStat = sstStr011i_Txt2Dbl ( Key, &LocDbl, &dRet);
  assert( dRet > (0.0-DIFF_D) && dRet < (0.0+DIFF_D) && iStat == -3);

  // Ist Zeichen eine Zahl zwischen 0 und 9?
  Key = 0;
  char Zeichen[2];
  strcpy(Zeichen,"1");
  iStat = sstStr011i_IsDigit ( Key, Zeichen);
  assert(iStat == 1);  // TRUE, 1 is Value
  strcpy(Zeichen,"9");
  iStat = sstStr011i_IsDigit ( Key, Zeichen);
  assert(iStat == 1);  // TRUE, 9 is Value
  strcpy(Zeichen,"a");
  iStat = sstStr011i_IsDigit ( Key, Zeichen);
  assert(iStat == 0);  // FALSE
  strcpy(Zeichen,"");
  iStat = sstStr011i_IsDigit ( Key, Zeichen);
  assert(iStat == 0);  // FALSE
  strcpy(Zeichen," ");
  iStat = sstStr011i_IsDigit ( Key, Zeichen);
  assert(iStat == 0);  // FALSE

  // Position einer Textadresse ermitteln.
  Key = 0;
  unsigned long TPos = 0;
  std::string Zeile;
  iStat = sstStr011_StrSet ( 0, (char*)"Test", &Zeile, 10);
  std::string TAdr = "Test";
  iStat = sstStr011i_AdrHasPos ( Key, &TPos, &Zeile, &TAdr);
  assert(iStat == 1 && TPos == 1);  // TRUE
  TAdr = "est";  // &Zeile.Txt[1];
  iStat = sstStr011i_AdrHasPos ( Key, &TPos, &Zeile, &TAdr);
  assert(iStat == 1 && TPos == 2);  // TRUE
  TAdr = "st";  // &Zeile.Txt[3];
  iStat = sstStr011i_AdrHasPos ( Key, &TPos, &Zeile, &TAdr);
  assert(iStat == 1 && TPos == 3);  // TRUE
  TAdr ="t"; //  &Zeile.Txt[4];
  iStat = sstStr011i_AdrHasPos ( Key, &TPos, &Zeile, &TAdr);
  assert(iStat == 1 && TPos == 4);  // FALSE
  TAdr = "23";  // &LocDbl.Txt[2];
  iStat = sstStr011i_AdrHasPos ( Key, &TPos, &Zeile, &TAdr);
  assert(iStat == 0 && TPos == 0);  // FALSE

  // Beginn der Information in einem String ab Position Pos feststellen.
  Key = 0;
  Pos = 1;
  char NoInfZ[4];
  strcpy(NoInfZ,"; ");
  iStat = sstStr011_StrSet ( 0, (char*)" Te;t", &Text, 10);
  long StartPos = 0;
  StartPos = sstStr011i_StartOfInfo ( Key, Pos, NoInfZ, &Text);
  assert(StartPos == 2);  // Position 2 is Information
  Pos = 0;
  StartPos = sstStr011i_StartOfInfo ( Key, Pos, NoInfZ, &Text);
  assert(StartPos == 2);  // Pos 0 is OK
  Pos = 6;
  StartPos = sstStr011i_StartOfInfo ( Key, Pos, NoInfZ, &Text);
  assert(StartPos == -2);  // End of String reached
  Pos = 2;
  StartPos = sstStr011i_StartOfInfo ( Key, Pos, NoInfZ, &Text);
  assert(StartPos == 2);  // Position 2 is Information
  iStat = sstStr011_StrSet ( 0, (char*)"      ", &Text, 10);
  Pos = 1;
  StartPos = sstStr011i_StartOfInfo ( Key, Pos, NoInfZ, &Text);
  assert(StartPos == -3);  // No Information found
  iStat = sstStr011_StrSet ( 0, (char*)"--Te;t", &Text, 10);

  strcpy(NoInfZ,"-; ");
  Pos = 1;
  StartPos = sstStr011i_StartOfInfo ( Key, Pos, NoInfZ, &Text);
  assert(StartPos == 3);  // Position 3 ist NoInformation

  // Ende der Information in einem String vom Anfang her feststellen.
  Key = 0;  // Aus der Information heraus vorwärts suchen
  Pos = 1;
  strcpy(NoInfZ,"-; ");
  iStat = sstStr011_StrSet ( 0, (char*)"Te;t; ", &Text, 10);
  long EndPos = 0;
  EndPos = sstStr011i_EndOfInfo ( Key, Pos, NoInfZ, &Text);
  assert(EndPos == 2);  // Position 3 ist NoInformation
  iStat = sstStr011_StrSet ( 0, (char*)"Test; ", &Text, 10);
  EndPos = sstStr011i_EndOfInfo ( Key, Pos, NoInfZ, &Text);
  assert(EndPos == 4);  // Position 3 ist NoInformation
  Pos = 0;
  EndPos = sstStr011i_EndOfInfo ( Key, Pos, NoInfZ, &Text);
  assert(EndPos == -2);  // Pos 0 not OK
  Pos = 5;
  EndPos = sstStr011i_EndOfInfo ( Key, Pos, NoInfZ, &Text);
  assert(EndPos == 4);  // Warum auch immer, falsche Herangehensweise
  Pos = 6;
  EndPos = sstStr011i_EndOfInfo ( Key, Pos, NoInfZ, &Text);
  assert(EndPos == 5);  // Warum auch immer, falsche Herangehensweise
  Pos = 6; Key = 1;
  EndPos = sstStr011i_EndOfInfo ( Key, Pos, NoInfZ, &Text);
  assert(EndPos == 4);  //

  // Lese nächsten String nach Suchstring.
  // Key
  // Zeile
  // TrennZ
  Key = 0;
  std::string SuchStr;
  std::string FindStr;
  iStat = sstStr011_StrSet ( 0, (char*)"Dies ist ein Teststring", &Zeile, 50);
  iStat = sstStr011_StrSet ( 0, (char*)"ein", &SuchStr, 10);
  strcpy(NoInfZ,"-; ");
  iStat = sstStr011i_LesTxtNach ( Key, &Zeile, NoInfZ, &SuchStr, &FindStr);
  // assert ( strcmp( FindStr.Txt,  "Teststring") == 0);
  ulPos = FindStr.find("Teststring",0);
  assert ( ulPos == 0);
  iStat = sstStr011_StrSet ( 0, (char*)"ist", &SuchStr, 10);
  strcpy(NoInfZ,"-; ");
  iStat = sstStr011i_LesTxtNach ( Key, &Zeile, NoInfZ, &SuchStr, &FindStr);
  // assert ( strcmp( FindStr.Txt,  "ein") == 0);
  ulPos = FindStr.find("ein",0);
  assert (ulPos == 0);

  // Steht an Position Information im String ?
  Key = 0;
  // std::string TstStr;
  iStat = sstStr011_StrSet ( 0, (char*)"Te st", &TstStr, 10);
  Pos = 0;
  char InfoStr[4];
  strcpy ( InfoStr, "; ");
  iStat = sstStr011i_PosHasInfo ( Key, &TstStr, Pos, InfoStr);
  assert(iStat == -2);  // Wrong Position
  Pos = 3;
  iStat = sstStr011i_PosHasInfo ( Key, &TstStr, Pos, InfoStr);
  assert(iStat == 0);  // No Information at Position
  Pos = 2;
  iStat = sstStr011i_PosHasInfo ( Key, &TstStr, Pos, InfoStr);
  assert(iStat == 1);  // Position is Information

  // Nächste Information aus Text-Zeile in Int2 umwandeln.
  Key = 0;
  // Zeile
  iStat = sstStr011_StrSet ( 0,(char*) "Es stehen 10 Bäume", &Zeile, 50);
  std::string ErrTxt;
  // TAdr = &Zeile.Txt[10];
  iRet = 0;
  // iStat = sstStr011i_AbPos_Int ( Key, TAdr, &Zeile, &ErrTxt, &iRet);
  // assert(iRet == 10 && iStat == 0);  // Position is Information


  // Ende der Information in einem String vom Anfang her feststellen.
  Key = 0;  // Aus der Information heraus vorwärts suchen
  strcpy(NoInfZ," ");
  std::string cText;
  cText = "1    ";
  EndPos = 0;

  Pos = 1;
  // EndPos = sstStr01_EndOfInfo ( 1, 5, NoInfZ, cText);
  EndPos = sstStr011i_EndOfInfo ( Key, Pos, NoInfZ, &cText);
  assert(EndPos == 1);  // Position 2 ist NoInformation

//  Pos = 1;
//  EndPos = sstStr01_EndOfInfo ( Key, Pos, NoInfZ, cText);
//  assert(EndPos == 4);  // Position 3 ist NoInformation
//
//  Pos = 0;
//  EndPos = sstStr01_EndOfInfo ( Key, Pos, NoInfZ, cText);
//  assert(EndPos == -2);  // Pos 0 not OK
//
//  Pos = 5;
//  EndPos = sstStr01_EndOfInfo ( Key, Pos, NoInfZ, cText);
//  assert(EndPos == 4);  // Warum auch immer, falsche Herangehensweise
//
//  Pos = 6;
//  EndPos = sstStr01_EndOfInfo ( Key, Pos, NoInfZ, cText);
//  assert(EndPos == 5);  // Warum auch immer, falsche Herangehensweise
//
//  Pos = 6; Key = 1;
//  EndPos = sstStr01_EndOfInfo ( Key, Pos, NoInfZ, cText);
//  assert(EndPos == 4);  //

  // Heavy Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(iRet >= 0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstStr011_StrSet (int          iKey,
                 char        *Str,
                 std::string *Str_Stru,
                 unsigned long         StrLenMax)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  if (StrLenMax >= dSSTSTR01_TEXTLEN) return -2;
  // long StrLen = strlen(Str);
  if( strlen(Str) >= dSSTSTR01_TEXTLEN)return -3;

  // memset ( Str_Stru->Txt, 0, dSSTSTR01_TEXTLEN);
  Str_Stru->clear();
  *Str_Stru = Str;  // strcpy ( Str_Stru->Txt, Str);
  // Str_Stru->AktLen = strlen(Str_Stru->Txt);


  // Heavy Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(iRet >= 0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================

