#ifndef ANANSI_PointAtoms_INC
#define ANANSI_PointAtoms_INC
//! \file PointAtoms.h

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

//! This class stores the point atoms in a spatial domain.
class PointAtoms
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        PointAtoms ();   // constructor

        //! The copy constructor.
        PointAtoms (const PointAtoms & other);   // copy constructor

        //! The move constructor.
        PointAtoms (PointAtoms && other);   // copy-move constructor

        ~PointAtoms ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        PointAtoms * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        PointAtoms& operator= ( const PointAtoms &other ); // assignment operator

        //! The move assignment operator.
        PointAtoms& operator= ( PointAtoms && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class PointAtoms  -----


}; // End of namespace ANANSI

#endif // ANANSI_PointAtoms_INC
