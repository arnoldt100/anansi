#ifndef  ANANSI_InterProcessCommEnv_INC
#define  ANANSI_InterProcessCommEnv_INC

//! @file InterProcessCommEnv.h
//!
//! Base class for initializing the interprocess communication environment.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiTask.h"

namespace ANANSI
{

class InterProcessCommEnv : public AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  InterProcessCommEnv
        //      Method:  InterProcessCommEnv :: InterProcessCommEnv
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        InterProcessCommEnv ();   // constructor

        InterProcessCommEnv (const InterProcessCommEnv & other);   // copy constructor

        InterProcessCommEnv (InterProcessCommEnv && other);   // copy-move constructor

        virtual ~InterProcessCommEnv ()=0;  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        InterProcessCommEnv& operator= ( const InterProcessCommEnv &other ); // assignment operator

        InterProcessCommEnv& operator= ( InterProcessCommEnv && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        virtual void enable_();
        
        virtual void disenable_();

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class InterProcessCommEnv  -----


}; // namespace ANANSI

#endif // ANANSI_InterProcessCommEnv_INC
