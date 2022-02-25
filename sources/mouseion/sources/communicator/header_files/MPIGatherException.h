/*
 * MPIGatherException.h
 *
 *  Created on: 04/21/19
 *      Authors: Arnold N. Tharrington
 */

#ifndef COMMUNICATOR_MPIGATHEREXCEPTION_H_
#define COMMUNICATOR_MPIGATHEREXCEPTION_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR {

class MPIGatherException : public std::exception {

public:
    //===== LIFECYCLE ======
	MPIGatherException();

	~MPIGatherException();

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======
    char const * what() const noexcept override;

    //===== MUTATORS =======

    //===== OPERATORS ======

    
protected:
    //===== LIFECYCLE ======

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======

    //===== MUTATORS =======

    //===== OPERATORS ======

private:
    //===== LIFECYCLE ======

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======

    //===== MUTATORS =======

    //===== OPERATORS ======


};

} /* namespace COMMUNICATOR */

#endif /* COMMUNICATOR_MPIGATHEREXCEPTION_H_ */
