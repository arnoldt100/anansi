#ifndef ANANSI_WorkLoadParameters_INC
#define ANANSI_WorkLoadParameters_INC
//! \file WorkLoadParameters.h
//!
//! \brief Brief description
//!
//! Detailed description

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
#include "Communicator.h"

namespace ANANSI
{

class WorkLoadParameters
{
    public:
        // ====================  LIFECYCLE     =======================================

        WorkLoadParameters ();   // constructor

        WorkLoadParameters (std::unique_ptr<COMMUNICATOR::Communicator> world_communicator);   // constructor

        WorkLoadParameters (const WorkLoadParameters & other);   // copy constructor

        WorkLoadParameters (WorkLoadParameters && other);   // copy-move constructor

        ~WorkLoadParameters ();  // destructor

        // ====================  ACCESSORS     =======================================
        WorkLoadParameters * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        WorkLoadParameters& operator= ( const WorkLoadParameters &other ); // assignment operator

        WorkLoadParameters& operator= ( WorkLoadParameters && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class WorkLoadParameters  -----


}; // namespace ANANSI

#endif // ANANSI_WorkLoadParameters_INC
