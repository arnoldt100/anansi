#ifndef ANANSI_MDInitSimEnv
#define ANANSI_MDInitSimEnv

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <functional>
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

#include "InitSimEnv.h"

namespace ANANSI

{
    //--------------------------------------------------------//
    //--------------------- Forwdard Declarations ------------//
    //--------------------------------------------------------//
    class AnansiMolecularDynamics;

     // =====================================================================================
     //        Class:  MDInitSimEnv
     //  Description:  
     //  =====================================================================================
    class MDInitSimEnv : public InitSimEnv
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  MDInitSimEnv
            //      Method:  MDInitSimEnv :: MDInitSimEnv
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            MDInitSimEnv ();   // constructor

            MDInitSimEnv (MDInitSimEnv const & other);   // copy constructor

            MDInitSimEnv (MDInitSimEnv && other);   // copy-move constructor

            ~MDInitSimEnv ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================
            static void genericAddCommand(std::shared_ptr<ANANSI::SimulationState> & cmd)
            {
                return;
            } 
            // ====================  OPERATORS     =======================================

            MDInitSimEnv& operator= ( MDInitSimEnv const & other ); // assignment operator

            MDInitSimEnv& operator= ( MDInitSimEnv && other ); // assignment-move operator

            // ===================  DATA MEMBERS  =======================================
            std::map<std::string, std::function<void(AnansiMolecularDynamics&)>> commands_;

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

            // ====================  ACCESSORS     =======================================
            void Execute_(Simulation * const a_simulation) const final;

            void Execute_() const final;

            void AddCommand_() const final;

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class MDInitSimEnv  -----


}; // namespace ANANSI

#endif // ANANSI_MDInitSimEnv
