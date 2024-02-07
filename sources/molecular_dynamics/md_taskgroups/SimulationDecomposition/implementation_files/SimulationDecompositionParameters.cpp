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
#include "match_string_to_positive_integer.h"
#include "words_in_string_are_positive_integers.h"

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
    this->workLoadDecomposition_ = SimulationDecompositionParameters::DefaultWorkLoadDecompositionType();
    this->processorTopologyLatticeType_ = SimulationDecompositionParameters::DefaultProcessorTopologyLatticeType();
    this->processorTopologySpatialDecomposition_ = 
        SimulationDecompositionParameters::DefaultProcessorTopologyLatticeSpatialDimensions();
    this->numberProcessorComputeUnitsPerDomain_ = 
        SimulationDecompositionParameters::DefaultProcessorTopologyNumberComputeUnitsPerSpatialDomain();
    return;
}

SimulationDecompositionParameters::SimulationDecompositionParameters(const std::string flag_default_null_value,
                                          const std::string work_load_decomposition,
                                          const std::string processor_topology_lattice,
                                          const std::string processor_topology_spatial_decomposition,
                                          const std::string number_processor_compute_units_per_domain)
{
    this->workLoadDecomposition_ =
        ANANSI::SDPConstructorHelpers::workload_decomposition_type(work_load_decomposition,flag_default_null_value);

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
// This section is for the workload decomposition type 
// parameters.
//
// -----------------------------------------------------

std::string SimulationDecompositionParameters::DefaultWorkLoadDecompositionType()
{
    return SimulationDecompositionParameters::validWorkLoadDecompositionValues_.at("spatial-data-domain-decomposition"); 
}

bool SimulationDecompositionParameters::IsValidWorkLoadDecompositionTypeValues(const std::string node_value)
{
    return SimulationDecompositionParameters::validWorkLoadDecompositionValues_.contains(node_value);
}

std::string SimulationDecompositionParameters::WorkLoadDecompositionTypeValues( const std::string node_value)
{
    return SimulationDecompositionParameters::validWorkLoadDecompositionValues_.at(node_value); 
}

// -----------------------------------------------------
// This section is for the processor lattice type 
// parameters - ProcessorTopologyLatticeType
//
// -----------------------------------------------------
std::string SimulationDecompositionParameters::DefaultProcessorTopologyLatticeType()
{
    return SimulationDecompositionParameters::validProcessorTopologyLatticeTypeValues_.at("rectangular");
}

bool SimulationDecompositionParameters::IsValidProcessorTopologyLatticeTypeValues(const std::string node_value)
{
    return SimulationDecompositionParameters::validProcessorTopologyLatticeTypeValues_.contains(node_value);
}

std::string SimulationDecompositionParameters::ProcessorTopologyLatticeTypeValues(const std::string node_value)
{
    return SimulationDecompositionParameters::validProcessorTopologyLatticeTypeValues_.at(node_value);
}

// -----------------------------------------------------
// This section is for the processor topology spatial decomposition
// parameters.
//
// -----------------------------------------------------

std::array<int,3> SimulationDecompositionParameters::DefaultProcessorTopologyLatticeSpatialDimensions()
{
    std::array<int,3> my_default_value{1,1,1};
    return my_default_value;
}

bool SimulationDecompositionParameters::IsValidProccesorTopologyLatticeSpatialDimensionsValues(const std::string node_value)
{
    // We need to form an array of 3 positive integers. If the string can be parsed to form an 
    // array of 3 positive integers, then we return true, otherwise return false.
    bool valid_value = true;

    // There must be only 3 words or return false.
    auto count = STRING_UTILITIES::count_words_in_string(node_value);
    if (count != 3)
    {
        valid_value = false;
        return valid_value;
    }
   
    // Each word must a positive integer.
    const bool all_words_positive_integers = STRING_UTILITIES::words_in_string_are_positive_integers(node_value);
    if (! all_words_positive_integers )
    {
        valid_value = false;
        return valid_value;
    }
    return valid_value;
}

std::array<int,3> SimulationDecompositionParameters::ProccesorTopologyLatticeSpatialDimensionsValues(const std::string node_value)
{
    std::array<int,3> my_default_value{1,1,1};
    return my_default_value;
}

bool SimulationDecompositionParameters::IsProccesorTopologyLatticeSpatialDimensionsMandatory()
{
    return true;
}

// -----------------------------------------------------
// This section is for the processor topology compute units per domain
// parameters. - ProcessorTopologyNumberComputeUnitsPerDomain
//
// -----------------------------------------------------
int SimulationDecompositionParameters::DefaultProcessorTopologyNumberComputeUnitsPerSpatialDomain()
{
    return 1;
}

bool SimulationDecompositionParameters::IsProcesorTopologyNumberComputeUnitsPerSpatialDomainMandatory()
{
    return true;
}




std::string SimulationDecompositionParameters::MessageMissingMandatoryNodeTag(const std::string node_tag)
{
    std::string message;

    boost::format s1_frmt("%1%\n");

    // Add header to message.
    s1_frmt % SimulationDecompositionParameters::ErrorMessageHeader_;
    message = s1_frmt.str();

    // Add warning to message.
    boost::format warning_frmt("Warning! The tag for the '%1%' is missing from the input file\nbut the tag is mandatory to run the program.\n");
    warning_frmt % node_tag.c_str();
    message += warning_frmt.str();

    // Add footer to message.
    s1_frmt % SimulationDecompositionParameters::ErrorMessageFooter_;
    message += s1_frmt.str();
    return message;
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
