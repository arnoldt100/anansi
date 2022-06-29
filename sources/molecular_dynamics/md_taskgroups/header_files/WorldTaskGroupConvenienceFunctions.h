#ifndef  ANANSI_WorldTaskGroupConvenienceFunctions_INC
#define  ANANSI_WorldTaskGroupConvenienceFunctions_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "WorldTaskGroup.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  WorldTaskGroupConvenienceFunctions
//  Description:  
//  =====================================================================================
class WorldTaskGroupConvenienceFunctions
{
    public:
        // ====================  LIFECYCLE     =======================================

        WorldTaskGroupConvenienceFunctions ();   // constructor

        WorldTaskGroupConvenienceFunctions (const WorldTaskGroupConvenienceFunctions & other);   // copy constructor

        WorldTaskGroupConvenienceFunctions (WorldTaskGroupConvenienceFunctions && other);   // copy-move constructor

        ~WorldTaskGroupConvenienceFunctions ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        WorldTaskGroupConvenienceFunctions& operator= ( const WorldTaskGroupConvenienceFunctions &other ); // assignment operator

        WorldTaskGroupConvenienceFunctions& operator= ( WorldTaskGroupConvenienceFunctions && other ); // assignment-move operator

        // ====================  STATIC        =======================================
        static void enable(std::unique_ptr<ANANSI::TaskGroup> & world_task_group);

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class WorldTaskGroupConvenienceFunctions  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_WorldTaskGroupConvenienceFunctions_INC  ----- 
