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
        BOOST_TEST( ! (a != a), "StringLiterals of \"A\" and \"A\" are supposed to be equal.");
        BOOST_TEST( (a != b), "StringLiterals of \"A\" and \"B\" are supposed to be not equal.");
    }

    template<typename T_a, typename T_b>
    void verify_relationship_operator_greaterthan(const T_a & a, 
                                                  const T_b & b)
    {
        BOOST_TEST( ! (a > a), "StringLiterals of \"A\" is not greater than itself.");
        BOOST_TEST( ! (a > b), "StringLiterals of \"A\" is supposed to be less than \"B\".");
        BOOST_TEST( (b > a), "StringLiterals of \"B\" is supposed to greater than \"A\".");
    }

    template<typename T_a, typename T_b>
    void verify_relationship_operator_greaterequalthan(const T_a & a, 
                                                       const T_b & b)
    {
        BOOST_TEST( (a >= a), "StringLiterals of \"A\" is not less than itself.");
        BOOST_TEST( ! (a >= b), "StringLiterals of \"A\" is supposed to be less than \"B\".");
        BOOST_TEST( (b >= a), "StringLiterals of \"B\" is supposed to greater or equal than \"A\".");
    }

    template<typename T_a, typename T_b>
    void verify_relationship_operator_lessthan(const T_a & a, 
                                               const T_b & b)
    {
        BOOST_TEST( ! (a < a), "StringLiterals of \"A\" is not less than itself.");
        BOOST_TEST( (a < b), "StringLiterals of \"A\" is supposed to be less than \"B\".");
        BOOST_TEST( ! (b < a), "StringLiterals of \"B\" is supposed to greater than \"A\".");
    }
    template<typename T_a, typename T_b>
    void verify_relationship_operator_lessequalthan(const T_a & a, 
                                                    const T_b & b)
    {
        BOOST_TEST( (a <= a), "StringLiterals of \"A\" is supposed to be than or equal to  itself.");
        BOOST_TEST( (a <= b), "StringLiterals of \"A\" is supposed to be less than or equal to \"B\".");
        BOOST_TEST( ! (b <= a), "StringLiterals of \"B\" is supposed to greater than \"A\".");
    }
} // namespace ANANSI

#endif // ---- test_stringliteral_relationship_operators ----
