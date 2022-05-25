/*
 * MPICommSizeException.h
 *
 *  Created on: 01/06/19
 *      Authors: Arnold Tharrington
 */

#ifndef ANANSI_MPICOMMSIZEEXCEPTION_H_
#define ANANSI_MPICOMMSIZEEXCEPTION_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI {

class MPICommSizeException : public std::exception {

public:
    //===== LIFECYCLE ======
	MPICommSizeException();

	~MPICommSizeException();

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======
    char const * what() const noexcept override;

    //===== MUTATORS =======

    //===== OPERATORS ======

    
protected:

private:

};

} /* namespace ANANSI */

#endif /* ANANSI_MPICOMMSIZEEXCEPTION_H_ */
