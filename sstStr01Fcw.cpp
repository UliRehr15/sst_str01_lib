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
// sstStr01Fcw.cpp    22.04.19  Re.    17.08.16  Re.
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
sstStr01FcwCls::sstStr01FcwCls()
{
  memset(this->cSeparator,0,2);
  memset(this->cNoInfo,0,2);
  memset(this->cBracket,0,2);
  memset(this->cBracketOpen,0,2);
  memset(this->cBracketClose,0,2);
  this->ulPos = 1;
  this->iFormatKenn = 0;
  this->iDecType = 0;
  strncpy(this->cSeparator," ",2);  // Default blank
  strncpy(this->cBracket,"",2);     // default empty
  strncpy(this->cNoInfo," ",2);     // default blank
  iSeparatorTyp = 0;
  iBoolTyp = 0;

}
//=============================================================================
int sstStr01FcwCls::String2Str(int iKey, int iColWidth, std:: string oFcwStr, std::string *oStrVal)
{
  if (iKey < 0 || iKey > 3) return -1;

  std::string oErrStr;
  std::string oRetStr;

  int iStat = sstStr011_Zeile2Str ( iKey, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, &oFcwStr, &oErrStr, oStrVal);
  this->SetErrorString(oErrStr);
  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::String2Char(int iKey, int iColWidth, std:: string oFcwStr, char *cVal, int iCharLen)
{
  if (iKey < 0 || iKey > 3) return -1;

  std::string oErrStr;
  std::string oRetStr;

  int iStat = sstStr011_Zeile2Str ( iKey, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, &oFcwStr, &oErrStr, &oRetStr);
  strncpy(cVal,oRetStr.c_str(), iCharLen);
  this->SetErrorString(oErrStr);
  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::Char2String(int iKey, int iColWidth, char *cVal, std:: string *oFcwStr)
{
  if (iKey < 0 || iKey > 3) return -1;

  int iStat = sstStr011_Char2Zeile ( iKey, this, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, cVal, oFcwStr);

  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::String2Int(int iKey, int iColWidth, std:: string oFcwStr, int *iVal)
{
  if (iKey < 0 || iKey > 3) return -1;

  std::string oErrStr;

  int iStat = sstStr011_Zeile2Int ( iKey, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, &oFcwStr, &oErrStr, iVal);
  this->SetErrorString(oErrStr);
  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::Int2String(int iKey, int iColWidth, int iVal, std:: string *oFcwStr)
{
  if (iKey < 0 || iKey > 3) return -1;

  int iStat = sstStr011_Int2Zeile ( iKey, this, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, iVal, oFcwStr);

  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::IntFrmt2String(int iKey, int iColWidth, int iVal, std::string oFrmtStr, std:: string *oFcwStr)
{
  if (iKey < 0 || iKey > 3) return -1;

  char cFrmtTxt[30];
  strncpy(cFrmtTxt,oFrmtStr.c_str(),30);

  int iStat = sstStr011_Int2ZeileFmt( iKey, this, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, iVal, cFrmtTxt, oFcwStr);

  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::String2Long(int iKey, int iColWidth, std:: string oFcwStr, long *lVal)
{
  if (iKey < 0 || iKey > 3) return -1;

  std::string oErrStr;

  int iStat = sstStr011_Zeile2Int4 ( iKey, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, &oFcwStr, &oErrStr, lVal);
  this->SetErrorString(oErrStr);
  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::Long2String(int iKey, int iColWidth, long lVal, std:: string *oFcwStr)
{
  if (iKey < 0 || iKey > 3) return -1;

  int iStat = sstStr011_Int4Zeile( iKey, this, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, lVal, oFcwStr);

  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::LongFrmt2String(int iKey, int iColWidth, long lVal, std::string oFrmtStr, std:: string *oFcwStr)
{
  if (iKey < 0 || iKey > 3) return -1;

  char cFrmtTxt[30];
  strncpy(cFrmtTxt,oFrmtStr.c_str(),30);

  int iStat = sstStr011_Int4ZeileFmt( iKey, this, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, lVal, cFrmtTxt, oFcwStr);

  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::String2Dbl(int iKey, int iColWidth, std:: string oFcwStr, double *dVal)
{
  if (iKey < 0 || iKey > 3) return -1;

  std::string oErrStr;

  int iStat = sstStr011_Zeile2Dbl ( iKey, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, &oFcwStr, &oErrStr, dVal);
  this->SetErrorString(oErrStr);
  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::Dbl2String(int iKey, int iColWidth, double dVal, std:: string *oFcwStr)
{
  if (iKey < 0 || iKey > 3) return -1;

  int iStat = sstStr011_Dbl2Zeile ( iKey, this, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, dVal, 4, oFcwStr);

  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::DblFrmt2String(int iKey, int iColWidth, double dVal, std::string oFrmtStr, std:: string *oFcwStr)
{
  if (iKey < 0 || iKey > 3) return -1;

  char cFrmtTxt[30];
  strncpy(cFrmtTxt,oFrmtStr.c_str(),30);

  int iStat = sstStr011_Dbl2ZeileFmt ( iKey, this, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, dVal, cFrmtTxt, oFcwStr);

  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::String2Float(int iKey, int iColWidth, std:: string oFcwStr, float *fVal)
{
  if (iKey < 0 || iKey > 3) return -1;

  std::string oErrStr;

  int iStat = sstStr011_Zeile2Float( iKey, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, &oFcwStr, &oErrStr, fVal);
  this->SetErrorString(oErrStr);
  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::Float2String(int iKey, int iColWidth, float fVal, std:: string *oFcwStr)
{
  if (iKey < 0 || iKey > 3) return -1;

  int iStat = sstStr011_Real2Zeile ( iKey, this, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, fVal, 4, oFcwStr);

  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::FloatFrmt2String(int iKey, int iColWidth, float fVal, std:: string oFrmtStr, std:: string *oFcwStr)
{
  if (iKey < 0 || iKey > 3) return -1;

  char cFrmtTxt[30];
  strncpy(cFrmtTxt,oFrmtStr.c_str(),30);

  int iStat = sstStr011_Real2ZeileFmt( iKey, this, this->GetReadPosition(), this->GetReadPosition()+iColWidth-1, fVal, cFrmtTxt, oFcwStr);

  this->SetReadPositon(0,this->GetReadPosition()+iColWidth);

  return iStat;
}
//=============================================================================
int sstStr01FcwCls::SetBracket(int iKey, char *cTmpBracket)
{
  if ( iKey != 0) return -1;
  this->cBracket[0] = cTmpBracket[0];
  this->cBracket[1] = 0;
  this->cBracketOpen[0] = cTmpBracket[0];
  this->cBracketOpen[1] = 0;
  this->cBracketClose[0] = cTmpBracket[1];
  this->cBracketClose[1] = 0;
  return 0;
}
//=============================================================================
int sstStr01FcwCls::SetSeparator(int iKey, char *cSeparator)
{
  if ( iKey != 0) return -1;
  strncpy ( this->cSeparator, cSeparator, 2);
  return 0;
}
//=============================================================================
int sstStr01FcwCls::SetReadPositon(int iKey, unsigned long ulTmpPos)
{
  if ( iKey != 0) return -1;
  this->ulPos = ulTmpPos;
  return 0;
}
//=============================================================================
int sstStr01FcwCls::SetSeparatorTyp(int iKey, int iTmpSeparatorTyp)
{
  if ( iKey != 0) return -1;
  this->iSeparatorTyp = iTmpSeparatorTyp;
  return 0;
}
//=============================================================================
int sstStr01FcwCls::SetBoolTyp(int iKey, int iTmpBoolTyp)
{
  if ( iKey != 0) return -1;
  this->iBoolTyp = iTmpBoolTyp;
  return 0;
}
//==============================================================================
int sstStr01FcwCls::SetNoInfoChar(int iKey, char *cNoInfoChar)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;
  strncpy ( this->cNoInfo, cNoInfoChar, 2);
  return 0;
}
//=============================================================================
int sstStr01FcwCls::GetSeparatorTyp()
{
  return this->iSeparatorTyp;
}
//=============================================================================
int sstStr01FcwCls::GetBoolTyp()
{
  return this->iBoolTyp;
}
//=============================================================================
char* sstStr01FcwCls::GetNoInfoChar()
{
  return this->cNoInfo;
}
//=============================================================================
char* sstStr01FcwCls::GetBraketOpen()
{
  return this->cBracketOpen;
}
//=============================================================================
char* sstStr01FcwCls::GetBraketClose()
{
  return this->cBracketClose;
}
//=============================================================================
std::string sstStr01FcwCls::GetSeparatorStr()
{
  std::string oTmpString;
  oTmpString = this->cSeparator;
  return oTmpString;
}
//=============================================================================
unsigned long sstStr01FcwCls::GetReadPosition()
{
  return this->ulPos;
}
//=============================================================================
std::string sstStr01FcwCls::GetErrorString()
{
  return this->oErrStr;
}
//=============================================================================
void sstStr01FcwCls::ClearAll()
{
  this->ulPos = 0;
  this->oErrStr.clear();
}
//=============================================================================
void sstStr01FcwCls::SetErrorString(std::string oTmpErrStr)
{
  this->oErrStr = oTmpErrStr;
}
//=============================================================================

