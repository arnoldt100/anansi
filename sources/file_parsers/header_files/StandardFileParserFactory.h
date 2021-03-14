#ifndef  StandardFileParserFactory_INC
#define  StandardFileParserFactory_INC

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
     //        Class:  StandardFileParserFactory
     //  Description:  
     //  =====================================================================================
    class StandardFileParserFactory
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  StandardFileParserFactory
            //      Method:  StandardFileParserFactory :: StandardFileParserFactory
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            StandardFileParserFactory ();   // constructor

            StandardFileParserFactory (const StandardFileParserFactory & other);   // copy constructor

            StandardFileParserFactory (StandardFileParserFactory && other);   // copy-move constructor

            ~StandardFileParserFactory ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            StandardFileParserFactory& operator= ( const StandardFileParserFactory &other ); // assignment operator

            StandardFileParserFactory& operator= ( StandardFileParserFactory && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class StandardFileParserFactory  -----


}; // namespace ANANSI

#endif   // ----- #ifndef StandardFileParserFactory_INC  ----- 
