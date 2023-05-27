#ifndef ANANSI_GenericMDTaskContainer_INC
#define ANANSI_GenericMDTaskContainer_INC
//! @file GenericMDTaskContainer,h

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
#include "TaskLabel.hpp"
#include "AnansiTask.h"

namespace ANANSI
{

//! This class stores the GenericMdTask objects.
//!
//! The purpose of this class is to 'wrap' the GenericMdTask objects
//1 to facilitate modifying the GenericMdTask objects by means of the
//1 ReceiverInterface::modifyReceiver method which GenericMdTask inherits.
//! The GenericMDTaskContainer provides a interface for identifying  the
//! type of GenericMdTask object being pass as a argument to method
//! ReceiverInterface::modifyReceiver.
class GenericMDTaskContainer 
{
    public:
        // ====================  LIFECYCLE     =======================================

        GenericMDTaskContainer ();   // constructor

        GenericMDTaskContainer(std::shared_ptr<AnansiTask> my_task);

        GenericMDTaskContainer (const GenericMDTaskContainer & other) = delete;   // copy constructor

        GenericMDTaskContainer (GenericMDTaskContainer && other);   // copy-move constructor

        ~GenericMDTaskContainer ();  // destructor

        // ====================  ACCESSORS     =======================================
        bool compareTaskLabel() const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GenericMDTaskContainer& operator= ( const GenericMDTaskContainer &other )=delete; // assignment operator

        GenericMDTaskContainer& operator= ( GenericMDTaskContainer && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::shared_ptr<AnansiTask> task_;

}; // -----  end of class GenericMDTaskContainer  -----


}; // namespace ANANSI

#endif // ANANSI_GenericMDTaskContainer_INC
