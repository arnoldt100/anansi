#ifndef ANANSI_VariableXMLKeyFormatPolicy_INC
#define ANANSI_VariableXMLKeyFormatPolicy_INC
//! \file VariableXMLKeyFormatPolicy.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <string_view>
#include <vector>
#include <tuple>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

class VariableXMLKeyFormatPolicy
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        VariableXMLKeyFormatPolicy ();   // constructor

        //! The copy constructor.
        VariableXMLKeyFormatPolicy (const VariableXMLKeyFormatPolicy & other);   // copy constructor

        //! The move constructor.
        VariableXMLKeyFormatPolicy (VariableXMLKeyFormatPolicy && other);   // copy-move constructor

        ~VariableXMLKeyFormatPolicy ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        VariableXMLKeyFormatPolicy * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        VariableXMLKeyFormatPolicy& operator= ( const VariableXMLKeyFormatPolicy &other ); // assignment operator

        //! The move assignment operator.
        VariableXMLKeyFormatPolicy& operator= ( VariableXMLKeyFormatPolicy && other ); // assignment-move operator

        //! Forms the internal key format string.
        std::string operator()(const std::string & old_key, const std::vector<std::string> & key_frmt_args) const;

        //! Forms the xml key from the the xml format string.
        std::string operator()(const std::string & old_key) const;

        // ====================  STATIC        =======================================
        static std::string create_variable_internal_key(const std::string & internal_key,const std::vector<std::string> & key_frmt_args);

        static std::tuple<std::string,std::vector<std::string>> split_variable_internal_key(const std::string & internal_key);

        static std::string create_external_xml_key(const std::string & variable_external_xml_key,const std::vector<std::string> & key_frmt_args);

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class VariableXMLKeyFormatPolicy  -----


}; // End of namespace ANANSI

#endif // ANANSI_VariableXMLKeyFormatPolicy_INC
