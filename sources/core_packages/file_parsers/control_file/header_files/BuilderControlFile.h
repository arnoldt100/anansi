#ifndef  ANANSI_BuilderControlFile_INC
#define  ANANSI_BuilderControlFile_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "BuilderFile.h"
#include "ControlFile.hpp"

namespace ANANSI
{

    class BuilderControlFile
    {
        public:

            // ====================  LIFECYCLE     =======================================
            using Filetype_t = ANANSI::ControlFile<ControlFileTraits::PICKLEPOLICY>;

            // ====================  LIFECYCLE     =======================================

            BuilderControlFile ();   // constructor

            BuilderControlFile (const BuilderControlFile & other);   // copy constructor

            BuilderControlFile (BuilderControlFile && other);   // copy-move constructor

            ~BuilderControlFile ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            BuilderControlFile& operator= ( const BuilderControlFile &other ); // assignment operator

            BuilderControlFile& operator= ( BuilderControlFile && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  MUTATORS      =======================================

            // ====================  DATA MEMBERS  =======================================
            std::shared_ptr<Filetype_t> myFile_;

    }; // -----  end of class BuilderControlFile  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_BuilderControlFile_INC  ----- 
