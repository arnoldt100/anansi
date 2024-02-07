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

        SimulationDecompositionParameters(const std::string flag_default_null_value,
                                          const std::string work_load_decomposition,
                                          const std::string processor_topology_lattice_type,
                                          const std::string processor_topology_spatial_decomposition,
                                          const std::string number_processor_compute_units_per_domain);

        SimulationDecompositionParameters (const SimulationDecompositionParameters & other);   // copy constructor

        SimulationDecompositionParameters (SimulationDecompositionParameters && other);   // copy-move constructor

        ~SimulationDecompositionParameters ();  // destructor

        // ====================  STATIC        =======================================

        // Error message for missing mandotory node tag.
        static std::string MessageMissingMandatoryNodeTag(const std::string node_tag);

        // -----------------------------------------------------
        // This section is for the workload decomposition type 
        // parameters - WorkLoadDecompositionType
        //
        // -----------------------------------------------------
        
        //! Returns the default value for the workload decomposition type.
        static std::string DefaultWorkLoadDecompositionType();

        //! \brief Returns a boolean that indicates if the node value is valid.
        static bool IsValidWorkLoadDecompositionTypeValues(const std::string node_value);

        //! \brief Returns a internal workload decomposition value for the given node_value.
        static std::string WorkLoadDecompositionTypeValues(const std::string node_value);

        // -----------------------------------------------------
        // This section is for the processor lattice type 
        // parameters - ProcessorTopologyLatticeType
        //
        // -----------------------------------------------------
        
        //! Returns the default value for the lattice type topology of the spatial decomposition.
        static std::string DefaultProcessorTopologyLatticeType();

        //! \brief Returns a boolean that indicates if the node value is valid.
        static  bool IsValidProcessorTopologyLatticeTypeValues(const std::string node_value);

        //! \brief Returns a internal processor lattice type value for the given node_value.
        static std::string ProcessorTopologyLatticeTypeValues(const std::string node_value);

        // To be moved to details.
        //! Returns the error message for invalid processor topology lattice type values.
        static std::string MessageInvalidProcessorTopologyLatticeTypeValues(const std::string invalid_value);
        


        // -----------------------------------------------------
        // This section is for the processor lattice type 
        // parameters - ProccesorTopologyLatticeSpatialDimensions
        //
        // -----------------------------------------------------
        //! Returns the default value for the dimensions of the latttoce topology of the spatial decomposition.
        static std::array<int,3> DefaultProcessorTopologyLatticeSpatiolDimensions();

        //! \brief Returns a boolean that indicates if the node value is valid.
        static bool IsValidProccesorTopologyLatticeSpatialDimensionsValues(const std::string node_value);

        //! \brief Returns a internal processor lattice type value for the given node_value.
        static  std::array<int,3> ProccesorTopologyLatticeSpatialDimensionsValues(const std::string node_value);

        //! Returns a boolean indicating if the key for processor lattice type is mandatory.
        static bool IsProccesorTopologyLatticeSpatialDimensionsMandatory();

        //! Returns a boolean indicating if the key for processor lattice type is mandatory.
        static std::string MessageInvalidProccesorTopologyLatticeSpatialDimensions(const std::string invalid_value);

        // -- More to do -- 
        // -- More to do -- 
        // -- More to do -- 

        //! Returns the default number of compute units per spatial domain.
        static std::string DefaultNumberProcessorComputeUnitsPerDomain();



        
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

        static constexpr char* ErrorMessageHeader_ = R"""(
# ----------------------
# Error Message
# ----------------------)""";

        static constexpr char* ErrorMessageFooter_ = R"""(# ----------------------)""";

        //! \brief A std::map where the keys are the valid simulation decomposition values, and the corresponding values
        //!  are the internal flags/values used within the program.
        static std::map<std::string,std::string> validWorkLoadDecompositionValues_;
        
        //! \brief A std::map where the keys are the valid processor lattice tyoe values, and the corresponding values
        //!  are the internal flags/values used within the program.
        static std::map<std::string,std::string> validProcessorTopologyLatticeTypeValues_;

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
        //! \details The array has the for [a,b,c] where 
        //! "a" is the dimension of the workload decomposition for the 0'th coordinate.
        //! "b" is the dimension of the workload decomposition for the first coordinate.
        //! "c" is the dimension of the workload decomposition for the second coordinate.
        //! For rectangular coordinates a, b and c are respectively the x,
        //! y and z dimensions spatial decomposition.
        std::array<int,3> processorTopologySpatialDecomposition_;

        //! \brief Stores the number of compute units per spatial decomposition.
        std::string numberProcessorComputeUnitsPerDomain_;


}; // -----  end of class SimulationDecompositionParameters  -----


}; // namespace ANANSI

#endif // ANANSI_SimulationDecompositionParameters_I
