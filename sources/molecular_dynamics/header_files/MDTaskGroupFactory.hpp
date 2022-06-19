#ifndef  ANANSI_MDTaskGroupFactory_INC
#define  ANANSI_MDTaskGroupFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <typeinfo>
#include <iostream>
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
#include "ForLoop.hpp"

namespace ANANSI
{
 
template<int I>
class RegisterTaskGroupObject
{
    private:
        using ConcreteProductType = MPL::mpl_at_c<typename MDTaskGroupTraits::ConcreteTypes,I>;

    public:
        void operator()() const
        {
            std::cout << "Registerd product " << I << " : " << typeid(ConcreteProductType).name() << std::endl;
            return;
        }       
};

// =====================================================================================
//        Class:  MDTaskGroupFactory
//  Description:  
//  =====================================================================================
template<class Traits=MDTaskGroupTraits>
class MDTaskGroupFactory final : private COUNTERCLASSES::ClassInstanceLimiter<MDTaskGroupFactory<Traits>,Traits::MAX_TASKGROUPFACTORY_INSTANCES>
{
    private:
        using ConcreteProductTypeList = MDTaskGroupTraits::ConcreteTypes;

    public:
        
        // ====================  LIFECYCLE     =======================================

        MDTaskGroupFactory ()   // constructor
        {
            constexpr auto i_start=0;
            constexpr auto i_end = MPL::mpl_size<ConcreteProductTypeList>::value-1;
            MPL::ForLoopOverTypeList<i_start,i_end,ConcreteProductTypeList,RegisterTaskGroupObject> concrete_products;
            concrete_products();

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
        MPL::Factory<typename Traits::AbstractProduct,
                     typename Traits::IdentifierType> _objectFactory;

        // ====================  STATIC METHODS ======================================

        // ====================  MUTATORS      =======================================


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
