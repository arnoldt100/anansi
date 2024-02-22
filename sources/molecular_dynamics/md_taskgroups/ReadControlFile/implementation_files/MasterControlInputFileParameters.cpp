//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MasterControlInputFileParameters.h"
#include "MasterControlInternalNodeKeys.h"
#include "GenericTaskInvokerUtilities.hpp"
#include "CommandFiles.h"
namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MasterControlInputFileParameters::MasterControlInputFileParameters()
{
    return;
}

MasterControlInputFileParameters::MasterControlInputFileParameters( MasterControlInputFileParameters const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

MasterControlInputFileParameters::MasterControlInputFileParameters( MasterControlInputFileParameters && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method MasterControlInputFileParameters::MasterControlInputFileParameters  -----


MasterControlInputFileParameters::~MasterControlInputFileParameters()
{
    return;
}

//============================= ACCESSORS ====================================

MasterControlInputFileParameters * MasterControlInputFileParameters::clone() const
{
    return new MasterControlInputFileParameters(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//============================= STATIC    ====================================


SimulationDecompositionParameters MasterControlInputFileParameters::GetSimulationDecompositionParameters(
		std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                   ReadControlFileTraits::concrete_products>
       > & control_file_invoker)
{

    // Get the result of the control_file_invoker macro command. 
    // This result contains the parameters for the decomposition of the
    // simulation. We use these parameters to form a 'SimulationDecompositionParameters' 
    // object.
    using abstract_tasks = ReadControlFileTraits::abstract_products;
    using concrete_tasks = ReadControlFileTraits::concrete_products;
    using label_t = decltype(ControlFileMacroReceiver::TASKLABEL);
    constexpr auto task_label = ControlFileMacroReceiver::TASKLABEL;
    
    auto my_copy_results = GenericTaskInvokerUtilities::getCopyOfInvokerTaskResult<abstract_tasks,
                                                                                   concrete_tasks,
                                                                                   label_t,
                                                                                   task_label>(control_file_invoker);

    // Get the value for the type of workload for a default value". This value serves as a flag
    // to indicate to use the default value for that particular parameter.
    const std::string flag_default_null_value = get_default_null_value_CommandFile(my_copy_results);

    // Get the value for the type of workload decomposition - The global key for this is 
    // "MasterControlInternalNodeKeys::Simulation_Workload_Decomposition_Type".
    const std::string wd_type = 
        get_value_CommandFile(my_copy_results,std::string(MasterControlInternalNodeKeys::Simulation_Workload_Decomposition_Type));

    // Get the value for the lattice type for the processor topology.
    const std::string pt_mpi_lattice_type = 
        get_value_CommandFile(my_copy_results,std::string(MasterControlInternalNodeKeys::Simulation_Processor_Lattice_Topology_Type));

    // Get the value for the processor topology mpi spatial decomposition.
    const std::string pt_mpi_spatial_decompostion = 
        get_value_CommandFile(my_copy_results,std::string(MasterControlInternalNodeKeys::Simulation_Processor_Lattice_Topology_Dimensions));

    // Get the value for the processor topology number of compute units per spatial domain.
    const std::string pt_number_cu_per_domain = 
        get_value_CommandFile(my_copy_results,std::string{MasterControlInternalNodeKeys::Simulation_Number_Compute_Units_Per_Spatial_Domain});

    // Get the list of files to read that have the initial atoms configuration
    const std::string initial_configuration_filenames =
    		get_value_CommandFile(my_copy_results, std::string{MasterControlInternalNodeKeys::Simulation_Initial_Configuration});

    SimulationDecompositionParameters sim_decomposition_parameters(flag_default_null_value,
                                                                   wd_type,
                                                                   pt_mpi_lattice_type,
                                                                   pt_mpi_spatial_decompostion,
                                                                   pt_number_cu_per_domain,
                                                                   initial_configuration_filenames);

    return sim_decomposition_parameters;
}

MasterControlInputFileParameters& MasterControlInputFileParameters::operator= ( const MasterControlInputFileParameters &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

MasterControlInputFileParameters& MasterControlInputFileParameters::operator= ( MasterControlInputFileParameters && other )
{
    if (this != &other)
    {

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

//============================= OPERATORS ====================================


} // namespace ANANSI
