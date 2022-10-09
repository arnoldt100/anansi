#ifndef ANANSI_GenericMDTask_INC
#define ANANSI_GenericMDTask_INC
//! @file GenericMDTask.hpp
//!
//! Brief description
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

class GenericMDTask final
{
    public:
        // ====================  LIFECYCLE     =======================================

        GenericMDTask ();   // constructor

        GenericMDTask (const GenericMDTask & other);   // copy constructor

        GenericMDTask (GenericMDTask && other);   // copy-move constructor

        ~GenericMDTask ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GenericMDTask& operator= ( const GenericMDTask &other ); // assignment operator

        GenericMDTask& operator= ( GenericMDTask && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class GenericMDTask  -----


}; // namespace ANANSI

#endif // ANANSI_GenericMDTask_INC
