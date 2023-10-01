#ifndef ANANSI_ReadControlFileResultsTraits_INC
#define ANANSI_ReadControlFileResultsTraits_INC
//! \file ReadControlFileResultsTraits.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "XMLFileReader.h"
#include "XMLFileWriter.h"
#include "CommandFiles.h"
#include "ControlInputFile.hpp"
#include "MasterControlInputFileNodeKeys.h"

namespace ANANSI
{

//! This class defines common traits for classes in ReadControlFile directory.
class ReadControlFileResultsTraits
{
    public:
        // ====================  ALIASES       =======================================
        //! The type erasure for the input file. 
        using result_t = CommandFiles<>;

        //! The input file stored in the type erasure.
        using ControlInputFile_t = ControlInputFile<MasterControlInputFileNodeKeys,XMLFileReader,XMLFileWriter>;

        // ====================  LIFECYCLE     =======================================

        ReadControlFileResultsTraits ();   // constructor

        ReadControlFileResultsTraits (const ReadControlFileResultsTraits & other);   // copy constructor

        ReadControlFileResultsTraits (ReadControlFileResultsTraits && other);   // copy-move constructor

        ~ReadControlFileResultsTraits ();  // destructor

        // ====================  ACCESSORS     =======================================
        ReadControlFileResultsTraits * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ReadControlFileResultsTraits& operator= ( const ReadControlFileResultsTraits &other ); // assignment operator

        ReadControlFileResultsTraits& operator= ( ReadControlFileResultsTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ReadControlFileResultsTraits  -----


}; // namespace ANANSI

#endif // ANANSI_ReadControlFileResultsTraits_INC
