/*
 * MPIAllGatherException.h
 *
 *  Created on: 01/06/19
 *      Authors: Arnold Tharrington
 */

#ifndef ANANSI_MPIALLGATHEREXCEPTION_H_
#define ANANSI_MPIALLGATHEREXCEPTION_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI {

class MPIAllGatherException : public std::exception {

public:
    //===== LIFECYCLE ======
	MPIAllGatherException();

	~MPIAllGatherException();

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======
    char const * what() const noexcept override;

    //===== MUTATORS =======

    //===== OPERATORS ======

    
protected:

private:

};

} /* namespace ANANSI */

#endif /* ANANSI_MPIGENERICEXCPTION_H_ */
