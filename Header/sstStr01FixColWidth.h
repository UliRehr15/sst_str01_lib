// sstStr01FixColWidth.h   29.04.10  Re.   29.04.10  Re.
//
// Datastructures and Prototypes for system "sstStr01FixColWidth"
//

#ifndef   _SST_STR01_FIXCOLWIDTH_HEADER
#define   _SST_STR01_FIXCOLWIDTH_HEADER

// Defines ---------------------------------------------------------------------

// Structures and Classes ------------------------------------------------------

//==============================================================================
/**
* @brief Definition Class X
*
* More Comment
*
* Changed: 19.02.10  Re.
*
* @ingroup examples
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
//==============================================================================
/**
* @brief // Shortstory <BR>
* iStat = oTest =  Func_1( iKey);
*
* @param iKey [in] For the moment 0
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*/
// ----------------------------------------------------------------------------
    // Func_1(int iKey);
    int String2Str(int iKey, int iColWidth, std:: string oFcwStr, std::string *oStrVal);
    int String2Char(int iKey, int iColWidth, std:: string oFcwStr, char *cVal, int iCharLen);
    int Char2String(int iKey, int iColWidth, char *cVal, std:: string *oFcwStr);
    int String2Int(int iKey, int iColWidth, std:: string oFcwStr, int *iVal);
    int Int2String(int iKey, int iColWidth, int iVal, std:: string *oFcwStr);
    int String2Long(int iKey, int iColWidth, std:: string oFcwStr, long *lVal);
    int Long2String(int iKey, int iColWidth, long lVal, std:: string *oFcwStr);
    int String2Dbl(int iKey, int iColWidth, std:: string oFcwStr, double *dVal);
    int Dbl2String(int iKey, int iColWidth, double dVal, std:: string *oFcwStr);
    int DblFrmt2String(int iKey, int iColWidth, double dVal, std::string oFrmtStr, std:: string *oFcwStr);
    int String2Float(int iKey, int iColWidth, std:: string oFcwStr, float *fVal);
    int Float2String(int iKey, int iColWidth, float fVal, std:: string *oFcwStr);
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
