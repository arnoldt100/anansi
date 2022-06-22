/*
 * MPIGenericException.h
 *
 *  Created on: 10/19/18
 *      Authors: Arnold Tharrington
 */

#ifndef ANANSI_MPIGENERICEXCPTION_H_
#define ANANSI_MPIGENERICEXCPTION_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI {

class MPIGenericException : public std::exception {

public:
    //===== LIFECYCLE ======
	MPIGenericException();

	~MPIGenericException();

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
