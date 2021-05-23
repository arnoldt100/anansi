#ifndef  ControlFileParser_INC
#define  ControlFileParser_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "FileParser.h"
#include "Communicator.h"
#include "RegistryControlFileParserStatus.h"

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
            // ====================  LIFECYCLE     =======================================

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
            ControlFileParser();   // constructor

            ControlFileParser (const ControlFileParser & other)=delete;   // copy constructor

            ControlFileParser (ControlFileParser && other);   // copy-move constructor

            virtual ~ControlFileParser ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            ControlFileParser& operator=( const ControlFileParser &other )=delete; // assignment operator

            ControlFileParser& operator=( ControlFileParser && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  MUTATORS      =======================================
            void _readFile() override;

            void _shareData () override;

            void _setFileName(const std::string file_name) override;

            void _setCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> && a_communicator) override;

            void _parseFile();


            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================
            std::string _fileName;
            std::unique_ptr<COMMUNICATOR::Communicator> _myCommunicator;
            ANANSI::RegistryControlFileParserStatus _myControlFileParserStatus;
            std::string _timestepValue;
            std::string _timestepUnits;

            
            std::map<std::string,std::string> _values;

    }; // -----  end of class ControlFileParser  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ControlFileParser_INC  ----- 
