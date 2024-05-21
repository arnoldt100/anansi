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
//! \tparam DataStoragePolicy Specifies the data storage policy.
//! \tparam DataPrecisionPolicy Specifies the data precision policy.
template <typename DataStoragePolicy,
          typename DataPrecisionPolicy>
class PointAtoms
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        PointAtoms ()   // constructor
        {
            return;
        }

        //! The copy constructor.
        PointAtoms (const PointAtoms & other)
        {
            if (this != &other)
            {
            }
            return;
        }

        //! The move constructor.
        PointAtoms (PointAtoms && other)  // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }    // -----  end of method PointAtoms::PointAtoms  -----

        ~PointAtoms ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        PointAtoms * clone () const
        {
            return new PointAtoms(*this);
        }


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        PointAtoms& operator= ( const PointAtoms &other ) // assignment operator
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment operator

        //! The move assignment operator.
        PointAtoms& operator= ( PointAtoms && other ) // assignment-move operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class PointAtoms  -----


}; // End of namespace ANANSI

#endif // ANANSI_PointAtoms_INC
