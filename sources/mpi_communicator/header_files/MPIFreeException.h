/*
 * MPIFreeException.h
 *
 *  Created on: 10/19/18
 *      Authors: Arnold Tharrington
 */

#ifndef ANASI_MPIFREEXCEPTION_H_
#define ANASI_MPIFREEXCEPTION_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI {

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

} /* namespace ANANSI */

#endif /* ANASI_MPIFREEXCEPTION_H_ */
