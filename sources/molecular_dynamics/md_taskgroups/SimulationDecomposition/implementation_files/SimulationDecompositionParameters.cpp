//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationDecompositionParameters.h"
#include "GenericErrorClass.hpp"

#include <boost/format.hpp>

#include "WorkloadDecompositionTypeHelpers.h"
#include "ProcessorTopologyLatticeTypeHelpers.h"
#include "ProccesorTopologyLatticeSpatialDimensionsHelpers.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

SimulationDecompositionParameters::SimulationDecompositionParameters() :
    workLoadDecomposition_{""},
    processorTopologyLatticeType_{""},
    processorTopologySpatialDecomposition_{1,1,1},
    numberProcessorComputeUnitsPerDomain_("")
{
    this->workLoadDecomposition_ = SimulationDecompositionParameters::DefaultWorkLoadDecompositionType();
    this->processorTopologyLatticeType_ = SimulationDecompositionParameters::DefaultProcessorTopologyLatticeType();
    this->processorTopologySpatialDecomposition_ = SimulationDecompositionParameters::DefaultProcessorTopologyLatticeSpatiolDimensions();
    this->numberProcessorComputeUnitsPerDomain_ = SimulationDecompositionParameters::DefaultNumberProcessorComputeUnitsPerDomain();
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

bool SimulationDecompositionParameters::IsWorkLoadDecompositionTypeMandatory()
{
    return true;
}

std::string SimulationDecompositionParameters::MessageInvalidWorkloadDecompositionTypeValues(const std::string invalid_value)
{
    std::string message;

    boost::format warning_frmt("Warning! Invalid input parameter '%1%' for workload decomposition type.\nValid values are the following:\n");
    boost::format header_frmt("%1%\n");
    boost::format s1_frmt("%1%\n");
    boost::format s2_frmt("    %1%\n");

    // Add header to message.
    header_frmt % SimulationDecompositionParameters::ErrorMessageHeader_;
    message += header_frmt.str();

    // Add warning to message.
    warning_frmt % invalid_value.c_str();
    message += warning_frmt.str();
    for (const auto [key,value] : SimulationDecompositionParameters::validWorkLoadDecompositionValues_)
    {
        s2_frmt % value.c_str();
        message += s2_frmt.str();
    }
    s1_frmt % "";
    message += s1_frmt.str();

    // Add footer to message.
    s1_frmt % SimulationDecompositionParameters::ErrorMessageFooter_;
    message += s1_frmt.str();
    return message;
}


// -----------------------------------------------------
// This section is for the processor lattice type 
// parameters - ProcessorTopologyLatticeType
//
// -----------------------------------------------------
std::string SimulationDecompositionParameters::DefaultProcessorTopologyLatticeType()
{
    return std::string("rectangular");
}

bool SimulationDecompositionParameters::IsValidProcessorTopologyLatticeTypeValues(const std::string node_value)
{
    return SimulationDecompositionParameters::validProcessorTopologyLatticeTypeValues_.contains(node_value);
}

std::string SimulationDecompositionParameters::ProcessorTopologyLatticeTypeValues(const std::string node_value)
{
    return SimulationDecompositionParameters::validProcessorTopologyLatticeTypeValues_.at(node_value);
}

bool SimulationDecompositionParameters::IsProcessorTopologyLatticeTypeMandatory()
{
    return true;
}

std::string SimulationDecompositionParameters::MessageInvalidProcessorTopologyLatticeTypeValues(const std::string invalid_value)
{
    std::string message;

    boost::format warning_frmt("Warning! Invalid input parameter '%1%' for lattice topology type.\nValid values are the following:\n");
    boost::format header_frmt("%1%\n%2%\n%3%\n");
    boost::format s1_frmt("%1%\n");
    boost::format s2_frmt("    %1%\n");

    header_frmt % ANANSI::SimulationDecompositionParameters::ErrorMessageHeader_;
    message += header_frmt.str();

    // Add warning to message.
    warning_frmt % invalid_value.c_str();
    message += warning_frmt.str();
    for (const auto [key,value] : SimulationDecompositionParameters::validProcessorTopologyLatticeTypeValues_ )
    {
        s2_frmt % value.c_str();
        message += s2_frmt.str();
    }
    s1_frmt % "";
    message += s1_frmt.str();

    // Add footer to message.
    s1_frmt % ANANSI::SimulationDecompositionParameters::ErrorMessageFooter_;
    message += s1_frmt.str();
    return message;
}


// -----------------------------------------------------
// This section is for the processor topology spatial decomposition
// parameters.
//
// -----------------------------------------------------

std::array<int,3> SimulationDecompositionParameters::DefaultProcessorTopologyLatticeSpatiolDimensions()
{
    std::array<int,3> my_default_value{1,1,1};
    return my_default_value;
}

bool SimulationDecompositionParameters::IsValidProccesorTopologyLatticeSpatialDimensionsValues(const std::string node_value)
{
    // We need to form an array of 3 positive integers. If the string can be parsed to form an 
    // array of 3 positive integers, then we return true, otherwise return false.
    bool valid_value = false;

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

std::string SimulationDecompositionParameters::MessageInvalidProccesorTopologyLatticeSpatialDimensions(const std::string invalid_value)
{
    std::string message;
    boost::format warning_frmt0("Warning! Invalid input parameter '%1%' for lattice topology spatial dimenssions.\n");
    boost::format warning_frmt1("\nThe input parameter must have form  of '<spaces>a<spaces>b<spaces>c<spaces>' where\n");

    boost::format warning_frmt2("%|4T |%|s|\n");

    boost::format s1_frmt("%1%\n");
    boost::format s2_frmt("\n%1%\n");
    
    // Add header to message.
    boost::format header_frmt("%1%\n");
    header_frmt % SimulationDecompositionParameters::ErrorMessageHeader_;
    message += header_frmt.str();

    warning_frmt0 % invalid_value.c_str();
    message += warning_frmt0.str();

    // Add warning.
    const char* warning = R"""(
The input parameter must have form  of '<spaces>a<spaces>b<spaces>c<spaces>' where
    - <spaces> is whitespace
    - a, b and c are positive integers
    - There must be at least one space between integers a and b
    - There must be at least one space between integers b and c
    - There can be any numbers spaces before integer a and after integer c

A Valid examples is 
      1 2     3)""";

    s1_frmt % warning;
    message += s1_frmt.str();

    // Add footer to message.
    s1_frmt % SimulationDecompositionParameters::ErrorMessageFooter_;
    message += s1_frmt.str();
    return message;
}

// -----------------------------------------------------
// This section is for the processor topology compute units per domain
// parameters.
//
// -----------------------------------------------------
std::string SimulationDecompositionParameters::DefaultNumberProcessorComputeUnitsPerDomain()
{
    return std::string("1");
}





std::string SimulationDecompositionParameters::MessageMissingMandatoryNodeTag(const std::string node_tag)
{
    std::string message;

    boost::format warning_frmt("Warning! The tag for the '%1%' is missing from the input file\nbut the tag is mandatory to run the program.\n");
    boost::format header_frmt("%1%\n%2%\n%3%\n");
    boost::format s1_frmt("%1%\n");

    // Add header to message.
    const char* header = R"""(# ----------------------)""";
    const char* header_message = R"""(# Error Message)""";
    header_frmt % header % header_message % header ;
    message = header_frmt.str();

    // Add warning to message.
    warning_frmt % node_tag.c_str();
    message += warning_frmt.str();

    // Add footer to message.
    const char* footer = R"""(# ----------------------)""";
    s1_frmt % footer;
    message += s1_frmt.str();
    return message;
}



//============================= ACCESSORS ====================================

SimulationDecompositionParameters * SimulationDecompositionParameters::clone() const
{
    return new SimulationDecompositionParameters(*this);
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
