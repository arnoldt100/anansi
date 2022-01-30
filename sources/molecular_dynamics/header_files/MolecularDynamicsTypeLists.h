#ifndef  ANANSI_MolecularDynamicsTypeLists_INC
#define  ANANSI_MolecularDynamicsTypeLists_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"
#include "AnansiMolecularDynamics.h" 

namespace ANANSI
{

     // =====================================================================================
     //        Class:  MolecularDynamicsTypeLists
     //  Description:  
     // =====================================================================================
    class MolecularDynamicsTypeLists
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  MolecularDynamicsTypeLists
            //      Method:  MolecularDynamicsTypeLists :: MolecularDynamicsTypeLists
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            MolecularDynamicsTypeLists ();   // constructor

            MolecularDynamicsTypeLists (const MolecularDynamicsTypeLists & other);   // copy constructor

            MolecularDynamicsTypeLists (MolecularDynamicsTypeLists && other);   // copy-move constructor

            virtual ~MolecularDynamicsTypeLists ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            MolecularDynamicsTypeLists& operator= ( const MolecularDynamicsTypeLists &other ); // assignment operator

            MolecularDynamicsTypeLists& operator= ( MolecularDynamicsTypeLists && other ); // assignment-move operator

            // ====================  ALIASES       =======================================
            using TypeList = MPL::mpl_typelist<AnansiMolecularDynamics>;

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class MolecularDynamicsTypeLists  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_MolecularDynamicsTypeLists_INC  ----- 
