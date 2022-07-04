#ifndef  ANANSI_WorldTaskGroupIngredients_INC
#define  ANANSI_WorldTaskGroupIngredients_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandLineArguments.h"
#include "Communicator.h"

namespace ANANSI_CRTP
{

// =====================================================================================
//        Class:  WorldTaskGroupIngredients
//  Description:  
//  =====================================================================================
class WorldTaskGroupIngredients
{
    public:
        // ====================  LIFECYCLE     =======================================

        WorldTaskGroupIngredients ();   // constructor
                                                                                         //
        WorldTaskGroupIngredients (const COMMANDLINE::CommandLineArguments & cmdline,
                                   const std::unique_ptr<COMMUNICATOR::Communicator> & world_communicator);   // constructor

        WorldTaskGroupIngredients (const WorldTaskGroupIngredients & other);   // copy constructor

        WorldTaskGroupIngredients (WorldTaskGroupIngredients && other);   // copy-move constructor

        ~WorldTaskGroupIngredients ();  // destructor

        // ====================  ACCESSORS     =======================================
        WorldTaskGroupIngredients* clone() const; 

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        WorldTaskGroupIngredients& operator= ( const WorldTaskGroupIngredients &other ); // assignment operator

        WorldTaskGroupIngredients& operator= ( WorldTaskGroupIngredients && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        COMMANDLINE::CommandLineArguments commandLineArguments_;
        std::unique_ptr<COMMUNICATOR::Communicator> worldCommunicator_;

}; // -----  end of class WorldTaskGroupIngredients  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_WorldTaskGroupIngredients_INC  ----- 
