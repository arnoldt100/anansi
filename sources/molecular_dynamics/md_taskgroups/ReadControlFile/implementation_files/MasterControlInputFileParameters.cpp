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

    // Get the result of the control_file_invoker macro command. Pass the result
    // to SimulationDecompositionParameters and create a
    // 'SimulationDecompositionParameters' object and return it.
    using abstract_tasks = ReadControlFileTraits::abstract_products;
    using concrete_tasks = ReadControlFileTraits::concrete_products;
    constexpr auto task_label = ControlFileMacroReceiver::TASKLABEL;

    GenericTaskInvoker<abstract_tasks,concrete_tasks>::getCopyOfInvokerTaskResult<task_label>(control_file_invoker);

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
