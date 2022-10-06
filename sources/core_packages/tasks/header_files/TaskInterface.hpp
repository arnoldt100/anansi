#ifndef ANANSI_TaskInterface_INC
#define ANANSI_TaskInterface_INC
//! @file TaskInterface.hpp
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

// =====================================================================================
//        Class:  TaskInterface
//  Description:  
//  =====================================================================================
template <typename Derived>
class TaskInterface
{
    public:
        // ====================  LIFECYCLE     =======================================

        TaskInterface ()   // constructor
        {
            return;
        }

        TaskInterface (const TaskInterface & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        TaskInterface (TaskInterface && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method TaskInterface::TaskInterface  -----

        virtual ~TaskInterface () = 0;  // destructor

        // ====================  ACCESSORS     =======================================

        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to a constant CRTP derived class "Derived".
        Derived const & asDerived() const
        {
            return *static_cast<Derived const*>(this);
        }


        // ====================  MUTATORS      =======================================

        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to the CRTP derived class.
        Derived& asDerived()
        {
            return *static_cast<Derived*>(this);
        }

        virtual void enableTask() 
        {
            asDerived().enableConcreteTask();
            return;
        }

        virtual void disableTask() 
        {
            asDerived().disableConcreteTask();
            return;
        }

        void bindReceivers()
        {
            return;
        }

        template<typename T, typename... Types>
        void bindReceivers(T firstArg, Types... args)
        {
            asDerived().bindAReceiver(firstArg);
            this->bindReceivers(args...);
            return;
        }

        // ====================  OPERATORS     =======================================

        TaskInterface& operator= ( const TaskInterface &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        TaskInterface& operator= ( TaskInterface && other ) // assignment-move operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment-move operator


        virtual void operator()()
        {
            asDerived().executeConcreteTask();
        }
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskInterface  -----

template <typename Derived>
TaskInterface<Derived>::~TaskInterface ()  // destructor
{
    return;
}

}; // namespace ANANSI

#endif // ANANSI_TaskInterface_INC
