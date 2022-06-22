/*
 * MPIFinalizedException.h
 *
 *  Created on: 10/19/18
 *      Authors: Arnold Tharrington
 */

#ifndef ANANSI_MPIFINALIZEDEXCEPTION_H_
#define ANANSI_MPIFINALIZEDEXCEPTION_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI {

class MPIFinalizedException : public std::exception {

public:
    //===== LIFECYCLE ======
	MPIFinalizedException();

	~MPIFinalizedException();

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======
    const char * what() const noexcept override;

    //===== MUTATORS =======

    //===== OPERATORS ======

    
protected:

private:

};

} /* namespace ANANSI */

#endif /* ANANSI_MPIFINALIZEDEXCEPTION_H_ */
