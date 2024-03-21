#ifndef ANANSI_MPICOMMUNICATORFACTORY_H_ 
#define ANANSI_MPICOMMUNICATORFACTORY_H_ 

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPICommunicator.h"
#include "CommunicatorFactory.h"

namespace ANANSI {

class MPICommunicatorFactory final : public COMMUNICATOR::CommunicatorFactory 
{

public:
    //===== LIFECYCLE ======
    MPICommunicatorFactory();

    MPICommunicatorFactory(MPICommunicatorFactory const & other);

    MPICommunicatorFactory(MPICommunicatorFactory && other);

    ~MPICommunicatorFactory();

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======

    //===== MUTATORS =======

    //===== OPERATORS ======
    MPICommunicatorFactory& operator=(MPICommunicatorFactory const & other);

    MPICommunicatorFactory& operator=(MPICommunicatorFactory && other);
    
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
     createWorldCommunicator_() const override;

    std::unique_ptr<COMMUNICATOR::Communicator>
     createNullWorldCommunicator_() const override;

     std::unique_ptr<COMMUNICATOR::Communicator>
     cloneCommunicator_(std::unique_ptr<COMMUNICATOR::Communicator> const & a_communicator) const override;

     std::unique_ptr<COMMUNICATOR::Communicator>
     cloneCommunicator_(std::shared_ptr<COMMUNICATOR::Communicator> const & a_communicator) const override;

     std::unique_ptr<COMMUNICATOR::Communicator>
     createCommunicator_(std::unique_ptr<COMMUNICATOR::Communicator> const & a_communicator) const override;

    //===== MUTATORS =======

    //===== OPERATORS ======


};

} /* namespace ANANSI */

#endif /* ANANSI_MPICOMMUNICATORFACTORY_H_ */
