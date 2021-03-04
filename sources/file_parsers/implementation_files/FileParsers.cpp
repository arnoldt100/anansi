//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "FileParsers.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

FileParsers::FileParsers()
{
    return;
}

FileParsers::FileParsers( FileParsers && other)
{
    return;
} 

FileParsers::~FileParsers()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void FileParsers::readFile()
{
    this->_readFile();
    return;
}   // -----  end of method FileParsers::readFile  ----- 


void FileParsers::shareData ()
{
    this->_shareData();
    return ;
}		// -----  end of method FileParsers::shareData  ----- 

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

FileParsers& FileParsers::operator=( const FileParsers &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

FileParsers& FileParsers::operator=( FileParsers && other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
