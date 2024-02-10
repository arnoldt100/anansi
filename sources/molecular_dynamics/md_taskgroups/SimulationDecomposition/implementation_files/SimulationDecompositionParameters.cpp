//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/format.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationDecompositionParameters.h"
#include "GenericErrorClass.hpp"
#include "WorkloadDecompositionTypeHelpers.h"
#include "ProcessorTopologyLatticeTypeHelpers.h"
#include "ProccesorTopologyLatticeSpatialDimensionsHelpers.h"
#include "ProcessorTopologyNumberComputeUnitsPerSpatialDomainHelpers.h";
#include "count_words_in_string.h"
#include "verify_N_integers_in_string.hpp"
#include "convert_string_to_int_array.hpp"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

SimulationDecompositionParameters::SimulationDecompositionParameters() :
    workLoadDecomposition_{""},
    processorTopologyLatticeType_{""},
    processorTopologySpatialDecomposition_{1,1,1},
    numberProcessorComputeUnitsPerDomain_{1}
{
    this->workLoadDecomposition_ = ANANSI::SDPConstructorHelpers::default_workload_decomposition_type();
    this->processorTopologyLatticeType_ = ANANSI::SDPConstructorHelpers::default_processor_topology_lattice_type();
    this->processorTopologySpatialDecomposition_ = ANANSI::SDPConstructorHelpers::default_processor_topology_lattice_spatial_dimensions();
    this->numberProcessorComputeUnitsPerDomain_ = ANANSI::SDPConstructorHelpers::default_processor_topology_number_compute_units_per_spatial_domain();
    return;
}

SimulationDecompositionParameters::SimulationDecompositionParameters(const std::string flag_default_null_value,
                                          const std::string work_load_decomposition_type,
                                          const std::string processor_topology_lattice,
                                          const std::string processor_topology_spatial_decomposition,
                                          const std::string number_processor_compute_units_per_domain)
{
    this->workLoadDecomposition_ =
        ANANSI::SDPConstructorHelpers::workload_decomposition_type(work_load_decomposition_type,flag_default_null_value);

    this->processorTopologyLatticeType_ =
        ANANSI::SDPConstructorHelpers::parse_processor_topology_lattice_type(processor_topology_lattice,flag_default_null_value);

    this->processorTopologySpatialDecomposition_ =
        ANANSI::SDPConstructorHelpers::parse_proccesor_topology_lattice_spatial_dimensions(processor_topology_spatial_decomposition,flag_default_null_value);

    this->numberProcessorComputeUnitsPerDomain_ = 
        ANANSI::SDPConstructorHelpers::parse_processor_topology_number_processor_compute_units_per_spatial_domain(number_processor_compute_units_per_domain,flag_default_null_value);
    return;
}

SimulationDecompositionParameters::SimulationDecompositionParameters(SimulationDecompositionParameters const & other) :
    workLoadDecomposition_{other.workLoadDecomposition_},
    processorTopologyLatticeType_{other.processorTopologyLatticeType_},
    processorTopologySpatialDecomposition_{other.processorTopologySpatialDecomposition_},
    numberProcessorComputeUnitsPerDomain_{other.numberProcessorComputeUnitsPerDomain_}
{
    if (this != &other)
    {
    }
    return;
}

SimulationDecompositionParameters::SimulationDecompositionParameters( SimulationDecompositionParameters && other) :
    workLoadDecomposition_{std::move(other.workLoadDecomposition_)},
    processorTopologyLatticeType_{std::move(other.processorTopologyLatticeType_)},
    processorTopologySpatialDecomposition_{std::move(other.processorTopologySpatialDecomposition_)},
    numberProcessorComputeUnitsPerDomain_{std::move(other.numberProcessorComputeUnitsPerDomain_)}
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method SimulationDecompositionParameters::SimulationDecompositionParameters  -----


SimulationDecompositionParameters::~SimulationDecompositionParameters()
{
    return;
}

//============================= OPERATORS ====================================

//============================= STATIC    ===================================

// -----------------------------------------------------
// This section is for the processor topology spatial decomposition
// parameters.
//
// -----------------------------------------------------

int SimulationDecompositionParameters::ProcessorTopologyNumberComputeUnitsPerSpatialDomainValues(const std::string node_value)
{
    std::array<int,1> my_value = STRING_UTILITIES::convert_string_to_int_array<1>(node_value);
    return my_value[0];
}

//============================= ACCESSORS ====================================

SimulationDecompositionParameters * SimulationDecompositionParameters::clone() const
{
    return new SimulationDecompositionParameters(*this);
}

//============================= STATIC    ====================================

std::vector<std::string> SimulationDecompositionParameters::validWorkLoadDecompositionValues()
{
    std::vector<std::string> valid_values;
    for (const auto [key,value] : SimulationDecompositionParameters::validWorkLoadDecompositionValues_)
    {
        valid_values.push_back(value);
    }
    return valid_values;
}

std::vector<std::string> SimulationDecompositionParameters::validProcessorTopologyLatticeTypeValues()
{
    std::vector<std::string> valid_values;
    for (const auto [key,value] : SimulationDecompositionParameters::validProcessorTopologyLatticeTypeValues_)
    {
        valid_values.push_back(value);
    }

    return valid_values;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

SimulationDecompositionParameters& SimulationDecompositionParameters::operator=( const SimulationDecompositionParameters &other )
{
    if (this != &other)
    {
        this->workLoadDecomposition_= other.workLoadDecomposition_;
        this->processorTopologyLatticeType_ = other.processorTopologyLatticeType_;
        this->processorTopologySpatialDecomposition_ = other.processorTopologySpatialDecomposition_;
        this->numberProcessorComputeUnitsPerDomain_ = other.numberProcessorComputeUnitsPerDomain_;
    }
    return *this;
} // assignment operator

SimulationDecompositionParameters& SimulationDecompositionParameters::operator= ( SimulationDecompositionParameters && other )
{
    if (this != &other)
    {
        this->workLoadDecomposition_= std::move(other.workLoadDecomposition_);
        this->processorTopologyLatticeType_ = std::move(other.processorTopologyLatticeType_);
        this->processorTopologySpatialDecomposition_ = std::move(other.processorTopologySpatialDecomposition_);
        this->numberProcessorComputeUnitsPerDomain_ = std::move(other.numberProcessorComputeUnitsPerDomain_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//! \todo Move oustide of class.
std::map<std::string,std::string> SimulationDecompositionParameters::validWorkLoadDecompositionValues_{
    {"replicated-data-domain-decomposition", "replicated-data-domain-decomposition"},
    {"spatial-data-domain-decomposition", "spatial-data-domain-decomposition"}
};


std::map<std::string,std::string> SimulationDecompositionParameters::validProcessorTopologyLatticeTypeValues_{
    {"rectangular", "rectangular"}
};


//============================= STATIC    ====================================

//============================= MUTATORS =====================================




} // namespace ANANSI
