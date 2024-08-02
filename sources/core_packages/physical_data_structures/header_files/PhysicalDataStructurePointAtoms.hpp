#ifndef ANANSI_PhysicalDataStructurePointAtoms_INC
#define ANANSI_PhysicalDataStructurePointAtoms_INC
//! \file PhysicalDataStructurePointAtoms.h

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

//! brief A container for a point atoms.
template <typename DataStoragePolicy,
          typename PrecisionPolicy>
class PhysicalDataStructurePointAtoms
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        PhysicalDataStructurePointAtoms ()   // constructor
        {
            return;
        }

        //! The copy constructor.
        PhysicalDataStructurePointAtoms (const PhysicalDataStructurePointAtoms & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        //! The move constructor.
        PhysicalDataStructurePointAtoms (PhysicalDataStructurePointAtoms && other);   // copy-move constructor

        ~PhysicalDataStructurePointAtoms ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        PhysicalDataStructurePointAtoms * clone () const
        {
            return new PhysicalDataStructurePointAtoms(*this);
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        PhysicalDataStructurePointAtoms& operator= ( const PhysicalDataStructurePointAtoms &other ) // assignment operator
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment operator

        //! The move assignment operator.
        PhysicalDataStructurePointAtoms& operator= ( PhysicalDataStructurePointAtoms && other ) // assignment-move operator
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

}; // -----  End of class PhysicalDataStructurePointAtoms  -----


}; // End of namespace ANANSI

#endif // ANANSI_PhysicalDataStructurePointAtoms_INC
