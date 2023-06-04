//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "../header_files/BuilderFile.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

BuilderFile::BuilderFile()
{
    return;
}

BuilderFile::BuilderFile( BuilderFile const & other)
{
    if (this != &other)
    {

    }
    return;
}   // -----  end of method BuilderFile::BuilderFile  -----

BuilderFile::BuilderFile( BuilderFile && other)
{
    if (this != &other)
    {

    }
    return;
}   // -----  end of method BuilderFile::BuilderFile  -----


BuilderFile::~BuilderFile()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void BuilderFile::setCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> && a_communicator)
{
	this->_setCommunicator(std::move(a_communicator));
	return;
}

void BuilderFile::setFileName(const std::string file_name)
{
	this->_setFileName(file_name);
	return;
}

std::shared_ptr<FileParser> BuilderFile::getParser()
{
	return this->_getParser();
}

//============================= OPERATORS ====================================

BuilderFile& BuilderFile::operator= ( const BuilderFile &other )
{
    if (this != &other)
    {

    }
    return *this;
}   // assignment operator

BuilderFile& BuilderFile::operator= ( BuilderFile && other )
{
    if (this != &other)
    {

    }
    return *this;
}   // assignment-move operator

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

//============================= MUTATORS =====================================
void BuilderFile::_setFileName(const std::string)
{
	return;
}

//============================= OPERATORS ====================================


}   // namespace ANANSI
