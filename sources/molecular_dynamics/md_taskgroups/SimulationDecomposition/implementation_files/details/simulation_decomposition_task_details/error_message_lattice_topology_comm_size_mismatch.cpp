//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/format.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "error_message_lattice_topology_comm_size_mismatch.h"

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
    }; // ----- End of anonymous namspace 
  
namespace SimulationDecompositionTasksHelpers
{
    template<typename iterator_t>
    std::string error_message_lattice_topology_comm_size_mismatch (iterator_t const & begin,
                                                                   iterator_t const & end,
                                                                   std::size_t const & communicator_size )
    {
        std::string message;

        boost::format s1_frmt("%1%\n");

        // Add header to message.
        s1_frmt % ErrorMessageHeader;
        message = s1_frmt.str();

        // Add warning to message.
        std::string warning_str("Warning! The requested communicator process topology dimensions\ndoes not equal the size of the communicator.\n");
        s1_frmt % warning_str.c_str();
        message += s1_frmt.str();

        // Print the communcator size.
        boost::format comm_size_frmt("The world communicator size: %1%\n");
        comm_size_frmt % communicator_size;

        boost::format topology_frmt("The world communicator size: %1%\n");

        boost::format topology_frmt("The requested communicator process topology:\n");
        boost::format topology_frmt("[  ] ");

        // Add footer to message.
        s1_frmt % ErrorMessageFooter;
        message += s1_frmt.str();
        return message;
    }   // -----  end of function error_message_lattice_topology_comm_size_mismatch  -----

}; // ----- End of namespace SimulationDecompositionTasksHelpers
}; // ----- End of namespace ANANSI

