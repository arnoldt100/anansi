
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "FilePicklerPropertyTreePointAtoms.hpp"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

FilePickler<boost::property_tree::ptree, Atoms>::FilePickler()
{
    return;
}

FilePickler<boost::property_tree::ptree, Atoms>::FilePickler( 
        FilePickler<boost::property_tree::ptree, Atoms> const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

FilePickler<boost::property_tree::ptree, Atoms>::FilePickler( 
        FilePickler<boost::property_tree::ptree,Atoms> && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method FilePickler::FilePickler  -----


FilePickler<boost::property_tree::ptree, Atoms>::~FilePickler()
{
    return;
}

//============================= ACCESSORS ====================================

FilePickler<boost::property_tree::ptree, Atoms> * 
FilePickler<boost::property_tree::ptree, Atoms>::clone() const
{
    return new FilePickler<boost::property_tree::ptree, Atoms>(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

FilePickler<boost::property_tree::ptree, Atoms>& 
FilePickler<boost::property_tree::ptree, Atoms>::operator=( 
        const FilePickler<boost::property_tree::ptree, Atoms> &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

FilePickler<boost::property_tree::ptree, Atoms>& 
FilePickler<boost::property_tree::ptree, Atoms>::operator=(
        FilePickler<boost::property_tree::ptree, Atoms> && other )
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
