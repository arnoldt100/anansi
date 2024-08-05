#ifndef ANANSI_ConvertGlobalNodeKey_INC
#define ANANSI_ConvertGlobalNodeKey_INC
//! \file ConvertGlobalNodeKey.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

template<class NodeKeyTraits> 
class ConvertGlobalNodeKey
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        ConvertGlobalNodeKey () // constructor
        {
            return;
        }

        //! The copy constructor.
        ConvertGlobalNodeKey (const ConvertGlobalNodeKey & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        //! The move constructor.
        ConvertGlobalNodeKey (ConvertGlobalNodeKey && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        ~ConvertGlobalNodeKey ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        ConvertGlobalNodeKey * clone () const
        {
            return new ConvertGlobalNodeKey(*this);
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        ConvertGlobalNodeKey& operator= ( const ConvertGlobalNodeKey &other ) // assignment operator
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment operator

        //! The move assignment operator.
        ConvertGlobalNodeKey& operator= ( ConvertGlobalNodeKey && other ) // assignment-move operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment-move operator


        std::string operator()(const std::string_view global_key) const 
        {
            std::string key_str(global_key);
            return key_str;
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class ConvertGlobalNodeKey  -----


}; // End of namespace ANANSI

#endif // ANANSI_ConvertGlobalNodeKey_INC
