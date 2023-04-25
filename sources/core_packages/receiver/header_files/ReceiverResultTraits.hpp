#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! @file ReceiverResultTraits.hpp
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

namespace RECEIVER
{

// =====================================================================================
//        Class:  ReceiverResultTraits
//  Description:  
//  =====================================================================================
class ReceiverResultTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        ReceiverResultTraits ()   // constructor
        {
            return;
        }

        ReceiverResultTraits (const ReceiverResultTraits & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        ReceiverResultTraits (ReceiverResultTraits && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        ~ReceiverResultTraits () // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ReceiverResultTraits& operator= ( const ReceiverResultTraits &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        ReceiverResultTraits& operator= ( ReceiverResultTraits && other ) // assignment-move operator
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

}; // -----  end of class ReceiverResultTraits  -----


}; // namespace RECEIVER

#endif // __filepreprocessordefine__
