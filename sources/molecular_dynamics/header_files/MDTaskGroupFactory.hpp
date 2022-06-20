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
#include "functional"

namespace ANANSI
{
 

// =====================================================================================
//        Class:  MDTaskGroupFactory
//  Description:  
//  =====================================================================================
template<class Traits=MDTaskGroupTraits>
class MDTaskGroupFactory final : private COUNTERCLASSES::ClassInstanceLimiter<MDTaskGroupFactory<Traits>,Traits::MAX_TASKGROUPFACTORY_INSTANCES>
{
    private:
        using ConcreteProductTypeList = MDTaskGroupTraits::ConcreteTypes;
        using ObjectFactoryType = MDTaskGroupTraits::FactoryType;

    public:
        
        // ====================  LIFECYCLE     =======================================

        MDTaskGroupFactory ()   // constructor
        {
            this->registerProducts_<ConcreteProductTypeList>();
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
        ObjectFactoryType objectFactory_;

        template<typename TypeList=ConcreteProductTypeList>
        void registerProducts_()
        {
            
            // Verify that the typelist size must be greater than 0. If not, 
            // the return with no products registered. 
            constexpr auto typelist_size = MPL::mpl_size<TypeList>::value-1;

            if constexpr (typelist_size >= 0)
            {
                // N_initial is the beginning index of the typelist
                // N_final is the ending index of the typelist.
                // N is the inde of the current type in the typelist.
                // The typelist use a 0 based indexing system.
                constexpr auto N_initial=0;
                constexpr auto N = 0;
                constexpr auto N_final = MPL::mpl_size<TypeList>::value-1;

                // Get the concrete product type to register.
                using ConcreteProductType = MPL::mpl_at_c<TypeList,N>;

                // Register the concrete product.
                 this->objectFactory_.registerFactory(N,&ConcreteProductType::create);

                // Attempt to register the next concrete product.
                constexpr auto N_next = N + 1;
                this->registerNextProduct_<TypeList,N_initial,N_final,N_next>();
            }
            return;
        }

        template<typename TypeList,int N_initial, int N_final, int N >
        void registerNextProduct_()
        {
            if constexpr ( (N_initial <= N) && (N <= N_final )  )
            {
                // Get the concrete product type to register.
                using ConcreteProductType = MPL::mpl_at_c<TypeList,N>;

                // Register the N'th concrete product.
                this->objectFactory_.registerFactory(N,&ConcreteProductType::create);

                // Attempt to register the next concrete product.
                constexpr auto N_next = N + 1;
                this->registerNextProduct_<TypeList,N_initial,N_final,N_next>();
            }
            return;
        }

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
