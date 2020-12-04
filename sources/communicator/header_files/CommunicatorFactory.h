/*
 * CommunicatorFactory.h
 *
 *  Created on: 12/05/18
 *      Authors: Arnold Tharrington
 */

#ifndef COMMUNICATOR_COMMUNICATORFACTORY_H_ 
#define COMMUNICATOR_COMMUNICATORFACTORY_H_ 

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"

namespace COMMUNICATOR {

class CommunicatorFactory 
{

public:
    //===== LIFECYCLE ======
    CommunicatorFactory();

    virtual ~CommunicatorFactory()=0;

    CommunicatorFactory(const CommunicatorFactory& other);

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======
    std::unique_ptr<COMMUNICATOR::Communicator> createCommunicator() const
    {
        return this->_createCommunicator();
    }

    std::unique_ptr<COMMUNICATOR::Communicator> 
    cloneCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> const & other) const
    {
        return this->_cloneCommunicator(other);
    }

    //===== MUTATORS =======

    //===== OPERATORS ======
    CommunicatorFactory& operator=(CommunicatorFactory const & other);

    
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
    virtual std::unique_ptr<COMMUNICATOR::Communicator> 
    _createCommunicator() const=0;

    virtual std::unique_ptr<COMMUNICATOR::Communicator> 
    _cloneCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> const & other) const=0;

    //===== MUTATORS =======

    //===== OPERATORS ======


};

} /* namespace COMMUNICATOR */

#endif /* COMMUNICATOR_COMMUNICATORFACTORY_H_  */
