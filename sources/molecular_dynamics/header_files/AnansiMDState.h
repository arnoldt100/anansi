#ifndef  AnansiMDState_INC
#define  AnansiMDState_INC

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

    class AnansiMDState
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            AnansiMDState ();   /* constructor      */

            AnansiMDState (const AnansiMDState & other);   /* copy constructor */

            AnansiMDState (AnansiMDState && other);   /* copy-move constructor */

            virtual ~AnansiMDState ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            AnansiMDState& operator=( const AnansiMDState &other ); /* assignment operator */

            AnansiMDState& operator=( AnansiMDState && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMDState  ----- */


}; /* namespace ANANSI */


#endif   /* ----- #ifndef AnansiMDState_INC  ----- */
