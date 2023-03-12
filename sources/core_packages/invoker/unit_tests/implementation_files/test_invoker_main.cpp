//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "test_invoker_main.h"
#include "test_invoker_utilities.h"
#include "TaskLabelContainerFixture.h"

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

BOOST_FIXTURE_TEST_SUITE(TEST_INDEX_OF,
                         ANANSI::TaskLabelContainerFixture)

    BOOST_AUTO_TEST_CASE(IndexOF_test)
    { 
        ANANSI::verify_index_at_front<TaskLabelContainerFixture::EmptyLabelTypelist>(); 
        ANANSI::verify_index_at_front<TaskLabelContainerFixture::SingleLabelTypelist>(); 
        ANANSI::verify_index_at_front<TaskLabelContainerFixture::LabelTypelist>(); 

        ANANSI::verify_index_at_middle<TaskLabelContainerFixture::EmptyLabelTypelist>(); 
        ANANSI::verify_index_at_middle<TaskLabelContainerFixture::SingleLabelTypelist>(); 
        ANANSI::verify_index_at_middle<TaskLabelContainerFixture::LabelTypelist>(); 

        ANANSI::verify_index_at_end<TaskLabelContainerFixture::EmptyLabelTypelist>(); 
        ANANSI::verify_index_at_end<TaskLabelContainerFixture::SingleLabelTypelist>(); 
        ANANSI::verify_index_at_end<TaskLabelContainerFixture::LabelTypelist>(); 
        
        ANANSI::verify_index_for_no_match<TaskLabelContainerFixture::LabelTypelist>(); 
    }

BOOST_AUTO_TEST_SUITE_END()

int main(int argc,char* argv[], char* envp[])
{
    return utf::unit_test_main(init_unit_test,argc,argv);
}
