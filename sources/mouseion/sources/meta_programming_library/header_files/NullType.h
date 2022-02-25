#ifndef  MOUSEION_NullType_INC
#define  MOUSEION_NullType_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace MPL
{

     // =====================================================================================
     //        Class:  NullType
     //  Description:  
     //  =====================================================================================
    class NullType
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  NullType
            //      Method:  NullType :: NullType
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            NullType ();   // constructor

            NullType (const NullType & other);   // copy constructor

            NullType (NullType && other);   // copy-move constructor

            virtual ~NullType ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            NullType& operator= ( const NullType &other ); // assignment operator

            NullType& operator= ( NullType && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class NullType  -----


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_NullType_INC  ----- 
