#ifndef  ANANSI_DummyTraits_INC
#define  ANANSI_DummyTraits_INC

//! @file DummyTraits.h
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"
#include "GenericMDTask.hpp"

// Includes for abstract tasks.
#include "DummyAbstractTask1.h"
#include "DummyAbstractTask2.h"


// Includes for concrete tasks receivers.
#include "DummyConcreteTask1.h"
#include "DummyConcreteTask2.h"

namespace ANANSI
{

class DummyTraits
{
    public:

        // ====================  LIFECYCLE     =======================================

        DummyTraits ();   // constructor

        DummyTraits (const DummyTraits & other);   // copy constructor

        DummyTraits (DummyTraits && other);   // copy-move constructor

        ~DummyTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        DummyTraits& operator= ( const DummyTraits &other ); // assignment operator

        DummyTraits& operator= ( DummyTraits && other ); // assignment-move operator

        using abstract_products = MPL::mpl_typelist<
                                                       DummyAbstractTask1,
                                                       DummyAbstractTask2
                                                   >;

        using concrete_products = MPL::mpl_typelist<
                                                       GenericMDTask<DummyAbstractTask1,DummyConcreteTaskReceiver1>,
                                                       GenericMDTask<DummyAbstractTask2,DummyConcreteTaskReceiver2>
                                                   >;

        using receiver_results_t = MPL::mpl_typelist <
                                                         DummyConcreteTaskReceiver1::receiver_result_t, 
                                                         DummyConcreteTaskReceiver2::receiver_result_t, 
                                                     >;

        static constexpr auto LABELS = std::array{
                                                         DummyConcreteTaskReceiver1::TASKLABEL,
                                                         DummyConcreteTaskReceiver2::TASKLABEL,
                                                 };
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class DummyTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_DummyTraits_INC  ----- 
