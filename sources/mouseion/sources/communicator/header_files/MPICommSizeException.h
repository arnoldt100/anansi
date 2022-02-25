/*
 * MPICommSizeException.h
 *
 *  Created on: 01/06/19
 *      Authors: Arnold Tharrington
 */

#ifndef COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_MPICOMMSIZEEXCEPTION_H_
#define COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_MPICOMMSIZEEXCEPTION_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR {

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

} /* namespace COMMUNICATOR */

#endif /* COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_MPICOMMSIZEEXCEPTION_H_ */
