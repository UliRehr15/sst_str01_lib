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
// sstStr01DefType.cpp    10.05.16  Re.    10.05.16  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include "sstStr01Lib.h"
#include "sstStr01LibInt.h"

//=============================================================================
// Constructor
sstStr01VarDefCls::sstStr01VarDefCls()
{
  memset(this->cSysNam,0,dSST_STR01_VAR_NAM_LEN);
  memset(this->cObjNam,0,dSST_STR01_VAR_NAM_LEN);
  memset(this->cEleNam,0,dSST_STR01_VAR_NAM_LEN);
  this->eType = sstStr01Unknown;
  this->iWidth=0;
  this->iDec=0;

}
//=============================================================================
int sstStr01VarDefCls::Set_SysNam(std::string oLocStr)
{
  strncpy(this->cSysNam,oLocStr.c_str(),dSST_STR01_VAR_NAM_LEN);
  return 0;
}
//=============================================================================
int sstStr01VarDefCls::Set_ObjNam(std::string oLocStr)
{
  strncpy(this->cObjNam,oLocStr.c_str(),dSST_STR01_VAR_NAM_LEN);
  return 0;
}
//=============================================================================
int sstStr01VarDefCls::Set_EleNam(std::string oLocStr)
{
  strncpy(this->cEleNam,oLocStr.c_str(),dSST_STR01_VAR_NAM_LEN);
  return 0;
}
//=============================================================================
int sstStr01VarDefCls::Set_Type(sstStr01VarType_enum eLocType)
{
  this->eType = eLocType;
  return 0;
}
//=============================================================================
int sstStr01VarDefCls::Set_Width(int iLocWidth)
{
  this->iWidth = iLocWidth;
  return 0;
}
//=============================================================================
int sstStr01VarDefCls::Set_Dec(int iLocDec)
{
  this->iDec = iLocDec;
  return 0;
}
//=============================================================================
std::string sstStr01VarDefCls::Get_SysNam()
{
  std::string oLocStr;
  oLocStr = this->cSysNam;
  return oLocStr;
}
//=============================================================================
std::string sstStr01VarDefCls::Get_ObjNam()
{
  std::string oLocStr;
  oLocStr = this->cObjNam;
  return oLocStr;
}
//=============================================================================
std::string sstStr01VarDefCls::Get_EleNam()
{
  std::string oLocStr;
  oLocStr = this->cEleNam;
  return oLocStr;
}
//=============================================================================
sstStr01VarType_enum sstStr01VarDefCls::Get_Type()
{
  return this->eType;
}
//=============================================================================
int sstStr01VarDefCls::Get_Width()
{
  return this->iWidth;
}
//=============================================================================
int sstStr01VarDefCls::Get_Dec()
{
  return this->iDec;
}
//=============================================================================
// Constructor
sstStr01VarDefFncCls::sstStr01VarDefFncCls()
{
  this->oCnvtStr.SetBracket(0,(char*)"");
}
//=============================================================================
int sstStr01VarDefFncCls::ReadCSV(int           iKey,
                             std::string  *sFilStr,
                             std::string  *sErrTxt,
                             sstStr01VarDefCls *oStrType)
{
  sstStr01VarType_enum eLocType;
  sstStr01VarTypeCls oVarType;
  std::string  sRetStr;
  char cTrnZ[2]=";";
  unsigned long TPos = 0;
  int iRet  = 0;
  int iStat = 0;
  int iStat1 = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Csv ab Position in String konvertieren.
  // Read System name
  iStat = Str1_AbPos2Str ( 0, &TPos, cTrnZ, sFilStr, sErrTxt, &sRetStr);

  if(iStat >= 0)
  {
    // strncpy(oStrType->cSysNam,sRetStr.c_str(),dSST_STR01_VAR_NAM_LEN);
    oStrType->Set_SysNam(sRetStr);
    // Read Class name
    iStat = Str1_AbPos2Str ( 0, &TPos, cTrnZ, sFilStr, sErrTxt, &sRetStr);
  }

  if(iStat >= 0)
  {
    // strncpy(oStrType->cObjNam,sRetStr.c_str(), dSST_STR01_VAR_NAM_LEN);
    oStrType->Set_ObjNam(sRetStr);
    // Read element name
    iStat = Str1_AbPos2Str ( 0, &TPos, cTrnZ, sFilStr, sErrTxt, &sRetStr);
  }

  if(iStat >= 0)
  {
    // strncpy(oStrType->cEleNam,sRetStr.c_str(), dSST_STR01_VAR_NAM_LEN);
    oStrType->Set_EleNam(sRetStr);
    // Read element Type
    iStat = Str1_AbPos2Str ( 0, &TPos, cTrnZ, sFilStr, sErrTxt, &sRetStr);
  }

  if (iStat >= 0)
  {
    iStat = oVarType.Str2Enm( 0, sRetStr.c_str(), &eLocType);
  }

  if(iStat >= 0)
  {

    // oStrType->eType = eLocType;
    oStrType->Set_Type(eLocType);
    // Read element width
    iStat = Str1_AbPos2Int ( 0, &TPos, cTrnZ, sFilStr, sErrTxt, &iRet);
  }

  if(iStat >= 0)
  {
    // oStrType->iWidth = iRet;
    oStrType->Set_Width(iRet);
    // Read element Dec
    iStat1 = Str1_AbPos2Int ( 0, &TPos, cTrnZ, sFilStr, sErrTxt, &iRet);
  }

  if(iStat1 >= 0)
  {
    // oStrType->iDec = iRet;
    oStrType->Set_Dec(iRet);
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
int sstStr01VarDefFncCls::WriteCSV(int            iKey,
                              sstStr01VarDefCls  oSstType,
                              std::string   *sErrTxt,
                              std::string   *sExpStr)
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Init Str1 object.
  iStat = Str1_Init ( 0, sExpStr);

  // convert string value to csv-formatted string and append to string
  // Insert system name
  iStat = this->oCnvtStr.Csv_Str_2String( 0, oSstType.Get_SysNam(), sExpStr);

  // convert string value to csv-formatted string and append to string
  // Insert object name
  iStat = this->oCnvtStr.Csv_Str_2String( 0, oSstType.Get_ObjNam(), sExpStr);

  // convert string value to csv-formatted string and append to string
  // insert element name
  iStat = this->oCnvtStr.Csv_Str_2String( 0, oSstType.Get_EleNam(), sExpStr);

  // convert string value to csv-formatted string and append to string
  // insert variable type information

  sstStr01VarTypeCls oVarTypeCnvt;
  std::string oVarTypeStr;
  oVarTypeCnvt.Enm2Str(0,oSstType.Get_Type(),&oVarTypeStr);
  iStat = this->oCnvtStr.Csv_Str_2String( 0, oVarTypeStr, sExpStr);

  // insert width
  iStat = this->oCnvtStr.Csv_Int2_2String( 0, oSstType.Get_Width(), sExpStr);

  // insert dec
  iStat = this->oCnvtStr.Csv_Int2_2String( 0, oSstType.Get_Dec(), sExpStr);

  *sErrTxt = this->oCnvtStr.GetErrorString();

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

