#ifndef ANANSI_FilePickler_INC
#define ANANSI_FilePickler_INC
//! \file FilePickler.hpp
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

class FilePickler
{
    public:
        // ====================  LIFECYCLE     =======================================

        FilePickler ();   // constructor

        FilePickler (const FilePickler & other);   // copy constructor

        FilePickler (FilePickler && other);   // copy-move constructor

        virtual ~FilePickler ();  // destructor

        // ====================  ACCESSORS     =======================================
        FilePickler * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        FilePickler& operator= ( const FilePickler &other ); // assignment operator

        FilePickler& operator= ( FilePickler && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class FilePickler  -----


}; // namespace ANANSI

#endif // ANANSI_FilePickler_INC
