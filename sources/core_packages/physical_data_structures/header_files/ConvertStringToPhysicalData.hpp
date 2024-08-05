#ifndef ANANSI_ConvertStringToPhysicalData_INC
#define ANANSI_ConvertStringToPhysicalData_INC
//! \file ConvertStringToPhysicalData.h
//!
//! \brief Brief description
//!
//! \details Detailed description

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
#include "PrecisionPolicy.h"

namespace ANANSI
{

template<typename Data_Precision_Policy>
class ConvertStringToPhysicalData
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        ConvertStringToPhysicalData ()   // constructor
        {
            return;
        }

            //! The copy constructor.
        ConvertStringToPhysicalData (const ConvertStringToPhysicalData & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        //! The move constructor.
        ConvertStringToPhysicalData (ConvertStringToPhysicalData && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }		// -----  end of method ConvertStringToPhysicalData::ConvertStringToPhysicalData  -----

        ~ConvertStringToPhysicalData ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        ConvertStringToPhysicalData * clone () const
        {
            return new ConvertStringToPhysicalData(*this);
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        ConvertStringToPhysicalData& operator= ( const ConvertStringToPhysicalData &other ) // assignment operator
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment operator

        //! The move assignment operator.
        ConvertStringToPhysicalData& operator= ( ConvertStringToPhysicalData && other ) // assignment-move operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment-move operator

        static auto  convertStringToPosition(const std::string & a_string)
        {
                
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class ConvertStringToPhysicalData  -----


}; // End of namespace ANANSI

#endif // ANANSI_ConvertStringToPhysicalData_INC
