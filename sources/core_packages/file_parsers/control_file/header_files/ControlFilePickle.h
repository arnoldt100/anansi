#ifndef ANANSI_ControlFilePickle_INC
#define ANANSI_ControlFilePickle_INC
//! \file ControlFilePickle.h
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

class ControlFilePickle
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlFilePickle ();   // constructor

        ControlFilePickle (const ControlFilePickle & other);   // copy constructor

        ControlFilePickle (ControlFilePickle && other);   // copy-move constructor

        virtual ~ControlFilePickle ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFilePickle& operator= ( const ControlFilePickle &other ); // assignment operator

        ControlFilePickle& operator= ( ControlFilePickle && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ControlFilePickle  -----


}; // namespace ANANSI

#endif // ANANSI_ControlFilePickle_INC
