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
#include "ConcreteReceiverConstraints.hpp"
#include "TaskLabel.hpp"
#include "AnansiTaskParameters.h"
#include "DefaultFunctorImpl.h"
#include "OwnershipTypes.hpp"

namespace ANANSI
{

//! This template class is the blueprint for all concrete tasks.
//!
//! @tparam Receiver The type of the concrete task receiver.
//! @tparam FunctorImpl Not presently used. Reserved for future use.
template <class Receiver,
          class FunctorImpl = DefaultFunctorImpl> requires RECEIVER::ConcreteReceiverConstraints<Receiver>
class GenericMDTask : public Receiver::MyParentTask  
{

    public:

        // ====================  TYPE ALIASES  =======================================
        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes = typename Receiver:: template MyOwnershipTypes<Q>;

        using RESULT_TYPE = typename Receiver::receiver_result_t;

        using RESULT_COPYTYPE = typename MyOwnershipTypes<RECEIVER::OwnershipTypes::COPYTYPE>::TYPE;

        using RESULT_SHARETYPE = typename MyOwnershipTypes<RECEIVER::OwnershipTypes::SHARETYPE>::TYPE;

        using RESULT_TRANSFERTYPE = typename MyOwnershipTypes<RECEIVER::OwnershipTypes::TRANSFERTYPE>::TYPE;

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



        // ====================  MUTATORS      =======================================

        //! This method is not used, but a simple placeholder.
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
        
        //! Gets the result of getCopyOfResults
        auto getCopyOfResults() const
        {
            receiver_copy_t results = 
                this->receiver_->getCopyOfResults();
            return results;
        }

        //! Gets the result of shareOwnershipOfResults
        auto shareOwnershipOfResults()
        {
            receiver_share_t results = 
                this->receiver_->shareOwnershipOfResults();
            return results;
        }

        //! Gets the result of takeOwnershipOfResults
        auto takeOwnershipOfResults()
        {
            receiver_transfer_t results = 
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

        // ====================  TYPE ALIASES  =======================================
        using receiver_t = Receiver;
        using task_result_t = typename Receiver::receiver_result_t;
        using receiver_copy_t =  RESULT_COPYTYPE;
        using receiver_share_t =  RESULT_SHARETYPE;
        using receiver_transfer_t =  RESULT_TRANSFERTYPE;

        // ====================  MUTATORS      =======================================

        AnansiTaskParameters::task_size_t taskIndex_() const override
        {
            return this->taskConcreteTypeListIndex_;
        }

        ANANSI::TaskLabel taskLabel_() const override
        {
            return TASKLABEL;
        }

        // ====================  DATA MEMBERS  =======================================
        std::shared_ptr<FunctorImpl> funcImpl_;
        std::shared_ptr<Receiver> receiver_;
        AnansiTaskParameters::task_size_t taskConcreteTypeListIndex_; 


}; // -----  end of class GenericMDTask  -----

}; // namespace ANANSI

#endif // ANANSI_GenericMDTask_INC
