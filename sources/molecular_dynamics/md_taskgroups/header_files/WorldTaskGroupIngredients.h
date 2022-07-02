#ifndef  ANANSI_WorldTaskGroupIngredients_INC
#define  ANANSI_WorldTaskGroupIngredients_INC


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
#include "CommandLineArguments.h"
#include "Communicator.h"

namespace ANANSI
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
        WorldTaskGroupIngredients (const COMMANDLINE::CommandLineArguments & cmdline);   // constructor

        WorldTaskGroupIngredients (const WorldTaskGroupIngredients & other);   // copy constructor

        WorldTaskGroupIngredients (WorldTaskGroupIngredients && other);   // copy-move constructor

        virtual ~WorldTaskGroupIngredients ();  // destructor

        // ====================  ACCESSORS     =======================================

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

}; // -----  end of class WorldTaskGroupIngredients  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_WorldTaskGroupIngredients_INC  ----- 
