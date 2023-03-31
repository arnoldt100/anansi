#ifndef  AnansiMDStateInt2Type_INC
#define  AnansiMDStateInt2Type_INC


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

// =====================================================================================
//        Class:  AnansiMDStateInt2Type
//  Description:  
//  =====================================================================================
template <int T>
class AnansiMDStateInt2Type
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  AnansiMDStateInt2Type
        //      Method:  AnansiMDStateInt2Type :: AnansiMDStateInt2Type
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        AnansiMDStateInt2Type ()
        {
            return;
        };   // constructor

        AnansiMDStateInt2Type (const AnansiMDStateInt2Type & other)
        {
            if (this != &other)
            {

            }
        return;
        }   // copy constructor

        AnansiMDStateInt2Type (AnansiMDStateInt2Type && other)
        {
            if (this != &other)
            {

            }
            return;
        }   // copy-move constructor

        ~AnansiMDStateInt2Type ()
        {
            return;
        }  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        AnansiMDStateInt2Type& operator= ( const AnansiMDStateInt2Type &other )
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator

        AnansiMDStateInt2Type& operator= ( AnansiMDStateInt2Type && other )
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment-move operator

        // ====================  DATA MEMBERS  =======================================
        enum { value = T };

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class AnansiMDStateInt2Type  -----


}; // namespace ANANSI

#endif   // ----- #ifndef AnansiMDStateInt2Type_INC  ----- 
