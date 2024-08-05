#ifndef ANANSI_MacroCommand_INC
#define ANANSI_MacroCommand_INC
//! @file MacroCommand.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiTask.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  MacroCommand
//  Description:  
//  =====================================================================================
template<typename... Types>
class MacroCommand : public AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        MacroCommand () :
            AnansiTask()
        {
            return;
        }

        MacroCommand (const MacroCommand & other) :
            AnansiTask(other)
        {
            return;
        }


        MacroCommand (MacroCommand && other) :
            AnansiTask(std::move(other))
       {
            if (this != &other)
            {

            }
            return;
       }

        virtual ~MacroCommand ()
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MacroCommand& operator= ( const MacroCommand &other )
        {
            if (this != &other)
            {
                AnansiTask::operator=(other); 
            }
            return *this;
        }

        MacroCommand& operator= ( MacroCommand && other )
        {
            if ( this != &other)
            {
                AnansiTask::operator=(std::move(other));
            }
            return *this;
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MacroCommand  -----


}; // namespace ANANSI

#endif // ANANSI_MacroCommand_INC
