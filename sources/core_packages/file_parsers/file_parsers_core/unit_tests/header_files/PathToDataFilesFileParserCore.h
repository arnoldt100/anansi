#ifndef ANANSI_PathToDataFilesFileParserCore_INC
#define ANANSI_PathToDataFilesFileParserCore_INC
//! \file PathToDataFilesFileParserCore.h
//!
//! \brief Brief description
//!
//! Detailed description

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

class PathToDataFilesFileParserCore
{
    public:
        // ====================  STATIC        =======================================
        static std::string pathToXMLControlFile();

        // ====================  LIFECYCLE     =======================================

        PathToDataFilesFileParserCore ();   // constructor

        PathToDataFilesFileParserCore (const PathToDataFilesFileParserCore & other);   // copy constructor

        PathToDataFilesFileParserCore (PathToDataFilesFileParserCore && other);   // copy-move constructor

        virtual ~PathToDataFilesFileParserCore ();  // destructor

        // ====================  ACCESSORS     =======================================
        PathToDataFilesFileParserCore * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        PathToDataFilesFileParserCore& operator= ( const PathToDataFilesFileParserCore &other ); // assignment operator

        PathToDataFilesFileParserCore& operator= ( PathToDataFilesFileParserCore && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class PathToDataFilesFileParserCore  -----


}; // namespace ANANSI

#endif // ANANSI_PathToDataFilesFileParserCore_INC
