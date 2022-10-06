#ifndef ANANSI_TaskInterfaceUtilities_INC
#define ANANSI_TaskInterfaceUtilities_INC
//! @file TaskInterfaceUtilities.hpp
//!
//! Brief description
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
#include "AnansiTask.h"

namespace ANANSI
{

template<typename ConcreteTaskType>
class TaskInterfaceUtilities
{
    public:

        using CONCRETE_TASK_TYPE = ConcreteTaskType;

        // ====================  LIFECYCLE     =======================================

        TaskInterfaceUtilities ()   // constructor
        {
            return;
        }

        TaskInterfaceUtilities (const TaskInterfaceUtilities & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        TaskInterfaceUtilities (TaskInterfaceUtilities && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method TaskInterfaceUtilities::TaskInterfaceUtilities  -----

        ~TaskInterfaceUtilities ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        TaskInterfaceUtilities& operator= ( const TaskInterfaceUtilities &other ) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator

        TaskInterfaceUtilities& operator= ( TaskInterfaceUtilities && other ) // assignment-move operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment-move operator

        // ====================  STATIC METHODS=======================================
        template<typename... Types>
        void bindReceiverToTask(std::shared_ptr<ANANSI::AnansiTask> & aTask, Types... args )
        {
            // auto tmp =  std::static_pointer_cast<CONCRETE_TASK_TYPE>(aTask);

            auto dPtr = this->asConcreteTask_(aTask);

            dPtr->bindReceivers(args...);


            // this->mpiEnvironmentCmd_->bindReceivers(this->mpiEnvironment_);
            // We need a for loop to peel of each function parameter, a receiver,  and
            // bind add to the task.
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  ACCESSORS     =======================================
        
        std::shared_ptr<CONCRETE_TASK_TYPE> asConcreteTask_(std::shared_ptr<ANANSI::AnansiTask> & aTask) const
        {
            return std::static_pointer_cast<CONCRETE_TASK_TYPE>(aTask);
        }
        
        // ====================  MUTATORS      =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskInterfaceUtilities  -----



}; // namespace ANANSI

#endif // ANANSI_TaskInterfaceUtilities_INC
