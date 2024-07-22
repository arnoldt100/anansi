#ifndef ANANSI_VariableKeyFormatPolicy_INC
#define ANANSI_VariableKeyFormatPolicy_INC
//! \file VariableKeyFormatPolicy.h

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

class VariableKeyFormatPolicy
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        VariableKeyFormatPolicy ();   // constructor

        //! The copy constructor.
        VariableKeyFormatPolicy (const VariableKeyFormatPolicy & other);   // copy constructor

        //! The move constructor.
        VariableKeyFormatPolicy (VariableKeyFormatPolicy && other);   // copy-move constructor

        ~VariableKeyFormatPolicy ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        VariableKeyFormatPolicy * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        VariableKeyFormatPolicy& operator= ( const VariableKeyFormatPolicy &other ); // assignment operator

        //! The move assignment operator.
        VariableKeyFormatPolicy& operator= ( VariableKeyFormatPolicy && other ); // assignment-move operator

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

}; // -----  End of class VariableKeyFormatPolicy  -----


}; // End of namespace ANANSI

#endif // ANANSI_VariableKeyFormatPolicy_INC
