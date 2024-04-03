#ifndef ANANSI_LowPrecision_INC
#define ANANSI_LowPrecision_INC
//! \file LowPrecision.h
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

class LowPrecision
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        LowPrecision ();   // constructor

        //! The copy constructor.
        LowPrecision (const LowPrecision & other);   // copy constructor

        //! The move constructor.
        LowPrecision (LowPrecision && other);   // copy-move constructor

        ~LowPrecision ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        LowPrecision * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        LowPrecision& operator= ( const LowPrecision &other ); // assignment operator

        //! The move assignment operator.
        LowPrecision& operator= ( LowPrecision && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class LowPrecision  -----


}; // End of namespace ANANSI

#endif // ANANSI_LowPrecision_INC
