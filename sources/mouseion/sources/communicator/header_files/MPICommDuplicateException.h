/*
 * MPICommDuplicateException.h
 *
 *  Created on: 10/19/18
 *      Authors: Arnold Tharrington
 */

#ifndef COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_MPICOMMDUPLICATEXCEPTION_H_
#define COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_MPICOMMDUPLICATEXCEPTION_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR {

class MPICommDuplicateException : public std::exception {

public:
    //===== LIFECYCLE ======
	MPICommDuplicateException();

	~MPICommDuplicateException();

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======
    const char * what() const noexcept override;

    //===== MUTATORS =======

    //===== OPERATORS ======

    
protected:

private:

};

} /* namespace COMMUNICATOR */

#endif /* COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_MPICOMMDUPLICATEXCEPTION_H_ */
