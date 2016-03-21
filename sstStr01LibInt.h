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
// sstStr01LibInt.h   24.11.15  Re.   24.11.15  Re.
//
// Intern Datastructures and Prototypes for system "sstStrLib"
//

#ifndef   _SST_STR01_LIB_INT_HEADER
#define   _SST_STR01_LIB_INT_HEADER

/**
 * @defgroup sstStr01IntLib sstStr01IntLib: sst Intern String lib (Version 1)
 * cpp string library for intern sst
 */


// Defines ---------------------------------------------------------------------

// Forward definitions ---------------------------------------------------------
class sstStr01IntCls;

// Structures and Classes ------------------------------------------------------

//==============================================================================
/**
* @brief CSV Test Class StrDs_Csv_Cls
*
* More Comment
*
* Changed: 19.02.10  Re.
*
* @ingroup sstStr01IntLib
*
* @author Re.
*
* @date 19.02.10
*/
// ----------------------------------------------------------------------------
class StrDs_Csv_Cls
{
  public:   // Öffentliche Funktionen
     StrDs_Csv_Cls();  // Konstruktor
    // ~X();  // Destruktor
     int iRetInt;              //!< Return Value Integer
     long lRetLong;            //!< Return Value Long Integer
     unsigned int uiRetInt;    //!< Return Value unsigned Integer
     unsigned long ulRetLong;  //!< Return Value unsigned Long Integer
     double dRetDouble;        //!< Return Value Double
     float fRetFloat;          //!< Return Value Float
     std::string sRetStr;      //!< Return Value String Ds
     char cRetStr[21];         //!< Return Value Char String
     bool bVal;                //!< Return Value Bool
  private:  // Private Funktionen
};
//==============================================================================
/**
* @brief Test CSV Read/Write Class StrDs_CsvFnc_Cls
*
* Read and Write CSV Testobject to row
*
* Changed: 21.04.15  Re.
*
* @ingroup sstStr01IntLib
*
* @author Re.
*
* @date 21.04.15
*/
// ----------------------------------------------------------------------------
class StrDs_CsvFnc_Cls
{
  public:   // Public functions
     StrDs_CsvFnc_Cls();   // Constructor
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
                 sstStr01IntCls *oFrmtTyp,
                 std::string      *sErrStr,
                 StrDs_Csv_Cls    *oCsvSet,
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
                  sstStr01IntCls *oFrmtTyp,
                  std::string   *sTstTxt,
                  std::string   *sErrTxt,
                  StrDs_Csv_Cls *oCsvSet);
    // ~X();   // Destructor
// ----------------------------------------------------------------------------
  private:  // Private functions
};
//==============================================================================
//==============================================================================
/**
* @brief Definition sstStr01IntCls
*
* More Comment
*
* Changed: 10.07.13 Re.
*
* @ingroup sstStr01IntLib
*
* @author Re.
*
* @date 10.07.13
*/
// ----------------------------------------------------------------------------
class sstStr01IntCls
{
  public:   // Öffentliche Funktionen
     sstStr01IntCls();  // Konstruktor
     //=============================================================================
     /**
     * @brief // Csv ab Position in Integer konvertieren  <BR>
     * iStat = Str1_AbPosCsv2Int2 ( iKey, *Zeile, *iRetVal);
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in]     For the moment 0
     * @param Zeile    [in]     Lese-String
     * @param iRetVal  [out]    Result-Int2
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
     int CsvString2_Int2 ( int          iKey,
                           std::string *Zeile,
                           int         *iRetVal);
     //=============================================================================
     /**
     * @brief Convert csv information from row positon in unsigned integer
     *
     * iStat = CsvString2_UInt2 ( iKey, *Zeile, *uiRetVal);
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey      [in]     For the moment 0
     * @param Zeile     [in]     Lese-String
     * @param uiRetVal  [out]    Result-Int2
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
     int CsvString2_UInt2 ( int            iKey,
                            std::string   *Zeile,
                            unsigned int  *uiRetVal);
     //=============================================================================
     /**
     * @brief Csv ab Position in Long konvertieren
     *
     * iStat = CsvString2_Int4 ( iKey, *Zeile, *lRetVal);
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in]     For the moment 0
     * @param Zeile    [in]     Lese-String
     * @param lRetVal  [out]    Result-Int4
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
     int CsvString2_Int4 ( int          iKey,
                           std::string *Zeile,
                           long        *lRetVal);
     //=============================================================================
     /**
     * @brief Csv ab Position in Unsigned Long konvertieren
     *
     * iStat = CsvString2_UInt4 ( iKey, *Zeile, *ulRetVal);
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in]     For the moment 0
     * @param Zeile    [in]     Lese-String
     * @param ulRetVal [out]    Result-Unsigned Int4
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
                            std::string      *Zeile,
                            unsigned long    *ulRetVal);
     //=============================================================================
     /**
     * @brief Csv ab Position in Double konvertieren
     *
     * iStat = Str1_AbPosCsv2Dbl ( iKey, *Zeile, *dRetVal);
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in]     For the moment 0
     * @param Zeile    [in]     Lese-String
     * @param dRetVal  [out]    Result-Double
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
     int CsvString2_Dbl ( int          iKey,
                          std::string *Zeile,
                          double      *dRetVal);
     //=============================================================================
     /**
     * @brief Csv ab Position in Float konvertieren
     *
     * iStat = Str1_AbPosCsv2Flt ( iKey, *Zeile, *fRetVal);
     *
     * Changed: 30.03.10  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in]     For the moment 0
     * @param Zeile    [in]     Lese-String
     * @param fRetVal  [out]    Result-float
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
     int CsvString2_Flt ( int          iKey,
                          std::string *Zeile,
                          float       *fRetVal);
     //=============================================================================
     /**
     * @brief Convert csv information from row positon in sst string
     *
     * iStat = CsvString2_Str ( iKey, *Zeile, *sRetStr);
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in]     For the moment 0
     * @param Zeile    [in]     Lese-String
     * @param sRetStr  [out]    Result-String
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
                          std::string      *Zeile,
                          std::string      *sRetStr);
     //=============================================================================
     /**
     * @brief Csv ab Position in String konvertieren
     *
     * iStat = CsvString2_Bool ( iKey, *sZeile, *bRetVal);
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in]     For the moment 0
     * @param sZeile   [in]     Lese-String
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
     int CsvString2_Bool ( int          iKey,
                           std::string *sZeile,
                           bool         *bRetVal);
     //=============================================================================
     /**
     * @brief Csv ab Position in String konvertieren
     *
     * iStat = int CsvString2_Char ( iKey, *sZeile, *cRetVal, lRetValLen)
     *
     * More Comment
     *
     * Changed: 30.03.10  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey        [in]     For the moment 0
     * @param sZeile      [in]     Lese-String
     * @param cRetVal     [out]    Result Bool
     * @param lRetValLen  [in]    Result Bool
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
     int CsvString2_Char ( int          iKey,
                           std::string *sZeile,
                           char        *cRetVal,
                           long         lRetValLen);
     //==============================================================================
     /**
     * @brief convert short int to csv-formatted string and append to string
     *
     * iStat = Csv_Int2_2String ( iKey, iVal, &sst_str);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in] For the moment 0
     * @param iVal     [in] short integer value
     * @param sst_str  [in out] csv-formatted string
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
                            std::string      *sst_str);
     //==============================================================================
     /**
     * @brief convert short int to csv-formatted string and append to string
     *
     * iStat = Csv_UInt2_2String ( iKey, uiVal, sst_str);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in] For the moment 0
     * @param uiVal    [in] short integer value
     * @param sst_str  [in out] csv-formatted string
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
                             std::string      *sst_str);
     //==============================================================================
     /**
     * @brief convert long int to csv-formatted string and append to string
     *
     * iStat = Csv_Int4_2String ( iKey, lVal, *Zeile);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in]     For the moment 0
     * @param lVal     [in]     long integer value
     * @param sst_str  [in out] csv-formatted string
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
     int Csv_Int4_2String (int               iKey,
                           long              lVal,
                           std::string      *sst_str);
     //==============================================================================
     /**
     * @brief convert long int to csv-formatted string and append to string
     *
     * iStat = Csv_UInt4_2String ( iKey, ulVal, sst_str);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in]     For the moment 0
     * @param ulVal    [in]     long integer value
     * @param sst_str  [in out] csv-formatted string
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
                            std::string      *sst_str);
     //==============================================================================
     /**
     * @brief convert double value to csv-formatted string and append to string
     *
     * iStat = Csv_Dbl_2String ( iKey, dVal, *sst_str);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in] For the moment 0
     * @param dVal     [in] double value
     * @param sst_str  [in out] csv-formatted string
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
                           std::string      *sst_str);
     //==============================================================================
     /**
     * @brief convert double value to csv-formatted string and append to string
     *
     * iStat = Csv_Real_2String ( iKey, *cFmtStr, fVal, *sst_str);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in] For the moment 0
     * @param cFmtStr  [in] Format String
     * @param fVal     [in] double value
     * @param sst_str  [in out] csv-formatted string
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
                           std::string      *sst_str);
     //==============================================================================
     /**
     * @brief convert double value to csv-formatted string and append to string
     *
     * iStat = Csv_Dbl_2String ( iKey, *cFmtStr, dVal, *sst_str);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in] For the moment 0
     * @param cFmtStr  [in] Format String
     * @param dVal     [in] double value
     * @param sst_str  [in out] csv-formatted string
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
                              std::string      *sst_str);
     //==============================================================================
     /**
     * @brief convert string value to csv-formatted string and append to string
     *
     * iStat = Csv_Str_2String ( iKey, sVal, *sst_str);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in] For the moment 0
     * @param sVal     [in] string value
     * @param sst_str  [in out] csv-formatted string
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
                          std::string       sVal,
                          std::string      *sst_str);
     //==============================================================================
     /**
     * @brief convert string value to csv-formatted string and append to string
     *
     * iStat = Csv_Char_2String ( iKey, cVal, *sst_str);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in] For the moment 0
     * @param cVal     [in] string value
     * @param sst_str  [in out] csv-formatted string
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
                           std::string      *sst_str);
     //==============================================================================
     /**
     * @brief convert bool value to csv-formatted string and append to string
     *
     * iStat = Csv_Bool_2String ( iKey, bVal, *sst_str);
     *
     * More Comment
     *
     * Changed: 04.05.11  Re.
     *
     * @ingroup sstStr01IntLib
     *
     * @param iKey     [in] For the moment 0
     * @param bVal     [in] bool value
     * @param sst_str  [in out] csv-formatted string
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
                           std::string      *sst_str);
     //==============================================================================
     /** Set Braket chars
     * @param iKey For the moment 0
     * @param cBracket one or two bracket chars
     */
     int SetBracket(int iKey, char *cBracket);
     //==============================================================================
     /** Set Separator char
     * @param iKey For the moment 0
     * @param cSeparator CSV Separator: for example ";" (default)
     */
     int SetSeparator(int iKey, char *cSeparator);
     //==============================================================================
     /** Set Read Position in String
     * @param iKey For the moment 0
     * @param lStartReadPos Set new Read position
     */
     int SetReadPositon(int iKey, unsigned long lStartReadPos);
     //==============================================================================
     /**
     * @brief Shortstory
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
     * @brief Set bool type
     * iStat = oSstStr.SetBoolTyp(iKey,iBoolTyp);
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
     * @brief Shortstory
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int GetSeparatorTyp();
     //==============================================================================
     /**
     * @brief Get bool type
     * iBoolTyp = oSstStr.GetBoolTyp();
     *
     * @return int bool type
     */
     // ----------------------------------------------------------------------------
     int GetBoolTyp();
     //==============================================================================
     /**
     * @brief Get Adress of NoInfomation char
     *
     * @retval   Return adress of no information char
     */
     // ----------------------------------------------------------------------------
     char* GetNoInfoChar();
     //==============================================================================
     /**
     * @brief Get Adress of Brake Open char
     *
     * @retval   Return adress of Brake Open char
     */
     // ----------------------------------------------------------------------------
     char* GetBraketOpen();
     //==============================================================================
     /**
     * @brief Get Adress of Brake Close char
     *
     * @retval   Return adress of Brake Close char
     */
     // ----------------------------------------------------------------------------
     char* GetBraketClose();
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
     * @brief // Get dec type type  <BR>
     * iDecTyp = oSstStr.getDecType();
     *
     * @return int Decimal type
     */
     // ----------------------------------------------------------------------------
     int getDecType() const;
     //==============================================================================
     /**
     * @brief // Set decimal type  <BR>
     * oSstStr.SetDecType ( value);
     *
     * @param value [in] Decimal type
     */
     // ----------------------------------------------------------------------------
     void setDecType(int value);
     //==============================================================================

private:  // Private functions
    char cSeparator[2];     //!< Separator Character, for example " " or ";"   */
    char cBracket[2];   //!< For example "\x22"                    */
    char cBracketOpen[2];   //!< For example "("                     */
    char cBracketClose[2];  //!< For example ")"                    */
    char cNoInfo[2];      //!< For example " " blank                         */
    unsigned long ulPos;  //!< Read Position in sst String                  */
    int  iFormatKenn;     //!< fixcolumnformat=0; charseparatedformat=1      */
    int  iDecType;        //!< floating comma = 0; floating point = 1        */
    int  iSeparatorTyp;   //!< 0=No Sep, 1=only strings,2=All                */
    int  iBoolTyp;        //!< 0=0/1, 1=F/T,2=.F./.T.                        */
    std::string oErrStr;  //!< Error string                                  */
};


//=============================================================================

//=============================================================================
/**
* @brief Teil von String1 nach String2 kopieren
*
* iStat = Str1_Zeile2Str ( Key, Von, Bis, *txt1, *ErrTxt, *txt2);
*
* Weiterer Kommentar
*
* Geändert: 17.06.04  UR
*
* 11.09.01: Result-String default leer.   UR
* 11.03.03: Textspeicher jetzt Int4.  UR
* 17.06.04: Länge Errorstring exakt wie Resultstring !
* 30.08.04: Auch Blanks werden kopiert.  UR
* 04.06.14: Key=0:Blanks werden kopiert, Key=1:Blanks überlesen
*
* @ingroup sstStr01IntLib
*
* @param Key:    [in]  0 oder 1
* @param Von:    [in]  von Textposition
* @param Bis:    [in]  bis Textposition
* @param txt1:   [in]  Quelle
* @param ErrTxt: [out] Read-Error bei -Errtxt-
* @param txt2:   [out] Resultstring
*
* @return Fehlerstatus
*
* @retval   =0 = OK
* @retval   <0 = allgemeiner Fehler
*
* @author ur
*
* @date 30.06.00
*/
//-----------------------------------------------------------------------------
int Str1_Zeile2Str ( int          Key,
                     unsigned long         Von,
                     unsigned long         Bis,
                     std::string *txt1,
                     std::string *ErrTxt,
                     std::string *txt2);

//=============================================================================
/**
* @brief Teil von String nach Int2 konvertieren.
*
* iStat = Str1_Zeile2Int ( Key, Von, Bis, *txt1, *ErrTxt, *iRet);
*
* @ingroup sstStr01IntLib
*
* @param iKey    [in]   Vorerst immer 0
* @param Von     [in]   Von Textposition
* @param Bis     [in]   Bis Textposition
* @param txt1    [in]   Quelle
* @param ErrTxt  [out]  Read-Error bei ErrTxt
* @param iRet    [out]  Result Integer
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1_Zeile2Int ( int          iKey,
                     unsigned long         Von,
                     unsigned long         Bis,
                     std::string *txt1,
                     std::string *ErrTxt,
                     int         *iRet);

//=============================================================================
/**
* @brief Teil von String nach Int4 konvertieren.
*
* iStat = Str1_Zeile2Int4 ( iKey, Von, Bis, *txt, *ErrTxt, *lRet);
*
* @ingroup sstStr01IntLib
*
* @param iKey    [in]  Vorerst immer 0
* @param Von     [in]  Von Textposition
* @param Bis     [in]  Bis Textposition
* @param txt     [in]  Text Quelle
* @param ErrTxt  [in]  Read-Error bei ErrTxt
* @param lRet    [in]  Result Long Integer
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1_Zeile2Int4 ( int          iKey,
                      unsigned long         Von,
                      unsigned long         Bis,
                      std::string *txt,
                      std::string *ErrTxt,
                      long        *lRet);

//=============================================================================
/**
* @brief Teil von String nach Double  konvertieren.
*
* iStat = Str1_Zeile2Dbl ( iKey, Von, Bis, *txt1, *ErrTxt, *dRet);
*
* @ingroup sstStr01IntLib
*
* @param iKey    [in]  Vorerst immer 0
* @param Von     [in]  Von Textposition
* @param Bis     [in]  Bis Textposition
* @param txt1    [in]  Text Quelle
* @param ErrTxt  [out] Read-Error bei ErrTxt
* @param dRet    [out] Result Double
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1_Zeile2Dbl ( int           iKey,
                     unsigned long          Von,
                     unsigned long          Bis,
                     std::string  *txt1,
                     std::string  *ErrTxt,
                     double       *dRet);

//=============================================================================
/**
* @brief Kopieren eines String in einen Zeilenbereich
*
* iStat = Str1_Str2Zeile ( Key, Von, Bis, *sWert, *Zeile);
*
* Und zwar in -Zeile- Platz-genau !!
* Key = 0: linksbündig
* Key = 1: rechtsbündig
*
* Geändert: 27.06.05  UR
*
* 05.04.02: Zielstring verlängern, wenn Ende vor -Von-.    UR
* 16.12.02: Variable ii undefiniert nach -Zeile auffüllen-.   UR
* 19.02.03: Blanks im einzufügenden String sollen erlaubt sein.  UR
* 10.07.04: Nicht benötigte Positionen zwischen Von und Bis sollen
*           unverändert bleiben, solange sie innerhalb des Strings sind.  UR
* 13.07.04: Das Verhalten, wenn String aufgefüllt werden muß, wurde
*           angepasst.  UR
* 03.08.04: Rücksprung nur, wenn -Bis- größer -ZeilLen-
* 27.06.05: Doxy-Header.  UR
*
* @ingroup sstStr01IntLib
*
* @param Key:     [in]     0 oder 1
* @param Von:     [in]     von Textposition im Zielstring
* @param Bis:     [in]     bis Textposition im Zielstring
* @param sWert:   [in]     Quelle
* @param Zeile:   [in out] Zielstring
*
* @return Fehlerstatus
*
* @retval   = 0: OK
* @retval   < 0: Allgemeiner Fehler
*
* @author ur
*
* @date 07.07.00
*/
//-----------------------------------------------------------------------------
int Str1_Str2Zeile ( int          Key,
                     unsigned long         Von,
                     unsigned long         Bis,
                     std::string *sWert,
                     std::string *Zeile);

//=============================================================================
/**
* @brief Kopieren eines Char in einen Zeilenbereich
*
* iStat = Str1_Char2Zeile ( iKey, Von, Bis, *cWert, *Zeile);
*
* Und zwar in -Zeile- Platz-genau !!
* Key = 0: linksbündig
* Key = 1: rechtsbündig
*
* Geändert: 27.06.05  UR
*
* 14.09.12: Abgeleitet von Str1_Str2Zeile.    UR
*
* @ingroup sstStr01IntLib
*
* @param Key:     [in]     0 oder 1
* @param Von:     [in]     von Textposition im Zielstring
* @param Bis:     [in]     bis Textposition im Zielstring
* @param cWert:   [in]     Quelle
* @param Zeile:   [in out] Zielstring
*
* @return Fehlerstatus
*
* @retval   = 0: OK
* @retval   < 0: Allgemeiner Fehler
*
* @author ur
*
* @date 14.09.12
*/
//-----------------------------------------------------------------------------
int Str1_Char2Zeile ( int          Key,
                      unsigned long         Von,
                      unsigned long         Bis,
                      char        *cWert,
                      std::string *Zeile);

//=============================================================================
/**
* @brief Int2 in einen String konvertieren und in Zeilenbereich kopieren.
*
* iStat = Str1_Int2Zeile ( Key, Von, Bis, iWert, *Zeile, ZeilLen);
*
* Key = 0: linksbündig
* Key = 1: rechtsbündig
*
* Geändert: 28.06.05  UR
*
* 28.06.05: Doxy-Header.  UR
*
* @ingroup sstStr01IntLib
*
* @param Key:     [in]     0 oder 1
* @param Von:     [in]     von Textposition im Zielstring
* @param Bis:     [in]     bis Textposition im Zielstring
* @param iWert:   [in]     Quelle
* @param Zeile:   [in out] Zielstring (initialisiert!)
*
* @return Fehlerstatus
*
* @retval   = 0: OK
* @retval   < 0: Allgemeiner Fehler
*
* @author ur
*
* @date 07.07.00
*/
//-----------------------------------------------------------------------------
int Str1_Int2Zeile ( int          Key,
                     unsigned long         Von,
                     unsigned long         Bis,
                     int          iWert,
                     std::string *Zeile);
//=============================================================================
/**
* @brief UInt2 in einen String konvertieren und in Zeilenbereich kopieren.
*
* iStat = Str1_UInt2Zeile ( Key, Von, Bis, uiWert, *Zeile, ZeilLen);
*
* Key = 0: linksbündig
* Key = 1: rechtsbündig
*
* Geändert: 28.06.05  UR
*
* 28.06.05: Doxy-Header.  UR
*
* @ingroup sstStr01IntLib
*
* @param Key:     [in]     0 oder 1
* @param Von:     [in]     von Textposition im Zielstring
* @param Bis:     [in]     bis Textposition im Zielstring
* @param uiWert:  [in]     Quelle
* @param Zeile:   [in out] Zielstring (initialisiert!)
*
* @return Fehlerstatus
*
* @retval   = 0: OK
* @retval   < 0: Allgemeiner Fehler
*
* @author ur
*
* @date 07.07.00
*/
//-----------------------------------------------------------------------------
int Str1_UInt2Zeile ( int           Key,
                      unsigned long          Von,
                      unsigned long          Bis,
                      unsigned int  uiWert,
                      std::string  *Zeile);
//=============================================================================
/**
* @brief Int2 in einen String konvertieren und in Zeilenbereich kopieren.
*
* iStat = Str1_Int2Zeile ( Key, Von, Bis, iWert, *Zeile, ZeilLen);
*
* Key = 0: linksbündig
* Key = 1: rechtsbündig
* Format string %03i
*
* Geändert: 28.06.05  UR
*
* 28.06.05: Doxy-Header.  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey    [in]     0 oder 1
* @param Von     [in]     von Textposition im Zielstring
* @param Bis     [in]     bis Textposition im Zielstring
* @param iWert   [in]     Quelle
* @param cFmtStr [in]     Format string for intern sprintf
* @param Zeile   [in out] Zielstring (initialisiert!)
*
* @return Fehlerstatus
*
* @retval   = 0: OK
* @retval   < 0: Allgemeiner Fehler
*
* @author ur
*
* @date 07.07.00
*/
//-----------------------------------------------------------------------------
int Str1_Int2ZeileFmt ( int           iKey,
                        unsigned long          Von,
                        unsigned long          Bis,
                        int           iWert,
                        char         *cFmtStr,
                        std::string  *Zeile);

//=============================================================================
/**
* @brief Int4 in einen String konvertieren und in Zeilenbereich kopieren.
*
* iStat = Str1_Int4Zeile ( Key, Von, Bis, *lWert, *Zeile);
*
* Key = 0: linksbündig
* Key = 1: rechtsbündig
*
* Geändert: 28.06.05  UR
*
* 28.06.05: Doxy-Header.  UR
*
* @ingroup sstStr01IntLib
*
* @param Key:     [in]     0 oder 1
* @param Von:     [in]     von Textposition im Zielstring
* @param Bis:     [in]     bis Textposition im Zielstring
* @param lWert:   [in]     Quelle
* @param Zeile:   [in out] Zielstring
*
* @return Fehlerstatus
*
* @retval   = 0: OK
* @retval   < 0: Allgemeiner Fehler
*
* @author ur
*
* @date 07.07.00
*/
//-----------------------------------------------------------------------------
int Str1_Int4Zeile ( int          Key,
                     unsigned long         Von,
                     unsigned long         Bis,
                     long         lWert,
                     std::string *Zeile);
//=============================================================================
/**
* @brief Int4 in einen String konvertieren und in Zeilenbereich kopieren.
*
* iStat = Str1_Int4Zeile ( Key, Von, Bis, *lWert, *Zeile);
*
* Key = 0: linksbündig
* Key = 1: rechtsbündig
*
* Geändert: 28.06.05  UR
*
* 28.06.05: Doxy-Header.  UR
*
* @ingroup sstStr01IntLib
*
* @param Key     [in]     0 oder 1
* @param Von     [in]     von Textposition im Zielstring
* @param Bis     [in]     bis Textposition im Zielstring
* @param ulWert  [in]     Quelle
* @param Zeile   [in out] Zielstring
*
* @return Fehlerstatus
*
* @retval   = 0: OK
* @retval   < 0: Allgemeiner Fehler
*
* @author ur
*
* @date 07.07.00
*/
//-----------------------------------------------------------------------------
int Str1_UInt4Zeile ( int             Key,
                      unsigned long            Von,
                      unsigned long            Bis,
                      unsigned long   ulWert,
                      std::string    *Zeile);
//=============================================================================
/**
* @brief Real in einen String konvertieren und in Zeilenbereich kopieren.
*
* iStat = Str1_Real2ZeileFmt ( Key, Von, Bis, *fWert ,cFmtStr, *Zeile);
*
* Konvertieren eines Real in einen Zeilen-Bereich
* Key = 0: linksbündig
* Key = 1: rechtsbündig
*
* write 3 leading zero: for example: -001.22 or 022.34
*
* Geändert: 28.06.05  UR
*
* 05.04.02: Nachkomma-Stellen werden jetzt berücksichtigt.   UR
* 28.06.05: Doxy-Header.  UR
*
* @ingroup sstStr01IntLib
*
* @param Key:     [in]     0 oder 1
* @param Von:     [in]     von Textposition im Zielstring
* @param Bis:     [in]     bis Textposition im Zielstring
* @param fWert:   [in]     Quelle
* @param cFmtStr: [in]     Format string for intern sprintf
* @param Zeile:   [in out] Zielstring
*
* @return Fehlerstatus
*
* @retval   = 0: OK
* @retval   < 0: Allgemeiner Fehler
*
* @author ur
*
* @date 07.07.00
*/
//-----------------------------------------------------------------------------
int Str1_Real2ZeileFmt ( int           Key,
                         unsigned long          Von,
                         unsigned long          Bis,
                         float         fWert,
                         char         *cFmtStr,
                         std::string  *Zeile);
//=============================================================================
/**
* @brief Real in einen String konvertieren und in Zeilenbereich kopieren.
*
* iStat = Str1_Real2Zeile ( Key, Von, Bis, *fWert ,NachKo, *Zeile);
*
* Konvertieren eines Real in einen Zeilen-Bereich
* Key = 0: linksbündig
* Key = 1: rechtsbündig
*
* Geändert: 28.06.05  UR
*
* 05.04.02: Nachkomma-Stellen werden jetzt berücksichtigt.   UR
* 28.06.05: Doxy-Header.  UR
*
* @ingroup sstStr01IntLib
*
* @param Key:     [in]     0 oder 1
* @param Von:     [in]     von Textposition im Zielstring
* @param Bis:     [in]     bis Textposition im Zielstring
* @param fWert:   [in]     Quelle
* @param NachKo:  [in]     Nachkommastellen
* @param Zeile:   [in out] Zielstring
*
* @return Fehlerstatus
*
* @retval   = 0: OK
* @retval   < 0: Allgemeiner Fehler
*
* @author ur
*
* @date 07.07.00
*/
//-----------------------------------------------------------------------------
int Str1_Real2Zeile ( int           Key,
                      unsigned long          Von,
                      unsigned long          Bis,
                      float         fWert,
                      int           NachKo,
                      std::string  *Zeile);
//=============================================================================
/**
* @brief Double in einen String konvertieren und in Zeilenbereich kopieren.
*
* iStat = Str1_Dbl2ZeileFmt ( Key, Von, Bis, *dWert ,cFmtStr, *Zeile);
*
* Konvertieren eines Double in einen Zeilen-Bereich
* Key = 0: linksbündig
* Key = 1: rechtsbündig
*
* write 3 leading zero: for example: -001.22 or 022.34
*
* Geändert: 28.06.05  UR
*
* 05.04.02: Nachkomma-Stellen werden jetzt berücksichtigt.   UR
* 28.06.05: Doxy-Header.  UR
*
* @ingroup sstStr01IntLib
*
* @param Key:     [in]     0 oder 1
* @param Von:     [in]     von Textposition im Zielstring
* @param Bis:     [in]     bis Textposition im Zielstring
* @param dWert:   [in]     Quelle
* @param cFmtStr: [in]     Format string for intern sprintf
* @param Zeile:   [in out] Zielstring
*
* @return Fehlerstatus
*
* @retval   = 0: OK
* @retval   < 0: Allgemeiner Fehler
*
* @author ur
*
* @date 07.07.00
*/
//-----------------------------------------------------------------------------
int Str1_Dbl2ZeileFmt ( int           Key,
                        unsigned long          Von,
                        unsigned long          Bis,
                        double        dWert,
                        char         *cFmtStr,
                        std::string  *Zeile);
//=============================================================================
/**
* @brief Double in einen String konvertieren und in Zeilenbereich kopieren.
*
* iStat = Str1_Dbl2ZeileWnk ( Key, Von, Bis, *dWert ,NachKo, *Zeile);
*
* Konvertieren eines Double in einen Zeilen-Bereich
* Key = 0: linksbündig
* Key = 1: rechtsbündig
*
* write 3 leading zero: for example: -001.22 or 022.34
*
* Geändert: 28.06.05  UR
*
* 05.04.02: Nachkomma-Stellen werden jetzt berücksichtigt.   UR
* 28.06.05: Doxy-Header.  UR
*
* @ingroup sstStr01IntLib
*
* @param Key:     [in]     0 oder 1
* @param Von:     [in]     von Textposition im Zielstring
* @param Bis:     [in]     bis Textposition im Zielstring
* @param dWert:   [in]     Quelle
* @param NachKo:  [in]     Nachkommastellen
* @param Zeile:   [in out] Zielstring
*
* @return Fehlerstatus
*
* @retval   = 0: OK
* @retval   < 0: Allgemeiner Fehler
*
* @author ur
*
* @date 07.07.00
*/
//-----------------------------------------------------------------------------
int Str1_Dbl2ZeileWnk ( int           Key,
                        unsigned long          Von,
                        unsigned long          Bis,
                        double        dWert,
                        int           NachKo,
                        std::string  *Zeile);

//=============================================================================
/**
* @brief Double in einen String konvertieren und in Zeilenbereich kopieren.
*
* iStat = Str1_Dbl2Zeile ( Key, Von, Bis, *dWert ,NachKo, *Zeile);
*
* Konvertieren eines Double in einen Zeilen-Bereich
* Key = 0: linksbündig
* Key = 1: rechtsbündig
*
* Geändert: 28.06.05  UR
*
* 05.04.02: Nachkomma-Stellen werden jetzt berücksichtigt.   UR
* 28.06.05: Doxy-Header.  UR
*
* @ingroup sstStr01IntLib
*
* @param Key:     [in]     0 oder 1
* @param Von:     [in]     von Textposition im Zielstring
* @param Bis:     [in]     bis Textposition im Zielstring
* @param dWert:   [in]     Quelle
* @param NachKo:  [in]     Nachkommastellen
* @param Zeile:   [in out] Zielstring
*
* @return Fehlerstatus
*
* @retval   = 0: OK
* @retval   < 0: Allgemeiner Fehler
*
* @author ur
*
* @date 07.07.00
*/
//-----------------------------------------------------------------------------
int Str1_Dbl2Zeile ( int           Key,
                     unsigned long          Von,
                     unsigned long          Bis,
                     double        dWert,
                     int           NachKo,
                     std::string  *Zeile);

//=============================================================================
/**
* @brief Bool in einen String konvertieren und in Zeilenbereich kopieren.
*
* iStat = Str1_Bool2Zeile (iKey, iStrTyp, lVon, lBis, *bVal, *sZeile);
*
* Konvertieren eines Real in einen Zeilen-Bereich
* Key = 0: linksbündig
* Key = 1: rechtsbündig
*
* Geändert: 28.06.05  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey    [in]     0 oder 1
* @param iStrTyp [in]     Format of Output String
* @param lVon    [in]     von Textposition im Zielstring
* @param lBis    [in]     bis Textposition im Zielstring
* @param bVal    [in]     Quelle
* @param sZeile  [in out] Zielstring
*
* @return Fehlerstatus
*
* @retval   = 0: OK
* @retval   < 0: Allgemeiner Fehler
*
* @author ur
*
* @date 07.07.00
*/
//-----------------------------------------------------------------------------
int Str1_Bool2Zeile ( int          iKey,
                      long         iStrTyp,
                      unsigned long         lVon,
                      unsigned long         lBis,
                      bool        *bVal,
                      std::string *sZeile);
//==============================================================================
/**
* @brief Init Str1 Object
*
* iStat = Str1_Init ( iKey, *Str1);
*
* More Comment
*
* Changed: 16.02.10  Re.
*
* @ingroup sstStr01IntLib
*
* @param iKey [in]     For the moment 0
* @param Str1 [out]    Str1-object
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 16.02.10
*/
//------------------------------------------------------------------------------
int Str1_Init ( int          iKey,
                std::string *Str1);

//=============================================================================
/**
* @brief Nächste Information aus Text-Zeile in String umwandeln.
*
* iStat = Str1_AbPos2Str ( iKey, *lTPos, *cTrnZ, *sZeile, *sErrTxt, *sRet);
*
* @ingroup sstStr01IntLib
*
* @param iKey     [in]     Vorerst immer null
* @param lTPos    [in]     Read from position in string
* @param cTrnZ    [in]     Lesen bis Trennzeichen
* @param sZeile   [in]     Lese-String
* @param sErrTxt  [out]    Read-Error bei ErrTxt
* @param sRet     [out]    Result String
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1_AbPos2Str ( int          iKey,
                     unsigned long        *lTPos,
                     char        *cTrnZ,
                     std::string *sZeile,
                     std::string *sErrTxt,
                     std::string *sRet);

//=============================================================================
/**
* @brief Nächste Information aus Text-Zeile in Char umwandeln.
*
* iStat = Str1_AbPos2Str ( Key, *TPos, *TrnZ, *Zeile, *ErrTxt, *tRet, iCRetLen);
*
* @ingroup sstStr01IntLib
*
* @param iKey      [in]     Vorerst immer null
* @param TPos      [in]     Read from position in string
* @param TrnZ      [in]     Lesen bis Trennzeichen
* @param Zeile     [in]     Lese-String
* @param ErrTxt    [out]    Read-Error bei ErrTxt
* @param cRet      [out]    Result String
* @param iCRetLen  [in]     Maximale Länge Result String
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1_AbPos2Char ( int          iKey,
                      unsigned long        *TPos,
                      char        *TrnZ,
                      std::string *Zeile,
                      std::string *ErrTxt,
                      char        *cRet,
                      int          iCRetLen);

//=============================================================================
/**
* @brief Nächste Information aus Text-Zeile in Int2 umwandeln.
*
* iStat = Str1_AbPos2Int ( Key, *TPos, *TrnZ, *Zeile, *ErrTxt, *iRet);
*
* @ingroup sstStr01IntLib
*
* @param iKey       [in]      Vorerst immer null
* @param TPos       [in]      Read from position in string
* @param TrnZ       [in]      Lesen bis Trennzeichen
* @param Zeile      [in]      Lesen-String
* @param ErrTxt     [out]     Read-Error bei ErrTxt
* @param iRet       [out]     Result Integer
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1_AbPos2Int ( int          iKey,
                     unsigned long        *TPos,
                     char        *TrnZ,
                     std::string *Zeile,
                     std::string *ErrTxt,
                     int         *iRet);
//=============================================================================
/**
* @brief Nächste Information aus Text-Zeile in Unsigned Int2 umwandeln.
*
* iStat = Str1_AbPos2UInt ( iKey, *lTPos, *cTrnZ, *sZeile, *sErrTxt, *uiRet);
*
* @ingroup sstStr01IntLib
*
* @param iKey       [in]      Vorerst immer null
* @param lTPos      [in]      Read from position in string
* @param cTrnZ      [in]      Lesen bis Trennzeichen
* @param sZeile     [in]      Lesen-String
* @param sErrTxt    [out]     Read-Error bei ErrTxt
* @param uiRet      [out]     Result Integer
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1_AbPos2UInt ( int           iKey,
                      unsigned long         *lTPos,
                      char         *cTrnZ,
                      std::string  *sZeile,
                      std::string  *sErrTxt,
                      unsigned int *uiRet);

//=============================================================================
/**
* @brief Read in Line from Position as Long Int until next Character TrnZ
*
* iStat = Str1_AbPos2Int4 ( iKey, *TPos, *TrnZ, *Zeile, *ErrTxt, *iRet4);
*
* More Comment
*
* Changed: 26.07.07  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey:   [in]     For the moment 0
* @param TPos:   [in out] Read from position in string
* @param TrnZ:   [in out] Lesen bis Trennzeichen
* @param Zeile:  [in out] Lese-String
* @param ErrTxt: [in out] Read-Error bei ErrTxt
* @param iRet4:  [in out] Result Long Integer
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author ur
*
* @date 26.07.07
*/
//-----------------------------------------------------------------------------
int Str1_AbPos2Int4 ( int          iKey,
                      unsigned long        *TPos,
                      char        *TrnZ,
                      std::string *Zeile,
                      std::string *ErrTxt,
                      long        *iRet4);
//=============================================================================
/**
* @brief Read in Line from Position as Unsigned Long Int until next Character TrnZ
*
* iStat = Str1_AbPos2UInt4 ( iKey, *TPos, *TrnZ, *Zeile, *ErrTxt, *uiRet4);
*
* More Comment
*
* Changed: 26.07.07  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey:   [in]      For the moment 0
* @param TPos:   [in out]  Read from position in string
* @param TrnZ:   [in out]  Lesen bis Trennzeichen
* @param Zeile:  [in out]  Lese-String
* @param ErrTxt: [in out]  Read-Error bei ErrTxt
* @param uiRet4:  [in out] Result Unsigend Long Integer
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author ur
*
* @date 26.07.07
*/
//-----------------------------------------------------------------------------
int Str1_AbPos2UInt4 ( int             iKey,
                       unsigned long           *TPos,
                       char           *TrnZ,
                       std::string    *Zeile,
                       std::string    *ErrTxt,
                       unsigned long  *uiRet4);
//=============================================================================
/**
* @brief Nächste Information aus Text-Zeile in Real umwandeln.
*
* iStat = Str1_AbPos2Real ( Key, *TPos, *TrnZ, *Zeile, *ErrTxt, *dRet);
*
* @ingroup sstStr01IntLib
*
* @param iKey   [in]     For the moment 0
* @param TPos   [in]     Read from position in string
* @param TrnZ   [in]     Lesen bis Trennzeichen
* @param Zeile  [in]     Lese-String
* @param ErrTxt [out]    Lese-Fehler bei ErrTxt
* @param rRet   [out]    Result Float
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1_AbPos2Real ( int           iKey,
                      unsigned long         *TPos,
                      char         *TrnZ,
                      std::string  *Zeile,
                      std::string  *ErrTxt,
                      float        *rRet);

//=============================================================================
/**
* @brief Nächste Information aus Text-Zeile in Double umwandeln.
*
* iStat = Str1_AbPos2Dbl ( Key, *TPos, *TrnZ, *Zeile, *ErrTxt, *dRet);
*
* @ingroup sstStr01IntLib
*
* @param iKey    [in]     For the moment 0
* @param TPos    [in]     Read from position in string
* @param TrnZ    [in]     Lesen bis Trennzeichen
* @param Zeile   [in]     Lese-String
* @param ErrTxt  [out]    Read-Error bei ErrTxt
* @param dRet    [out]    Result Double
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1_AbPos2Dbl ( int           iKey,
                     unsigned long         *TPos,
                     char         *TrnZ,
                     std::string  *Zeile,
                     std::string  *ErrTxt,
                     double       *dRet);
//=============================================================================
/**
* @brief Nächste Information aus Text-Zeile in Bool umwandeln.
*
* iStat = Str1_AbPos2Bool ( Key, *TPos, *TrnZ, *Zeile, *ErrTxt, *bRet);
*
* @ingroup sstStr01IntLib
*
* @param iKey     [in]     For the moment 0
* @param TPos     [in]     Read from position in string
* @param TrnZ     [in]     Lesen bis Trennzeichen
* @param Zeile    [in]     Lese-String
* @param ErrTxt   [out]    Read-Error bei ErrTxt
* @param bRet     [out]    Result Bool
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1_AbPos2Bool ( int          iKey,
                      unsigned long        *TPos,
                      char        *TrnZ,
                      std::string *Zeile,
                      std::string *ErrTxt,
                      bool        *bRet);

//=============================================================================
//=============================================================================
/**
* @brief String in String-Struktur kopieren
*
* iStat = Str1_StrSet ( iKey, *Str, *Str_Stru, StrLenMax);
*
* Wozu wird StrLenMax gebraucht?
*
* Changed: 13.12.07  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey:      [in]  For the moment 0
* @param Str:       [in]  Eingabe-String
* @param Str_Stru:  [out] Ausgabe-String
* @param StrLenMax: [in]  Maximale Stringlänge ??
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author ur
*
* @date 13.12.07
*/
//-----------------------------------------------------------------------------
int Str1_StrSet (int          iKey,
                 char        *Str,
                 std::string *Str_Stru,
                 unsigned long         StrLenMax);

/**
* @brief Copy Chars to Str1 structure
*
* iStat = Str1Cpy ( iKey, *sStrInfo, *cCopyChar);
*
* More Comment
*
* Changed: 19.09.12  Re.
*
* @ingroup sstStr01IntLib
*
* @param iKey:      [in]     For the moment 0
* @param sStrInfo:  [in out] string structure for import string
* @param cCopyChar: [in]     copy chars
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 19.09.12
*/
//------------------------------------------------------------------------------
int Str1Cpy (int            iKey,
             std::string   *sStrInfo,
             char          *cCopyChar);
//==============================================================================
/**
* @brief Cat Chars to Str1 structure
*
* iStat = Str1Cat ( iKey, *sStrInfo, *cCatChar);
*
* More Comment
*
* Changed: 19.09.12  Re.
*
* @ingroup sstStr01IntLib
*
* @param iKey:     [in]     For the moment 0
* @param sStrInfo: [in out] string structure for import string
* @param cCatChar: [in]     copy chars
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 19.09.12
*/
//------------------------------------------------------------------------------
int Str1Cat (int            iKey,
             std::string   *sStrInfo,
             const char          *cCatChar);
//==============================================================================
/**
* @brief Get Information until next delimiter and ignore brakes
*
* iStat = Str1_AbPos2StrBrk ( iKey, *Zeile, *lStrPos, *cDelimit, *cBrakeOpen, *cBrakeClose, *sTag);
*
* More Comment
*
* Changed: 17.04.12  Re.
*
* @ingroup sstStr01IntLib
*
* @param iKey: [in]
* @param Zeile: [in]
* @param lStrPos: [in]
* @param cDelimit: [in]
* @param cBrakeOpen: [in]
* @param cBrakeClose: [in]
* @param sTag: [out]
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 17.04.12
*/
//------------------------------------------------------------------------------
int Str1_AbPos2StrBrk (int            iKey,
                       std::string   *Zeile,
                       unsigned long          *lStrPos,
                       char          *cDelimit,
                       char          *cBrakeOpen,
                       char          *cBrakeClose,
                       std::string   *sTag);
//==============================================================================
/**
* @brief Get Info until next delimiter and interpret info inside small brackets as string
* iStat = Str1_AbPos2StrSBrk ( iKey, *Zeile, *lStrPos, *cDelimit, *cSBrake, *sTag);
*
* More Comment
*
* Changed: 17.04.12  Re.
*
* @ingroup sstStr01IntLib
*
* @param iKey     [in] iKey
* @param Zeile    [in] String
* @param lStrPos  [in] String position
* @param cDelimit [in] Delimiter
* @param cSBrake  [in] Bracket
* @param sTag     [out] result string
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 17.04.12
*/
//------------------------------------------------------------------------------
int Str1_AbPos2StrSBrk (int             iKey,
                        std::string    *Zeile,
                        unsigned long  *lStrPos,
                        char           *cDelimit,
                        char           *cSBrake,
                        std::string    *sTag);
//=============================================================================
/**
* @brief In String durch Adresse und Länge bezeichneten Substring austauschen
*
* iStat = Str_SubS_Tausch ( iKey, *cWorkStr, *cOldStrAdr, iOldStrLen, *cNewStr);
*
* Es kann ein Austauschstring übergeben werden, sonst wird lediglich
* der Substring aus dem String entfernt.
*
* Changed: 26.07.04  Re.
*
* 23.08.01: Endlosschleife, wenn Substring Ende des Textes ist, und
*           kein Austauschstring vorhanden ist. (F_4935)   UR
* 26.07.04: Text, in dem getauscht werden soll, kann jetzt maximale Länge gleich
*           Speichergröße haben.  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey        [in] For the moment 0
* @param cWorkStr    [in out] String to work
* @param cOldStrAdr  [in] Adress of Sub-String inside Workstring
* @param iOldStrLen  [in] Length of Sub-String
* @param cNewStr     [in] New Sub-String
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 23.03.01
*/
//-----------------------------------------------------------------------------
int Str_SubS_Tausch ( int    iKey,
                      std::string  *cWorkStr,
                      std::string  *cOldStrAdr,
                      unsigned long    iOldStrLen,
                      std::string  *cNewStr);
//=============================================================================
/**
* @brief Begrenzungszeichen in einem String ab Position Pos suchen.
* iStat = Str1i_BeGrzFind ( iKey, ulPos, *BeGrzZ, *Text);
*
* @param iKey   [in] For the moment 0
* @param ulPos  [in] Suchen ab Position
* @param BeGrzZ [in] Begrenzungszeichen
* @param Text   [in] Prüf-Text
*
* @ingroup sstStr01IntLib
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
long Str1i_BeGrzFind ( int            iKey,
                       unsigned long  ulPos,
                       char          *BeGrzZ,
                       std::string   *Text);
//=============================================================================
/**
* @brief Find next Trennzeichen from Position Pos
*
* iStat = Str1i_TrnZFind ( iKey, Pos, *TrnZ, *Text);
*
* More Comment
*
* Changed: 05.11.07  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey: [in]     For the moment 0
* @param Pos:  [in out] Suchen ab Position
* @param TrnZ: [in]     Trennzeichen
* @param Text: [in]     Prüf-Text
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author ur
*
* @date 05.11.07
*/
//-----------------------------------------------------------------------------
long Str1i_TrnZFind ( int          iKey,     // v  -> Vorerst immer 0
                      unsigned long         Pos,      //   <-> Suchen ab Position
                      char        *TrnZ,     //   <-> Trennzeichen
                      std::string *Text);    //   <-> Prüf-Text

//=============================================================================
/**
* @brief String direkt in Int2 konvertieren
*
* iStat = Str1i_Txt2Int ( Key, *LocInt, *iRet);
*
* Der String Txt wird nicht vorverarbeit.
*
* Changed: 14.12.07  UR
*
* 25.11.04: Vorzeichen (+/-) darf nur an erster Stelle kommen.  UR
* 14.12.07: Zu langer String wird zurückgewiesen.  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey:   [in]  For the moment 0
* @param LocInt: [in]  Konvertierungstext
* @param iRet:   [out] Result-Int2
*
* @return Errorstate
*
* @retval   =  0: OK
* @retval   = -1: Wrong Key
* @retval   = -2: String not convertible
* @retval   = -3: String too long
* @retval   <  0: Unspecified Error
*
* @author ur
*
* @date 14.07.00
*/
//-----------------------------------------------------------------------------
int Str1i_Txt2Int ( int          iKey,
                    std::string *LocInt,
                    int         *iRet);
//=============================================================================
/**
* @brief String direkt in Int2 konvertieren
*
* iStat = Str1i_Txt2Int ( Key, *LocInt, *iRet);
*
* Der String Txt wird nicht vorverarbeit.
*
* Changed: 14.12.07  UR
*
* 25.11.04: Vorzeichen (+/-) darf nur an erster Stelle kommen.  UR
* 14.12.07: Zu langer String wird zurückgewiesen.  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey    [in]  For the moment 0
* @param LocInt  [in]  Konvertierungstext
* @param uiRet   [out] Result-Int2
*
* @return Errorstate
*
* @retval   =  0: OK
* @retval   = -1: Wrong Key
* @retval   = -2: String not convertible
* @retval   = -3: String too long
* @retval   <  0: Unspecified Error
*
* @author ur
*
* @date 14.07.00
*/
//-----------------------------------------------------------------------------
int Str1i_Txt2UInt ( int            iKey,
                     std::string   *LocInt,
                     unsigned int  *uiRet);
//=============================================================================
/**
* @brief String direkt in Int4 konvertieren
* iStat = Str1i_Txt2Int4 ( iKey, *LocInt, *lRet);
*
* @param iKey   [in]  For the moment 0
* @param LocInt [in]  Konvertierungstext
* @param lRet   [out] Result Long Int4
*
* @ingroup sstStr01IntLib
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1i_Txt2Int4 ( int          iKey,
                     std::string *LocInt,
                     long        *lRet);
//=============================================================================
/**
* @brief String direkt in unsigned Int4 konvertieren
* iStat = Str1i_Txt2UInt4 ( iKey, *LocInt, *ulRet);
*
* @param iKey   [in]  For the moment 0
* @param LocInt [in]  Konvertierungstext
* @param ulRet  [out] Result-Unsigned Int4
*
* @ingroup sstStr01IntLib
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1i_Txt2UInt4 ( int            iKey,
                      std::string   *LocInt,
                      unsigned long *ulRet);
//=============================================================================
/**
* @brief String direkt in Real konvertieren
*
* iStat = Str1i_Txt2Real ( iKey, *LocReal, *rRet);
*
* Der String -LocReal- wird nicht vorverarbeit.
*
* Changed: 01.04.03  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey    [in]  For the moment 0
* @param LocReal [in]  Konvertierungstext
* @param rRet    [out] Result-Real
*
* @return Errorstate
*
* @retval   =  0: OK
* @retval   = -1: Wrong Key
* @retval   = -2: String not convertible
* @retval   = -3: Stringlength not OK
* @retval   <  0: Unspecified Error
*
* @author ur
*
* @date 01.04.03
*/
//-----------------------------------------------------------------------------
int Str1i_Txt2Real ( int           iKey,
                     std::string  *LocReal,
                     float        *rRet);

//=============================================================================
/**
* @brief String direkt in Double konvertieren.
* iStat = Str1i_Txt2Dbl ( iKey, *LocDbl, *dRet);
*
* @param iKey   [in]  For the moment 0
* @param LocDbl [in]  Konvertierungstext
* @param dRet   [out] Result Double
*
* @ingroup sstStr01IntLib
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1i_Txt2Dbl ( int           iKey,
                    std::string  *LocDbl,
                    double       *dRet);
//=============================================================================
/**
* @brief Ist Prüfzeichen eine Zahl zwischen 0 und 9 ?
* iStat = Str1i_IsDigit ( Key, &Zeichen);
*
* Die Länge des Zeichen-Strings ist unwichtig
*
* Changed: 30.06.00  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey    [in] For the moment 0
* @param Zeichen [in] Prüfzeichen in String
*
* @return Errorstate
*
* @retval   = 1: TRUE, Char is Value
* @retval   = 0: FALSE, Char is no Value
* @retval   < 0: Unspecified Error
*
* @author ur
*
* @date 30.06.00
*/
//-----------------------------------------------------------------------------
int Str1i_IsDigit ( int   iKey,
                    char *Zeichen);
//=============================================================================
/**
* @brief search Position of string in string
*
* iStat = Str1i_AdrHasPos ( iKey, *ulPos, *Zeile, *TAdr);
*
* Position 1..n
*
* Changed: 17.12.07  UR
* 17.12.07: Ausprogrammiert.  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey   [in]  For the moment 0
* @param ulPos  [out] Position of searchstring
* @param Zeile  [in]  string
* @param TAdr   [in]  Searchstring
*
* @return Errorstate
*
* @retval   =  1: Positon found
* @retval   =  0: No Position found
* @retval   = -1: Wrong Key
* @retval   <  0: Unspecified Error
*
* @author ur
*
* @date 27.09.00
*/
//-----------------------------------------------------------------------------
int Str1i_AdrHasPos ( int             iKey,
                      unsigned long  *ulPos,
                      std::string    *Zeile,
                      std::string    *TAdr);
//=============================================================================
/**
* @brief Beginn der Information in einem String ab Position Pos feststellen.
* StartPos = Str1i_StartOfInfo ( iKey, *ulPos, *TrnZ, *Text);
*
* @param iKey  [in] For the moment 0
* @param ulPos [in] Suchen ab Position
* @param TrnZ  [in] Trennzeichen
* @param Text  [in] Prüf-Text
*
* @ingroup sstStr01IntLib
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
long Str1i_StartOfInfo ( int             iKey,
                         unsigned long   ulPos,
                         char           *TrnZ,
                         std::string    *Text);
//=============================================================================
/**
* @brief Beginn der Information in einem String ab Position Pos feststellen.
* StartPos = Str1i_StartOfInfo2 ( iKey, *Pos, *TrnZ, *Text);
*
* @param iKey [in] For the moment 0
* @param Pos  [in] Suchen ab Position
* @param TrnZ [in] Trennzeichen
* @param Text [in] Prüf-Text
*
* @ingroup sstStr01IntLib
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
long Str1i_StartOfInfo2 ( int            iKey,
                          unsigned long  Pos,
                          char          *TrnZ,
                          std::string   *Text);
//=============================================================================
/**
* @brief Ende der Information in einem String feststellen
* EndPos = Str1i_EndOfInfo ( iKey, ulPos, *TrnZ, *Text);
*
* Ab Position Pos wird vorwärts im String Text das Ende gesucht.
* Ende kann sein ein NoInformation-Zeichen oder '\0'.
* Ist ein Ende gefunden, wird rückwärts bis zur nächsten Information
* gegangen. Diese Position wird zurückgegeben.
* Ist der String leer, wird Fehler zurückgegeben
* Die Position wird im Bereich 1..n berechnet.
*
* Changed: 24.09.04  UR
*
* 26.04.01: Wenn bis zum Ende gesucht wird, muß das Result das Ende
*           vom Text sein.   UR
* 11.03.03: Speichergröße jetzt Int4.  UR
* 24.09.04: Key = 1 für Rückwärts-Suche.  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey    [in] For the moment 0
* @param ulPos   [in] Suchen ab Position
* @param TrnZ    [in] NoInformation-Zeichen
* @param Text    [in] Prüf-Text
*
* @return Errorstate
*
* @retval   >  0: Gefundene Position
* @retval   =  0: Nix gefunden
* @retval   = -1: Wrong Key
* @retval   = -2: Wrong Position
* @retval   <  0: Unspecified Error
*
* @author ur
*
* @date 14.07.00
*/
//-----------------------------------------------------------------------------
unsigned long Str1i_EndOfInfo ( int             iKey,
                                unsigned long   ulPos,
                                char           *TrnZ,
                                std::string    *Text);
//=============================================================================
/**
* @brief Ende der Information in einem String feststellen
* EndPos = Str1i_EndOfInfo2 ( iKey, ulPos, TrnZ, *Text);
*
* Ab Position Pos wird vorwärts im String Text das Ende gesucht.
* Ende kann sein ein NoInformation-Zeichen oder '\0'.
* Ist ein Ende gefunden, wird rückwärts bis zur nächsten Information
* gegangen. Diese Position wird zurückgegeben.
* Ist der String leer, wird Fehler zurückgegeben
* Die Position wird im Bereich 1..n berechnet.
*
* Changed: 24.09.04  UR
*
* 26.04.01: Wenn bis zum Ende gesucht wird, muß das Result das Ende
*           vom Text sein.   UR
* 11.03.03: Speichergröße jetzt Int4.  UR
* 24.09.04: Key = 1 für Rückwärts-Suche.  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey   [in] For the moment 0
* @param ulPos  [in] Suchen ab Position
* @param TrnZ   [in] NoInformation-Zeichen
* @param Text   [in] Prüf-Text
*
* @return Errorstate
*
* @retval   >  0: Gefundene Position
* @retval   =  0: Nix gefunden
* @retval   = -1: Wrong Key
* @retval   = -2: Wrong Position
* @retval   <  0: Unspecified Error
*
* @author ur
*
* @date 14.07.00
*/
//-----------------------------------------------------------------------------
long Str1i_EndOfInfo2 ( int            iKey,
                        unsigned long  ulPos,
                        char          *TrnZ,
                        std::string   *Text);
//=============================================================================
/**
* @brief Lese nächsten String nach Suchstring.
* iStat = Str1i_LesTxtNach ( iKey, *Zeile, *TrennZ, *SuchStr, *FindStr);
*
* @param iKey    [in] For the moment 0
* @param Zeile   [in] Bearbeitungszeile
* @param TrennZ  [in] String mit Trennzeichen
* @param SuchStr [in] Such-String
* @param FindStr [out] Result-String
*
* @ingroup sstStr01IntLib
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1i_LesTxtNach ( int          iKey,
                       std::string *Zeile,
                       char        *TrennZ,
                       std::string *SuchStr,
                       std::string *FindStr);
//=============================================================================
/**
* @brief Steht an Position Information im String ?
* iStat = Str1i_PosHasInfo ( iKey, *TstStr, Pos, *InfoStr);
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
* @param iKey     [in] Vorerst immer 0
* @param TstStr   [in] Bearbeitungszeile
* @param Pos      [in] Position im TstStr 1..n
* @param InfoStr  [in] String mit Info-Angaben
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
int Str1i_PosHasInfo ( int             iKey,
                       std::string    *TstStr,
                       unsigned long   Pos,
                       char           *InfoStr);

//=============================================================================
/**
* @brief Steht im String an Position eins der übergebenen Zeichen?
*
* iStat = Str1i_PosIsZch ( Key, *TstStr, Pos, *ZchStr);
*
* Es wird der zu untersuchende String übergeben.
* Dazu eine Positionsangabe zum String.
* Verwandt mit Funktion Str_PosHasInfo, eine Art Umkehrung.
*
* Changed: 14.12.07  UR
*
* 14.12.07: Umstellung auf StrDS1.  UR
*
* @ingroup sstStr01IntLib
*
* @param Key:     [in] Vorerst immer 0
* @param TstStr:  [in] Bearbeitungszeile
* @param Pos:     [in] Position im TstStr 1..n
* @param ZchStr:  [in] String mit Info-Angaben
*
* @return Fehlerstatus
*
* @retval   =1: Ja, an Position steht eins der übergebenen Zeichen
* @retval   =0: Nein, keins der übergebenen Zeichen gefunden
* @retval   = -1: Wrong Key
* @retval   = -2: Given Position wrong
* @retval   <  0: Unspecified Error
*
* @author ur
*
* @date 08.09.00
*/
//-----------------------------------------------------------------------------
int Str1i_PosIsZch ( int          Key,       // v  -> Vorerst immer 0
                     std::string *TstStr,    //   <-> Bearbeitungszeile
                     unsigned long         Pos,       // v <-> Position im TstStr 1..n
                     char        *ZchStr);   //   <-> String mit Zeichen

//=============================================================================
/**
* @brief Nächste Information aus Text-Zeile in Int2 umwandeln.
* iStat = Str1i_AbPos_Int ( iKey, *TAdr, *ErrTxt, *iRet);
*
* @param iKey   [in]  For the moment 0
* @param TAdr   [in]  Lesen ab Adresse
* @param ErrTxt [in]  Read-Error bei ErrTxt
* @param iRet   [out] Result Int2
*
* @ingroup sstStr01IntLib
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1i_AbPos_Int ( int           iKey,
                      std::string  *TAdr,
                      std::string  *ErrTxt,
                      int          *iRet);
//=============================================================================
/**
* @brief Nächste Information aus Text-Zeile in Double umwandeln.
*
* iStat = Str1i_AbPos_Dbl ( Key, *TAdr, *Zeile, *ErrTxt, *dRet);
*
* @ingroup sstStr01IntLib
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
int Str1i_AbPos_Dbl ( int          Key);      /**< v  -> Vorerst immer 0         */
//                      char        *TAdr,     /**<   <-> Lesen ab Adresse        */
//                      std::string *Zeile,    /**<   <-> Lese-String             */
//                      std::string *ErrTxt,   /**<   <-> Read-Error -bei Errtxt- */
//                      int         *dRet);    /**<   <-> Result-Dble           */


//=============================================================================
/**
* @brief Is String to Int/LongInt convertible?
*
*  iStat = Str1i_IntConvertible ( iKey, *LocInt);
*
* More Comment
*
* Changed: 14.12.07  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey:   [in] For the moment 0
* @param LocInt: [in] String
*
* @return Errorstate
*
* @retval   = 1: TRUE, to Int convertible
* @retval   = 0: FALSE, not to Int convertible
* @retval   < 0: Unspecified Error
*
* @author ur
*
* @date 14.12.07
*/
//-----------------------------------------------------------------------------
int Str1i_IntConvertible (int          iKey,
                          std::string *LocInt);

//=============================================================================
/**
* @brief Is String to Float/Double convertible?
*
* iStat  = Str1_FloatConvertible ( iKey, *LocReal);
*
* More Comment
*
* Changed: 14.12.07  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey:    [in] For the moment 0
* @param LocReal: [in] String
*
* @return Errorstate
*
* @retval   = 1: TRUE, to F/D convertible
* @retval   = 0: FALSE, not to F/D convertible
* @retval   < 0: Unspecified Error
*
* @author ur
*
* @date 14.12.07
*/
//-----------------------------------------------------------------------------
int Str1_FloatConvertible (int          iKey,
                           std::string *LocReal);

//==============================================================================
/**
* @brief Remove starting and ending spaces from string
*
* iStat = Stri_RemoveSpaces ( iKey, txt1);
*
* More Comment
*
* Changed: 20.12.11  Re.
*
* @ingroup sstStr01IntLib
*
* @param iKey: [in]     For the moment 0
* @param txt1: [in out] string for removing spaces
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 20.12.11
*/
//------------------------------------------------------------------------------
int Stri_RemoveSpaces (int           iKey,
                       std::string  *txt1);

//==============================================================================
/**
* @brief Remove ending spaces from string
*
* iStat = Str1i_RemoveEndingSpaces ( iKey, *oFmtInfo, *sZeile);
*
* More Comment
*
* Changed: 03.07.14  Re.
*
* @ingroup sstStr01IntLib
*
* @param iKey     [in]     For the moment 0
* @param oFmtInfo [in]     Format Infos
* @param sZeile   [in out] string for removing spaces
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 03.07.14
*/
//------------------------------------------------------------------------------
int Str1i_RemoveEndingSpaces (int               iKey,
                              sstStr01IntCls *oFmtInfo,
                              std::string      *sZeile);
//=============================================================================
//==============================================================================
/**
* @brief Return next informationstring and ignore contents inside of brakes
*
* iStat = Str1i_IsDelimiter ( iKey, *Zeile, *cDelimit);
*
* More Comment
*
* Changed: 16.02.10  Re.
*
* @ingroup examples
*
* @param iKey: [in] For the moment 0
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 16.02.10
*/
//------------------------------------------------------------------------------
int Str1i_IsDelimiter (int          iKey,
                       std::string *Zeile,
                       unsigned long         uPos,
                       char        *cDelimit);
int Str1i_IsBrakeOpen (int            iKey,
                       std::string   *Zeile,
                       unsigned long  ulPos,
                       char          *cBrakeOpen);
int Str1i_IsBrakeClose (int            iKey,
                        std::string   *Zeile,
                        unsigned long  ulPos,
                        char          *cBrakeClose);
//=============================================================================
/**
* @brief Beginn der Information in einem String ab Position Pos feststellen.
*
* StartPos = Str_StartOfInfo ( Key, *Pos, *TrnZ, *Text);
*
* @param iKey [in] For the moment 0
* @param Pos  [in] Suchen ab Position
* @param TrnZ [in] Trennzeichen
* @param Text [in] Prüf-Text
*
* @ingroup sstStr01IntLib
*
* @author ur
*
* @date 11.02.05
*/
//-----------------------------------------------------------------------------
unsigned long Str_StartOfInfo ( int             iKey,
                                unsigned long   Pos,
                                char           *TrnZ,
                                std::string    *Text);
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
* @param iKey    [in] 0 = vorwärts, 1 = rückwärts
* @param lPos    [in] Suchen ab Position
* @param TrnZ    [in] NoInformation-Zeichen
* @param Text    [in] Prüf-Text
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
unsigned long Str_EndOfInfo ( int             iKey,
                              unsigned long   lPos,
                              char           *TrnZ,
                              std::string    *Text);
//=============================================================================
/**
* @brief Steht an Position Information im String ?
*
* iStat = Str_PosHasInfo ( Key, *TstStr, Pos, *InfoStr);
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
int Str_PosHasInfo ( int  Key,      // v  -> Vorerst immer 0
                       std::string *TstStr,   //   <-> Bearbeitungszeile
                       unsigned long  Pos,      // v <-> Position im TstStr 1..n
                       char *InfoStr); //   <-> String mit Info-Angaben
//=============================================================================
/**
* @brief In String durch Adresse und Länge bezeichneten Substring austauschen
*
* iStat = Str_SubS_Tausch ( iKey, *cWorkStr, *cOldStrAdr, *cNewStr);
*
* Es kann ein Austauschstring übergeben werden, sonst wird lediglich
* der Substring aus dem String entfernt.
*
* Changed: 26.07.04  Re.
*
* 23.08.01: Endlosschleife, wenn Substring Ende des Textes ist, und
*           kein Austauschstring vorhanden ist. (F_4935)   UR
* 26.07.04: Text, in dem getauscht werden soll, kann jetzt maximale Länge gleich
*           Speichergröße haben.  UR
*
* @ingroup sstStr01IntLib
*
* @param iKey        [in] For the moment 0
* @param cWorkStr    [in out] String to work
* @param cOldStrAdr  [in] Adress of Sub-String inside Workstring
* @param cNewStr     [out] New Sub-String
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 23.03.01
*/
//-----------------------------------------------------------------------------
int Str_SubS_Tausch ( int           iKey,
                      std::string  *cWorkStr,
                      std::string  *cOldStrAdr,
                      std::string  *cNewStr);
//=============================================================================
int Str1_Test_FuncInt (int iKey);
//=============================================================================
int Str1_Csv_Test (int            iKey,
                   std::string   *sTstTxt,
                   std::string   *sErrTxt,
                   StrDs_Csv_Cls *oCsvSet);
//=============================================================================
int Str1_GetNextBrakeInfo (int             iKey,
                           std::string    *StrInfo,
                           unsigned long  *lStrPos,
                           char           *cBrakeOpen,
                           char           *cBrakeClose,
                           std::string    *sTag);
//==============================================================================
/**
* @brief  // Get next string inside simple brackets <BR>
* iStat = Str1_GetNextSBrakeInfo ( iKey, &oString, &ulStrPos, &cSBracket, &oStrResult);
*
* For example return string "'xxx'" or "xxx" from string "ccc'xxx'777"  <BR>
* iKey=0: Return with brackets, iKey=1: return without brackets
*
* Changed: 09.07.15  Re.
*
* @ingroup sstStr01IntLib
*
* @param iKey       [in]     0 or 1
* @param oString    [in]     string
* @param ulStrPos   [in out] old and new read position in string
* @param cSBracket  [in]     1 char simple bracket
* @param oStrResult [out]    result string inside brackets
*
* @return Errorstate
*
* @retval   = 1: result found
* @retval   = 0: no result found
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 09.07.15
*/
//------------------------------------------------------------------------------
int Str1_GetNextSBrakeInfo (int             iKey,
                            std::string    *oString,
                            unsigned long  *ulStrPos,
                            char           *cSBracket,
                            std::string    *oStrResult);
//=============================================================================

#endif

// --------------------------------------------------------------- File End ----

