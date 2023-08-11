#ifndef ANANSI_GenericMDTaskUtilities_INC
#define ANANSI_GenericMDTaskUtilities_INC
//! \file GenericMDTaskUtilities.hpp

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
#include "AnansiTask.h"
#include "GenericMDTask.hpp"

namespace ANANSI
{

template <class Receiver,
          class RootTask=ANANSI::AnansiTask>
class GenericMDTaskUtilities
{
    public:
        // ====================  LIFECYCLE     =======================================

        GenericMDTaskUtilities ()   // constructor
        {
            return;
        }

        GenericMDTaskUtilities (const GenericMDTaskUtilities & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        GenericMDTaskUtilities (GenericMDTaskUtilities && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method GenericMDTaskUtilities::GenericMDTaskUtilities  -----

        ~GenericMDTaskUtilities () // destructor
        {
            return;
        }

        // ====================  STATIC        =======================================
        static void convertToConcreteGenericmdtask(std::shared_ptr<RootTask> task)
        {
            // We do a dynamic down cast to std::shared_ptr<GenericMDTask<Receiver>>
            using derived = GenericMDTask<Receiver>;
            auto ptr = std::dynamic_pointer_cast<derived>(task);
            auto results = ptr->getCopyOfResults();
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GenericMDTaskUtilities& operator= ( const GenericMDTaskUtilities &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        GenericMDTaskUtilities& operator= ( GenericMDTaskUtilities && other ) // assignment-move operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class GenericMDTaskUtilities  -----


}; // namespace ANANSI

#endif // ANANSI_GenericMDTaskUtilities_INC
