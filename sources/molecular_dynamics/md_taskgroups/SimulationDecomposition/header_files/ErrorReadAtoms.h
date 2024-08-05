#ifndef ANANSI_ErrorReadAtoms_INC
#define ANANSI_ErrorReadAtoms_INC
//! \file ErrorReadAtoms.h
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

class ErrorReadAtoms 
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        ErrorReadAtoms ();   // constructor

        //! The copy constructor.
        ErrorReadAtoms (const ErrorReadAtoms & other);   // copy constructor

        //! The move constructor.
        ErrorReadAtoms (ErrorReadAtoms && other);   // copy-move constructor

        ~ErrorReadAtoms ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        ErrorReadAtoms * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        ErrorReadAtoms& operator= ( const ErrorReadAtoms &other ); // assignment operator

        //! The move assignment operator.
        ErrorReadAtoms& operator= ( ErrorReadAtoms && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class ErrorReadAtoms  -----


}; // End of namespace ANANSI

#endif // ANANSI_ErrorReadAtoms_INC
