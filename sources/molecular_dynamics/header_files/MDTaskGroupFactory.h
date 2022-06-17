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

#include "MDTaskGroupTraits.h"
#include "ClassInstanceLimiter.hpp"
#include "TaskGroup.h"
#include "DefaultTaskGroup.h"
#include "Factory.hpp"
#include "MPLAliases.hpp"
#include "RegisterObjectFactories.hpp"

namespace ANANSI
{
 
// Sets the maximum number of instances of the class MDTaskGroupFactory.  We
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
//        Class:  MDTaskGroupFactory
//  Description:  
//  =====================================================================================
class MDTaskGroupFactory final : private COUNTERCLASSES::ClassInstanceLimiter<MDTaskGroupFactory,MAX_TASKGROUPFACTORY_INSTANCES>
{
    public:
        // ====================  LIFECYCLE     =======================================

        MDTaskGroupFactory ();   // constructor

        MDTaskGroupFactory (const MDTaskGroupFactory & other)=delete;   // copy constructor

        MDTaskGroupFactory (MDTaskGroupFactory && other)=delete;   // copy-move constructor

        ~MDTaskGroupFactory ();  // destructor

        // ====================  ACCESSORS     =======================================
        std::unique_ptr<ANANSI::TaskGroup> buildWorldTaskGroup() const;


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDTaskGroupFactory& operator= ( const MDTaskGroupFactory &other )=delete ; // assignment operator

        MDTaskGroupFactory& operator= ( MDTaskGroupFactory && other )=delete; // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  STATIC METHODS ======================================

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================


}; // -----  end of class MDTaskGroupFactory  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_TaskGroupFactory_INC  ----- */
