#ifndef ANANSI_ConsoleMessageContainer_INC
#define ANANSI_ConsoleMessageContainer_INC
//! @file ConsoleMessageContainer.h
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
//        Class:  ConsoleMessageContainer
//  Description:  
//  =====================================================================================
class ConsoleMessageContainer final
{
    public:
        // ====================  LIFECYCLE     =======================================

        ConsoleMessageContainer ();   // constructor

        ConsoleMessageContainer (const ConsoleMessageContainer & other);   // copy constructor

        ConsoleMessageContainer (ConsoleMessageContainer && other);   // copy-move constructor

        ~ConsoleMessageContainer ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ConsoleMessageContainer& operator= ( const ConsoleMessageContainer &other ); // assignment operator

        ConsoleMessageContainer& operator= ( ConsoleMessageContainer && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ConsoleMessageContainer  -----


}; // namespace ANANSI

#endif // ANANSI_ConsoleMessageContainer_INC
