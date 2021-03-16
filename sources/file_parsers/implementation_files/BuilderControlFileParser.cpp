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
	_myParser()
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
void BuilderControlFileParser::_addFileName()
{
	return;
}

void BuilderControlFileParser::_addCommunicator()
{
	return;
}

std::shared_ptr<FileParser> BuilderControlFileParser::_getParser()
{
	std::shared_ptr<ControlFileParser> a_parser;
	this->_resetBuilder();
	return a_parser;
}

void BuilderControlFileParser::_resetBuilder()
{
	return;
}
//============================= OPERATORS ====================================


} // namespace ANANSI
