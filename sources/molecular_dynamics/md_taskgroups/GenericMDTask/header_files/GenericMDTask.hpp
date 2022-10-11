#ifndef ANANSI_GenericMDTask_INC
#define ANANSI_GenericMDTask_INC
//! @file GenericMDTask.hpp
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
#include "DefaultFunctorImpl.h"

namespace ANANSI
{

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

        // ====================  MUTATORS      =======================================
        template<typename... T>
        typename FunctorImplType::ResultType operator()(T &... args)
        {
            std::cout << "FunctorImplType::ResultType operator stud call";
        }
        
        template <typename... Types>
        void bindReceivers(Types &... args)
        {
            std::cout << "Binding " << sizeof...(args)  << " receiver(s)." << std::endl;
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
        template <typename firstArgType, typename... Types>
        void bindReceiverrs_(firstArgType & firstarg, Types &... args)
        {
            std::cout << "Binding a general receiver." << std::endl;
        }

        // ====================  DATA MEMBERS  =======================================
        std::shared_ptr<FunctorImplType> funcImpl_;
        std::shared_ptr<ReceiverType> receiver_;

}; // -----  end of class GenericMDTask  -----


}; // namespace ANANSI

#endif // ANANSI_GenericMDTask_INC
