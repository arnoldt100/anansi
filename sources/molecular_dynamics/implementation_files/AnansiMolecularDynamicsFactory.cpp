//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "Pointer.hpp"
#include "Pointer2d.hpp"
#include "copy_2d_char_array.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiMolecularDynamicsFactory.h"

namespace ANANSI
{

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

/*
 *--------------------------------------------------------------------------------------
 *       Class:  AnansiMolecularDynamicsFactory
 *      Method:  AnansiMolecularDynamicsFactory
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
AnansiMolecularDynamicsFactory::AnansiMolecularDynamicsFactory() :
    MolecularDynamicsFactory(),
    argc_(0),
    argv_ptr_(nullptr)
{
    return;
}  /* -----  end of method AnansiMolecularDynamicsFactory::AnansiMolecularDynamicsFactory  (constructor)  ----- */


AnansiMolecularDynamicsFactory::AnansiMolecularDynamicsFactory(int const argc, char const * const * const & argv ) :
    MolecularDynamicsFactory(),
    argc_(argc),
    argv_ptr_(nullptr)
{
    if (argv != nullptr )
    {
        STRING_UTILITIES::copy_2d_char_array(argc,argv,this->argv_ptr_);
    }
    return; 
}
/*
 *--------------------------------------------------------------------------------------
 *       Class:  AnansiMolecularDynamicsFactory
 *      Method:  ~AnansiMolecularDynamicsFactory
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
AnansiMolecularDynamicsFactory::~AnansiMolecularDynamicsFactory ()
{
    if (this->argv_ptr_ != nullptr)
    {
        MEMORY_MANAGEMENT::Pointer2d<char>::destroyPointer2d(this->argc_,this->argv_ptr_);
    }
    return;

}  /* -----  end of method AnansiMolecularDynamicsFactory::~AnansiMolecularDynamicsFactory  (destructor)  ----- */


//============================= ACCESSORS ====================================



//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

std::shared_ptr<MolecularDynamics> AnansiMolecularDynamicsFactory::_create_shared_ptr()
{
    std::shared_ptr<MolecularDynamics> aMD = std::make_shared<AnansiMolecularDynamics>(this->argc_,this->argv_ptr_);
    return aMD;
}
//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


}; /* -----  end of namespace ANANSI  ----- */
