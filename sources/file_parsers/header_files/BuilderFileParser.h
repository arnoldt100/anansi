#ifndef  BuilderFileParser_INC
#define  BuilderFileParser_INC


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
     //        Class:  BuilderFileParser
     //  Description:  
     //  =====================================================================================
    class BuilderFileParser
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  BuilderFileParser
            //      Method:  BuilderFileParser :: BuilderFileParser
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            BuilderFileParser ();   // constructor

            BuilderFileParser (const BuilderFileParser & other);   // copy constructor

            BuilderFileParser (BuilderFileParser && other);   // copy-move constructor

            virtual ~BuilderFileParser()=0;  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            BuilderFileParser& operator= ( const BuilderFileParser &other ); // assignment operator

            BuilderFileParser& operator= ( BuilderFileParser && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    };  // -----  end of class BuilderFileParser  -----


}; // namespace ANANSI

#endif   // ----- #ifndef BuilderFileParser_INC  ----- 
