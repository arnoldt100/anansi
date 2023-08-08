#ifndef ANANSI_ControlFileNodeKeyNotFound_INC
#define ANANSI_ControlFileNodeKeyNotFound_INC

//! \file ControlFileNodeKeyNotFound.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <exception>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

//! \exception Thrown to indicate a node key is not found 
//!             to exist in MasterControlFileNodeKeys.
class ControlFileNodeKeyNotFound : public std::exception
{
  public: 
        // ====================  LIFECYCLE     =======================================

        ControlFileNodeKeyNotFound ();   // constructor

        ControlFileNodeKeyNotFound (const std::string error_message);   // constructor

        ControlFileNodeKeyNotFound (const ControlFileNodeKeyNotFound & other);   // copy constructor

        ControlFileNodeKeyNotFound (ControlFileNodeKeyNotFound && other);   // copy-move constructor

        virtual ~ControlFileNodeKeyNotFound ();  // destructor

        // ====================  ACCESSORS     =======================================
        const char* what();

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFileNodeKeyNotFound& operator= ( const ControlFileNodeKeyNotFound &other ); // assignment operator

        ControlFileNodeKeyNotFound& operator= ( ControlFileNodeKeyNotFound && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::string errorMessage_;
}; // End of class  ControlFileNodeKeyNotFound


}; // namespace ANANSI

#endif // ANANSI_ControlFileNodeKeyNotFound_INC
