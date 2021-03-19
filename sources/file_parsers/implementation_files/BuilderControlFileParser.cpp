//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "BuilderControlFileParser.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

BuilderControlFileParser::BuilderControlFileParser() :
    BuilderFileParser(),
	_myParser(std::make_shared<ControlFileParser>())
{
    return;
}

BuilderControlFileParser::BuilderControlFileParser( BuilderControlFileParser && other) :
    BuilderFileParser(std::move(other)),
	_myParser(std::move(other._myParser))
{
    return;
}		// -----  end of method BuilderControlFileParser::BuilderControlFileParser  -----


BuilderControlFileParser::~BuilderControlFileParser()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

BuilderControlFileParser& BuilderControlFileParser::operator= ( const BuilderControlFileParser &other )
{
    if (this != &other)
    {
    	this->_myParser = other._myParser;
    }
    return *this;
} // assignment operator

BuilderControlFileParser& BuilderControlFileParser::operator=( BuilderControlFileParser && other )
{
    if (this != &other)
    {
        BuilderFileParser::operator=(std::move(other));
        this->_myParser = std::move(other._myParser);
    }
    return *this;
} // assignment-move operator

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
void BuilderControlFileParser::_setFileName(const std::string file_name)
{
	this->_myParser->setFileName(file_name);
	return;
}

void BuilderControlFileParser::_setCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> && a_communicator)
{
    this->_myParser->setCommunicator(std::move(a_communicator));
	return;
}

std::shared_ptr<FileParser> BuilderControlFileParser::_getParser()
{
	std::shared_ptr<ControlFileParser> a_parser = std::move(this->_myParser);
	this->_resetBuilder();
	return a_parser;
}

void BuilderControlFileParser::_resetBuilder()
{
	this->_myParser = std::make_shared<ControlFileParser>();
	return;
}
//============================= OPERATORS ====================================


} // namespace ANANSI
