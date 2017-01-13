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
// sstStr01Lib.h   17.01.17  Re.   24.11.15  Re.
//
// Datastructures and Prototypes for system "sstStrLib"
//

#ifndef   _SST_STR01_LIB_HEADER
#define   _SST_STR01_LIB_HEADER

#include <vector>

/**
 * @defgroup sstStr01Lib sstStr01Lib: sst String lib (Version 1)
 * cpp string library for sst
 */

// Defines ---------------------------------------------------------------------

#define dSSTSTR01_TEXTLEN   300  // temporary row length maximum


#define dSSTSTR01_CINT1_MIN         (-127-1)   // Minimum für Cint1
#define dSSTSTR01_CINT1_MAX           127      // Maximum für Cint1
#define dSSTSTR01_CUINT1_MAX          256U     // Maximum für Cuint1

#define dSSTSTR01_CINT2_MIN       (-32767-1)   // Minimum für Cint2
#define dSSTSTR01_CINT2_MAX         32767      // Maximum für Cint2
#define dSSTSTR01_CUINT2_MAX        65535U     // Maximum für Cuint2

#define dSSTSTR01_CINT4_MIN  (-2147483647L-1)  // Minimum für Cint4
#define dSSTSTR01_CINT4_MAX    2147483647L     // Maximum für Cint4
#define dSSTSTR01_CUINT4_MAX   4294967295UL    // Maximum für Cuint4

#define dSSTSTR01_UNDEF_DOUBLE -999999999      // Undefine for Double

//**************************************************************************

// forward declaration ---------------------------------------------------------

class sstStr01IntCls;
class sstStr01Cls;

// Structures and Classes ------------------------------------------------------

//==============================================================================
/**
* @brief Definition Enum VarType_enum
*
* All Variable types.  <BR>
* <BR>
* In File:  LL, II, FF, DD, CC, BB, DA <BR>
*
* Changed: 10.05.16  Re.
*
* @ingroup sstStr01Lib
*
* @author Re.
*
* @date 10.05.16
*/
// ----------------------------------------------------------------------------
enum _sstStr01VarType_enum
{ sstStr01Unknown,  //!< unknown       XX    */
  sstStr01Char,     //!< char          CC    */
  sstStr01WChar,    //!< wchar         WC    */
  sstStr01Date,     //!< date          DA    */
  sstStr01Bool,     //!< bool          BB    */
  sstStr01Int,      //!< int           II    */
  sstStr01UInt,     //!< unsigned int  UI    */
  sstStr01Long,     //!< long          LL    */
  sstStr01ULong,    //!< unsigned long UL    */
  sstStr01Float,    //!< float         FF    */
  sstStr01Double,   //!< double        DD    */
  sstStr01String,   //!< string        ST    */
  sstStr01Custom    //!< custom data type    */
};
typedef enum _sstStr01VarType_enum sstStr01VarType_enum;
//==============================================================================
/**
* @brief String convert class for enum VarType_enum
*
* Converts enum to string and back <BR>
*
* Changed: 08.07.15  Re.
*
* @ingroup sstStr01Lib
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstStr01VarTypeCls
{
  public:   // Public functions
     sstStr01VarTypeCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // convert string II,DD,CC ... to type enum <BR>
     * iStat = oVarType.Str2Enm ( iKey, oTypeStr, &eLocType);
     *
     * @param iKey     [in]  For the moment 0
     * @param oTypeStr [in]  For the moment 0
     * @param eLocType [out] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Str2Enm (int                   iKey,
                              std::string           oTypeStr,
                              sstStr01VarType_enum *eLocType);
     //==============================================================================
     /**
     * @brief // convert type enum to cpp var type full string int,double,char ... <BR>
     * iStat = oVarType.Enm2FullStr ( iKey, eCppType, *cTypeStr);
     *
     * @param iKey     [in]  For the moment 0
     * @param eCppType [in] For the moment 0
     * @param oTypeStr [out]  return string int, double, char ...
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Enm2FullStr (int                    iKey,
                           sstStr01VarType_enum   eCppType,
                           std::string           *oTypeStr);
     //==============================================================================
     /**
     * @brief // convert type enum to cpp var type string II, DD, CC ... <BR>
     * iStat = oVarType.Enm2Str ( iKey, eCppType, *oTypeStr);
     *
     * @param iKey     [in]  For the moment 0
     * @param eCppType [in] For the moment 0
     * @param oTypeStr [out]  return string int, double, char ...
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Enm2Str (int                    iKey,
                  sstStr01VarType_enum   eCppType,
                  std::string           *oTypeStr);
     //==============================================================================
     /**
     * @brief // convert type enum to short char i,d,c,..  <BR>
     * iStat = oVarType.Enm2ShortStr ( iKey, eCppType, *cTypeChar);
     *
     * @param iKey      [in]  For the moment 0
     * @param eCppType  [in] For the moment 0
     * @param oTypeStr  [out]  For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Enm2ShortStr (int                    iKey,
                           sstStr01VarType_enum   eCppType,
                           std::string           *oTypeStr);
// ----------------------------------------------------------------------------
private:  // Private functions
// int Dum;        /**< Dummy */
};
//==============================================================================
#define dSST_STR01_VAR_NAM_LEN   31    //!< string lenght of cpp object name @ingroup sstStr01Lib */
//==============================================================================
/**
* @brief Definition record class for data classes and member variables
*
* Defines one variable member for example in cpp class. <br>
* For example:   testdbf;testrec;fValue;FF;5;2;Info_Sys;Info_Obj;Info_Ele   <br>
*
* Info Strings are for doxygen.
*
* Changed: 25.06.12  Re.
*
* @ingroup sstStr01Lib
*
* @author Re.
*
* @date 25.06.12
*/
// ---strClassDefCls-------------------------------------------------------------
class sstStr01VarDefCls
{
  public:
     sstStr01VarDefCls();  // Constructor
   //  ~X();  // Destruktor
     //==============================================================================
     /**
     * @brief // set system name in def type class <BR>
     * iStat = oVarDef.Set_SysNam(oSysNamStr);
     *
     * @param oSysNamStr [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Set_SysNam(std::string oSysNamStr);
     //==============================================================================
     /**
     * @brief // set class name in def type class <BR>
     * iStat = oVarDef.Set_ObjNam(oClsNamStr);
     *
     * @param oClsNamStr [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Set_ObjNam(std::string oClsNamStr);
     //==============================================================================
     /**
     * @brief // set Variable element name in def type class <BR>
     * iStat = oVarDef.Set_EleNam(oEleNamStr);
     *
     * @param oEleNamStr [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Set_EleNam(std::string oEleNamStr);
     //==============================================================================
     /**
     * @brief // set system Info in def type class <BR>
     * iStat = oVarDef.Set_SysInfo(oSysInfoStr);
     *
     * @param oSysInfoStr [in] Info string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Set_SysInfo(std::string oSysInfoStr);
     //==============================================================================
     /**
     * @brief // set class Info in def type class <BR>
     * iStat = oVarDef.Set_ObjInfo(oClsInfoStr);
     *
     * @param oClsInfoStr [in] Info string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Set_ObjInfo(std::string oClsInfoStr);
     //==============================================================================
     /**
     * @brief // set Variable element Info in def type class <BR>
     * iStat = oVarDef.Set_EleInfo(oEleInfoStr);
     *
     * @param oEleInfoStr [in] Info string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Set_EleInfo(std::string oEleInfoStr);
     //==============================================================================
     /**
     * @brief // set var type in def type class <BR>
     * iStat = oVarDef.Set_Type ( eType);
     *
     * @param eType [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Set_Type(sstStr01VarType_enum eType);
     //==============================================================================
     /**
     * @brief // set width in def type class <BR>
     * iStat = oVarDef.Set_Width ( iWidth);
     *
     * @param iWidth [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Set_Width(int iWidth);
     //==============================================================================
     /**
     * @brief // set dec in def type class <BR>
     * iStat = oVarDef.Set_iDec( iDec);
     *
     * @param iDec [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Set_Dec(int iDec);
     //==============================================================================
     /**
     * @brief // Get System Name from def type class <BR>
     * oSysNamStr = oVarDef.Get_SysNam();
     *
     * @return string SysNam
     */
     // ----------------------------------------------------------------------------
     std::string Get_SysNam();
     //==============================================================================
     /**
     * @brief // Get class/object Name from def type class <BR>
     * oObjNamStr = oVarDef.Get_ObjNam();
     *
     * @return string ObjNam
     */
     // ----------------------------------------------------------------------------
     std::string Get_ObjNam();
     //==============================================================================
     /**
     * @brief // Get variable/element Name from def type class <BR>
     * oEleNamStr = oVarDef.Get_EleNam();
     *
     * @return string EleNam
     */
     // ----------------------------------------------------------------------------
     std::string Get_EleNam();
     //==============================================================================
     /**
     * @brief // Get System Info from def type class <BR>
     * oSysInfoStr = oVarDef.Get_SysInfo();
     *
     * @return string SysInfo
     */
     // ----------------------------------------------------------------------------
     std::string Get_SysInfo();
     //==============================================================================
     /**
     * @brief // Get class/object Info from def type class <BR>
     * oObjInfoStr = oVarDef.Get_ObjInfo();
     *
     * @return string ObjInfo
     */
     // ----------------------------------------------------------------------------
     std::string Get_ObjInfo();
     //==============================================================================
     /**
     * @brief // Get variable/element Info from def type class <BR>
     * oEleInfoStr = oVarDef.Get_EleInfo();
     *
     * @return string EleInfo
     */
     // ----------------------------------------------------------------------------
     std::string Get_EleInfo();
     //==============================================================================
     /**
     * @brief // Get variable type from def type class <BR>
     * eVarType = oVarDef.Get_Type();
     *
     * @return enum type
     */
     // ----------------------------------------------------------------------------
     sstStr01VarType_enum Get_Type();
     //==============================================================================
     /**
     * @brief // Get width from def type class <BR>
     * iWidth = oVarDef.Get_Width();
     *
     * @return int variable width
     */
     // ----------------------------------------------------------------------------
     int Get_Width();
     //==============================================================================
     /**
     * @brief // Get dec from def type class <BR>
     * iDec = oVarDef.Get_Dec();
     *
     * @return string int dec
     */
     // ----------------------------------------------------------------------------
     int Get_Dec();
     //==============================================================================

  private:  // Private Funktionen
     char cSysNam[dSST_STR01_VAR_NAM_LEN];  //!< System (Lib) name of classes          */
     char cObjNam[dSST_STR01_VAR_NAM_LEN];  //!< Class name                            */
     char cEleNam[dSST_STR01_VAR_NAM_LEN];  //!< Name of member variable               */
     sstStr01VarType_enum eType;              //!< Type of member variable               */
     int iWidth;                      //!< Whole Width ( incl. Dec) in file row 1 - 9999  */
     int iDec;                        //!< Dec of float/double in file row 0 - 6 */
     char cSysInfo[dSST_STR01_VAR_NAM_LEN];      //!< Info String for System / Library for doxygen  */
     char cObjInfo[dSST_STR01_VAR_NAM_LEN];      //!< Info String for Class for doxygen             */
     char cEleInfo[dSST_STR01_VAR_NAM_LEN];      //!< Info String for Class Element for doxygen     */
};
//==============================================================================
/**
* @brief Definition sstStr01Cls
*
* More Comment
*
* Changed: 10.07.13 Re.
*
* @ingroup sstStr01Lib
*
* @author Re.
*
* @date 10.07.13
*/
// ----------------------------------------------------------------------------
class sstStr01Cls
{
  public:   // Öffentliche Funktionen
     sstStr01Cls();  // Konstruktor
     ~sstStr01Cls();

     //=============================================================================
     /**
     * @brief // Convert csv information from row positon in integer  <BR>
     * iStat = oSstStr.CsvString2_2Int2 ( iKey, *oZeile, *iRetVal);
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @param iKey      [in]     For the moment 0
     * @param oZeile    [in]     Lese-String
     * @param iRetVal   [out]    Result-Int2
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 30.03.10
     */
     //-----------------------------------------------------------------------------
     int CsvString2_Int2 ( int              iKey,
                           std::string     *oZeile,
                           int             *iRetVal);
     //=============================================================================
     /**
     * @brief // Convert csv information from row positon in unsigned integer <BR>
     * iStat = oSstStr.CsvString2_UInt2 ( iKey, *oZeile, *uiRetVal);
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @param iKey      [in]     For the moment 0
     * @param oZeile    [in]     Lese-String
     * @param uiRetVal  [out]    Result-Int2
     *
     * @return Errorstate
     *
     * @retval   = 0: OKSetReadPositon
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 30.03.10
     */
     //-----------------------------------------------------------------------------
     int CsvString2_UInt2 ( int             iKey,
                            std::string    *oZeile,
                            unsigned int   *uiRetVal);
     //=============================================================================
     /**
     * @brief // Convert csv information from row positon to long integer <BR>
     * iStat = oSstStr.CsvString2_Int4 ( iKey, *oZeile, *lRetVal);
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @param iKey      [in]     For the moment 0
     * @param oZeile    [in]     Lese-String
     * @param lRetVal   [out]    Result-Int4
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 30.03.10
     */
     //-----------------------------------------------------------------------------
     int CsvString2_Int4 ( int              iKey,
                           std::string     *oZeile,
                           long            *lRetVal);
     //=============================================================================
     /**
     * @brief // Convert csv information from row positon in unsigned long integer <BR>
     * iStat = oSstStr.CsvString2_UInt4 ( iKey, *oZeile, *ulRetVal);
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @param iKey      [in]     For the moment 0
     * @param oZeile    [in]     Lese-String
     * @param ulRetVal  [out]    Result-Unsigned Int4
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 30.03.10
     */
     //-----------------------------------------------------------------------------
     int CsvString2_UInt4 ( int               iKey,
                            std::string      *oZeile,
                            unsigned long    *ulRetVal);
     //=============================================================================
     /**
     * @brief // Convert csv information from row positon to double <BR>
     * iStat = oSstStr.CsvString2_2Dbl ( iKey, *oZeile, *dRetVal);
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @param iKey      [in]     For the moment 0
     * @param oZeile    [in]     Lese-String
     * @param dRetVal   [out]    Result-Double
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 30.03.10
     */
     //-----------------------------------------------------------------------------
     int CsvString2_Dbl ( int              iKey,
                          std::string     *oZeile,
                          double          *dRetVal);
     //=============================================================================
     /**
     * @brief // Convert csv information from row positon to float <BR>
     * iStat = oSstStr.CsvString2_2Flt ( iKey, *oZeile, *fRetVal);
     *
     * Changed: 30.03.10  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey      [in]     For the moment 0
     * @param oZeile    [in]     Lese-String
     * @param fRetVal   [out]    Result-float
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 30.03.10
     */
     //-----------------------------------------------------------------------------
     int CsvString2_Flt ( int              iKey,
                          std::string     *oZeile,
                          float           *fRetVal);
     //=============================================================================
     /**
     * @brief // Convert csv information from row positon in sst string <BR>
     * iStat = oSstStr.CsvString2_Str ( iKey, *oZeile, *sRetStr);
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @param iKey      [in]     For the moment 0
     * @param oZeile    [in]     Lese-String
     * @param sRetStr   [out]    Result-String
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 30.03.10
     */
     //-----------------------------------------------------------------------------
     int CsvString2_Str ( int               iKey,
                          std::string      *oZeile,
                          std::string      *sRetStr);
     //=============================================================================
     /**
     * @brief // Convert csv information from row positon to bool  <BR>
     * iStat = oSstStr.CsvString2_Bool ( iKey, *oZeile, *bRetVal);
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @param iKey     [in]     For the moment 0
     * @param oZeile   [in]     Lese-String
     * @param bRetVal  [out]    Result Bool
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 30.03.10
     */
     //-----------------------------------------------------------------------------
     int CsvString2_Bool ( int              iKey,
                           std::string     *oZeile,
                           bool            *bRetVal);
     //=============================================================================
     /**
     * @brief // Convert csv information from row positon to char string <BR>
     * iStat = oSstStr.CsvString2_Char ( iKey, *oZeile, *cRetVal, ulRetValLen)
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @param iKey         [in]     For the moment 0
     * @param oZeile       [in]     Lese-String
     * @param cRetVal      [out]    Result Bool
     * @param ulRetValLen  [in]     Result Bool
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 30.03.10
     */
     //-----------------------------------------------------------------------------
     int CsvString2_Char ( int              iKey,
                           std::string     *oZeile,
                           char            *cRetVal,
                           unsigned long    ulRetValLen);
     //=============================================================================
     /**
     * @brief // Convert csv information to string vector array <BR>
     * iStat = oSstStr.CsvString2_VectorAll ( iKey, &oCsvRow, &data)
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @param iKey      [in]     For the moment 0
     * @param oCsvRow   [in]     Lese-String
     * @param data      [out]    return Vector array of strings
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 30.03.10
     */
     //-----------------------------------------------------------------------------
     int CsvString2_VectorAll ( int                  iKey,
                                const std::string    oCsvRow,
                                std::vector<std::string> *data);
     //==============================================================================
     /**
     * @brief // convert short int to csv-formatted string and append to string <BR>
     * iStat = oSstStr.Csv_Int2_2String ( iKey, iVal, *oSstStr);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param iVal     [in] short integer value
     * @param oSstStr  [in out] csv-formatted string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 04.05.11
     */
     //------------------------------------------------------------------------------
     int Csv_Int2_2String  (int               iKey,
                            int               iVal,
                            std::string      *oSstStr);
     //==============================================================================
     /**
     * @brief // convert unsigned short int to csv-formatted string and append to string <BR>
     * iStat = oSstStr.Csv_UInt2_2String ( iKey, iVal, *oSstStr);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param uiVal    [in] short integer value
     * @param oSstStr  [in out] csv-formatted string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 04.05.11
     */
     //------------------------------------------------------------------------------
     int Csv_UInt2_2String  (int               iKey,
                            unsigned int      uiVal,
                            std::string      *oSstStr);
     //==============================================================================
     /**
     * @brief // convert long int to csv-formatted string and append to string <BR>
     * iStat = oSstStr.Csv_Int4_2String ( iKey, lVal, *oSstStr);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in]     For the moment 0
     * @param lVal     [in]     long integer value
     * @param oSstStr  [in out] csv-formatted string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 04.05.11
     */
     //------------------------------------------------------------------------------
     int Csv_Int4_2String (int              iKey,
                          long              lVal,
                          std::string      *oSstStr);
     //==============================================================================
     /**
     * @brief // convert long int to csv-formatted string and append to string <BR>
     * iStat = oSstStr.Csv_Int4_2String ( iKey, lVal, *oSstStr);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in]     For the moment 0
     * @param ulVal    [in]     long integer value
     * @param oSstStr  [in out] csv-formatted string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 04.05.11
     */
     //------------------------------------------------------------------------------
     int Csv_UInt4_2String (int               iKey,
                            unsigned long     ulVal,
                            std::string      *oSstStr);
     //==============================================================================
     /**
     * @brief // convert double value to csv-formatted string and append to string <BR>
     * iStat = oSstStr.Csv_Dbl_2String ( iKey, dVal, *oSstStr);
     *
     * Decimal Formatted with intern value uiDec.
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param dVal     [in] double value
     * @param oSstStr  [in out] csv-formatted string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 04.05.11
     */
     //------------------------------------------------------------------------------
     int Csv_Dbl_2String ( int               iKey,
                           double            dVal,
                           std::string      *oSstStr);
     //==============================================================================
     /**
     * @brief // convert float value to csv-formatted string with format info and append to string <BR>
     * iStat = oSstStr.Csv_Dbl_2String ( iKey, *cFmtStr, dVal, *oSstStr);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param cFmtStr  [in] Format String
     * @param fVal     [in] double value
     * @param oSstStr  [in out] csv-formatted string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 04.05.11
     */
     //------------------------------------------------------------------------------
     int Csv_Real_2String (int               iKey,
                           char             *cFmtStr,
                           float             fVal,
                           std::string      *oSstStr);
     //==============================================================================
     /**
     * @brief // convert double value to csv-formatted string with format info and append to string <BR>
     * iStat = oSstStr.Csv_Dbl_2String ( iKey, *cFmtStr, dVal, *oSstStr);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param cFmtStr  [in] Format String
     * @param dVal     [in] double value
     * @param oSstStr  [in out] csv-formatted string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 04.05.11
     */
     //------------------------------------------------------------------------------
     int Csv_DblFrmt_2String (int               iKey,
                              char             *cFmtStr,
                              double            dVal,
                              std::string      *oSstStr);
     //==============================================================================
     /**
     * @brief // convert string value to csv-formatted string and append to string <BR>
     * iStat = oSstStr.Csv_Str_2String ( iKey, oVal, *oSstStr);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param oVal     [in] string value
     * @param oSstStr  [in out] csv-formatted string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 04.05.11
     */
     //------------------------------------------------------------------------------
     int Csv_Str_2String (int               iKey,
                          std::string       oVal,
                          std::string      *oSstStr);
     //==============================================================================
     /**
     * @brief // convert char string value to csv-formatted string and append to string <BR>
     * iStat = oSstStr.Csv_Char_2String ( iKey, cVal, *oSstStr);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param cVal     [in] string value
     * @param oSstStr  [in out] csv-formatted string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 04.05.11
     */
     //------------------------------------------------------------------------------
     int Csv_Char_2String (int               iKey,
                           char             *cVal,
                           std::string      *oSstStr);
     //==============================================================================
     /**
     * @brief // convert bool value to csv-formatted string and append to string <BR>
     * iStat = oSstStr.Csv_Bool_2String ( iKey, bVal, *oSstStr);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param bVal     [in] bool value
     * @param oSstStr  [in out] csv-formatted string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 04.05.11
     */
     //------------------------------------------------------------------------------
     int Csv_Bool_2String (int               iKey,
                           bool              bVal,
                           std::string      *oSstStr);
     //==============================================================================
     /**
     * @brief // Set Braket chars  "xx";"yy" <BR>
     * iStat = oSstStr.SetBracket( iKey, *cBracket);
     *
     * double quote:  For example "\x22"
     *
     * @param iKey     [in] For the moment 0
     * @param cBracket [in] one or two bracket chars
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     int SetBracket(int iKey, char *cBracket);
     //==============================================================================
     /**
     * @brief // Set Separator char  1;2;3;4  <BR>
     * iStat = oSstStr.SetSeparator( iKey, *cSeparator);
     *
     * @param iKey       [in] For the moment 0
     * @param cSeparator [in] CSV Separator: for example ";" (default)
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     int SetSeparator(int iKey, char *cSeparator);
     //==============================================================================
     /**
     * @brief // Get Separator char  1;2;3;4  <BR>
     * oSepStr = oSstStr.GetSeparator();
     *
     * @return Separator String
     */
     std::string GetSeparator();
     //==============================================================================
     /** Set No Information  char
     *
     * @param iKey For the moment 0
     * @param cNoInfoChar CSV Separator: for example ";" (default)
     *
     */
     int SetNoInfoChar(int iKey, char *cNoInfoChar);
     //==============================================================================
     /**
     * @brief // Set Read Position in String <BR>
     * iStat = oSstStr.SetReadPositon ( iKey, ulStartReadPos);
     *
     * @param iKey           [in] For the moment 0
     * @param ulStartReadPos [in] Set new Read position
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     int SetReadPositon (int iKey, unsigned long ulStartReadPos);
     //==============================================================================
     /**
     * @brief // Set Separator type <BR>
     * iStat = oSstStr.SetSeparatorTyp( iKey, iSeparatorTyp);
     *
     * @param iKey          [in] For the moment 0
     * @param iSeparatorTyp [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int SetSeparatorTyp(int iKey, int iSeparatorTyp);
     //==============================================================================
     /**
     * @brief // Set Bool type <BR>
     * iStat = oSstStr.SetBoolTyp( iKey, iBoolTyp);
     *
     * @param iKey     [in] For the moment 0
     * @param iBoolTyp [in] 0=0/1, 1=F/T, 2=.F./.T.
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int SetBoolTyp(int iKey, int iBoolTyp);
     //==============================================================================
     /**
     * @brief // Get Separator type <BR>
     * iSeparatorTyp = oSstStr.GetSeparatorTyp();
     *
     * @retval   = Separator type
     */
     // ----------------------------------------------------------------------------
     int GetSeparatorTyp();
     //==============================================================================
     /**
     * @brief // Get Bool type <BR>
     * iBoolTyp = SstStr.GetBoolTyp();
     *
     * @retval   = Bool Type
     */
     // ----------------------------------------------------------------------------
     int GetBoolTyp();
     //==============================================================================
     /**
     * @brief Get Errorstring
     *
     * @retval   Return Errorstring
     */
     // ----------------------------------------------------------------------------
     std::string GetErrorString();
     //==============================================================================
     /**
     * @brief Reset Interpreting conditions
     */
     // ----------------------------------------------------------------------------
     void ClearAll();
     //==============================================================================
     /**
     * @brief // Look for next Bracket Open and Close and return string inside <BR>
     * iStat = oSstStr.GetNextBrakeInfo( iKey, &oStrInput, oStrResult);
     *
     * @param iKey       [in]  For the moment 0
     * @param oStrInput  [in]  input string
     * @param oStrResult [out] return string inside brackets
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int GetNextBrakeInfo (int             iKey,
                           std::string    *oStrInput,
                           std::string    *oStrResult);
     //==============================================================================
     /**
     * @brief // Get dec type <BR>
     * iDecTyp = oSstStr.getDecType();
     *
     * floating comma = 0 (default)  <BR>
     * floating point = 1  <BR>
     *
     * @return int Decimal type
     */
     // ----------------------------------------------------------------------------
     int getDecType() const;
     //==============================================================================
     /**
     * @brief // Set decimal type <BR>
     * oSstStr.SetDecType ( value);
     *
     * floating comma = 0 (default)  <BR>
     * floating point = 1  <BR>
     *
     * @param value [in] Decimal type
     */
     // ----------------------------------------------------------------------------
     void setDecType(int value);
     //==============================================================================
     /**
     * @brief // Get number of decimal values for formatting double/float  <BR>
     * uiValue = oSstStr.getUiDec();
     *
     * Default is uiDec = 3
     *
     * @return unsigned int value
     */
     // ----------------------------------------------------------------------------
     unsigned int getUiDec() const;
     //==============================================================================
     /**
     * @brief // Set number of decimal values for formatting double/float <BR>
     * oSstStr.SetUiVal ( value);
     *
     * Default is uiDec = 3
     *
     * @param value [in] value
     */
     // ----------------------------------------------------------------------------
     void setUiDec(unsigned int value);
     //==============================================================================
     /**
     * @brief // Get actual read position  <BR>
     * ulPos = oSstStr.getReadPosition();
     *
     * @return unsigned long read position
     */
     // ----------------------------------------------------------------------------
     unsigned long getReadPosition() const;
     //==============================================================================

private:  // Private functions
     sstStr01IntCls *poStr01Intern;   /**< Pointer to intern object */
};


//==============================================================================
/**
* @brief Definition Class sstStr01VarDefFncCls
*
* More Comment
*
* Changed: 22.06.15  Re.
*
* @ingroup sstStr01Lib
*
* @author Re.
*
* @date 22.06.15
*/
// ----------------------------------------------------------------------------
class sstStr01VarDefFncCls
{
  public:   // Public functions
     sstStr01VarDefFncCls();   // Constructor
  //   ~X();   // Destructor
     //==============================================================================
     /**
     * @brief Read CSV Row from file as sstStr01VarDefCls object
     *
     * iStat = oVarDefFnc.ReadCSV( iKey, *sFilStr, *sErrTxt, *oStrType);
     *
     * @param iKey     [in] For the moment 0
     * @param sFilStr  [in]
     * @param sErrTxt  [out]
     * @param oStrType [out]
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadCSV(int           iKey,
                 std::string  *sFilStr,
                 std::string  *sErrTxt,
                 sstStr01VarDefCls *oStrType);
       //==============================================================================
       /**
       * @brief Write sstStr01VarDefCls object to CSV Row into file
       *
       * iStat = oVarDefFnc.WriteCSV( iKey, *oSstType, *sErrTxt, *sExpStr);
       *
       * @param iKey     [in] For the moment 0
       * @param oSstType [in]
       * @param sErrTxt  [out]
       * @param sExpStr  [out]
       *
       * @return Errorstate
       *
       * @retval   = 0: OK
       * @retval   < 0: Unspecified Error
       */
       // ----------------------------------------------------------------------------
     int WriteCSV(int            iKey,
                  sstStr01VarDefCls  oSstType,
                  std::string   *sErrTxt,
                  std::string   *sExpStr);
// ----------------------------------------------------------------------------
  // int Dum2;       /**< Dummy2 */
  private:  // Private functions
  //  int Dum;        /**< Dummy */
  sstStr01Cls oCnvtStr;  /**< Convert String system */
};
//==============================================================================
/**
* @brief CSV Test Class sstStr01Ds_Csv_Cls
*
* More Comment
*
* Changed: 19.02.10  Re.
*
* @ingroup sstStr01Lib
*
* @author Re.
*
* @date 19.02.10
*/
// ----------------------------------------------------------------------------
class sstStr01TestRecSmallCls
{
  public:   // Öffentliche Funktionen
     sstStr01TestRecSmallCls();  // Konstruktor
    // ~X();  // Destruktor
     //==============================================================================
     /**
     * @brief // Get test integer value
     * iVal = oTestRecSmall.getIVal();
     *
     * @return value
     */
     // ----------------------------------------------------------------------------
     int getIVal() const;
     //==============================================================================
     /**
     * @brief // set Variable element name in def type class <BR>
     * iStat = oTestRecSmall.setIVal(Value);
     *
     * @param value [in] value
     */
     // ----------------------------------------------------------------------------
     void setIVal(int value);
     //==============================================================================
     /**
     * @brief // Get test char value
     * cVal = oTestRecSmall.getCVal();
     *
     * @return string ObjNam
     */
     // ----------------------------------------------------------------------------
     char* getCVal();
     //==============================================================================
     /**
     * @brief // set test char value
     * iStat = oTestRecSmall.setCVal(value);
     *
     * @param value [in] value
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     void setCVal(const char *value);
     //==============================================================================
private:  // Private Funktionen
     int iVal;              //!< Test Value Integer
     char cVal[21];         //!< Test Value Char String
};
//==============================================================================
/**
* @brief Test CSV Read/Write Class sstStr01TestRecFullFncCls
*
* Read and Write CSV Testobject to row
*
* Changed: 21.04.15  Re.
*
* @ingroup sstStr01Lib
*
* @author Re.
*
* @date 21.04.15
*/
// ----------------------------------------------------------------------------
class sstStr01TestRecSmallFncCls
{
  public:   // Public functions
     sstStr01TestRecSmallFncCls();   // Constructor
     //==============================================================================
     /**
     * @brief Write TestRecord to Row
     *
     * iStat = oCsvRowFnc.WrtCsv(  iKey, *oFrmtTyp, *sErrStr, *oCsvSet, *sResult_Row);
     *
     * @param iKey [in]         For the moment 0
     * @param oFrmtTyp [in]     For the moment 0
     * @param sErrStr [in]      For the moment 0
     * @param oCsvSet [in]      For the moment 0
     * @param sResult_Row [out]  Result row
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtCsv( int               iKey,
                 sstStr01Cls *oFrmtTyp,
                 std::string      *sErrStr,
                 sstStr01TestRecSmallCls    *oCsvSet,
                 std::string      *sResult_Row);
     //==============================================================================
     /**
     * @brief Read TestRecord from Row
     *
     * iStat = oCsvRowFnc.ReadCsv( iKey, *oFrmtTyp, *sTstTxt, *sErrTxt, *oCsvSet);
     *
     * @param iKey [in]     For the moment 0
     * @param oFrmtTyp [in] For the moment 0
     * @param sTstTxt  [in]  For the moment 0
     * @param sErrTxt  [in]  For the moment 0
     * @param oCsvSet  [out] result test object
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadCsv( int            iKey,
                  sstStr01Cls *oFrmtTyp,
                  std::string   *sTstTxt,
                  std::string   *sErrTxt,
                  sstStr01TestRecSmallCls *oCsvSet);
    // ~X();   // Destructor
// ----------------------------------------------------------------------------
  private:  // Private functions
};
//==============================================================================
/**
* @brief CSV Test Class sstStr01Ds_Csv_Cls
*
* More Comment
*
* Changed: 19.02.10  Re.
*
* @ingroup sstStr01Lib
*
* @author Re.
*
* @date 19.02.10
*/
// ----------------------------------------------------------------------------
class sstStr01TestRecFullCls
{
  public:   // Öffentliche Funktionen
     sstStr01TestRecFullCls();  // Konstruktor
    // ~X();  // Destruktor
     //==============================================================================
     /**
     * @brief // Get test value
     * iVal = oTestRecFull.getVal();
     *
     * @return value
     */
     // ----------------------------------------------------------------------------
     int getIVal() const;
     //==============================================================================
     /**
     * @brief // set Value <BR>
     * iStat = oTestRecFull.setVal(Value);
     *
     * @param value [in] value
     */
     // ----------------------------------------------------------------------------
     void setIVal(int value);

     //==============================================================================
     /**
     * @brief // Get test value
     * iVal = oTestRecFull.getVal();
     *
     * @return value
     */
     // ----------------------------------------------------------------------------
     long getLVal() const;
     //==============================================================================
     /**
     * @brief // set Value <BR>
     * iStat = oTestRecFull.setVal(Value);
     *
     * @param value [in] value
     */
     // ----------------------------------------------------------------------------
     void setLVal(long value);

     //==============================================================================
     /**
     * @brief // Get test value
     * iVal = oTestRecFull.getVal();
     *
     * @return value
     */
     // ----------------------------------------------------------------------------
     unsigned int getUiVal() const;
     //==============================================================================
     /**
     * @brief // set Value <BR>
     * iStat = oTestRecFull.setVal(Value);
     *
     * @param value [in] value
     */
     // ----------------------------------------------------------------------------
     void setUiVal(unsigned int value);

     //==============================================================================
     /**
     * @brief // Get test value
     * iVal = oTestRecFull.getVal();
     *
     * @return value
     */
     // ----------------------------------------------------------------------------
     unsigned long getUlVal() const;
     //==============================================================================
     /**
     * @brief // set Value <BR>
     * iStat = oTestRecFull.setVal(Value);
     *
     * @param value [in] value
     */
     // ----------------------------------------------------------------------------
     void setUlVal(unsigned long value);

     //==============================================================================
     /**
     * @brief // Get test value
     * iVal = oTestRecFull.getVal();
     *
     * @return value
     */
     // ----------------------------------------------------------------------------
     double getDVal() const;
     //==============================================================================
     /**
     * @brief // set Value <BR>
     * iStat = oTestRecFull.setVal(Value);
     *
     * @param value [in] value
     */
     // ----------------------------------------------------------------------------
     void setDVal(double value);

     //==============================================================================
     /**
     * @brief // Get test value
     * iVal = oTestRecFull.getVal();
     *
     * @return value
     */
     // ----------------------------------------------------------------------------
     float getFVal() const;
     //==============================================================================
     /**
     * @brief // set Value <BR>
     * iStat = oTestRecFull.setVal(Value);
     *
     * @param value [in] value
     */
     // ----------------------------------------------------------------------------
     void setFVal(float value);

     //==============================================================================
     /**
     * @brief // Get test value
     * iVal = oTestRecFull.getVal();
     *
     * @return value
     */
     // ----------------------------------------------------------------------------
     std::string getSVal() const;
     //==============================================================================
     /**
     * @brief // set Value <BR>
     * iStat = oTestRecFull.setVal(Value);
     *
     * @param value [in] value
     */
     // ----------------------------------------------------------------------------
     void setSVal(const std::string &value);

     //==============================================================================
     /**
     * @brief // Get test value
     * iVal = oTestRecFull.getVal();
     *
     * @return value
     */
     // ----------------------------------------------------------------------------
     char* getCVal();
     //==============================================================================
     /**
     * @brief // set Value <BR>
     * iStat = oTestRecFull.setVal(Value);
     *
     * @param value [in] value
     */
     // ----------------------------------------------------------------------------
     void setCVal(const char *value);

     //==============================================================================
     /**
     * @brief // Get test value
     * iVal = oTestRecFull.getVal();
     *
     * @return value
     */
     // ----------------------------------------------------------------------------
     bool getBVal() const;
     //==============================================================================
     /**
     * @brief // set Value <BR>
     * iStat = oTestRecFull.setVal(Value);
     *
     * @param value [in] value
     */
     // ----------------------------------------------------------------------------
     void setBVal(bool value);

private:  // Private Funktionen
     int iVal;              //!< Test Value Integer
     long lVal;             //!< Test Value Long Integer
     unsigned int uiVal;    //!< Test Value unsigned Integer
     unsigned long ulVal;   //!< Test Value unsigned Long Integer
     double dVal;           //!< Test Value Double
     float fVal;            //!< Test Value Float
     std::string sVal;      //!< Test Value String Ds
     char cVal[21];         //!< Test Value Char String
     bool bVal;             //!< Test Value Bool
};
//==============================================================================
/**
* @brief Test CSV Read/Write Class sstStr01TestRecFullFncCls
*
* Read and Write CSV Testobject to row
*
* Changed: 21.04.15  Re.
*
* @ingroup sstStr01Lib
*
* @author Re.
*
* @date 21.04.15
*/
// ----------------------------------------------------------------------------
class sstStr01TestRecFullFncCls
{
  public:   // Public functions
     sstStr01TestRecFullFncCls();   // Constructor
     //==============================================================================
     /**
     * @brief Write TestRecord to Row
     *
     * iStat = oCsvRowFnc.WrtCsv(  iKey, *oFrmtTyp, *sErrStr, *oCsvSet, *sResult_Row);
     *
     * @param iKey [in]         For the moment 0
     * @param oFrmtTyp [in]     For the moment 0
     * @param sErrStr [in]      For the moment 0
     * @param oCsvSet [in]      For the moment 0
     * @param sResult_Row [out]  Result row
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtCsv( int               iKey,
                 sstStr01Cls *oFrmtTyp,
                 std::string      *sErrStr,
                 sstStr01TestRecFullCls    *oCsvSet,
                 std::string      *sResult_Row);
     //==============================================================================
     /**
     * @brief Read TestRecord from Row
     *
     * iStat = oCsvRowFnc.ReadCsv( iKey, *oFrmtTyp, *sTstTxt, *sErrTxt, *oCsvSet);
     *
     * @param iKey [in]     For the moment 0
     * @param oFrmtTyp [in] For the moment 0
     * @param sTstTxt  [in]  For the moment 0
     * @param sErrTxt  [in]  For the moment 0
     * @param oCsvSet  [out] result test object
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadCsv( int            iKey,
                  sstStr01Cls *oFrmtTyp,
                  std::string   *sTstTxt,
                  std::string   *sErrTxt,
                  sstStr01TestRecFullCls *oCsvSet);
    // ~X();   // Destructor
// ----------------------------------------------------------------------------
  private:  // Private functions
};
//==============================================================================

// Do some intern sstStr01 Tests
int sstStr01_DoSomeInternTests (int iKey);

#endif

// --------------------------------------------------------------- File End ----
