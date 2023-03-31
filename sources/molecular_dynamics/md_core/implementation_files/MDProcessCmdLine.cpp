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
#include "MDProcessCmdLineVisitor.h"
#include "MDProcessCmdLine.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDProcessCmdLine::MDProcessCmdLine() :
    ProcessCmdLine()
{
    return;
}

MDProcessCmdLine::MDProcessCmdLine( MDProcessCmdLine const & other) :
    ProcessCmdLine(other)
{
    if (this != &other)
    {

    }
    return;
}

MDProcessCmdLine::MDProcessCmdLine( MDProcessCmdLine && other)
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method MDProcessCmdLine::MDProcessCmdLine  -----


MDProcessCmdLine::~MDProcessCmdLine()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDProcessCmdLine& MDProcessCmdLine::operator= ( const MDProcessCmdLine &other )
{
    if (this != &other)
    {
        ProcessCmdLine::operator=(other);
    }
    return *this;
} // assignment operator

MDProcessCmdLine& MDProcessCmdLine::operator= ( MDProcessCmdLine && other )
{
    if (this != &other)
    {
        ProcessCmdLine::operator=(std::move(other));
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================
void MDProcessCmdLine::Execute_(Simulation * const a_simulation) const 
{
    MDProcessCmdLineVisitor a_visitor;
    a_simulation->Accept(a_visitor);
    return;
};

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
