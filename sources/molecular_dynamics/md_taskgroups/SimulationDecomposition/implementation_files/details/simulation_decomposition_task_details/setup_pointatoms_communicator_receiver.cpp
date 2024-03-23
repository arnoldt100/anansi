//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <vector>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_pointatoms_communicator_receiver.h"
#include "GenericTaskFactory.hpp"
#include "GenericReceiverFactory.hpp"
#include "sdp_create_communicator_embryo.hpp"
#include "MPICommunicatorFactory.h"

namespace ANANSI
{

void setup_pointatoms_communicator_receiver (const SimulationDecompositionParameters & work_load_parameters,
                                             std::unique_ptr<COMMUNICATOR::Communicator> world_communicator,
                                             std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
                                                                                       SimulationDecompositionTaskTraits::concrete_products>
                                               > & simulation_decomposer_invoker)
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
    // GenericMDTask<PointAtomsCommunicator>
    //
    // ---------------------------------------------------
    using base_receiver_t = ANANSI::PointAtomsCommunicator::MyParentTask; // The base class for the task we are setting up. 
    using concrete_receiver_t = ANANSI::PointAtomsCommunicator; // The concrete tasks we are setting up.
    auto constexpr task_label = concrete_receiver_t::TASKLABEL;

    // ---------------------------------------------------
    // Create the receiver of concrete task 
    // GenericMDTask<PointAtomsCommunicator>
    // ---------------------------------------------------
    auto point_atoms_communicator_receiver = 
        RECEIVER::GenericReceiverFactory<my_abstract_tasks,my_concrete_tasks>::createSharedReceiver<concrete_receiver_t>();
   
    // ---------------------------------------------------
    // Modify the receiver by adding.
    //
    // ---------------------------------------------------
    auto communicator_embryo = COMMUNICATOR::create_communicator_embryo(work_load_parameters);
    std::unique_ptr<COMMUNICATOR::CommunicatorFactory> a_communicator_factory = std::make_unique<MPICommunicatorFactory>();
    std::unique_ptr<COMMUNICATOR::Communicator> my_comm = 
        std::move(a_communicator_factory->createCommunicator(world_communicator,communicator_embryo));
    
    // ---------------------------------------------------
    // Create task object and bind the receiver to the task object.
    // 
    // ---------------------------------------------------
    std::shared_ptr<ANANSI::AnansiTask> my_task = 
        concrete_task_factory->create_shared_ptr<base_receiver_t>(point_atoms_communicator_receiver);

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
}   // -----  end of function setup_pointatoms_communicator_receiver  -----


}; // namespace ANANSI

