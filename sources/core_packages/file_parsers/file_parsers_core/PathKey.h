#ifndef ANANSI_PathKey_INC
#define ANANSI_PathKey_INC
//! \file PathKey.h
//!
//! \brief Brief description
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

class PathKey
{
    public:
        // ====================  LIFECYCLE     =======================================

        PathKey ();   // constructor

        PathKey (const PathKey & other);   // copy constructor

        PathKey (PathKey && other);   // copy-move constructor

        virtual ~PathKey ();  // destructor

        // ====================  ACCESSORS     =======================================
        PathKey * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        PathKey& operator= ( const PathKey &other ); // assignment operator

        PathKey& operator= ( PathKey && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class PathKey  -----


}; // namespace ANANSI

#endif // ANANSI_PathKey_INC
