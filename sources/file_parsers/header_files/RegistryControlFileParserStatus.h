#ifndef  RegistryControlFileParserStatus_INC
#define  RegistryControlFileParserStatus_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

    // =====================================================================================
    //        Scoped Enum :  RegistryControlFileParserStatus
    //  Description: The status of the MD instance is delineated.
    // =====================================================================================
    enum class RegistryControlFileParserStatus : int
    {
        Undefined,
        Successful,
        FailedToParseXMLFileToPropertyTree,
        FailedToResolveXMLPath

    }; /* -----  end of enum class RegistryControlFileParserStatus  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef RegistryControlFileParserStatus_INC  ----- */
