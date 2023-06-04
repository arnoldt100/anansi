/*
 * =====================================================================================
 *
 *       Filename:  BaseInputFile.h
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef  ANANSI_BaseInputFile_INC
#define  ANANSI_BaseInputFile_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

    template< typename Derived>
    class BaseInputFile
    {
        public:
            // ====================  LIFECYCLE     =======================================

            BaseInputFile () // constructor
            {
                return;
            }

            BaseInputFile ( const BaseInputFile &other ) // copy constructor
            {
                if (this != &other)
                {
            
                }
                return;
            } 

            BaseInputFile (BaseInputFile && other) // copy-move constructor
            {
                if (this != &other)
                {
            
                }
                return;
            } 

            ~BaseInputFile () // destructor
            {
                return;
            }

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            BaseInputFile& operator= ( const BaseInputFile &other ) /* assignment operator */
            {
                if (this != &other)
                {
            
                }
                return *this;
            } // assignment operator

            BaseInputFile& operator= ( BaseInputFile && other ) // assignment-move operator
            {
                if (this != &other)
                {
                }
                return *this;
            } // assignment-move operator

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            // ====================  MUTATORS      =======================================

            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class BaseInputFile  ----- */


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_BaseInputFile_INC  ----- */
