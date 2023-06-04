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
#include <memory>
#include <string>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"

namespace ANANSI
{

    /*
     * =====================================================================================
     *        Class:  BaseInputFile
     *  Description:  
     * =====================================================================================
     */
    class BaseInputFile
    {
        public:
            // ====================  LIFECYCLE     =======================================

            /*
             *--------------------------------------------------------------------------------------
             *       Class:  BaseInputFile
             *      Method:  BaseInputFile :: BaseInputFile
             * Description:  Constructor
             *
             * Arguments: 
             *
             *--------------------------------------------------------------------------------------
             */
            BaseInputFile (); // constructor

            BaseInputFile ( const BaseInputFile &other ); // copy constructor

            BaseInputFile (BaseInputFile && other); // copy-move constructor

            virtual ~BaseInputFile ()=0; // destructor

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            BaseInputFile& operator= ( const BaseInputFile &other ); /* assignment operator */

            BaseInputFile& operator= ( BaseInputFile && other ); // assignment-move operator
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
