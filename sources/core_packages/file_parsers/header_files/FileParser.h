/*
 * =====================================================================================
 *
 *       Filename:  FileParser.h
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef  FileParser_INC
#define  FileParser_INC

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
     *        Class:  FileParser
     *  Description:  
     * =====================================================================================
     */
    class FileParser
    {
        public:
            // ====================  LIFECYCLE     =======================================

            /*
             *--------------------------------------------------------------------------------------
             *       Class:  FileParser
             *      Method:  FileParser :: FileParser
             * Description:  Constructor
             *
             * Arguments: 
             *
             *--------------------------------------------------------------------------------------
             */
            FileParser (); // constructor

            FileParser ( const FileParser &other ); // copy constructor

            FileParser (FileParser && other); // copy-move constructor

            virtual ~FileParser ()=0; // destructor

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */


            //--------------------------------------------------------------------------------------
            //       Class:  FileParser
            //      Method:  FileParser :: readFile
            // Description:  Reads the input file.  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            void readFile();
       
             
            //--------------------------------------------------------------------------------------
            //       Class:  FileParser
            //      Method:  FileParser :: shareData
            // Description:  Shares the data of file with others in communicator group.
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            void shareData();

            //--------------------------------------------------------------------------------------
            //       Class:  FileParser
            //      Method:  FileParser :: setFileName
            // Description:  Sets the file name of the parser.
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            void setFileName(const std::string file_name);

            //--------------------------------------------------------------------------------------
            //       Class:  FileParser
            //      Method:  FileParser :: setCommunicator
            // Description:  Sets the communicator of the FileParser.
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            void setCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> && a_communicator);

            /* ====================  OPERATORS     ======================================= */

            FileParser& operator= ( const FileParser &other ); /* assignment operator */

            FileParser& operator= ( FileParser && other ); // assignment-move operator
        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            // ====================  MUTATORS      =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  FileParser
            //      Method:  FileParser :: readFile
            // Description:  Reads the input file.  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            virtual void _readFile()=0;

            virtual void _shareData()=0;

            virtual void _setFileName(const std::string file_name)=0;

            virtual void _setCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> && a_communicator)=0;

            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class FileParser  ----- */


}; // namespace ANANSI

#endif   /* ----- #ifndef FileParser_INC  ----- */
