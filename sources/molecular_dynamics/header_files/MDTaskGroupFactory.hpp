#ifndef  ANANSI_MDTaskGroupFactory_INC
#define  ANANSI_MDTaskGroupFactory_INC

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
 

// =====================================================================================
//        Class:  MDTaskGroupFactory
//  Description:  
//  =====================================================================================
template<class Traits=MDTaskGroupTraits>
class MDTaskGroupFactory final : private COUNTERCLASSES::ClassInstanceLimiter<MDTaskGroupFactory<Traits>,Traits::MAX_TASKGROUPFACTORY_INSTANCES>
{
    public:
        // ====================  LIFECYCLE     =======================================

        MDTaskGroupFactory ()   // constructor
        {
            return;
        }

        MDTaskGroupFactory (const MDTaskGroupFactory & other)=delete;   // copy constructor

        MDTaskGroupFactory (MDTaskGroupFactory && other)=delete;   // copy-move constructor

        ~MDTaskGroupFactory ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        std::unique_ptr<typename Traits::AbstractProduct> buildWorldTaskGroup() const
        {
            

            std::unique_ptr<typename Traits::AbstractProduct> task_group = std::move(std::make_unique<DefaultTaskGroup>() );
            return task_group;
        }


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDTaskGroupFactory& operator= ( const MDTaskGroupFactory &other )=delete ; // assignment operator

        MDTaskGroupFactory& operator= ( MDTaskGroupFactory && other )=delete; // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  STATIC METHODS ======================================
        
        // ====================  MUTATORS      =======================================

        void registerObjectFactories_()
        {
            return;
        }

        // ====================  DATA MEMBERS  =======================================


}; // -----  end of class MDTaskGroupFactory  -----


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

#endif   /* ----- #ifndef ANANSI_MDTaskGroupFactory_INC  ----- */
