#ifndef  ANANSI_CommunicatorIngredientTraits_INC
#define  ANANSI_CommunicatorIngredientTraits_INC
//! @file CommunicatorIngredientTraits.h
//!
//! This file contains the class CommunicatorIngredientTraits.
//!
//! The responsibilty of the class is to store the type of
//! the base class for all communicators.

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

//! @class CommunicatorIngredientTraits
//!
//! Stores the type of the base class for all communicators.
//
//! To access the base class type simply use
//!
//!     CommunicatorIngredientTraits::type
//!
//! 
class CommunicatorIngredientTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        CommunicatorIngredientTraits ();   // constructor

        CommunicatorIngredientTraits (const CommunicatorIngredientTraits & other);   // copy constructor

        CommunicatorIngredientTraits (CommunicatorIngredientTraits && other);   // copy-move constructor

        ~CommunicatorIngredientTraits ();  // destructor

        // ====================  Aliases       =======================================
        using type = std::unique_ptr<COMMUNICATOR::Communicator>;

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        CommunicatorIngredientTraits& operator= ( const CommunicatorIngredientTraits &other ); // assignment operator

        CommunicatorIngredientTraits& operator= ( CommunicatorIngredientTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class CommunicatorIngredientTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_CommunicatorIngredientTraits_INC  ----- 
