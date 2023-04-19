#ifndef ANANSI_initialize_controlfile_invoker_and_taskfactory_INC
#define ANANSI_initialize_controlfile_invoker_and_taskfactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReadControlFileTraits.h"
#include "GenericTaskFactory.hpp"
#include "GenericTaskInvokerFactory.hpp"

namespace ANANSI
{

struct S
{
    mutable std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                       ReadControlFileTraits::concrete_products>
                            > x;

    mutable std::shared_ptr<GenericTaskFactory<ReadControlFileTraits::abstract_products,
                                               ReadControlFileTraits::concrete_products>
                           > y;
};

S initialize_controlfileinvoker_and_taskfactory();

}; /* namespace ANANSI */

#endif /* ANANSI_initialize_controlfile_invoker_and_taskfactory_INC */
