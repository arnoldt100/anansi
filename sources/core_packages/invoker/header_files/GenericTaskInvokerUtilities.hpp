#ifndef ANANSI_GenericTaskInvokerUtilities_INC
#define ANANSI_GenericTaskInvokerUtilities_INC

//! @file GenericTaskInvokerUtilities.hpp
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TaskLabel.hpp"
#include "AnansiTask.h"
#include "AnansiTaskUtilities.hpp"
#include "MPLAliases.hpp"
#include "GenericTaskUtilities.hpp"
#include "OwnershipTypes.hpp"

namespace ANANSI
{

class GenericTaskInvokerUtilities
{
    public:
        // ====================  LIFECYCLE     =======================================

        GenericTaskInvokerUtilities() // constructor
        {
            return;
        }

        GenericTaskInvokerUtilities(
            const GenericTaskInvokerUtilities &other) // copy constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        GenericTaskInvokerUtilities(
            GenericTaskInvokerUtilities &&other) // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~GenericTaskInvokerUtilities() // destructor
        {
            return;
        }

        // ====================  STATIC        =======================================

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GenericTaskInvokerUtilities &
        operator=(const GenericTaskInvokerUtilities &other) // assignment operator
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment operator

        GenericTaskInvokerUtilities &
        operator=(GenericTaskInvokerUtilities &&other) // assignment-move operator
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        //! An alias for the concrete task type located at position index.
        //!
        //! @tparam ConcreteTasksTypeList A typelist of concrete task types.
        //! @tparam concrete_index The location of the concrete type in
        //! ConcreteTasksTypeList we desire
        template <typename ConcreteTasksTypeList, MPL::mpl_size_type concrete_index>
        using CONCRETE_TASK_TYPE_AT_INDEX_ =
            MPL::mpl_at_c<ConcreteTasksTypeList,concrete_index>;

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class GenericTaskInvokerUtilities  -----

}; // namespace ANANSI

#endif // ----- #ifndef ANANSI_GenericTaskInvokerUtilities_INC  -----
