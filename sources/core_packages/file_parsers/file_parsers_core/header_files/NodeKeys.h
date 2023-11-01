#ifndef ANANSI_NodeKeys_INC
#define ANANSI_NodeKeys_INC
//! \file NodeKeys.h
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

class NodeKeys
{
    public:
        // ====================  LIFECYCLE     =======================================

        NodeKeys ();   // constructor

        NodeKeys (const NodeKeys & other);   // copy constructor

        NodeKeys (NodeKeys && other);   // copy-move constructor

        ~NodeKeys ();  // destructor

        // ====================  ACCESSORS     =======================================
        NodeKeys * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        NodeKeys& operator= ( const NodeKeys &other ); // assignment operator

        NodeKeys& operator= ( NodeKeys && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class NodeKeys  -----


}; // namespace ANANSI

#endif // ANANSI_NodeKeys_INC
