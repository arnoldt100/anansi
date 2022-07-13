#ifndef  ANANSI_CommandLineArgumentsIngredientTraits_INC
#define  ANANSI_CommandLineArgumentsIngredientTraits_INC

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

namespace ANANSI
{

// =====================================================================================
//        Class:  CommandLineArgumentsIngredientTraits
//  Description:  
//  =====================================================================================
class CommandLineArgumentsIngredientTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        CommandLineArgumentsIngredientTraits ();   // constructor

        CommandLineArgumentsIngredientTraits (const CommandLineArgumentsIngredientTraits & other);   // copy constructor

        CommandLineArgumentsIngredientTraits (CommandLineArgumentsIngredientTraits && other);   // copy-move constructor

        ~CommandLineArgumentsIngredientTraits ();  // destructor

        // ====================  Aliases       =======================================
        using type = COMMANDLINE::CommandLineArguments;

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        CommandLineArgumentsIngredientTraits& operator= ( const CommandLineArgumentsIngredientTraits &other ); // assignment operator

        CommandLineArgumentsIngredientTraits& operator= ( CommandLineArgumentsIngredientTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class CommandLineArgumentsIngredientTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_CommandLineArgumentsIngredientTraits_INC  ----- 
