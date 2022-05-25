#ifndef ANANSI_MPIINITIALIZEDEXCEPTION_H_
#define ANANSI_MPIINITIALIZEDEXCEPTION_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI {

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

} /* namespace ANANSI */

#endif /* ANANSI_MPIINITIALIZEDEXCEPTION_H_ */
