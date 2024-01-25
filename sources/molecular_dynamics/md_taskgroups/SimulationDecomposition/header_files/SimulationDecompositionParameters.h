#ifndef ANANSI_SimulationDecompositionParameters_INC
#define ANANSI_SimulationDecompositionParameters_INC
//! \file SimulationDecompositionParameters.h
//!
//! \brief Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"

namespace ANANSI
{

//! Stores the information for decomposing the simulation workload.
class SimulationDecompositionParameters
{
    public:
        // ====================  LIFECYCLE     =======================================

        SimulationDecompositionParameters ();   // constructor

        SimulationDecompositionParameters(const std::string work_load_decomposition,
                                          const std::string processor_topology_lattice_type,
                                          const std::string processor_topology_spatial_decomposition,
                                          const std::string number_processor_compute_units_per_domain);

        SimulationDecompositionParameters (const SimulationDecompositionParameters & other);   // copy constructor

        SimulationDecompositionParameters (SimulationDecompositionParameters && other);   // copy-move constructor

        ~SimulationDecompositionParameters ();  // destructor

        // ====================  ACCESSORS     =======================================
        SimulationDecompositionParameters * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        SimulationDecompositionParameters& operator= ( const SimulationDecompositionParameters &other ); // assignment operator

        SimulationDecompositionParameters& operator= ( SimulationDecompositionParameters && other ); // assignment-move operator


    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        // ====================  DATA MEMBERS  =======================================
        //! \brief Stores the type of workload decomposition.
        //!
        //! \detailed Only 1 valid accepted value - "domain-decomposition".
        //! The default value is "domain-decomposition".
        std::string workLoadDecomposition_;

        //! \brief Stores the lattice type for the spatial workload decomposition.
        //!
        //! \detailed Only 1 valid accepted value - "rectangular".
        std::string processorTopologyLatticeType_;

        //! \brief Stores the  spatial workload decomposition dimension.
        //!
        //! \detailed The string has the form af "a b c" where
        //! "a" is the dimension of the workload decomposition for the 0'th coordinate.
        //! "b" is the dimension of the workload decomposition for the first coordinate.
        //! "c" is the dimension of the workload decomposition for the second coordinate.
        //! For rectangular coordinates a, b and c are respectively the x,
        //! y and z dimenensions spatial decomposition.
        std::string processorTopologySpatialDecomposition_;


        //! \brief Stores the number of compute units per spatial decomposition.
        std::string numberProcessorComputeUnitsPerDomain_;

        // ====================  STATIC        =======================================
        static std::string DefaultWorkLoadDecomposition_();
        static std::string DefaultProcessorTopologyLatticeType_();
        static std::string DefaultProcessorTopologySpatialDecomposition_();
        static std::string DefaultNumberProcessorComputeUnitsPerDomain_();

}; // -----  end of class SimulationDecompositionParameters  -----


}; // namespace ANANSI

#endif // ANANSI_SimulationDecompositionParameters_INC
