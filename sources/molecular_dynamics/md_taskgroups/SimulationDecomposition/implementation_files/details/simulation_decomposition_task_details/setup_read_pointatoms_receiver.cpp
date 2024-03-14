//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_read_pointatoms_receiver.h"
#include "GenericTaskFactory.hpp"
#include "GenericReceiverFactory.hpp"

namespace ANANSI
{

void setup_read_pointatoms_receiver (std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
                                                                                SimulationDecompositionTaskTraits::concrete_products>
                                               > & simulation_decomposer_invoker )
{
    // ---------------------------------------------------
    // We define some type aliases to reduce the amount of typing.
    //
    // ---------------------------------------------------
    using my_abstract_tasks = SimulationDecompositionTaskTraits::abstract_products; // The abstract task typelist.
    using my_concrete_tasks = SimulationDecompositionTaskTraits::concrete_products; // The concrete tasks typelist.
    
    // ---------------------------------------------------
    // Declare the concrete task factory for the these set of concrete task
    // products.
    //
    // ---------------------------------------------------
    auto concrete_task_factory = std::make_unique<GenericTaskFactory<my_abstract_tasks,
                                                                    my_concrete_tasks>
                                                                   >();

    // ---------------------------------------------------
    // Get the task label for the concrete task that we want to create:
    // GenericMDTask<ReadPointAtoms>
    //
    // ---------------------------------------------------
    using base_receiver_t = ANANSI::ReadPointAtoms::MyParentTask; // The base class for the task we are setting up. 
    using concrete_receiver_t = ANANSI::ReadPointAtoms; // The concrete tasks we are setting up.
    auto constexpr task_label = concrete_receiver_t::TASKLABEL;

    // ---------------------------------------------------
    // Create the receiver of concrete task 
    // GenericMDTask<ReadPointAtoms>
    // ---------------------------------------------------
    auto read_point_atoms_reciver = 
        RECEIVER::GenericReceiverFactory<my_abstract_tasks,my_concrete_tasks>::createSharedReceiver<concrete_receiver_t>();

    // ---------------------------------------------------
    // Create task object and bind the receiver to the task object.
    // 
    // ---------------------------------------------------
    std::shared_ptr<ANANSI::AnansiTask> my_task = 
        concrete_task_factory->create_shared_ptr<base_receiver_t>(read_point_atoms_reciver);

    // ---------------------------------------------------
    // Modify the receiver 
    //
    // ---------------------------------------------------
    // To do is modify the receiver.

    // ---------------------------------------------------
    // Add the task object/command to the invoker.
    //
    // ---------------------------------------------------
    simulation_decomposer_invoker->addTask(task_label,my_task);

    return ;
}   // -----  end of function setup_read_pointatoms_receiver  -----


}; // namespace ANANSI

