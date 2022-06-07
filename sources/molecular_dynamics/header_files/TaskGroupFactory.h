#ifndef  ANANSI_TaskGroupFactory_INC
#define  ANANSI_TaskGroupFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

#include "ClassInstanceLimiter.hpp"
#include "TaskGroup.h"
#include "Factory.hpp"

namespace ANANSI
{

constexpr auto MAX_TASKGROUPFACTORY_INSTANCES = 1;

// =====================================================================================
//        Class:  TaskGroupFactory
//  Description:  
//  =====================================================================================
class TaskGroupFactory final : private COUNTERCLASSES::ClassInstanceLimiter<TaskGroupFactory,MAX_TASKGROUPFACTORY_INSTANCES>
{
    public:
        // ====================  LIFECYCLE     =======================================

        TaskGroupFactory ();   // constructor

        TaskGroupFactory (const TaskGroupFactory & other)=delete;   // copy constructor

        TaskGroupFactory (TaskGroupFactory && other)=delete;   // copy-move constructor

        ~TaskGroupFactory ();  // destructor

        // ====================  ACCESSORS     =======================================
        std::unique_ptr<ANANSI::TaskGroup> buildWorldTaskGroup() const;


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        TaskGroupFactory& operator= ( const TaskGroupFactory &other )=delete ; // assignment operator

        TaskGroupFactory& operator= ( TaskGroupFactory && other )=delete; // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================
        MPL::Factory<ANANSI::TaskGroup,int> myFactory_;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskGroupFactory  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_TaskGroupFactory_INC  ----- */
