#ifndef ANANSI_ReceiverInterface_INC
#define ANANSI_ReceiverInterface_INC
//! @file ReceiverInterface.hpp
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

template<typename Derived>
class ReceiverInterface
{
    public:
        // ====================  LIFECYCLE     =======================================

        ReceiverInterface ()   // constructor
        {
            return;
        }

        ReceiverInterface (const ReceiverInterface & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        ReceiverInterface (ReceiverInterface && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method ReceiverInterface::ReceiverInterface  -----

        virtual ~ReceiverInterface ()=0;  // destructor

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

        void enable()
        {
            asDerived().enableReceiver();
        }

        void disable()
        {
            asDerived().disableReceiver();
        }

        // ====================  OPERATORS     =======================================

        ReceiverInterface& operator= ( const ReceiverInterface &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        ReceiverInterface& operator= ( ReceiverInterface && other ) // assignment-move operator
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

}; // -----  end of class ReceiverInterface  -----

template <typename Derived>
ReceiverInterface<Derived>::~ReceiverInterface ()  // destructor
{
    return;
}

}; // namespace ANANSI

#endif // ANANSI_ReceiverInterface_INC
