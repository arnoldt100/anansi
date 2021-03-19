
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
    FileParser(),
    _fileName(),
    _myCommunicator()
{
    return;
}

ControlFileParser::ControlFileParser( ControlFileParser && other) :
    FileParser(std::move(other)),
    _fileName(std::move(other._fileName)),
    _myCommunicator(std::move(other._myCommunicator))
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


ControlFileParser& ControlFileParser::operator= ( ControlFileParser && other )
{
    if (this != &other)
    {
        FileParser::operator=(std::move(other));
        this->_fileName = std::move(other._fileName);
        this->_myCommunicator = std::move(other._myCommunicator);
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
    const auto world_rank = this->_myCommunicator->getWorldCommunicatorRank();
    switch ( world_rank )
    {
        case COMMUNICATOR::MASTER_TASK_ID :	
            this->_parseFile();
            break;

        default:	
            break;
    }				/* -----  end switch  ----- */
    this->shareData();

    return;
}   // -----  end of method ControlFileParser::readFile  ----- 



void ControlFileParser::_shareData()
{
    std::cout << "Sharing control file data." << std::endl;
    return ;
}		// -----  end of method FileParser::shareData  ----- 


void ControlFileParser::_setFileName(const std::string file_name) 
{
    this->_fileName = file_name;
    return;
}

void ControlFileParser::_setCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> && a_communicator)
{
    this->_myCommunicator = std::move(a_communicator);
    return;
}

void ControlFileParser::_parseFile()
{
    std::cout << "Parsing control file data." << std::endl;
    return;
}

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
