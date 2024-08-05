
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/filesystem.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "PathToDataFilesFileParserCore.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

// ====================  STATIC        =======================================
std::string PathToDataFilesFileParserCore::pathToXMLControlFile()
{
    char * anansi_top_level = std::getenv("ANANSI_TOP_LEVEL");
    boost::filesystem::path p;
    p /= anansi_top_level;
    p /= "data_files";
    p /= "file_parser_core";
    p /= "water_simulation.anansi";
    std::string my_path(p.c_str());
    return my_path;
}

//============================= LIFECYCLE ====================================

PathToDataFilesFileParserCore::PathToDataFilesFileParserCore()
{
    return;
}

PathToDataFilesFileParserCore::PathToDataFilesFileParserCore( PathToDataFilesFileParserCore const & other)
{
    if (this != &other)
    {
    }
    return;
}

PathToDataFilesFileParserCore::PathToDataFilesFileParserCore( PathToDataFilesFileParserCore && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method PathToDataFilesFileParserCore::PathToDataFilesFileParserCore  -----


PathToDataFilesFileParserCore::~PathToDataFilesFileParserCore()
{
    return;
}

//============================= ACCESSORS ====================================

PathToDataFilesFileParserCore * PathToDataFilesFileParserCore::clone() const
{
    return new PathToDataFilesFileParserCore(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

PathToDataFilesFileParserCore& PathToDataFilesFileParserCore::operator= ( const PathToDataFilesFileParserCore &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

PathToDataFilesFileParserCore& PathToDataFilesFileParserCore::operator= ( PathToDataFilesFileParserCore && other )
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
