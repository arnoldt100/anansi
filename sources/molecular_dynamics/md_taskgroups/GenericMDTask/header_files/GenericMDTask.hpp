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
namespace ANANSI
{

template <typename ReceiverType,
          typename FunctorImplType,
          typename BaseClass>
class GenericMDTask final : public BaseClass  
{
    public:
        // ====================  LIFECYCLE     =======================================

        GenericMDTask ()   // constructor
        {
            return;
        }

        GenericMDTask (const GenericMDTask & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        GenericMDTask (GenericMDTask && other)   // copy-move constructor
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
        void bindReceivers(Types... args)
        {
            std::cout << "Binding receivers." << std::endl;
        }

        template <typename T>
        void bindAReceiver(T arg)
        {
            std::cout << "Binding a general receiver." << std::endl;
        }

        // ====================  OPERATORS     =======================================

        GenericMDTask& operator= (const GenericMDTask &other) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        GenericMDTask& operator= ( GenericMDTask && other ) // assignment-move operator
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
        std::shared_ptr<FunctorImplType> funcImpl_;
        std::shared_ptr<ReceiverType> receiver_;

}; // -----  end of class GenericMDTask  -----


}; // namespace ANANSI

#endif // ANANSI_GenericMDTask_INC
