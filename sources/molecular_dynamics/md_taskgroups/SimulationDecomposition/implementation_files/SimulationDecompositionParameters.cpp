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
#include "ErrorInvalidSimulationDecompositionParameters.h"

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
    this->workLoadDecomposition_ = SimulationDecompositionParameters::DefaultWorkLoadDecomposition_();
    this->processorTopologyLatticeType_ = SimulationDecompositionParameters::DefaultProcessorTopologyLatticeType_();
    this->processorTopologySpatialDecomposition_ = SimulationDecompositionParameters::DefaultProcessorTopologySpatialDecomposition_();
    this->numberProcessorComputeUnitsPerDomain_ = SimulationDecompositionParameters::DefaultNumberProcessorComputeUnitsPerDomain_();
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
    const std::tuple<bool,std::string> wld = this->_computeWorkLoadDecomposition(flag_default_null_value,work_load_decomposition);
    if ( std::get<bool>(wld))
    {
        this->workLoadDecomposition_ = std::get<std::string>(wld);
    }
    else
    {
    	std::string error_message = SimulationDecompositionParameters::ErrorInvalidWorkloadDecompositionVales();
    	throw ErrorInvalidSimulationDecompositionParameters(error_message);
    }

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

//!
std::tuple<bool,std::string> SimulationDecompositionParameters::_computeWorkLoadDecomposition(const std::string flag_default_null_value,
                                                                                              const std::string node_value)
{
    std::string ret_value;
    bool valid_node_value = true;

    if ( (node_value == flag_default_null_value) && 
         SimulationDecompositionParameters::WorkLoadDecompositionKeyIsMandatory_()  )
    {
        std::string error_message = SimulationDecompositionParameters::ErrorMessageMissingWorkloadDecompositionTag();
    	throw ErrorInvalidSimulationDecompositionParameters(error_message);
    }
    else if (this->validWorkLoadDecompositionValues_.contains(node_value))
    {
        ret_value = this->validWorkLoadDecompositionValues_.at(node_value);
    }
    else
    {
        valid_node_value = false;
        ret_value = node_value;
    }
    return std::make_tuple(valid_node_value,ret_value);
}

//============================= OPERATORS ====================================

//============================= STATIC    ====================================

std::map<std::string,std::string> SimulationDecompositionParameters::validWorkLoadDecompositionValues_{
    {"replicated-data-domain-decomposition", "replicated-data-domain-decomposition"},
    {"spatial-data-domain-decomposition", "spatial-data-domain-decomposition"}
};

std::string SimulationDecompositionParameters::DefaultWorkLoadDecomposition_()
{
    return SimulationDecompositionParameters::validWorkLoadDecompositionValues_.at("spatial-data-domain-decomposition"); 
}

bool SimulationDecompositionParameters::WorkLoadDecompositionKeyIsMandatory_()
{
    return true;
}

std::string SimulationDecompositionParameters::DefaultProcessorTopologyLatticeType_()
{
    return std::string("rectangular");
}

std::string SimulationDecompositionParameters::DefaultProcessorTopologySpatialDecomposition_()
{
    return std::string("1 1 1");
}

std::string SimulationDecompositionParameters::DefaultNumberProcessorComputeUnitsPerDomain_()
{
    return std::string("1");
}

std::string SimulationDecompositionParameters::ErrorMessageMissingWorkloadDecompositionTag()
{
    std::map<std::string,std::string> allowed_values = SimulationDecompositionParameters::validWorkLoadDecompositionValues_;
    std::string message;
    message += "The workload decomposition tag is missing from the input file.\n";
    message += "but the tag is mandatory to run the program.\n";
    return message;
}

std::string SimulationDecompositionParameters::ErrorInvalidWorkloadDecompositionVales()
{
    std::map<std::string,std::string> allowed_values = SimulationDecompositionParameters::validWorkLoadDecompositionValues_;
    std::string message;
    message += "The workload decomposition value is incorrect in the input file.\n";
    message += "The allowed values are the following:\n";
    for (auto const& [key, val] : allowed_values )
    {
        message += "    ";
        message += val;
        message += "\n";
    }
    return message;
}



} // namespace ANANSI
