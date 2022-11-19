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

namespace ANANSI
{

// =====================================================================================
//        Class:  GeneralFileLogger
//  Description:  
//  =====================================================================================
class GeneralFileLogger
{
    public:
        // ====================  LIFECYCLE     =======================================

        GeneralFileLogger (); // constructor

        GeneralFileLogger (const GeneralFileLogger & other); // copy constructor

        GeneralFileLogger (GeneralFileLogger && other); // copy-move constructor

        virtual ~GeneralFileLogger ()=0; // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GeneralFileLogger& operator= ( const GeneralFileLogger &other ); // assignment operator

        GeneralFileLogger& operator= ( GeneralFileLogger && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class GeneralFileLogger  -----


}; // namespace ANANSI

#endif //  ANANSI_Logger_INC
