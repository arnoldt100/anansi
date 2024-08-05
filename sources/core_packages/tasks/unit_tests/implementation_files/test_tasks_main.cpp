//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "test_tasks_main.h"
#include "test_tasklabeltraits.h"
#include "TaskLabelTestFixture.h"
#include "test_tasklabel_relationship_operators.h"

namespace RECEIVER {

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


}; // namespace RECEIVER

BOOST_AUTO_TEST_SUITE(TEST_TASKLABELTRAITS)

    BOOST_AUTO_TEST_CASE(char_array_size)
    {
        RECEIVER::verify_valid_char_array_size();
    }

BOOST_AUTO_TEST_SUITE_END()



BOOST_FIXTURE_TEST_SUITE(TEST_TASKLABEL_RELATIONSHIP_OPERATORS,
                         RECEIVER::TaskLabelTestFixture)

    BOOST_AUTO_TEST_CASE(relationship_operators)
    {
        RECEIVER::verify_relationship_operator_equal(a,b);
        RECEIVER::verify_relationship_operator_notequal(a,b);
        RECEIVER::verify_relationship_operator_greaterthan(a,b);
        RECEIVER::verify_relationship_operator_greaterequalthan(a,b);
        RECEIVER::verify_relationship_operator_lessthan(a,b);
        RECEIVER::verify_relationship_operator_lessequalthan(a,b);
    }

BOOST_AUTO_TEST_SUITE_END()

int main(int argc,char* argv[], char* envp[])
{
    return utf::unit_test_main(init_unit_test,argc,argv);
}
