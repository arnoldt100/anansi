#ifndef ANANSI_message_missing_mandatory_node_tag_INC
#define ANANSI_message_missing_mandatory_node_tag_INC

//! \file message_missing_mandatory_node_tag.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//


namespace ANANSI
{

namespace 
{

static constexpr char* ErrorMessageHeader = R"""(
# ----------------------
# Error Message
# ----------------------)""";

//!  Move this outside the class to  helper function.
static constexpr char* ErrorMessageFooter = R"""(# ----------------------)""";

}; // End of anonynous namespace.

namespace SDPConstructorHelpers {

//! \brief Stud text for brief description
std::string message_missing_mandatory_node_tag ( const std::string node_tag );

}; // End of namespace SDPConstructorHelpers

}; // End of namespace ANANSI

#endif // ANANSI_message_missing_mandatory_node_tag_INC
