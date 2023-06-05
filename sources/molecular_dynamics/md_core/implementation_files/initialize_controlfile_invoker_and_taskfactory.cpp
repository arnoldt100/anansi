//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "initialize_controlfile_invoker_and_taskfactory.h"

namespace ANANSI
{

S initialize_controlfileinvoker_and_taskfactory()
{
    // Create the ControlFile invoker.
    std::shared_ptr<GenericTaskInvokerFactory<ReadControlFileTraits::abstract_products,
                                              ReadControlFileTraits::concrete_products>
                   > mdControlFileInvkFactory = 
        std::make_shared<GenericTaskInvokerFactory<ReadControlFileTraits::abstract_products,
                                                   ReadControlFileTraits::concrete_products>
                        >();

    std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                               ReadControlFileTraits::concrete_products>
                    > t1= mdControlFileInvkFactory->create_shared_ptr();

    // Create the ControlFile task factory.
    std::shared_ptr<GenericTaskFactory<ReadControlFileTraits::abstract_products,
                                       ReadControlFileTraits::concrete_products>
                   > t2 = std::make_shared<GenericTaskFactory<ReadControlFileTraits::abstract_products,
                                           ReadControlFileTraits::concrete_products>
                                          >();

    return S{t1,t2};
}   //  end of function initialize_controlfile_invoker_and_taskfactory


}; /* namespace __NAMESPACE__ */

