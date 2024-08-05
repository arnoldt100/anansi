#ifndef ANANSI_FixtureBroadcastVectorStringCache_INC
#define ANANSI_FixtureBroadcastVectorStringCache_INC
//! \file FixtureBroadcastVectorStringCache.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "VectorStringCache.h"

class FixtureBroadcastVectorStringCache
{
    public:
        // ====================  LIFECYCLE     =======================================

        FixtureBroadcastVectorStringCache ();   // constructor

        FixtureBroadcastVectorStringCache (const FixtureBroadcastVectorStringCache & other);   // copy constructor

        FixtureBroadcastVectorStringCache (FixtureBroadcastVectorStringCache && other);   // copy-move constructor

        ~FixtureBroadcastVectorStringCache ();  // destructor

        // ====================  ACCESSORS     ======================================= v
        FixtureBroadcastVectorStringCache * clone () const;

        // ====================  MUTATORS      =======================================
        void setup();

        void teardown();

        // ====================  OPERATORS     =======================================

        FixtureBroadcastVectorStringCache& operator= ( const FixtureBroadcastVectorStringCache &other ); // assignment operator

        FixtureBroadcastVectorStringCache& operator= ( FixtureBroadcastVectorStringCache && other ); // assignment-move operator

        STRING_UTILITIES::VectorStringCache experimentalVecStringCache1;
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class FixtureBroadcastVectorStringCache  -----


#endif // ANANSI_FixtureBroadcastVectorStringCache_INC
