#ifndef ANANSI_coordinates_INC
#define ANANSI_coordinates_INC
//! \file coordinates.h

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

//! \brief This class responsibility is to store the atomic coordinates.
class coordinates
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        coordinates ();   // constructor

        //! The copy constructor.
        coordinates (const coordinates & other);   // copy constructor

        //! The move constructor.
        coordinates (coordinates && other);   // copy-move constructor

        ~coordinates ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        coordinates * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        coordinates& operator= ( const coordinates &other ); // assignment operator

        //! The move assignment operator.
        coordinates& operator= ( coordinates && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class coordinates  -----


}; // namespace ANANSI

#endif // ANANSI_coordinates_INC
