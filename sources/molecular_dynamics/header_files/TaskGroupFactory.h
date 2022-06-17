#ifndef  ANANSI_TaskGroupFactory_INC
#define  ANANSI_TaskGroupFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

#include "TaskGroupTraits.h"
#include "ClassInstanceLimiter.hpp"
#include "TaskGroup.h"
#include "DefaultTaskGroup.h"
#include "Factory.hpp"
#include "MPLAliases.hpp"
#include "RegisterObjectFactories.hpp"

namespace ANANSI
{
 
// Sets the maximum number of instances of the class TaskGroupFactory.  We
// specify 1 due to only requiring that we register the derived TaskGroups only
// once.
constexpr auto MAX_TASKGROUPFACTORY_INSTANCES = 1;

// Define an alias for typelist with the types of concrete TaskGroups to
// create.
using TaskGroupsTypeList = MPL::mpl_typelist<DefaultTaskGroup>;

// Define ans alias for the superclass type of the derived TaskGroups.
using TaskGroupsBaseClassType = TaskGroup;

// Define an alias for the TaskGroups concrete classes ID type.
using TaskGroupsIDType = int;

// Define an alias of the TaskGroup object factory type.
//
using TGObjectFactoryType = MPL::Factory<TaskGroupsBaseClassType,TaskGroupsIDType>;



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
        // ====================  STATIC METHODS ======================================

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================


}; // -----  end of class TaskGroupFactory  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_TaskGroupFactory_INC  ----- */
