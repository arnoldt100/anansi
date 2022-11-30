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
#include <string>

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

        explicit ConsoleMessageContainer ();   // constructor

        explicit ConsoleMessageContainer (std::string const & message,
                                          std::string const & sender);   // constructor

        explicit ConsoleMessageContainer (const ConsoleMessageContainer & other);   // copy constructor

        explicit ConsoleMessageContainer (ConsoleMessageContainer && other);   // copy-move constructor

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
        std::string message_;
        std::string sender_;

}; // -----  end of class ConsoleMessageContainer  -----


}; // namespace ANANSI

#endif // ANANSI_ConsoleMessageContainer_INC
