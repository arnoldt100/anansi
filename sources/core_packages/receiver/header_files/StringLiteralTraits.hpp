#ifndef  ANANSI_StringLiteralTraits_INC
#define  ANANSI_StringLiteralTraits_INC

//!@ file StringLiteralTraits.hpp
//!
//! This class stores additional information for the StringLiteral classr.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <cstddef>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace STRINGLITERAL

{


    
class StringLiteralTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The size of the char[] array in class StringLiteral.
        //! 
        //! The class StringLiteral has a class data attribute that is of
        //! length char[StringLiteralTraits::MAX_NM_CHARS]. Not this includes
        //! the null character '\0'.
        inline const static std::size_t MAX_NM_CHARS = 100;

        // ====================  LIFECYCLE     =======================================

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class StringLiteralTraits  -----


}; // namespace STRINGLITERAL

#endif // ANANSI_StringLiteralTraits_INC
