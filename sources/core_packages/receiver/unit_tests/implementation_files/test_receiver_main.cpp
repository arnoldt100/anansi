//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "test_receiver_main.h"
#include "test_stringliteraltraits.h"
#include "StringLiteralTestFixture.h"
#include "test_stringliteral_relationship_operators.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


}; // namespace ANANSI

BOOST_AUTO_TEST_SUITE(TEST_STRINGLITERALTRAITS)

    BOOST_AUTO_TEST_CASE(char_array_size)
    {
        ANANSI::verify_valid_char_array_size();
    }

BOOST_AUTO_TEST_SUITE_END()



BOOST_FIXTURE_TEST_SUITE(TEST_STRINGLITERAL_RELATIONSHIP_OPERATORS,
                         ANANSI::StringLiteralTestFixture)

    BOOST_AUTO_TEST_CASE(relationship_operators)
    {
        ANANSI::verify_relationship_operator_equal(a,b);
        ANANSI::verify_relationship_operator_notequal(a,b);
        ANANSI::verify_relationship_operator_greaterthan(a,b);
        ANANSI::verify_relationship_operator_greaterequalthan(a,b);
        ANANSI::verify_relationship_operator_lessthan(a,b);
        ANANSI::verify_relationship_operator_lessequalthan(a,b);
    }

BOOST_AUTO_TEST_SUITE_END()

int main(int argc,char* argv[], char* envp[])
{
    return utf::unit_test_main(init_unit_test,argc,argv);
}
