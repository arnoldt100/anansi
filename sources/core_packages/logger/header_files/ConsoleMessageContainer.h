#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
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
class ConsoleMessageContainer
{
    public:
        // ====================  LIFECYCLE     =======================================

        ConsoleMessageContainer ();   // constructor

        ConsoleMessageContainer (const ConsoleMessageContainer & other);   // copy constructor

        ConsoleMessageContainer (ConsoleMessageContainer && other);   // copy-move constructor

        virtual ~ConsoleMessageContainer ();  // destructor

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

#endif // __filepreprocessordefine__
