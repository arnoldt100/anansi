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
std::shared_ptr<FileParser> StandardFileParserFactory::create( std::shared_ptr<BuilderFileParser> builder,
                                                               const std::string file_name, 
                                                               std::unique_ptr<COMMUNICATOR::Communicator> && a_communicator)
{
	builder->setCommunicator(std::move(a_communicator));
	builder->setFileName(file_name);
	std::shared_ptr<FileParser> a_parser = builder->getParser();
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
