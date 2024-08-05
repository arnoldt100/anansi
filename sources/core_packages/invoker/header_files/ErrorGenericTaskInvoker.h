#ifndef ANANSI_ErrorGenericTaskInvoker_INC
#define ANANSI_ErrorGenericTaskInvoker_INC
//! \file ErrorGenericTaskInvoker.h
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

class ErrorGenericTaskInvoker
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        ErrorGenericTaskInvoker ();   // constructor

        //! The copy constructor.
        ErrorGenericTaskInvoker (const ErrorGenericTaskInvoker & other);   // copy constructor

        //! The move constructor.
        ErrorGenericTaskInvoker (ErrorGenericTaskInvoker && other);   // copy-move constructor

        ~ErrorGenericTaskInvoker ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        ErrorGenericTaskInvoker * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        ErrorGenericTaskInvoker& operator= ( const ErrorGenericTaskInvoker &other ); // assignment operator

        //! The move assignment operator.
        ErrorGenericTaskInvoker& operator= ( ErrorGenericTaskInvoker && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class ErrorGenericTaskInvoker  -----


}; // End of namespace ANANSI

#endif // ANANSI_ErrorGenericTaskInvoker_INC
