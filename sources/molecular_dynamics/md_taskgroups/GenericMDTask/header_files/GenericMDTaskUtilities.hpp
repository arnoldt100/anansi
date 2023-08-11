#ifndef ANANSI_GenericMDTaskUtilities_INC
#define ANANSI_GenericMDTaskUtilities_INC
//! \file GenericMDTaskUtilities.hpp

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

template <class RootTaskClass,
          class Receiver>
class GenericMDTaskUtilities
{
    public:
        // ====================  LIFECYCLE     =======================================

        GenericMDTaskUtilities ()   // constructor
        {
            return;
        }

        GenericMDTaskUtilities (const GenericMDTaskUtilities & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        GenericMDTaskUtilities (GenericMDTaskUtilities && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method GenericMDTaskUtilities::GenericMDTaskUtilities  -----

        ~GenericMDTaskUtilities () // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GenericMDTaskUtilities& operator= ( const GenericMDTaskUtilities &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        GenericMDTaskUtilities& operator= ( GenericMDTaskUtilities && other ) // assignment-move operator
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

}; // -----  end of class GenericMDTaskUtilities  -----


}; // namespace ANANSI

#endif // ANANSI_GenericMDTaskUtilities_INC
