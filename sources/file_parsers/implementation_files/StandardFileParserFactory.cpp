//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "StandardFileParserFactory.h"
#include "ControlFileParser.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

StandardFileParserFactory::StandardFileParserFactory()
{
    return;
}

StandardFileParserFactory::StandardFileParserFactory( StandardFileParserFactory && other)
{
    return;
}		// -----  end of method StandardFileParserFactory::StandardFileParserFactory  -----


StandardFileParserFactory::~StandardFileParserFactory()
{
    return;
}

//============================= ACCESSORS ====================================
std::shared_ptr<FileParser> create( std::shared_ptr<BuilderFileParser>& builder )
{
    std::shared_ptr<FileParser> a_parser = std::make_shared<ControlFileParser>();
    return a_parser;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

StandardFileParserFactory& StandardFileParserFactory::operator=( const StandardFileParserFactory &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

StandardFileParserFactory& StandardFileParserFactory::operator=( StandardFileParserFactory && other )
{
    if (this != &other)
    {

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

//============================= OPERATORS ====================================


} // namespace ANANSI
