#ifndef ANANSI_GenericMDTask_INC
#define ANANSI_GenericMDTask_INC
//! @file GenericMDTask.hpp
//!
//! This file contains the declaration for GenericMDTask.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <memory>
#include <vector>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TaskLabel.hpp"
#include "AnansiTaskParameters.h"
#include "DefaultFunctorImpl.h"

namespace ANANSI
{

//! This template class is the blueprint for all concrete tasks.
//!
//! @tparam BaseClass The base class for the concrete task
//! @tparam Receiver The type of the concrete task receiver.
//! @tparam FunctorImpl Not presently used. Reserved for future use.
template <class BaseClass,
          class Receiver,
          class FunctorImpl = DefaultFunctorImpl>
class GenericMDTask : public BaseClass  
{

    public:

        using task_result_t = typename Receiver::receiver_result_t;
        using receiver_copy_t =  typename Receiver::receiver_copy_t;

        // ====================  STATIC       =======================================
        static constexpr ANANSI::TaskLabel TASKLABEL =
            Receiver::TASKLABEL;

        // ====================  LIFECYCLE     =======================================

        GenericMDTask ()  : // constructor
            funcImpl_(nullptr),
            receiver_(nullptr)
        {
            return;
        }

        GenericMDTask (const GenericMDTask & other)  :  // copy constructor
            funcImpl_(other.funcImpl_),
            receiver_(other.receiver_)
        {
            if (this != &other)
            {
            }
            return;
        }

        GenericMDTask (GenericMDTask && other) :  // copy-move constructor
            funcImpl_(std::move(other.funcImpl_)),
            receiver_(std::move(other.receiver_))
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method GenericMDTask::GenericMDTask  -----

        ~GenericMDTask ()  // destructor
        {
            return;
        }


        // ====================  ACCESSORS     =======================================
        AnansiTaskParameters::task_size_t taskIndex_() const override
        {
            return this->taskConcreteTypeListIndex_;
        }

        //! Gets the result of getCopyOfResults
        //!
        //! Returns a copy of the receiver results.  The calling function
        //! gets a copy results via a unique_ptr. The original results does not 
        //! reset to default values.
        auto getCopyOfResults() const
        {
            task_result_t results = 
                this->receiver_->getCopyOfResults();
            return results;
        }

        // ====================  MUTATORS      =======================================

        //! This method is mot used, but a simple placeholder.
        template<typename... T>
        typename FunctorImpl::ResultType operator()(T &... args)
        {
            std::cout << "FunctorImpl::ResultType operator stud call" << std::endl;
        }

        //! Performs the concrete task.
        //!
        //! @param [in] flags Used for any purpose in the concrete class
        void doConcreteTaskAction(const std::vector<std::string> & flags) const override
        {
            this->receiver_->doAction();
            return;
        }

        //! Undoes the concrete task.
        //!
        //! @param [in] flags Used for any purpose in the concrete class
        void undoConcreteTaskAction(const std::vector<std::string> & flags) override
        {
            this->receiver_->undoAction();
            return;
        }

        //! Enables  the concrete task.
        //!
        //! @param [in] flags Used for any purpose in the concrete class
        void enableConcreteTask(const std::vector<std::string> & flags) override
        {
            this->receiver_->enable();
            return;
        }
        //! Disables the concrete task.
        //!
        //! @param [in] flags Used for any purpose in the concrete class
        void disableConcreteTask(const std::vector<std::string> & flags) override
        {
            this->receiver_->disable();
            return;
        }

        //! Binds the receiver to the concrete task.
        //!
        //! @tparam index_t Not used at the time.
        //! @param [in] recv The receiver to bind to the concrete task
        template<typename index_t>
        void bindReceiver(std::shared_ptr<Receiver> & recv)
        {
            this->receiver_ = recv;
            this->taskConcreteTypeListIndex_ = index_t::value;
        }

        //! Modifies the receiver of the concrete task
        //!
        //! @tparam T A template parameter of values for modifying the receiver.
        //! param  ...args  The values for modifying the receiver 
        template<typename... T>
        void modifyReceiver(T &... args)
        {
            this->receiver_->modifyReceiver(args...);
            return;
        }

        //! Gets the result of shareOwnershipOfResults
        //!
        //! Returns a shared_ptr of the receiver results.  The calling function
        //! shares ownership of the receiver results via a shared_ptr.
        task_result_t shareOwnershipOfResults()
        {
            task_result_t results = 
                this->receiver_->shareOwnershipOfResults();
            return results;
        }

        //! Gets the result of takeOwnershipOfResults
        //!
        //! Returns a unique_ptr of the receiver results.  The calling function
        //! takes ownership of the receiver results via a unique_ptr. The original results 
        //! resets to default values.
        task_result_t takeOwnershipOfResults()
        {
            task_result_t results = 
                this->receiver_->transferOwnershipOfResults();
            return results;
        }
        // ====================  OPERATORS     =======================================

        GenericMDTask& operator= (const GenericMDTask &other) // assignment operator
        {
            if (this != &other)
            {
                this->funcImpl_ = other.funcImpl_;
                this->receiver_ = other.receiver_;
        
            }
            return *this;
        } // assignment operator

        GenericMDTask& operator= ( GenericMDTask && other ) // assignment-move operator
        {
            if (this != &other)
            {
                this->funcImpl_ = std::move(other.funcImpl_);
                this->receiver_ = std::move(other.receiver_);
            }
            return *this;
        } // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::shared_ptr<FunctorImpl> funcImpl_;
        std::shared_ptr<Receiver> receiver_;
        AnansiTaskParameters::task_size_t taskConcreteTypeListIndex_; 


}; // -----  end of class GenericMDTask  -----

}; // namespace ANANSI

#endif // ANANSI_GenericMDTask_INC
