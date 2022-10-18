#ifndef  ANANSI_WorldCommunicatorIngredientTraits_INC
#define  ANANSI_WorldCommunicatorIngredientTraits_INC

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
#include "Communicator.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  WorldCommunicatorIngredientTraits
//  Description:  
//  =====================================================================================
// :TODO: Remove class WorldCommunicatorIngredientTraits from project.
class WorldCommunicatorIngredientTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        WorldCommunicatorIngredientTraits ();   // constructor

        WorldCommunicatorIngredientTraits (const WorldCommunicatorIngredientTraits & other);   // copy constructor

        WorldCommunicatorIngredientTraits (WorldCommunicatorIngredientTraits && other);   // copy-move constructor

        ~WorldCommunicatorIngredientTraits ();  // destructor

        // ====================  Aliases       =======================================
        using type = std::unique_ptr<COMMUNICATOR::Communicator>;

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        WorldCommunicatorIngredientTraits& operator= ( const WorldCommunicatorIngredientTraits &other ); // assignment operator

        WorldCommunicatorIngredientTraits& operator= ( WorldCommunicatorIngredientTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class WorldCommunicatorIngredientTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_WorldCommunicatorIngredientTraits_INC  ----- 
