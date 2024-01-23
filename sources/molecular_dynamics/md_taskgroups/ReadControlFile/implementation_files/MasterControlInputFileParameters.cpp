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
    SimulationDecompositionParameters sim_decomposition_parameters;

    // Get the result of the control_file_invoker macro command. 
    // This result contains the parameters for the decomposition of the
    // simulation. We use these parameters to form a 'SimulationDecompositionParameters' 
    // object.
    using abstract_tasks = ReadControlFileTraits::abstract_products;
    using concrete_tasks = ReadControlFileTraits::concrete_products;
    using label_t = decltype(ControlFileMacroReceiver::TASKLABEL);
    constexpr auto task_label = ControlFileMacroReceiver::TASKLABEL;
    
    auto my_copy_results = GenericTaskInvokerUtilities::getCopyOfInvokerTaskResult<abstract_tasks,concrete_tasks,label_t,task_label>(control_file_invoker);

    // Get the value for the type of workload decomposition. The node key is "workload-decomposition".
    // const std::string wd = get_value_CommandFile(my_copy_results,std::string("workload-decomposition"));

    // Get the value for the lattice type for the processor topology.
    // const std::string pt_mpi_lattice_type = get_value_CommandFile(my_copy_results,std::string("processor-topology.lattice-type"));

    // Get the value for the processor topology mpi spatial decomposition.
    // const std::string pt_mpi_spatial_decompostion = get_value_CommandFile(my_copy_results,std::string("processor-topology.mpi-spatial-decomposition"));

    // Get the value for the processor topology number of compute units per spatial domain.
    // const std::string pt_number_cu_per_domain = get_value_CommandFile(my_copy_results,std::string("processor-topology.compute-units-per-spatial-domain"));

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
