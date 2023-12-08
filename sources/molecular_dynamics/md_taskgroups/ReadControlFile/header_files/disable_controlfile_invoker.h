#ifndef ANANSI_disable_controlfile_invoker_INC
#define ANANSI_disable_controlfile_invoker_INC

//! \file disable_controlfile_invoker.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "GenericTaskInvoker.hpp"
#include "ReadControlFileTraits.h"


namespace ANANSI
{

//! \brief Stud text for brief description
void disable_controlfile_invoker ( std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                   ReadControlFileTraits::concrete_products>
                                                  > & control_file_invoker );


}; // namespace ANANSI

#endif // ANANSI_disable_controlfile_invoker_INC