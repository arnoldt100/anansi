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
#include "ErrorInvalidSimulationDecompositionParameters.h"
#include "ErrorInvalidSimulationWorkloadDecompositionType.h"
#include "ErrorMissingSimulationWorkloadDecompositionParameters.h"

#include <boost/format.hpp>

#include "SDPConstructorHelpers.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

SimulationDecompositionParameters::SimulationDecompositionParameters() :
    workLoadDecomposition_{""},
    processorTopologyLatticeType_{""},
    processorTopologySpatialDecomposition_(""),
    numberProcessorComputeUnitsPerDomain_("")
{
    this->workLoadDecomposition_ = SimulationDecompositionParameters::DefaultWorkLoadDecomposition();
    this->processorTopologyLatticeType_ = SimulationDecompositionParameters::DefaultProcessorTopologyLatticeType();
    this->processorTopologySpatialDecomposition_ = SimulationDecompositionParameters::DefaultProcessorTopologySpatialDecomposition();
    this->numberProcessorComputeUnitsPerDomain_ = SimulationDecompositionParameters::DefaultNumberProcessorComputeUnitsPerDomain();
    return;
}

SimulationDecompositionParameters::SimulationDecompositionParameters(const std::string flag_default_null_value,
                                          const std::string work_load_decomposition,
                                          const std::string processor_topology_lattice_type,
                                          const std::string processor_topology_spatial_decomposition,
                                          const std::string number_processor_compute_units_per_domain)
{
    // Compute the work load decomposition type and assign to member attribute.
    // "this->workLoadDecomposition_".
    std::tuple<bool,std::string> wld;

    try 
    {
        wld = this->_computeWorkLoadDecomposition(flag_default_null_value,work_load_decomposition);
    }
    catch (const ErrorMissingSimulationWorkloadDecompositionParameters & my_error) 
    {
        const std::string error_message{my_error.what()};
        throw MOUSEION::GenericErrorClass<SimulationDecompositionParameters>(error_message); 
    }
    catch (const ErrorInvalidSimulationWorkloadDecompositionType & my_error) 
    {
        const std::string error_message{my_error.what()};
        throw MOUSEION::GenericErrorClass<SimulationDecompositionParameters>(error_message); 
    }

    this->workLoadDecomposition_ = ANANSI::SDPConstructorHelpers::workload_decomposition_type(work_load_decomposition,flag_default_null_value);
    this->workLoadDecomposition_ = std::get<std::string>(wld);

    return;
}

SimulationDecompositionParameters::SimulationDecompositionParameters( SimulationDecompositionParameters const & other) :
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

std::tuple<bool,std::string> SimulationDecompositionParameters::_computeWorkLoadDecomposition(const std::string flag_default_null_value,
                                                                                              const std::string node_value)
{
    std::string ret_value;
    bool valid_node_value = true;

    if ( (node_value == flag_default_null_value) && 
         SimulationDecompositionParameters::WorkLoadDecompositionKeyIsMandatory()  )
    {
        std::string error_message = SimulationDecompositionParameters::ErrorMessageMissingWorkloadDecompositionNodeTag();
    	throw ErrorMissingSimulationWorkloadDecompositionParameters(error_message);
    }
    else if (this->validWorkLoadDecompositionValues.contains(node_value))
    {
        ret_value = this->validWorkLoadDecompositionValues.at(node_value);
    }
    else
    {
    	std::string error_message = SimulationDecompositionParameters::ErrorMessageInvalidWorkloadDecompositionNodeValue(node_value);
    	throw ErrorInvalidSimulationWorkloadDecompositionType(error_message);
    }
    return std::make_tuple(valid_node_value,ret_value);
}

//============================= OPERATORS ====================================

//============================= STATIC    ====================================

std::map<std::string,std::string> SimulationDecompositionParameters::validWorkLoadDecompositionValues{
    {"replicated-data-domain-decomposition", "replicated-data-domain-decomposition"},
    {"spatial-data-domain-decomposition", "spatial-data-domain-decomposition"}
};

std::string SimulationDecompositionParameters::DefaultWorkLoadDecomposition()
{
    return SimulationDecompositionParameters::validWorkLoadDecompositionValues.at("spatial-data-domain-decomposition"); 
}

bool SimulationDecompositionParameters::WorkLoadDecompositionKeyIsMandatory()
{
    return true;
}

std::string SimulationDecompositionParameters::DefaultProcessorTopologyLatticeType()
{
    return std::string("rectangular");
}

std::string SimulationDecompositionParameters::DefaultProcessorTopologySpatialDecomposition()
{
    return std::string("1 1 1");
}

std::string SimulationDecompositionParameters::DefaultNumberProcessorComputeUnitsPerDomain()
{
    return std::string("1");
}

std::string SimulationDecompositionParameters::ErrorMessageMissingWorkloadDecompositionNodeTag()
{
    std::string message;

    boost::format s1_frmt("%1%\n");
    boost::format s2_frmt("    %1%\n");
    boost::format s3_frmt("    %1%\n\n");

    const char* header = R"""(# ----------------------)""";

    // Add header to message.
    s1_frmt % header;
    message = s1_frmt.str();

    // Add warning.
    const char* warning1 = R"""(Warning! The workload decomposition tag is missing from the input file)""";
    s1_frmt % warning1;
    message += s1_frmt.str();

    const char* warning2 = R"""(but the tag is mandatory to run the program.)""";
    s1_frmt % warning2;
    message += s1_frmt.str();

    // Add footer to message.
    const char* footer = R"""(# ----------------------)""";
    s1_frmt % footer;
    message += s1_frmt.str();
    return message;
}

std::string SimulationDecompositionParameters::ErrorMessageInvalidWorkloadDecompositionNodeValue(const std::string invalid_value)
{
    std::string message;

    boost::format s1_frmt("%1%\n");
    boost::format s2_frmt("    %1%\n");
    boost::format s3_frmt("    %1%\n\n");

    const char* header = R"""(# ----------------------)""";

    // Add header to message.
    s1_frmt % header;
    message = s1_frmt.str();

    // Add warning.
    const char* warning1 = R"""(Warning! Invalid parameter for simulation workload decomposition type.)""";
    s1_frmt % warning1;
    message += s1_frmt.str();

    const char* warning2 = R"""(The decomposition workload type:)""";
    s1_frmt % warning2;
    message += s1_frmt.str();


    s3_frmt % invalid_value.c_str();
    message += s3_frmt.str();

    const char* warning3 = R"""(is an invalid value. The following values are valid choices:)""";
    s1_frmt % warning3;
    message += s1_frmt.str();

    for (const auto [key,value] : SimulationDecompositionParameters::validWorkLoadDecompositionValues )
    {
        s2_frmt % value.c_str();
        message += s2_frmt.str();
    }
    s2_frmt % "";
    message += s2_frmt.str();

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

//============================= MUTATORS =====================================




} // namespace ANANSI
