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

namespace ANANSI
{

class ReadControlFileResultsTraits
{
    public:
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
