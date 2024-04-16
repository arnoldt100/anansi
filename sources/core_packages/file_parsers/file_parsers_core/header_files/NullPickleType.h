#ifndef ANANSI_NullPickleType_INC
#define ANANSI_NullPickleType_INC
//! \file NullPickleType.h
//!
//! \brief Brief description
//!
//! \details Detailed description

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

class NullPickleType
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        NullPickleType ();   // constructor

        //! The copy constructor.
        NullPickleType (const NullPickleType & other);   // copy constructor

        //! The move constructor.
        NullPickleType (NullPickleType && other);   // copy-move constructor

        virtual ~NullPickleType ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        NullPickleType * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        NullPickleType& operator= ( const NullPickleType &other ); // assignment operator

        //! The move assignment operator.
        NullPickleType& operator= ( NullPickleType && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class NullPickleType  -----


}; // End of namespace ANANSI

#endif // ANANSI_NullPickleType_INC
