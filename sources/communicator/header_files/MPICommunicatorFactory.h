/*
 * MPICommunicatorFactory.h
 *
 *  Created on: 12/05/18
 *      Authors: Arnold Tharrington
 */

#ifndef COMMUNICATOR_MPICOMMUNICATORFACTORY_H_ 
#define COMMUNICATOR_MPICOMMUNICATORFACTORY_H_ 

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPICommunicator.h"
#include "CommunicatorFactory.h"

namespace COMMUNICATOR {

class MPICommunicatorFactory : public CommunicatorFactory 
{

public:
    //===== LIFECYCLE ======
    MPICommunicatorFactory();

    ~MPICommunicatorFactory();

    MPICommunicatorFactory(MPICommunicatorFactory const & other);

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======

    //===== MUTATORS =======

    //===== OPERATORS ======
    MPICommunicatorFactory& operator=(MPICommunicatorFactory const & other);
    
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
    std::unique_ptr<COMMUNICATOR::Communicator>
     _createCommunicator() const override;

     std::unique_ptr<COMMUNICATOR::Communicator>
     _cloneCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> const & a_communicator) const override;

    //===== MUTATORS =======

    //===== OPERATORS ======


};

} /* namespace COMMUNICATOR */

#endif /* COMMUNICATOR_MPICOMMUNICATORFACTORY_H_ */
