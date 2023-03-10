#ifndef RECEIVER_TASKLABEL_FIXTURES_INC
#define RECEIVER_TASKLABEL_FIXTURES_INC

//! @file TasklabelTestFixtures.h
//!
//! Provides test case for the TaskLabel tests.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TaskLabelTraits.hpp"
#include "TaskLabel.hpp"

namespace RECEIVER
{

class TaskLabelTestFixture
{
    public:
        constexpr static std::size_t MY_SIZE = TaskLabelTraits::MAX_NM_CHARS;
        constexpr static char LETTER_A[MY_SIZE]  = {"A"};
        constexpr static char LETTER_B[MY_SIZE]  = {"B"};

        // ====================  LIFECYCLE     =======================================

        TaskLabelTestFixture ();   // constructor

        ~TaskLabelTestFixture ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        // ====================  DATA MEMBERS  =======================================
        RECEIVER::TaskLabel a;
        RECEIVER::TaskLabel b;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskLabelTestFixture  -----


}; // namespace RECEIVER

#endif // RECEIVER_TASKLABEL_FIXTURES_INC
