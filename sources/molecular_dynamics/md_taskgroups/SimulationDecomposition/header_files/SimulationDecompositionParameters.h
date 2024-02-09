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
#include <map>
#include <array>
#include <vector>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"

namespace ANANSI
{

//! \brief Stores the simulation pararmeters for decomposing the simulation workload.
//!
//! \details This class stores the following information:
//! - The type of simulation decomposition 
//!   The program currently only supports spatial domain decomposition. 
//! - The type of lattice topology for the simulation decomposition
//!   The program currently only supports rectangular lattice topology.
//! - The dimensions of the lattice topology 
//! - The number of compute units per spatial domain
class SimulationDecompositionParameters
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        //! 
        //! \details This constructor doesn't initialize its members to usable values.
        SimulationDecompositionParameters ();

        //! \brief Constructs class SimulationDecompositionParameters with std::string parameters.
        //! \details This constructor indirectly throws exceptions.
        //! \param [in] flag_default_null_value A string to indicate if a simulation parameter is assigned a default value.
        //! \param [in] work_load_decomposition_type Contains the parameters for type of workload decomposition.
        //! \param [in] processor_topology_lattice_type Contains the parameters for the type of processor latticae topology.
        //! \param [in] processor_topology_spatial_decomposition Contains the parameters for the dimensions of the processor latticae topology
        //! \param [in] number_processor_compute_units_per_domain Conatins the number of compute units per spatial domain.
        explicit SimulationDecompositionParameters(const std::string flag_default_null_value,
                                          const std::string work_load_decomposition_type,
                                          const std::string processor_topology_lattice_type,
                                          const std::string processor_topology_spatial_decomposition,
                                          const std::string number_processor_compute_units_per_domain);

        //! \brief The copy constructor.
        SimulationDecompositionParameters (const SimulationDecompositionParameters & other);   // copy constructor

        //! \brief The move constructor.
        SimulationDecompositionParameters (SimulationDecompositionParameters && other);   // copy-move constructor

        //! \brief The destructor.
        ~SimulationDecompositionParameters ();  // destructor

        // ====================  STATIC        =======================================

        // -----------------------------------------------------
        // This section is for the processor lattice type 
        // parameters - ProccesorTopologyLatticeSpatialDimensions
        //
        // -----------------------------------------------------
        //! \brief Returns a boolean that indicates if the node value is valid.
        static bool IsValidProccesorTopologyLatticeSpatialDimensionsValues(const std::string node_value);

        //! \brief Returns a internal processor lattice type value for the given node_value.
        static  std::array<int,3> ProccesorTopologyLatticeSpatialDimensionsValues(const std::string node_value);

        // -- More to do -- 
        // -- More to do -- 
        // -- More to do -- 

        //! Returns the default number of compute units per spatial domain.
        int DefaultProcessorTopologyNumberComputeUnitsPerSpatialDomain();

        //! \brief Returns a boolean indicating if the key for processor number
        //!        compute units per spatial domain is mandatory.
        static bool IsProcesorTopologyNumberComputeUnitsPerSpatialDomainMandatory();

        static bool IsValidProcessorTopologyNumberComputeUnitsPerSpatialDomainValues(const std::string node_value);
        
        static int ProcessorTopologyNumberComputeUnitsPerSpatialDomainValues(const std::string node_value);

        // ====================  ACCESSORS     =======================================
        SimulationDecompositionParameters * clone () const;


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        SimulationDecompositionParameters& operator= ( const SimulationDecompositionParameters &other ); // assignment operator

        SimulationDecompositionParameters& operator= ( SimulationDecompositionParameters && other ); // assignment-move operator

        // ====================  STATIC        =======================================
        static std::vector<std::string> validWorkLoadDecompositionValues();

        static std::vector<std::string> validProcessorTopologyLatticeTypeValues();


    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //============================= STATIC    ====================================

        //! \todo Move oustide of class.
        //! \brief A std::map where the keys are the valid simulation decomposition values, and the corresponding values
        //!  are the internal flags/values used within the program.
        static std::map<std::string,std::string> validWorkLoadDecompositionValues_;
        
        //! \brief A std::map where the keys are the valid processor lattice tyoe values, and the corresponding values
        //!  are the internal flags/values used within the program.
        static std::map<std::string,std::string> validProcessorTopologyLatticeTypeValues_;

        // ====================  DATA MEMBERS  =======================================
        //! \brief Stores the type of workload decomposition.
        //!
        //! \details Only 1 valid accepted value - "domain-decomposition".
        //! The default value is "domain-decomposition".
        std::string workLoadDecomposition_;

        //! \brief Stores the lattice type for the spatial workload decomposition.
        //!
        //! \details Only 1 valid accepted value - "rectangular".
        std::string processorTopologyLatticeType_;

        //! \brief Stores the  spatial workload decomposition dimension.
        //!
        //! \details The array has the for [a,b,c] where 
        //! "a" is the dimension of the workload decomposition for the 0'th coordinate.
        //! "b" is the dimension of the workload decomposition for the first coordinate.
        //! "c" is the dimension of the workload decomposition for the second coordinate.
        //! For rectangular coordinates a, b and c are respectively the x,
        //! y and z dimensions spatial decomposition.
        std::array<int,3> processorTopologySpatialDecomposition_;

        //! \brief Stores the number of compute units per spatial decomposition.
        int numberProcessorComputeUnitsPerDomain_;


}; // -----  end of class SimulationDecompositionParameters  -----


}; // namespace ANANSI

#endif // ANANSI_SimulationDecompositionParameters_I
