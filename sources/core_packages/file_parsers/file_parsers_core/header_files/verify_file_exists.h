#ifndef ANANSI_verify_file_exists_INC
#define ANANSI_verify_file_exists_INC

//! \file verify_file_exists.h

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

//! \brief If file doesn't existt then an error is thrown.
void verify_file_exists (const std::string filename );


}; // namespace ANANSI

#endif // ANANSI_verify_file_exists_INC
