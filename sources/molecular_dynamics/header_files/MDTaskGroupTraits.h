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

#include "MPLAliases.hpp"
#include "DefaultTaskGroup.h"

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
        using ConcreteTypes = MPL::mpl_typelist<DefaultTaskGroup>;

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


}; // namespace __NAMESPACE__

#endif   /* ----- #ifndef ANANSI_MDTaskGroupTraits_INC  ----- */
