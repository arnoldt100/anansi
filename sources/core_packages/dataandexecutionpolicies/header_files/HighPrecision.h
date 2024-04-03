#ifndef ANANSI_HighPrecision_INC
#define ANANSI_HighPrecision_INC
//! \file HighPrecision.h
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

class HighPrecision
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        HighPrecision ();   // constructor

        //! The copy constructor.
        HighPrecision (const HighPrecision & other);   // copy constructor

        //! The move constructor.
        HighPrecision (HighPrecision && other);   // copy-move constructor

        ~HighPrecision ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        HighPrecision * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        HighPrecision& operator= ( const HighPrecision &other ); // assignment operator

        //! The move assignment operator.
        HighPrecision& operator= ( HighPrecision && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class HighPrecision  -----


}; // End of namespace ANANSI

#endif // ANANSI_HighPrecision_INC
