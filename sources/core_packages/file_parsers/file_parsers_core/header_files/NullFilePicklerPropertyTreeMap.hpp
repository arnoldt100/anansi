#ifndef ANANSI_NullFilePicklerPropertyTreeMap_INC
#define ANANSI_NullFilePicklerPropertyTreeMap_INC
//! \file NullFilePickler.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

template<>
class NullFilePickler<boost::property_tree::ptree, std::map<std::string,std::string>>
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        NullFilePickler();   // constructor

            //! The copy constructor.
        NullFilePickler(const NullFilePickler& other);   // copy constructor

        //! The move constructor.
        NullFilePickler (NullFilePickler && other);   // copy-move constructor

        ~NullFilePickler ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        NullFilePickler * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        NullFilePickler& operator= ( const NullFilePickler &other ); // assignment operator

        //! The move assignment operator.
        NullFilePickler& operator= ( NullFilePickler && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class NullFilePickler  -----


}; // End of namespace ANANSI

#endif // ANANSI_NullFilePicklerPropertyTreeMap_INC
