#ifndef  ANANSI_Logger_INC
#define  ANANSI_Logger_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiTask.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  GeneralLogger
//  Description:  
//  =====================================================================================
class GeneralLogger
{
    public:
        // ====================  LIFECYCLE     =======================================

        GeneralLogger (); // constructor

        GeneralLogger (const GeneralLogger & other); // copy constructor

        GeneralLogger (GeneralLogger && other); // copy-move constructor

        virtual ~GeneralLogger ()=0; // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GeneralLogger& operator= ( const GeneralLogger &other ); // assignment operator

        GeneralLogger& operator= ( GeneralLogger && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class GeneralLogger  -----


}; // namespace ANANSI

#endif //  ANANSI_Logger_INC
