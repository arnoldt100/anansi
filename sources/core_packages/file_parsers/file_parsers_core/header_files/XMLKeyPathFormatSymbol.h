#ifndef ANANSI_XMLKeyPathFormatSymbol_INC
#define ANANSI_XMLKeyPathFormatSymbol_INC
//! \file XMLKeyPathFormatSymbol.h
//!
//! \brief Brief description
//!
//! \details Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include<string_view>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

class XMLKeyPathFormatSymbol
{
    public:
        // ====================  LIFECYCLE     =======================================
        static constexpr std::string_view format_symbol{"%"};

        //! The default constructor.
        XMLKeyPathFormatSymbol ();   // constructor

        //! The copy constructor.
        XMLKeyPathFormatSymbol (const XMLKeyPathFormatSymbol & other);   // copy constructor

        //! The move constructor.
        XMLKeyPathFormatSymbol (XMLKeyPathFormatSymbol && other);   // copy-move constructor

        ~XMLKeyPathFormatSymbol ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        XMLKeyPathFormatSymbol * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        XMLKeyPathFormatSymbol& operator= ( const XMLKeyPathFormatSymbol &other ); // assignment operator

        //! The move assignment operator.
        XMLKeyPathFormatSymbol& operator= ( XMLKeyPathFormatSymbol && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class XMLKeyPathFormatSymbol  -----


}; // End of namespace ANANSI

#endif // ANANSI_XMLKeyPathFormatSymbol_INC
