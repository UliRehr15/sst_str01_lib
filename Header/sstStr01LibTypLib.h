//  sstStr01LibTypLib.h   21.03.18  Re.   21.03.18  Re.
//
//  Definitions of class "sstStr01Lib"
//
  
#ifndef   _SST_sstStr01Lib_Typ_HEADER
#define   _SST_sstStr01Lib_Typ_HEADER
  
/**
 * @defgroup sstStr01LibLib sstStr01LibLib
 *
 * Description: sstStr01LibLib
 *
 */
 
//==============================================================================
/**
* @brief Base
*
* More Comment
*
* Used Type Definitions
* sstStr01Cls oCsvCnvt;;0;0;;;oCsvCnvt Info
*
* Changed: 21.03.18  Re.
*
* @ingroup sstStr01LibLib
*
* @author Re.
*
* @date 21.03.18
*/
// ----------------------------------------------------------------------------
class sstStr01LibTypBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstStr01LibTypBaseCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstStr01LibTypBaseCls();// Constructor
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber();// Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName();// Get Csv-String with all Class member names
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType();// Get Csv-String with all Class member definition types
    //==============================================================================
    /**
    * @brief // Csv_Read <BR>
    * @param iKey
    * @param *sErrTxt
    * @param *ssstStr01Lib_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstStr01Lib_Str);// Csv Read Function
    //==============================================================================
    /**
    * @brief // Csv_Write <BR>
    * @param iKey
    * @param *ssstStr01Lib_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Write(int iKey , std::string *ssstStr01Lib_Str);// Csv Write Function
     sstStr01Cls oCsvCnvt;  /**< oCsvCnvt Info */
  private:
};
 
//==============================================================================
/**
* @brief Test 1 Class
*
* More Comment
*
* Used Type Definitions
* sstStr01Lib;Tst1Cls;iVal;II;3;0;sst String01 Library;Test 1 Class;Signed Integer Value
* sstStr01Lib;Tst1Cls;uiVal;UI;3;0;sst String01 Library;Test 1 Class;Unsigned Integer Value
* sstStr01Lib;Tst1Cls;lVal;LL;8;0;sst String01 Library;Test 1 Class;Signed Long Integer Value
* sstStr01Lib;Tst1Cls;ulVal;UL;8;0;sst String01 Library;Test 1 Class;Unsigned Long Integer Value
*
* Changed: 21.03.18  Re.
*
* @ingroup sstStr01LibLib
*
* @author Re.
*
* @date 21.03.18
*/
// ----------------------------------------------------------------------------
class sstStr01LibTypTst1ClsCls : public sstStr01LibTypBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstStr01LibTypTst1ClsCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstStr01LibTypTst1ClsCls();// Constructor
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber();// Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName();// Get Csv-String with all Class member names
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType();// Get Csv-String with all Class member definition types
    //==============================================================================
    /**
    * @brief // Csv_Read <BR>
    * @param iKey
    * @param *sErrTxt
    * @param *ssstStr01Lib_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstStr01Lib_Str);// Csv Read Function
    //==============================================================================
    /**
    * @brief // Csv_Write <BR>
    * @param iKey
    * @param *ssstStr01Lib_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Write(int iKey , std::string *ssstStr01Lib_Str);// Csv Write Function
    int iVal;  /**< Signed Integer Value */
    unsigned int uiVal;  /**< Unsigned Integer Value */
    long lVal;  /**< Signed Long Integer Value */
    unsigned long ulVal;  /**< Unsigned Long Integer Value */
  private:
};
 
//==============================================================================
/**
* @brief Test 2 Class
*
* More Comment
*
* Used Type Definitions
* sstStr01Lib;Tst2Cls;dVal;DD;10;2;sst String01 Library;Test 2 Class;Double Value
* sstStr01Lib;Tst2Cls;fVal;FF;6;2;sst String01 Library;Test 2 Class;Float Value
*
* Changed: 21.03.18  Re.
*
* @ingroup sstStr01LibLib
*
* @author Re.
*
* @date 21.03.18
*/
// ----------------------------------------------------------------------------
class sstStr01LibTypTst2ClsCls : public sstStr01LibTypBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstStr01LibTypTst2ClsCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstStr01LibTypTst2ClsCls();// Constructor
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber();// Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName();// Get Csv-String with all Class member names
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType();// Get Csv-String with all Class member definition types
    //==============================================================================
    /**
    * @brief // Csv_Read <BR>
    * @param iKey
    * @param *sErrTxt
    * @param *ssstStr01Lib_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstStr01Lib_Str);// Csv Read Function
    //==============================================================================
    /**
    * @brief // Csv_Write <BR>
    * @param iKey
    * @param *ssstStr01Lib_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Write(int iKey , std::string *ssstStr01Lib_Str);// Csv Write Function
    double dVal;  /**< Double Value */
    float fVal;  /**< Float Value */
  private:
};
 
//==============================================================================
/**
* @brief Test 3 Class
*
* More Comment
*
* Used Type Definitions
* sstStr01Lib;Tst3Cls;cVal;CC;6;0;sst String01 Library;Test 3 Class;Character Value
* sstStr01Lib;Tst3Cls;bVal;BB;1;0;sst String01 Library;Test 3 Class;Bool Value
* sstStr01Lib;Tst3Cls;daVal;DA;8;0;sst String01 Library;Test 3 Class;Date Value
*
* Changed: 21.03.18  Re.
*
* @ingroup sstStr01LibLib
*
* @author Re.
*
* @date 21.03.18
*/
// ----------------------------------------------------------------------------
class sstStr01LibTypTst3ClsCls : public sstStr01LibTypBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstStr01LibTypTst3ClsCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstStr01LibTypTst3ClsCls();// Constructor
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber();// Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName();// Get Csv-String with all Class member names
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType();// Get Csv-String with all Class member definition types
    //==============================================================================
    /**
    * @brief // Csv_Read <BR>
    * @param iKey
    * @param *sErrTxt
    * @param *ssstStr01Lib_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstStr01Lib_Str);// Csv Read Function
    //==============================================================================
    /**
    * @brief // Csv_Write <BR>
    * @param iKey
    * @param *ssstStr01Lib_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Write(int iKey , std::string *ssstStr01Lib_Str);// Csv Write Function
    char cVal[7];  /**< Character Value */
    bool bVal;  /**< Bool Value */
    char daVal[9];  /**< Date Value */
  private:
};
 
#endif
//
// --------------------------------------------------------------- File End ----
