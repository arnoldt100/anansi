#ifndef  MOUSEION_Factory_INC
#define  MOUSEION_Factory_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>
#include <utility>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "DefaultFactoryError.hpp"

namespace MPL
{

// =====================================================================================
//        Class:  Factory
//  Description:  
//  =====================================================================================
template <class AbstractProduct,
          typename IdentifierType,
          typename ProductCreator=AbstractProduct* (*)(),      
          template<typename,class> class FactoryErrorPolicy = DefaultFactoryError>
class Factory 
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  Factory
        //      Method:  Factory :: Factory
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        Factory() :
            factoryErrorPolicy_uptr_(std::make_unique<FactoryErrorPolicy<IdentifierType, AbstractProduct>>())
        {
            return;
        }   // constructor

        Factory (const Factory & other) = delete;   // copy constructor

        Factory (Factory && other) = delete; // copy-move constructor

        virtual ~Factory () // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================
        bool registerFactory(const IdentifierType & id, ProductCreator creator)
        {
            auto const element_registered = associations_.insert(typename AssocMap::value_type(id,creator)).second;
            return element_registered;
        }

        bool unregisterFactory(const IdentifierType & id)
        {
            auto element_removed = false;
            auto const nm_elements_removed = associations_.erase(id);
            if (nm_elements_removed == 1)
            {
                element_removed = true;
            }
            return element_removed;
        }

        AbstractProduct* createObject (IdentifierType const & id)
        {
            typename AssocMap::const_iterator it = associations_.find(id);
            if ( it != associations_.end())
            {
                return it->second();
            }
            return (*factoryErrorPolicy_uptr_).OnUnknownType(id);
        }		// -----  end of method Factory<T>::createObject  ----- 


        // ====================  OPERATORS     =======================================

        Factory& operator= ( const Factory &other ) = delete;

        Factory& operator= ( Factory && other ) = delete; // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================
        using AssocMap = std::map<IdentifierType,ProductCreator>;
        AssocMap associations_;
        std::unique_ptr<FactoryErrorPolicy<IdentifierType,AbstractProduct>> factoryErrorPolicy_uptr_; 

        // ====================  DATA MEMBERS  =======================================


}; // -----  end of class Factory  -----


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_Factory_INC  ----- 
