#ifndef ANANSI_InitialConfigurationFilenames_INC
#define ANANSI_InitialConfigurationFilenames_INC
//! \file InitialConfigurationFilenames.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <vector>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

class InitialConfigurationFilenames
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        InitialConfigurationFilenames ();   // constructor

        explicit InitialConfigurationFilenames(std::vector<std::string> const & file_names);

        //! The copy constructor.
        InitialConfigurationFilenames (const InitialConfigurationFilenames & other);   // copy constructor

        //! The move constructor.
        InitialConfigurationFilenames (InitialConfigurationFilenames && other);   // copy-move constructor

        ~InitialConfigurationFilenames ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        InitialConfigurationFilenames * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        InitialConfigurationFilenames& operator= ( const InitialConfigurationFilenames &other ); // assignment operator

        //! The move assignment operator.
        InitialConfigurationFilenames& operator= ( InitialConfigurationFilenames && other ); // assignment-move operator

        std::vector<std::string> operator()() const;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::vector<std::string> fileNames_;

}; // -----  End of class InitialConfigurationFilenames  -----


}; // End of namespace ANANSI

#endif // ANANSI_InitialConfigurationFilenames_INC
