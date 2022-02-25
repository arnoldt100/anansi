/*
 * MPIFreeException.h
 *
 *  Created on: 10/19/18
 *      Authors: Arnold Tharrington
 */

#ifndef COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_MPIFREEXCEPTION_H_
#define COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_MPIFREEXCEPTION_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR {

class MPIFreeException : public std::exception {

public:
    //===== LIFECYCLE ======
	MPIFreeException();

	~MPIFreeException();

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======
    char const * what() const noexcept override;

    //===== MUTATORS =======

    //===== OPERATORS ======

    
protected:

private:

};

} /* namespace COMMUNICATOR */

#endif /* COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_MPIFREEXCEPTION_H_ */
