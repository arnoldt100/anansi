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
#include "MasterControlFileNodeKeys.h"
#include "ControlFileName.h"

namespace ANANSI
{

class ControlFilePickle
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlFilePickle ();   // constructor

        ControlFilePickle (const ControlFilePickle & other);   // copy constructor

        ControlFilePickle (ControlFilePickle && other);   // copy-move constructor

        ~ControlFilePickle ();  // destructor

        // ====================  STATIC        =======================================
        template<typename InternalRepresentation_t,
                 typename PickleType_t,
                 typename DefaultValue> 
        static InternalRepresentation_t unpickle(const MasterControlFileNodeKeys & master_node_keys,
                                                 const PickleType_t & pickled_object)
        {
            InternalRepresentation_t ret_value;

            return ret_value;
        }

        static void pickle();

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
