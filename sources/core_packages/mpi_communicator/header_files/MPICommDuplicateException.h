/*
 * MPICommDuplicateException.h
 *
 *  Created on: 10/19/18
 *      Authors: Arnold Tharrington
 */

#ifndef ANANSI_MPICOMMDUPLICATEXCEPTION_H_
#define ANANSI_MPICOMMDUPLICATEXCEPTION_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI {

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

} /* namespace ANANSI */

#endif /* ANANSI_MPICOMMDUPLICATEXCEPTION_H_ */
