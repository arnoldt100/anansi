//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "BuilderFileParser.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

BuilderFileParser::BuilderFileParser()
{
    return;
}

BuilderFileParser::BuilderFileParser( BuilderFileParser && other)
{
    return;
}   // -----  end of method BuilderFileParser::BuilderFileParser  -----


BuilderFileParser::~BuilderFileParser()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void BuilderFileParser::setCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> && a_communicator)
{
	this->_setCommunicator(std::move(a_communicator));
	return;
}

void BuilderFileParser::setFileName(const std::string file_name)
{
	this->_setFileName(file_name);
	return;
}

std::shared_ptr<FileParser> BuilderFileParser::getParser()
{
	return this->_getParser();
}

//============================= OPERATORS ====================================

BuilderFileParser& BuilderFileParser::operator= ( const BuilderFileParser &other )
{
    if (this != &other)
    {

    }
    return *this;
}   // assignment operator

BuilderFileParser& BuilderFileParser::operator= ( BuilderFileParser && other )
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
void BuilderFileParser::_setFileName(const std::string)
{
	return;
}

void BuilderFileParser::_setCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> && a_communicator)
{
	return;
}

//============================= OPERATORS ====================================


}   // namespace ANANSI
