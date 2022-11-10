#ifndef  ANANSI_AnansiTaskUtilities_INC
#define  ANANSI_AnansiTaskUtilities_INC

//! @file AnansiTaskUtilities.hpp
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

template <typename AbstractProductsTypeList, typename ConcreteProductsTypeLists>
class AnansiTaskUtilities
{
    public:
        // ====================  LIFECYCLE     =======================================

        AnansiTaskUtilities ()   // constructor
        {
            return;
        }

        AnansiTaskUtilities (const AnansiTaskUtilities & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        AnansiTaskUtilities (AnansiTaskUtilities && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method __classname__::__classname__  -----

        ~AnansiTaskUtilities ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        AnansiTaskUtilities& operator= ( const AnansiTaskUtilities &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        AnansiTaskUtilities& operator= ( AnansiTaskUtilities && other ) // assignment-move operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment-move operator


    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class AnansiTaskUtilities  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_AnansiTaskUtilities_INC  ----- 
