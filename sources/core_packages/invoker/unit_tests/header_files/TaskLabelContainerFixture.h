#ifndef RECEIVER_TaskLabelContainerFixture_INC
#define RECEIVER_TaskLabelContainerFixture_INC



//! @file TaskLabelContainerFixture.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string_view>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TaskLabelTraits.hpp"
#include "TaskLabel.hpp"
#include "GenericTaskUtilities.hpp"
#include "MPLAliases.hpp"

namespace ANANSI
{

template<ANANSI::TaskLabel T>
class TestConcreteTask
{
    public:
        constexpr static ANANSI::TaskLabel value = T; 
};

class TaskLabelContainerFixture
{
    public:
        // ====================  STATIC        =======================================

        // Defining type ConcreteTaskA 
        constexpr static char A[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'A'} ;
        using ConcreteA = TestConcreteTask<A>; 

        // Defining type ConcreteTaskB 
        constexpr static char B[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'B'} ;
        using ConcreteB = TestConcreteTask<B>; 

        // Defining type ConcreteTaskC 
        constexpr static char C[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'C'} ;
        using ConcreteC = TestConcreteTask<C>; 

        // Defining type ConcreteTaskD 
        constexpr static char D[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'D'} ;
        using ConcreteD = TestConcreteTask<D>; 

        // Defining type ConcreteTaskE 
        constexpr static char E[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'E'} ;
        using ConcreteE = TestConcreteTask<E>; 

        // Defining type ConcreteTaskF 
        constexpr static char F[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'F'} ;
        using ConcreteNotInList = TestConcreteTask<F>; 

        // Defining a typelist.
        using LabelTypelist = MPL::mpl_typelist<ConcreteA,
                                                ConcreteB,
                                                ConcreteC,
                                                ConcreteD,
                                                ConcreteE >;

        // Defining a typelist.
        using SingleLabelTypelist = MPL::mpl_typelist<ConcreteA>;

        // Defining a typelist.
        using EmptyLabelTypelist = MPL::mpl_typelist<>;

        static constexpr auto correct_index_at_front_tests = 0;
        static constexpr auto correct_index_empty_typelist = -1;

    
        // ====================  LIFECYCLE     =======================================

        TaskLabelContainerFixture ();   // constructor

        ~TaskLabelContainerFixture ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskLabelContainerFixture  -----


}; // namespace ANANSI

#endif // ANANSI_TaskLabelContainerFixture_INC
