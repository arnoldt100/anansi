#ifndef ANANSI_ControlFileTraits_INC
#define ANANSI_ControlFileTraits_INC
//! \file ControlFileTraits.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlFilePickle.h"

namespace ANANSI
{

class ControlFileTraits
{
    public:
        using PICKLETYPE = std::map<std::string,std::string>;
        using PICKLERPOLICY = ControlFilePickle;
        using INTERNALREPRESENTATION = boost::property_tree::ptree;
        constexpr static char DEFAULTVALUE[] = {"default-null-value"};

        // ====================  LIFECYCLE     =======================================

        ControlFileTraits ();   // constructor

        ControlFileTraits (const ControlFileTraits & other);   // copy constructor

        ControlFileTraits (ControlFileTraits && other);   // copy-move constructor

        ~ControlFileTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFileTraits& operator= ( const ControlFileTraits &other ); // assignment operator

        ControlFileTraits& operator= ( ControlFileTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ControlFileTraits  -----


}; // namespace ANANSI

#endif // ANANSI_ControlFileTraits_INC
