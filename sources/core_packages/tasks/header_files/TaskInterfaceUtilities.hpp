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

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

template<typename T>
class TaskInterfaceUtilities
{
    public:
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
        template<template... Types>
        static BindReceiverToTask(T aTask, Types... args )
        {
            /// this->mpiEnvironmentCmd_->bindReceivers(this->mpiEnvironment_);
        }
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskInterfaceUtilities  -----


}; // namespace ANANSI

#endif // ANANSI_TaskInterfaceUtilities_INC
