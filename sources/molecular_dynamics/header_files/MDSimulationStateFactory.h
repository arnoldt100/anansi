#ifndef ANANSI_MDSimulationStateFactory_INC
#define ANANSI_MDSimulationStateFactory_INC

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

     // =====================================================================================
     //        Class:  MDSimulationStateFactory
     //  Description:  
     //  =====================================================================================
    class MDSimulationStateFactory
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  MDSimulationStateFactory
            //      Method:  MDSimulationStateFactory :: MDSimulationStateFactory
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            MDSimulationStateFactory ();   // constructor

            MDSimulationStateFactory (const MDSimulationStateFactory & other);   // copy constructor

            MDSimulationStateFactory (MDSimulationStateFactory && other);   // copy-move constructor

            ~MDSimulationStateFactory ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            MDSimulationStateFactory& operator= ( const MDSimulationStateFactory &other ); // assignment operator

            MDSimulationStateFactory& operator= ( MDSimulationStateFactory && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class MDSimulationStateFactory  -----


}; // namespace ANANSI

#endif // ANANSI_MDSimulationStateFactory_INC
