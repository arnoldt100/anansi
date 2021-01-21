#ifndef  RegistryAnansiMDStatus_INC
#define  RegistryAnansiMDStatus_INC


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
    //        Scoped Enum :  RegistryAnansiMDStatus
    //  Description: The status of the MD instance is delineated.
    // =====================================================================================
    enum class RegistryAnansiMDStatus : int
    {
        Undefined,
        InitializingSimulationEnvironmentInProgess,
        InitializingSimulationEnvironmentSucessful,
        InitializingSimulationEnvironmentFail,
        ProcessingCommandLineInProgress,
        ProcessingCommandLineSuccessful,
        ProcessingCommandLineFailed,
        InitializingInitialConditionInProgress,
        InitializingInitialConditionSuccessful,
        InitializingInitialConditionFailed,
        PerfomingSimulationInProgress,
        PerfomingSimulationSuccessful,
        PerfomingSimulationFailed,
        TerminatingSimulationEnvironmentInProgress,
        TerminatingSimulationEnvironmentSuccessful,
        TerminatingSimulationEnvironmentFailed
    }; /* -----  end of enum class RegistryAnansiMDStatus  ----- */


}; /* namespace ANANSI */

#endif   // ----- #ifndef RegistryAnansiMDStatus_INC  ----- 
