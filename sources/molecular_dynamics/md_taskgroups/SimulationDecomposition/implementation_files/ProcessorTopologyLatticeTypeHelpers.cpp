//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{
namespace SDPConstructorHelpers 
{

std::string parse_processor_topology_lattice_type(const std::string a_string,
                                                  const std::string flag_default_null_value)
{
    std::string my_processor_topology_lattice_type = "";
    try
    {
        if ( (a_string == flag_default_null_value) && 
             SimulationDecompositionParameters::ProcessorTopologyLatticeTypeKeyIsMandatory()  )
        {
            std::string error_message = SimulationDecompositionParameters::ErrorMessageMissingMandatoryNodeTag("processor topology lattice type");
            throw ErrorMissingProcessorTopologyLatticeTypeParameters(error_message);
        }
        else if (SimulationDecompositionParameters::validProcessorTopologyLatticeTypeValues.contains(a_string))
        {
            my_workload_decomposition_type = SimulationDecompositionParameters::validWorkLoadDecompositionValues.at(a_string);
        }
        else
        {
            std::string error_message = SimulationDecompositionParameters::ErrorMessageInvalidProcessorTopologyLatticeTypeValues(a_string);
            throw ErrorInvalidProcessorTopologyLatticeType(error_message);
        }
    }
    catch (const ErrorMissingProcessorTopologyLatticeTypeParameters & my_error)
    {
            const std::string error_message{my_error.what()};
            throw MOUSEION::GenericErrorClass<SimulationDecompositionParameters>(error_message); 
    }
    catch (const ErrorInvalidProcessorTopologyLatticeType & my_error)
    {
            const std::string error_message{my_error.what()};
            throw MOUSEION::GenericErrorClass<SimulationDecompositionParameters>(error_message); 
    }
    return my_processor_topology_lattice_type; 
}

}; // end of namespace SDPConstructorHelpers 
}; // end of namespace ANANSI

