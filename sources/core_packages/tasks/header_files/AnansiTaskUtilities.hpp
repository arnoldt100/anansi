#ifndef  ANANSI_AnansiTaskUtilities_INC
#define  ANANSI_AnansiTaskUtilities_INC

//! @file AnansiTaskUtilities.hpp
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

namespace ANANSI
{

template <typename abstract_task_t, typename concrete_task_t>
class AnansiTaskUtilities
{
    public:
        // ====================  LIFECYCLE     =======================================

        AnansiTaskUtilities ()   // constructor
        {
            return;
        }

        AnansiTaskUtilities (const AnansiTaskUtilities & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        AnansiTaskUtilities (AnansiTaskUtilities && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method __classname__::__classname__  -----

        ~AnansiTaskUtilities ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        template<typename... Types>
        static std::shared_ptr<abstract_task_t> bindReceiverToTask(std::shared_ptr<abstract_task_t> & product, Types &... args)
        {
            std::shared_ptr<concrete_task_t> p_concrete = 
                AnansiTaskUtilities<abstract_task_t,concrete_task_t>::asConcreteTask_(product);
            p_concrete->bindReceivers(args...);
            std::shared_ptr<abstract_task_t> p_abstract = 
                AnansiTaskUtilities<abstract_task_t,concrete_task_t>::asAbstractTask_(p_concrete);
            return p_abstract;
        }

        template<typename... Types>
        static std::unique_ptr<abstract_task_t> bindReceiverToTask(std::unique_ptr<abstract_task_t> & product, Types &... args)
        {
            std::unique_ptr<concrete_task_t> p_concrete = 
                AnansiTaskUtilities<abstract_task_t,concrete_task_t>::asConcreteTask_(product);
            p_concrete->bindReceivers(args...);
            std::unique_ptr<abstract_task_t> p_abstract = 
                AnansiTaskUtilities<abstract_task_t,concrete_task_t>::asAbstractTask_(p_concrete);
            return p_abstract;
        }
        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        AnansiTaskUtilities& operator= ( const AnansiTaskUtilities &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        AnansiTaskUtilities& operator= ( AnansiTaskUtilities && other ) // assignment-move operator
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
        
        static std::shared_ptr<abstract_task_t> asAbstractTask_(std::shared_ptr<concrete_task_t> & aTask) 
        {
            return std::static_pointer_cast<abstract_task_t>(aTask);
        }

        static std::unique_ptr<abstract_task_t> asAbstractTask_(std::unique_ptr<concrete_task_t> & aTask)
        {
            abstract_task_t* tmp_ptr = dynamic_cast<concrete_task_t*>(aTask.get());
            std::unique_ptr<abstract_task_t> p_ptr(nullptr);
            if ( tmp_ptr != nullptr)
            {
                aTask.release();
                p_ptr.reset(tmp_ptr);
            }
            return p_ptr;
        }

        static std::shared_ptr<concrete_task_t> asConcreteTask_(std::shared_ptr<abstract_task_t> & aTask) 
        {
            return std::static_pointer_cast<concrete_task_t>(aTask);
        }
        
        static std::unique_ptr<concrete_task_t> asConcreteTask_(std::unique_ptr<abstract_task_t> & aTask)
        {
            concrete_task_t* tmp_ptr = dynamic_cast<concrete_task_t*>(aTask.get());
            std::unique_ptr<concrete_task_t> p_ptr(nullptr);
            if ( tmp_ptr != nullptr)
            {
                aTask.release();
                p_ptr.reset(tmp_ptr);
            }
            return p_ptr;
        }

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class AnansiTaskUtilities  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_AnansiTaskUtilities_INC  ----- 
