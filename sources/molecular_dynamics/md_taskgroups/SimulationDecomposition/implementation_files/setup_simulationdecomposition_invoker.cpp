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
#include "SimulationDecompositionTaskTraits.h"
#include "setup_simulationdecomposition_invoker.h"
#include "setup_read_pointatoms_receiver.h"
#include "setup_pointatoms_decomposer_receiver.h"
#include "setup_pointatoms_communicator_receiver.h"
#include "setup_macro_read_pointatoms_receiver.h"
#include "MasterProcess.h"
#include "sdp_create_communicator_embryo.hpp"
#include "verify_correct_size_for_world_communicator.h"
#include "MPICommunicatorFactory.h"
#include "GenericTaskInvokerFactory.hpp"
namespace ANANSI
{

namespace 
{
    std::shared_ptr<COMMUNICATOR::Communicator> create_rectangular_communicator(
               const SimulationDecompositionParameters & simulation_decomposition_parameters,
               std::unique_ptr<COMMUNICATOR::Communicator> world_communicator )
    {
        auto communicator_embryo =
            COMMUNICATOR::create_communicator_embryo(simulation_decomposition_parameters);
        auto communicator_dims = communicator_embryo.communicatorDimensions();
        try {
          SimulationDecompositionTasksHelpers::
              verify_correct_size_for_world_communicator(
                  communicator_dims, world_communicator->getSizeofCommunicator());
        } catch (const ErrorInvalidSimulationDecompositionParameters &my_error) {
          const std::string error_message = my_error.what();
          throw MOUSEION::GenericErrorClass<SimulationDecompositionParameters>(
              error_message);
        }

        std::unique_ptr<COMMUNICATOR::CommunicatorFactory> a_communicator_factory =
            std::make_unique<MPICommunicatorFactory>();
        std::shared_ptr<COMMUNICATOR::Communicator> my_rect_comm =
            a_communicator_factory->createCommunicator(world_communicator,
                                                       communicator_embryo);
        world_communicator->freeCommunicator();
        return my_rect_comm;
    }
};  // ----- End of anonymous namespace

void setup_simulationdecomposition_invoker (const SimulationDecompositionParameters & simulation_decomposition_parameters,
		                                    std::unique_ptr<COMMUNICATOR::Communicator> world_communicator,
                                            std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
                                                                                       SimulationDecompositionTaskTraits::concrete_products>
                                               > & simulation_decomposer_invoker )
{
    simulation_decomposer_invoker  = 
      GenericTaskInvokerFactory<SimulationDecompositionTaskTraits::abstract_products,
                                SimulationDecompositionTaskTraits::concrete_products>::initializeInvoker();

    std::shared_ptr<COMMUNICATOR::Communicator> my_rect_comm = 
        create_rectangular_communicator(simulation_decomposition_parameters,
                                        std::move(world_communicator));

    const bool master_process = my_rect_comm->iAmMasterProcess();
    COMMUNICATOR::MasterProcess my_master_process(master_process);

    setup_pointatoms_communicator_receiver(simulation_decomposition_parameters,my_rect_comm,simulation_decomposer_invoker);

    setup_read_pointatoms_receiver(simulation_decomposition_parameters,my_rect_comm,simulation_decomposer_invoker);

    setup_pointatoms_decomposer_receiver(simulation_decomposer_invoker);

    setup_macro_read_pointatoms_receiver(simulation_decomposer_invoker);

    return;
}   // -----  end of function setup_simulationdecomposition_invoker  -----


}; // namespace ANANSI

