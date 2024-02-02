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

        //! \brief A std::map where the keys are the valid simulation decomposition values, and the corresponding values
        //!  are the internal flags/values used within the program.
        static std::map<std::string,std::string> validWorkLoadDecompositionValues;

        //! Returns the default value for the workload decomposition type.
        static std::string DefaultWorkLoadDecomposition();

        //! Returns a boolean indicating if the key for workload decompostion is mandatory.
        static bool WorkLoadDecompositionKeyIsMandatory();

        //! Returns the default value for the lattice type topology of the spatial decomposition.
        static std::string DefaultProcessorTopologyLatticeType();

        //! Returns the default value for the dimensions of the latttoce topology of the spatial decomposition.
        static std::string DefaultProcessorTopologySpatialDecomposition();

        //! Returns the default number of compute units per spatial domain.
        static std::string DefaultNumberProcessorComputeUnitsPerDomain();

        //! Returns the error message for missing workload decomposition tag.
        static std::string ErrorMessageMissingWorkloadDecompositionNodeTag();

        //! Returns the error message for missing workload decomposition value.
        static std::string ErrorMessageInvalidWorkloadDecompositionNodeValue(const std::string invalid_value);
        
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
        //! y and z dimensions spatial decomposition.
        std::string processorTopologySpatialDecomposition_;

        //! \brief Stores the number of compute units per spatial decomposition.
        std::string numberProcessorComputeUnitsPerDomain_;


}; // -----  end of class SimulationDecompositionParameters  -----


}; // namespace ANANSI

#endif // ANANSI_SimulationDecompositionParameters_INC
