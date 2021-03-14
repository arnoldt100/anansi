#ifndef  ControlFileParser_INC
#define  ControlFileParser_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "FileParser.h"

namespace ANANSI
{

    /*
     * =====================================================================================
     *        Class:  ControlFileParser
     *  Description:  
     * =====================================================================================
     */
    class ControlFileParser : public FileParser
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            /*
             *--------------------------------------------------------------------------------------
             *       Class:  ControlFileParser
             *      Method:  ControlFileParser :: ControlFileParser
             * Description:  Constructor
             *
             * Arguments: 
             *
             *--------------------------------------------------------------------------------------
             */
            ControlFileParser ();   /* constructor      */

            ControlFileParser (const ControlFileParser & other);   /* copy constructor */

            ControlFileParser (ControlFileParser && other);   /* copy-move constructor */

            virtual ~ControlFileParser ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            ControlFileParser& operator= ( const ControlFileParser &other ); /* assignment operator */

            ControlFileParser& operator= ( ControlFileParser && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  MUTATORS      ======================================= */
            void _readFile() override;

            void _shareData () override;
    // -----  end of method ControlFileParser::readFile  ----- 

            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class ControlFileParser  ----- */


}; // namespace ANANSI

#endif   // ----- #ifndef ControlFileParser_INC  ----- 
