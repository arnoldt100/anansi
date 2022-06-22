/*
 * MPICommSplitException.h
 *
 *  Created on: 10/19/18
 *      Authors: Arnold Tharrington
 */

#ifndef ANANSI_MPICOMMSPLITEXCEPTION_H_
#define ANANSI_MPICOMMSPLITEXCEPTION_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI {

class MPICommSplitException : public std::exception {

public:
    //===== LIFECYCLE ======
	MPICommSplitException();

	~MPICommSplitException();

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======
    char const * what() const noexcept override;

    //===== MUTATORS =======

    //===== OPERATORS ======

    
protected:

private:

};

} /* namespace ANANSI */

#endif /* ANANSI_MPICOMMSPLITEXCEPTION_H_ */
