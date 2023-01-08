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
#include "AnansiTaskParameters.h"
#include "DefaultFunctorImpl.h"

namespace ANANSI
{

//! This template class is the blueprint for all concrete tasks.
//!
//! @tparam BaseClass The base class for the concrete task
//! @tparam ReceiverType The type of the concrete task receiver.
//! @tparam FunctorImplType Not presently used.
template <typename BaseClass,
          typename ReceiverType,
          typename FunctorImplType = DefaultFunctorImpl>
class GenericMDTask : public BaseClass  
{
    public:
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
        AnansiTaskParameters::task_size_t taskIndex_() const
        {
            return this->taskConcreteTypeListIndex_;
        }

        // ====================  MUTATORS      =======================================
        template<typename... T>
        typename FunctorImplType::ResultType operator()(T &... args)
        {
            std::cout << "FunctorImplType::ResultType operator stud call";
        }

        //! Performs the concrete task.
        //!
        //! @param [in] flags Used for any purpose in the concrete class
        void doConcreteTaskAction(const std::vector<std::string> & flags) const override
        {
            this->receiver_->action();
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
        void bindReceiver(std::shared_ptr<ReceiverType> & recv)
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
        std::shared_ptr<FunctorImplType> funcImpl_;
        std::shared_ptr<ReceiverType> receiver_;
        AnansiTaskParameters::task_size_t taskConcreteTypeListIndex_; 


}; // -----  end of class GenericMDTask  -----

}; // namespace ANANSI

#endif // ANANSI_GenericMDTask_INC
