
#ifndef  AnansiMDStateTypeList_INC
#define  AnansiMDStateTypeList_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/mp11.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiMDStateNull.h"
#include "AnansiMDStateISE.h"
#include "AnansiMDStatePCL.h"
#include "AnansiMDStateIIC.h"
#include "AnansiMDStatePS.h" 
#include "AnansiMDStateTSE.h"



namespace ANANSI
{


// =====================================================================================
//        Class:  AnansiMDStateTypeList
//  Description:  
//  =====================================================================================
class AnansiMDStateTypeList
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  AnansiMDStateTypeList
        //      Method:  AnansiMDStateTypeList :: AnansiMDStateTypeList
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        AnansiMDStateTypeList ();   // constructor

        AnansiMDStateTypeList (const AnansiMDStateTypeList & other);   // copy constructor

        AnansiMDStateTypeList (AnansiMDStateTypeList && other);   // copy-move constructor

        ~AnansiMDStateTypeList ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        AnansiMDStateTypeList& operator= ( const AnansiMDStateTypeList &other ); // assignment operator

        AnansiMDStateTypeList& operator= ( AnansiMDStateTypeList && other ); // assignment-move operator

        // ====================  ALIASES       =======================================
        using TypeList = boost::mp11::mp_list<AnansiMDStateNull,
                                              AnansiMDStateISE,
                                              AnansiMDStatePCL,
                                              AnansiMDStateIIC,
                                              AnansiMDStatePS,
                                              AnansiMDStateTSE>;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class AnansiMDStateTypeList  -----


}; // namespace ANANSI

#endif   // ----- #ifndef AnansiMDStateTypeList_INC  ----- 
