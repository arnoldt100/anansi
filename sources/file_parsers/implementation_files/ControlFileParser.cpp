
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlFileParser.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileParser::ControlFileParser() :
    FileParsers()
{
    return;
}

ControlFileParser::ControlFileParser( ControlFileParser && other) :
    FileParsers(std::move(other))
{
    return;
} // -----  end of method ControlFileParser::ControlFileParser  -----


ControlFileParser::~ControlFileParser()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFileParser& ControlFileParser::operator= ( const ControlFileParser &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

ControlFileParser& ControlFileParser::operator= ( ControlFileParser && other )
{
    if (this != &other)
    {
        FileParsers::operator=(std::move(other));
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void ControlFileParser::_readFile()
{
    std::cout << "Reading control file." << std::endl;
    return;
}   // -----  end of method ControlFileParser::readFile  ----- 



void ControlFileParser::_shareData()
{
    std::cout << "Sharing control file data." << std::endl;
    return ;
}		// -----  end of method FileParsers::shareData  ----- 
//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
