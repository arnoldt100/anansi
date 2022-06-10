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

#include "ClassInstanceLimiter.hpp"
#include "TaskGroup.h"
#include "DefaultTaskGroup.h"
#include "Factory.hpp"
#include "MPLAliases.hpp"
#include "RegisterObjectFactories.hpp"

namespace ANANSI
{
 
constexpr auto MAX_TASKGROUPFACTORY_INSTANCES = 1;

// Define an alias of the TaskGroup object factory type.
template <typename V,typename W>
using TGObjectFactoryType = MPL::Factory<V,W>;

// Define an alias for the TaskGroups concrete classes ID type.
using TaskGroupIDType = int;

// Define a typelist with the types of concrete TaskGroups to create.
using TaskGroups_TList = MPL::mpl_typelist<DefaultTaskGroup>;

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

        TGObjectFactoryType<TaskGroup,TaskGroupIDType> myFactory_;


}; // -----  end of class TaskGroupFactory  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_TaskGroupFactory_INC  ----- */
