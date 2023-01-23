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
#include "test_receiver_utilities.h"
#include "TaskLabelContainerFixture.h"

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

BOOST_FIXTURE_TEST_SUITE(TEST_INDEX_OF,
                         RECEIVER::TaskLabelContainerFixture)

    BOOST_AUTO_TEST_CASE(IndexOF_test)
    {
        RECEIVER::verify_index_at_front<TaskLabelContainerFixture::EmptyLabelTypelist>(); 
        RECEIVER::verify_index_at_front<TaskLabelContainerFixture::LabelTypelist>(); 
        // RECEIVER::verify_index_at_front<TaskLabelContainerFixture::SingleLabelTypelist>(); 

        RECEIVER::verify_index_at_middle<TaskLabelContainerFixture::LabelTypelist>(); 
        RECEIVER::verify_index_at_end<TaskLabelContainerFixture::LabelTypelist>(); 
        RECEIVER::verify_index_for_no_match<TaskLabelContainerFixture::LabelTypelist>(); 
        RECEIVER::verify_index_for_empty_list<TaskLabelContainerFixture::EmptyLabelTypelist>(); 
    }

BOOST_AUTO_TEST_SUITE_END()

int main(int argc,char* argv[], char* envp[])
{
    return utf::unit_test_main(init_unit_test,argc,argv);
}
