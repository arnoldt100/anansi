#ifndef  ANANSI_MPICommunicatorInvokerUtility_INC
#define  ANANSI_MPICommunicatorInvokerUtility_INC

//! @file MPICommunicatorInvokerUtility.h
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

class MPICommunicatorInvokerUtility
{
    public:
        // ====================  LIFECYCLE     =======================================

        MPICommunicatorInvokerUtility ();   // constructor

        MPICommunicatorInvokerUtility (const MPICommunicatorInvokerUtility & other);   // copy constructor

        MPICommunicatorInvokerUtility (MPICommunicatorInvokerUtility && other);   // copy-move constructor

        ~MPICommunicatorInvokerUtility ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MPICommunicatorInvokerUtility& operator= ( const MPICommunicatorInvokerUtility &other ); // assignment operator

        MPICommunicatorInvokerUtility& operator= ( MPICommunicatorInvokerUtility && other ); // assignment-move operator

        // ====================  STATIC  METHODS =======================================

        template<typename INVK_t,typename RECV_t>
        static void addMPITasks(INVK_t & invoker, RECV_t & receiver)
        {
            return;
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MPICommunicatorInvokerUtility  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_MPICommunicatorInvokerUtility_INC  ----- 
