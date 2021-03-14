/*
 * =====================================================================================
 *
 *       Filename:  FileParsers.h
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef  FileParsers_INC
#define  FileParsers_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

    /*
     * =====================================================================================
     *        Class:  FileParsers
     *  Description:  
     * =====================================================================================
     */
    class FileParsers
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            /*
             *--------------------------------------------------------------------------------------
             *       Class:  FileParsers
             *      Method:  FileParsers :: FileParsers
             * Description:  Constructor
             *
             * Arguments: 
             *
             *--------------------------------------------------------------------------------------
             */
            FileParsers (); // constructor

            FileParsers ( const FileParsers &other ); // copy constructor

            FileParsers (FileParsers && other); // copy-move constructor

            virtual ~FileParsers ()=0; // destructor

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */


            //--------------------------------------------------------------------------------------
            //       Class:  FileParsers
            //      Method:  FileParsers :: readFile
            // Description:  Reads the input file.  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            void readFile();
       
             
            //--------------------------------------------------------------------------------------
            //       Class:  FileParsers
            //      Method:  FileParsers :: shareData
            // Description:  Shares the data of file with others in communicator group.
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            void shareData();

            /* ====================  OPERATORS     ======================================= */

            FileParsers& operator= ( const FileParsers &other ); /* assignment operator */

            FileParsers& operator= ( FileParsers && other ); // assignment-move operator
        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            // ====================  MUTATORS      =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  FileParsers
            //      Method:  FileParsers :: readFile
            // Description:  Reads the input file.  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            virtual void _readFile()=0;

            virtual void _shareData()=0;

            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class FileParsers  ----- */


}; // namespace ANANSI

#endif   /* ----- #ifndef FileParsers_INC  ----- */
