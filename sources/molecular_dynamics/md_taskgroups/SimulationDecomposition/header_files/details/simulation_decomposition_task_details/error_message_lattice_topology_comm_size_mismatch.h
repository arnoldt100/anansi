#ifndef ANANSI_error_message_lattice_topology_comm_size_mismatch_INC
#define ANANSI_error_message_lattice_topology_comm_size_mismatch_INC

//! \file error_message_lattice_topology_comm_size_mismatch.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/format.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//


namespace ANANSI
{
namespace SimulationDecompositionTasksHelpers
{
    static constexpr char* ErrorMessageHeader = R"""(
# ----------------------
# Error Message
# ----------------------)""";

    //!  Move this outside the class to  helper function.
    static constexpr char* ErrorMessageFooter = R"""(# ----------------------)""";
   
    template<typename Container_t>
    std::string topology_dimensions(const Container_t & my_container)
    {
        std::string message{"[ "};
        for ( auto it=my_container.cbegin(); it != my_container.cend(); ++it)
        {

            message += std::to_string(*it);
            message += std::string(" ");
        }
        message += std::string{" ]"};
        message += "\n";
        return message;
    }

    template<typename Container_t>
    std::string error_message_lattice_topology_comm_size_mismatch (const Container_t & my_container,
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
        boost::format comm_size_frmt("The communicator size: %1%\n");
        comm_size_frmt % communicator_size;
        message += comm_size_frmt.str();

        // Print the process topology dimensions.
        std::string topology_frmt("The requested communicator process topology dimensions:\n");
        s1_frmt % topology_frmt.c_str();
        message += s1_frmt.str();
        message += topology_dimensions(my_container);

        // Add footer to message.
        s1_frmt % ErrorMessageFooter;
        message += s1_frmt.str();
        return message;
    }   // -----  end of function error_message_lattice_topology_comm_size_mismatch  -----

}; // ----- End of namspace SimulationDecompositionTasksHelpers.
}; // ----- End of namespace ANANSI

#endif // ANANSI_error_message_lattice_topology_comm_size_mismatch_INC
