#ifndef test_stringliteral_relationship_operators
#define test_stringliteral_relationship_operators

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include <boost/test/unit_test.hpp>

namespace ANANSI
{
    template<typename T_a, typename T_b>
    void verify_relationship_operator_equal(const T_a & a, 
                                            const T_b & b)
    {
        BOOST_TEST( (a == a), "StringLiterals of \"A\" and \"A\" are supposed to be equal.");
        BOOST_TEST( !(a == b), "StringLiterals of \"A\" and \"B\" are supposed to be not equal.");
    }

    template<typename T_a, typename T_b>
    void verify_relationship_operator_notequal(const T_a & a, 
                                               const T_b & b)
    {
        BOOST_TEST( (a != a), "StringLiterals of \"A\" and \"A\" are supposed to be equal.");
        BOOST_TEST( (a != b), "StringLiterals of \"A\" and \"B\" are supposed to be not equal.");
    }

} // namespace ANANSI

#endif // ---- test_stringliteral_relationship_operators ----
