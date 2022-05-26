/*
 * MPIAllReduceException.h
 *
 *  Created on: 12/16/2018
 *      Authors: Arnold Tharrington
 */

#ifndef ANASI_MPIALLREDUCEEXCEPTION_H_
#define ANASI_MPIALLREDUCEEXCEPTION_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI {

class MPIAllReduceException : public std::exception {

public:
    //===== LIFECYCLE ======
	MPIAllReduceException();

	~MPIAllReduceException();

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======
    char const * what() const noexcept override;

    //===== MUTATORS =======

    //===== OPERATORS ======

    
protected:

private:

};

} /* namespace ANANSI */

#endif /* ANASI_MPIALLREDUCEEXCEPTION_H_ */
