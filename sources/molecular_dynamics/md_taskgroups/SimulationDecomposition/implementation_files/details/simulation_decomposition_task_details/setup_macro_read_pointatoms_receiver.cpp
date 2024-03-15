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
#include "setup_macro_read_pointatoms_receiver.h"
#include "GenericTaskFactory.hpp"
#include "GenericReceiverFactory.hpp"

namespace ANANSI
{

void setup_macro_read_pointatoms_receiver (std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
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
    // GenericMDTask<MacroReadPointAtoms>
    //
    // ---------------------------------------------------
    using base_receiver_t = ANANSI::MacroReadPointAtoms::MyParentTask; // The base class for the task we are setting up. 
    using concrete_receiver_t = ANANSI::MacroReadPointAtoms; // The concrete tasks we are setting up.
    auto constexpr task_label = concrete_receiver_t::TASKLABEL;

    // ---------------------------------------------------
    // Create the receiver of concrete task 
    // GenericMDTask<MacroReadPointAtoms>
    // ---------------------------------------------------
    auto macro_read_point_atoms_receiver = 
        RECEIVER::GenericReceiverFactory<my_abstract_tasks,my_concrete_tasks>::createSharedReceiver<concrete_receiver_t>();

    // ---------------------------------------------------
    // Create task object and bind the receiver to the task object.
    // 
    // ---------------------------------------------------
    std::shared_ptr<ANANSI::AnansiTask> my_task = 
        concrete_task_factory->create_shared_ptr<base_receiver_t>(macro_read_point_atoms_receiver);

    // ---------------------------------------------------
    // Modify the receiver by adding the
    // component tasks. 
    //
    // ---------------------------------------------------
     constexpr auto my_task_label0 = ReadPointAtoms::TASKLABEL;
     auto my_read_point_atoms_task =
         simulation_decomposer_invoker->getHandleToTask<my_task_label0>();
    macro_read_point_atoms_receiver->modifyReceiver(my_read_point_atoms_task); 

     constexpr auto my_task_label1 = PointAtomsDecomposer::TASKLABEL;
     auto my_point_atoms_decompser_task =
         simulation_decomposer_invoker->getHandleToTask<my_task_label1>();
    macro_read_point_atoms_receiver->modifyReceiver(my_point_atoms_decompser_task); 

     constexpr auto my_task_label2 = PointAtomsCommunicator::TASKLABEL;
     auto my_point_atoms_communicator_task =
         simulation_decomposer_invoker->getHandleToTask<my_task_label2>();
    macro_read_point_atoms_receiver->modifyReceiver(my_point_atoms_communicator_task); 

    // ---------------------------------------------------
    // Add the task object/command to the invoker.
    //
    // ---------------------------------------------------
    simulation_decomposer_invoker->addTask(task_label,my_task);

    // ---------------------------------------------------
    // Now enable the task
    //
    // ---------------------------------------------------
    std::vector my_labels = {task_label};
    simulation_decomposer_invoker->enableTask(my_labels);

    return;
}   // -----  end of function setup_macro_read_pointatoms_receiver  -----


}; // namespace ANANSI

