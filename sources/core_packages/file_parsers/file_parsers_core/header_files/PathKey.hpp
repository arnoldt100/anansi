#ifndef ANANSI_PathKey_INC
#define ANANSI_PathKey_INC
//! \file PathKey.h
//!
//! \brief Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{


//! \brief Forms the path key for the internal representation of the (key,value) pair.
//!
//! \tparam PathSepartor_t The policy for forming the path key.
template<typename PathSepartor_t>
class PathKey
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
                this = other.clone()
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

#endif // ANANSI_PathKey_INC
