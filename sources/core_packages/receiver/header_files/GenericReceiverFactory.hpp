#ifndef  ANANSI_GenericReceiverFactory_INC
#define  ANANSI_GenericReceiverFactory_INC

//! @file GenericReceiverFactory.hpp
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

// =====================================================================================
//        Class:  GenericReceiverFactory
//  Description:  
//  =====================================================================================
class GenericReceiverFactory
{
    public:
        // ====================  LIFECYCLE     =======================================

        GenericReceiverFactory ()   // constructor
        {
            return;
        }

        GenericReceiverFactory (const GenericReceiverFactory & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        GenericReceiverFactory (GenericReceiverFactory && other);   // copy-move constructor

        ~GenericReceiverFactory ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GenericReceiverFactory& operator= ( const GenericReceiverFactory &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        GenericReceiverFactory& operator= ( GenericReceiverFactory && other ) // assignment-move operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class GenericReceiverFactory  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_GenericReceiverFactory_INC  ----- 
