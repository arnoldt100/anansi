#ifndef COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_MPIINITIALIZEDEXCEPTION_H_
#define COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_MPIINITIALIZEDEXCEPTION_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR {

class MPIInitializedException : public std::exception {

public:
    //===== LIFECYCLE ======
	MPIInitializedException();

	~MPIInitializedException();

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======
    const char * what() const noexcept override;
    
    //===== MUTATORS =======

    //===== OPERATORS ======

    
protected:

private:

};

} /* namespace COMMUNICATOR */

#endif /* COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_MPIINITIALIZEDEXCEPTION_H_ */
