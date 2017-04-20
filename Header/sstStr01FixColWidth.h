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
// sstStr01FixColWidth.h   29.04.10  Re.   29.04.10  Re.
//
// Datastructures and Prototypes for system "sstStr01FixColWidth"
//

#ifndef   _SST_STR01_FIXCOLWIDTH_HEADER
#define   _SST_STR01_FIXCOLWIDTH_HEADER

#include <vector>

/**
 * @defgroup sstStr01Lib sstStr01Lib: sst String lib (Version 1)
 * cpp string library for sst
 */

// Defines ---------------------------------------------------------------------

// Structures and Classes ------------------------------------------------------

//==============================================================================
/**
* @brief Fix Column Width class for reading / writing asc data
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
class sstStr01FcwCls
{
  public:   // Public functions
     sstStr01FcwCls();   // Constructor
    // ~X();   // Destructor
     //============================================================================
     /**
     * @brief // read next data from oFcwStr as string <BR>
     * iStat = oFcwStr.String2Str ( iKey, iColWidth, &oFcwStr, &oStrVal);
     *
     * @param iKey      [in] For the moment 0
     * @param iColWidth [in] Column width in string for reading
     * @param oFcwStr   [in] string with fix column width data
     * @param oStrVal   [out] return value
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
    int String2Str(int iKey, int iColWidth, std:: string oFcwStr, std::string *oStrVal);
    //==============================================================================
    /**
    * @brief // read next data from oFcwStr as char string <BR>
    * iStat = oFcwStr.String2Char ( iKey, iColWidth, &oFcwStr, &cVal, iCharLen);
    *
    * @param iKey      [in] For the moment 0
    * @param iColWidth [in] Column width in string for reading
    * @param oFcwStr   [in] string with fix column width data
    * @param cVal      [out] return value
    * @param iCharLen  [in]  size of char string
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int String2Char(int iKey, int iColWidth, std:: string oFcwStr, char *cVal, int iCharLen);
    //==============================================================================
    /**
    * @brief // write char string as string to oFcwStr <BR>
    * iStat = oFcwStr.Char2String ( iKey, iColWidth, &cVal, &oFcwStr);
    *
    * @param iKey      [in] For the moment 0
    * @param iColWidth [in] read next data
    * @param cVal      [in] char string value
    * @param oFcwStr   [out] return string with fix column width data
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Char2String(int iKey, int iColWidth, char *cVal, std:: string *oFcwStr);
    //============================================================================
    /**
    * @brief // read next data from oFcwStr as integer value <BR>
    * iStat = oFcwStr.String2Str ( iKey, iColWidth, &oFcwStr, &iVal);
    *
    * @param iKey      [in] For the moment 0
    * @param iColWidth [in] Column width in string for reading
    * @param oFcwStr   [in] string with fix column width data
    * @param iVal      [out] return integer value
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int String2Int(int iKey, int iColWidth, std:: string oFcwStr, int *iVal);
    //==============================================================================
    /**
    * @brief // write int value as string to oFcwStr <BR>
    * iStat = oFcwStr.Char2String ( iKey, iColWidth, iVal, &oFcwStr);
    *
    * @param iKey      [in] For the moment 0
    * @param iColWidth [in] read next data
    * @param iVal      [in] char string value
    * @param oFcwStr   [out] return string with fix column width data
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Int2String(int iKey, int iColWidth, int iVal, std:: string *oFcwStr);
    //==============================================================================
    /**
    * @brief // write int value with format info as string to oFcwStr <BR>
    * iStat = oFcwStr.IntFrmt2String ( iKey, iColWidth, iVal, oFrmtStr, &oFcwStr);
    *
    * @param iKey      [in] For the moment 0
    * @param iColWidth [in] read next data
    * @param iVal      [in] char string value
    * @param oFrmtStr  [in] format string
    * @param oFcwStr   [out] return string with fix column width data
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int IntFrmt2String(int iKey, int iColWidth, int iVal, std::string oFrmtStr, std:: string *oFcwStr);
    //============================================================================
    /**
    * @brief // read next data from oFcwStr as long int value <BR>
    * iStat = oFcwStr.String2Str ( iKey, iColWidth, &oFcwStr, &lVal);
    *
    * @param iKey      [in] For the moment 0
    * @param iColWidth [in] Column width in string for reading
    * @param oFcwStr   [in] string with fix column width data
    * @param lVal      [out] return long int value
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int String2Long(int iKey, int iColWidth, std:: string oFcwStr, long *lVal);
    //==============================================================================
    /**
    * @brief // write long int value as string to oFcwStr <BR>
    * iStat = oFcwStr.Long2String ( iKey, iColWidth, lVal, &oFcwStr);
    *
    * @param iKey      [in] For the moment 0
    * @param iColWidth [in] read next data
    * @param lVal      [in] long int value
    * @param oFcwStr   [out] return string with fix column width data
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Long2String(int iKey, int iColWidth, long lVal, std:: string *oFcwStr);
    //==============================================================================
    /**
    * @brief // write long int value  with format info as string to oFcwStr <BR>
    * iStat = oFcwStr.LongFrmt2String ( iKey, iColWidth, lVal, oFrmtStr, &oFcwStr);
    *
    * @param iKey      [in] For the moment 0
    * @param iColWidth [in] read next data
    * @param lVal      [in] long int value
    * @param oFrmtStr  [in] format string
    * @param oFcwStr   [out] return string with fix column width data
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int LongFrmt2String(int iKey, int iColWidth, long lVal, std::string oFrmtStr, std:: string *oFcwStr);
    //============================================================================
    /**
    * @brief // read next data from oFcwStr as double value <BR>
    * iStat = oFcwStr.String2Str ( iKey, iColWidth, &oFcwStr, &dVal);
    *
    * @param iKey      [in] For the moment 0
    * @param iColWidth [in] Column width in string for reading
    * @param oFcwStr   [in] string with fix column width data
    * @param dVal      [out] return double value
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int String2Dbl(int iKey, int iColWidth, std:: string oFcwStr, double *dVal);
    //==============================================================================
    /**
    * @brief // write char string as string to oFcwStr <BR>
    * iStat = oFcwStr.Char2String ( iKey, iColWidth, dVal, &oFcwStr);
    *
    * @param iKey      [in] For the moment 0
    * @param iColWidth [in] read next data
    * @param dVal      [in] char string value
    * @param oFcwStr   [out] return string with fix column width data
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Dbl2String(int iKey, int iColWidth, double dVal, std:: string *oFcwStr);
    //==============================================================================
    /**
    * @brief // write double value with format info as string to oFcwStr <BR>
    * iStat = oFcwStr.DblFrmt2String ( iKey, iColWidth, dVal, oFrmtStr, &oFcwStr);
    *
    * @param iKey      [in] For the moment 0
    * @param iColWidth [in] read next data
    * @param dVal      [in] char string value
    * @param oFrmtStr  [in] format string
    * @param oFcwStr   [out] return string with fix column width data
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int DblFrmt2String(int iKey, int iColWidth, double dVal, std::string oFrmtStr, std:: string *oFcwStr);
    //============================================================================
    /**
    * @brief // read next data from oFcwStr as float value <BR>
    * iStat = oFcwStr.String2Str ( iKey, iColWidth, &oFcwStr, &fVal);
    *
    * @param iKey      [in] For the moment 0
    * @param iColWidth [in] Column width in string for reading
    * @param oFcwStr   [in] string with fix column width data
    * @param fVal      [out] return float value
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int String2Float(int iKey, int iColWidth, std:: string oFcwStr, float *fVal);
    //==============================================================================
    /**
    * @brief // write char string as string to oFcwStr <BR>
    * iStat = oFcwStr.Char2String ( iKey, iColWidth, fVal, &oFcwStr);
    *
    * @param iKey      [in] For the moment 0
    * @param iColWidth [in] read next data
    * @param fVal      [in] char string value
    * @param oFcwStr   [out] return string with fix column width data
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Float2String(int iKey, int iColWidth, float fVal, std:: string *oFcwStr);
    //==============================================================================
    /**
    * @brief // write float value with format info as string to oFcwStr <BR>
    * iStat = oFcwStr.FloatFrmt2String ( iKey, iColWidth, fVal, oFrmtStr, &oFcwStr);
    *
    * @param iKey      [in] For the moment 0
    * @param iColWidth [in] read next data
    * @param fVal      [in] char string value
    * @param oFrmtStr  [in] format string
    * @param oFcwStr   [out] return string with fix column width data
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int FloatFrmt2String(int iKey, int iColWidth, float fVal, std::string oFrmtStr, std:: string *oFcwStr);
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
/** Set No Information Char <BR>
*
* Default " " (Blank)
*
* @param iKey        [in] For the moment 0
* @param cNoInfoChar [in] No Information Char
*
*/
int SetNoInfoChar(int iKey, char *cNoInfoChar);
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
* @brief Get Separator string
*
* @retval   Return separator string
*/
// ----------------------------------------------------------------------------
std::string GetSeparatorStr();
//==============================================================================
/**
* @brief Get actual read position
*
* @retval Return Actual read position in string
*/
// ----------------------------------------------------------------------------
unsigned long GetReadPosition();
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


// ----------------------------------------------------------------------------
  int Dum2;       /**< Dummy2 */
  private:  // Private functions
  //==============================================================================
  /** Set Error string
  * @param oErrStr oErrStr
  */
  void SetErrorString(std::string oErrStr);
  //==============================================================================
  char cSeparator[2];     //!< Separator Character, for example " " or ";"   */
  char cBracket[2];       //!< For example "\x22"                    */
  char cBracketOpen[2];   //!< For example "("                     */
  char cBracketClose[2];  //!< For example ")"                    */
  char cNoInfo[2];        //!< For example " " blank                         */
  unsigned long ulPos;    //!< Read Position in sst String                  */
  int  iFormatKenn;       //!< fixcolumnformat=0; charseparatedformat=1      */
  int  iDecType;          //!< floating comma = 0; floating point = 1        */
  int  iSeparatorTyp;     //!< 0=No Sep, 1=only strings,2=All                */
  int  iBoolTyp;          //!< 0=0/1, 1=F/T,2=.F./.T.                        */
  std::string oErrStr;    //!< Error string                                  */
};
//-----------------------------------------------------------------------------


//==============================================================================

#endif

// ------------------------------------------------------------------- End -----
