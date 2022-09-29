#ifndef  ANANSI_MDTaskGroupTraits_INC
#define  ANANSI_MDTaskGroupTraits_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

#include "Factory.hpp"
#include "MPLAliases.hpp"

namespace ANANSI
{

// =====================================================================================
//        Class:  MDTaskGroupTraits
//  Description:  
//  =====================================================================================
class MDTaskGroupTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        MDTaskGroupTraits ();   // constructor

        MDTaskGroupTraits (const MDTaskGroupTraits & other);   // copy constructor

        MDTaskGroupTraits (MDTaskGroupTraits && other);   // copy-move constructor

        ~MDTaskGroupTraits ();  // destructor

        // ====================  STATIC        =======================================

        // Define an alias for typelist with the types of concrete TaskGroups to
        // create.
        using ConcreteTypes = MPL::mpl_typelist<>;

        // Define an alias for the superclass type of the derived TaskGroups.
        using AbstractProduct = ANANSI::TaskGroup;

        // Define an alias for the TaskGroups concrete classes ID type.
        using IdentifierType = int;

        // Define an alias for the TaskGroups object factory type
        using FactoryType = MPL::Factory<AbstractProduct,
                                         IdentifierType>;

        // Sets the maximum number of instances of the class MDTaskGroupFactory.  We
        // specify 1 due to only requiring that we register the derived TaskGroups only
        // once.
        static const int MAX_TASKGROUPFACTORY_INSTANCES = 1;

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDTaskGroupTraits& operator= ( const MDTaskGroupTraits &other ); // assignment operator

        MDTaskGroupTraits& operator= ( MDTaskGroupTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MDTaskGroupTraits  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_MDTaskGroupTraits_INC  ----- */
