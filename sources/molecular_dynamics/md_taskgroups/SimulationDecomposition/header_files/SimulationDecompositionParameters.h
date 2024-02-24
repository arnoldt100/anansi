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
//! - The file names that contains the initial configuration of Atoms.
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
        //! \param [in] initial_configuration_filenames  Conatins the file names that contain the initial configuration of the atoms.
        explicit SimulationDecompositionParameters(const std::string flag_default_null_value,
                                          const std::string work_load_decomposition_type,
                                          const std::string processor_topology_lattice_type,
                                          const std::string processor_topology_spatial_decomposition,
                                          const std::string number_processor_compute_units_per_domain,
                                          const std::string initial_configuration_filenames,
                                          const std::string coordinate_system);

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

        // ====================  ACCESSORS     =======================================

        //! \brief The cloning function.
        SimulationDecompositionParameters * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! \brief The copy assignment operator.
        SimulationDecompositionParameters& operator= ( const SimulationDecompositionParameters &other ); // assignment operator

        //! \brief The move assignment operator.
        SimulationDecompositionParameters& operator= ( SimulationDecompositionParameters && other ); // assignment-move operator

        // ====================  STATIC        =======================================

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //============================= STATIC    ====================================

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

        //! \brief Stores the filenames of the initial atoms configuration.
        std::vector<std::string> initialConfigurationFilenames_;

        //! \brief Stores the filename for the coordinate system.
        std::string coordinateSystemFilename_;

}; // -----  end of class SimulationDecompositionParameters  -----


}; // namespace ANANSI

#endif // ANANSI_SimulationDecompositionParameters_I
