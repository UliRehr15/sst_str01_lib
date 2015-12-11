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
// sstStr01Lib.h   07.12.15  Re.   24.11.15  Re.
//
// Datastructures and Prototypes for system "sstStrLib"
//

#ifndef   _SST_STR01_LIB_HEADER
#define   _SST_STR01_LIB_HEADER

/**
 * @defgroup sstStr01Lib
 * cpp string library for sst
 */

// Defines ---------------------------------------------------------------------

#define dSTR1_TEXTLEN   300  // temporary row length maximum

/**
 * @brief Extended explanation for define
 * @ingroup sstTemplateLib
 */
#define dKODE_MIN


#define CINT1_MIN         (-127-1)   // Minimum für Cint1
#define CINT1_MAX           127      // Maximum für Cint1
#define CUINT1_MAX          256U     // Maximum für Cuint1

#define CINT2_MIN       (-32767-1)   // Minimum für Cint2
#define CINT2_MAX         32767      // Maximum für Cint2
#define CUINT2_MAX        65535U     // Maximum für Cuint2

#define CINT4_MIN  (-2147483647L-1)  // Minimum für Cint4
#define CINT4_MAX    2147483647L     // Maximum für Cint4
#define CUINT4_MAX   4294967295UL    // Maximum für Cuint4

#define UNDEF_DOUBLE -999999999      // Undefine for Double

//**************************************************************************
//                Defines für Struktur FND_STRU
//**************************************************************************
/**
 * @brief Längendefinitionen für Dateinamen und Pfade
 */
#define FMS_NAME_LEN    13        /**< Filenamenlänge (ASCIZ-Länge)            @ingroup sstStr01Lib */
#define FMS_LONG_NAME   255       /**< Lange Dateinamen: max. ohne LW und Pfad @ingroup sstStr01Lib */
#define MAX_PFAD        260       /**< maximale Pfadlängen                     @ingroup sstStr01Lib */
#define MAX_CPFAD       MAX_PFAD  /**< maximale Länge eines Datei-Pfades       @ingroup sstStr01Lib */


// forward declaration ---------------------------------------------------------

// class sstTestBaseInternCls;
class sstStr01IntCls;

// Structures and Classes ------------------------------------------------------

//==============================================================================
/**
* @brief Definition sstStr01IntCls
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
     * @ingroup str_lib
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
     //==============================================================================
     /**
     * @brief // convert short int to csv-formatted string and append to string <BR>
     * iStat = oSstStr.Csv_Int2_2String ( iKey, iVal, *oSstStr, *oErrTxt);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param iVal     [in] short integer value
     * @param oSstStr  [in out] csv-formatted string
     * @param oErrTxt  [out] Error-String
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
     * iStat = oSstStr.Csv_UInt2_2String ( iKey, iVal, *oSstStr, *oErrTxt);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param uiVal    [in] short integer value
     * @param oSstStr  [in out] csv-formatted string
     * @param oErrTxt  [out] Error-String
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
     * iStat = oSstStr.Csv_Int4_2String ( iKey, lVal, *oSstStr, *oErrTxt);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in]     For the moment 0
     * @param lVal     [in]     long integer value
     * @param oSstStr  [in out] csv-formatted string
     * @param oErrTxt  [out]    Error-String
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
     * iStat = oSstStr.Csv_Int4_2String ( iKey, lVal, *oSstStr, *oErrTxt);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in]     For the moment 0
     * @param ulVal    [in]     long integer value
     * @param oSstStr  [in out] csv-formatted string
     * @param oErrTxt  [out]    Error-String
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
     * iStat = oSstStr.Csv_Dbl_2String ( iKey, dVal, *oSstStr, *oErrTxt);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param dVal     [in] double value
     * @param oSstStr  [in out] csv-formatted string
     * @param oErrTxt  [out] Error-String
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
     * iStat = oSstStr.Csv_Dbl_2String ( iKey, *cFmtStr, dVal, *oSstStr, *oErrTxt);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param cFmtStr  [in] Format String
     * @param fVal     [in] double value
     * @param oSstStr  [in out] csv-formatted string
     * @param oErrTxt  [out] Error-String
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
     * iStat = oSstStr.Csv_Dbl_2String ( iKey, *cFmtStr, dVal, *oSstStr, *oErrTxt);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param cFmtStr  [in] Format String
     * @param dVal     [in] double value
     * @param oSstStr  [in out] csv-formatted string
     * @param oErrTxt  [out] Error-String
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
     * iStat = oSstStr.Csv_Str_2String ( iKey, oVal, *oSstStr, *oErrTxt);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param oVal     [in] string value
     * @param oSstStr  [in out] csv-formatted string
     * @param oErrTxt  [out] Error-String
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
                          std::string      *oVal,
                          std::string      *oSstStr);
     //==============================================================================
     /**
     * @brief // convert char string value to csv-formatted string and append to string <BR>
     * iStat = oSstStr.Csv_Char_2String ( iKey, cVal, *oSstStr, *oErrTxt);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param cVal     [in] string value
     * @param oSstStr  [in out] csv-formatted string
     * @param oErrTxt  [out] Error-String
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
     * iStat = oSstStr.Csv_Bool_2String ( iKey, bVal, *oSstStr, *oErrTxt);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @param iKey     [in] For the moment 0
     * @param bVal     [in] bool value
     * @param oSstStr  [in out] csv-formatted string
     * @param oErrTxt  [out] Error-String
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
     * @brief // Set Braket chars <BR>
     * iStat = oSstStr.SetBracket( iKey, *cBracket);
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
     * @brief // Set Separator char <BR>
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
     * @param iBoolTyp [in] For the moment 0
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
  private:  // Private Funktionen
     sstStr01IntCls *poStr01Intern;   /**< Pointer to intern object */
};


// Do some intern sstStr01 Tests
int sstStr01_DoSomeInternTests (int iKey);

#endif

// --------------------------------------------------------------- File End ----
