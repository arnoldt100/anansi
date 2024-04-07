//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <algorithm>
#include <string>
#include <vector>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_read_pointatoms_receiver.h"
#include "GenericTaskFactory.hpp"
#include "GenericReceiverFactory.hpp"
#include "InitialConfigurationFilenames.h"
#include "create_master_process_tag.hpp"
#include "create_communicator_rank_tag.hpp"
#include "create_communicator_size_tag.hpp"
#include "DataPartitioner.hpp"
namespace ANANSI
{

void setup_read_pointatoms_receiver (SimulationDecompositionParameters const & simulation_decomposition_parameters,
                                     std::shared_ptr<COMMUNICATOR::Communicator> & rect_communicator,  
                                     std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
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
    // Modify the receiver 
    //
    // ---------------------------------------------------

    // Add the master process tag to the receiver.
    COMMUNICATOR::MasterProcess my_master_process_tag{COMMUNICATOR::create_master_process_tag(rect_communicator)};
    read_point_atoms_reciver->modifyReceiver(my_master_process_tag);

    // Add the communicator rank tag to the receiver.
    COMMUNICATOR::CommunicatorRank my_comm_rank_tag{COMMUNICATOR::create_communicator_rank_tag(rect_communicator)};
    read_point_atoms_reciver->modifyReceiver(my_comm_rank_tag);

    // ---------------------------------------------------
    // Create task object and bind the receiver to the task object.
    // 
    // ---------------------------------------------------
    std::shared_ptr<ANANSI::AnansiTask> my_task = 
        concrete_task_factory->create_shared_ptr<base_receiver_t>(read_point_atoms_reciver);

    // Add the list of files to read the initial configuration. 
    // We alphabetically sort the files to ensure the files
    // are in the same order on each communicator rank.
    std::vector<std::string> list_of_files = 
        simulation_decomposition_parameters.listOfInitialConfigurationFiles();
    std::sort(list_of_files.begin(),list_of_files.end());
    COMMUNICATOR::CommunicatorRank::rank_t tag{my_comm_rank_tag.operator()()};
    // auto partitioned_file_list  = RoundRobinDataPartitioner<std::vector<std::string>,COMMUNICATOR::CommunicatorRank::rank_t> (list_of_files.begin(),
    //                                                         list_of_files.end(),
    //                                                         tag);

    auto partitioned_file_list  = RoundRobinDataPartitioner(list_of_files,
                                                            tag);

    // InitialConfigurationFilenames my_files{partitioned_file_list};
    // read_point_atoms_reciver->modifyReceiver(my_files);
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

    return ;
}   // -----  end of function setup_read_pointatoms_receiver  -----


}; // namespace ANANSI

