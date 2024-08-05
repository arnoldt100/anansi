
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

FilePickler<boost::property_tree::ptree, Atoms<DataStoragePolicy,PrecisionPolicy>>::FilePickler()
{
    return;
}

FilePickler<boost::property_tree::ptree, Atoms<DataStoragePolicy,PrecisionPolicy>>::FilePickler( 
        FilePickler<boost::property_tree::ptree, Atoms<DataStoragePolicy,PrecisionPolicy>> const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

FilePickler<boost::property_tree::ptree, Atoms<DataStoragePolicy,PrecisionPolicy>>::FilePickler( 
        FilePickler<boost::property_tree::ptree,Atoms<DataStoragePolicy,PrecisionPolicy>> && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method FilePickler::FilePickler  -----


FilePickler<boost::property_tree::ptree, Atoms<DataStoragePolicy,PrecisionPolicy>>::~FilePickler()
{
    return;
}

//============================= ACCESSORS ====================================

FilePickler<boost::property_tree::ptree, Atoms<DataStoragePolicy,PrecisionPolicy>> * 
FilePickler<boost::property_tree::ptree, Atoms<DataStoragePolicy,PrecisionPolicy>>::clone() const
{
    return new FilePickler<boost::property_tree::ptree, Atoms<DataStoragePolicy,PrecisionPolicy>>(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

FilePickler<boost::property_tree::ptree, Atoms<DataStoragePolicy,PrecisionPolicy>>& 
FilePickler<boost::property_tree::ptree, Atoms<DataStoragePolicy,PrecisionPolicy>>::operator=( 
        const FilePickler<boost::property_tree::ptree, Atoms<DataStoragePolicy,PrecisionPolicy>> &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

FilePickler<boost::property_tree::ptree, Atoms<DataStoragePolicy,PrecisionPolicy>>& 
FilePickler<boost::property_tree::ptree, Atoms<DataStoragePolicy,PrecisionPolicy>>::operator=(
        FilePickler<boost::property_tree::ptree, Atoms<DataStoragePolicy,PrecisionPolicy>> && other )
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
