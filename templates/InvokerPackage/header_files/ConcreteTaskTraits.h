#ifndef ANANSI_ConcreteTaskTraits_INC
#define ANANSI_ConcreteTaskTraits_INC
//! @file ConcreteTaskTraits.h
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
#include "AbstractTask.h"
#include "GenericMDTask.hpp"
#include "ConcreteTaskReceiver.h"

namespace ANANSI
{

class ConcreteTaskTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        ConcreteTaskTraits ();   // constructor

        ConcreteTaskTraits (const ConcreteTaskTraits & other);   // copy constructor

        ConcreteTaskTraits (ConcreteTaskTraits && other);   // copy-move constructor

        ~ConcreteTaskTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ConcreteTaskTraits& operator= ( const ConcreteTaskTraits &other ); // assignment operator

        ConcreteTaskTraits& operator= ( ConcreteTaskTraits && other ); // assignment-move operator
        
        // ====================  ALIASES       =======================================

        using abstract_products = MPL::mpl_typelist<
                                                        AbstractTask
                                                   >;

        using concrete_products = MPL::mpl_typelist<
                                                        GenericMDTask<AbstractTask,ConcreteTaskReceiver>
                                                   >;

        using receiver_results_t = MPL::mpl_typelist<
                                                        ConcreteTaskReceiver::receiver_result_t 
                                                    >;

        static constexpr auto LABELS = std::array{
                                                    ConcreteTaskReceiver::TASKLABEL
                                                 };

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ConcreteTaskTraits  -----


}; // namespace ANANSI

#endif // ANANSI_ConcreteTaskTraits_INC
