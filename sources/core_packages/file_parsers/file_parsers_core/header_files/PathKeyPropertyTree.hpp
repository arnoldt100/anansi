#ifndef ANANSI_PathKeyPropertyTree_INC
#define ANANSI_PathKeyPropertyTree_INC
//! \file PathKey.h


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "PathKey.hpp"

namespace ANANSI
{


//! \brief Forms the path key for the internal representation of the (key,value) pair of boost property tree.
//!
//! The class template specialization is for the internal representation being a boost::propert_tree::ptree.
template<>
class PathKey<boost::property_tree::ptree>
{
    public:
        // ====================  LIFECYCLE     =======================================

        PathKey ()   // constructor
        {
            return;
        }

        PathKey( PathKey const & other)
        {
            if (this != &other)
            {
                
            }
            return;
        }

        PathKey (PathKey && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }		// -----  end of method PathKey::PathKey  -----

        ~PathKey ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        PathKey * clone() const
        {
            return new PathKey(*this);
        }


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================
        PathKey& operator= ( const PathKey &other )
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment operator

        PathKey& operator= ( PathKey && other ) // assignment-move operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class PathKey  -----


}; // namespace ANANSI

#endif // ANANSI_PathKeyPropertyTree_INC
