#ifndef  ANANSI_ControlFile_INC
#define ANANSI_ControlFile_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <vector>
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlFilePickle.h"
#include "ControlFileTraits.h"
#include "MasterControlFileNodeKeys.h"
#include "ControlFileName.h"
#include "BaseInputFile.h"

namespace ANANSI
{

template<typename PicklingPolicy=ControlFileTraits::PICKLEPOLICY>
class ControlFile : public ANANSI::BaseInputFile<ControlFile<PicklingPolicy>,
                                                 ControlFileTraits>
{
    public:

        // ====================  LIFECYCLE     =======================================

        ControlFile() :   // constructor
            BaseInputFile<ControlFile,ControlFileTraits>(),
            fileName_(),
            masterNodeKeys_(),
            pt_()
        {
            auto keys = this->masterNodeKeys_.allKeysIterator();
            for(; keys.first != keys.second; keys.first++)
            {
                const auto my_node_key = (keys.first)->c_str();
                this->pt_.put(my_node_key,this->defaultValue_);
            }

            return;
        }

        ControlFile( const ControlFile & other) : 
            BaseInputFile<ControlFile,ControlFileTraits>(other),
            fileName_(other.fileName_),
            masterNodeKeys_(other.masterNodeKeys_),
            pt_(other.pt_)
        {
            return;
        } // -----  end of method ControlFile::ControlFile  -----

        ControlFile( ControlFile && other) :
            BaseInputFile<ControlFile,ControlFileTraits>(std::move(other)),
            fileName_(std::move(other.fileName_)),
            masterNodeKeys_(std::move(other.masterNodeKeys_)),
            pt_(std::move(other.pt_))

        {
            return;
        } // -----  end of method ControlFile::ControlFile  -----

        ~ControlFile()
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFile& operator= ( const ControlFile & other )
        {
            if (this != &other)
            {
                BaseInputFile<ControlFile,ControlFileTraits>::operator=(other);
                this->fileName_ = other.fileName_;
                this->masterNodeKeys_ = other.masterNodeKeys_;
                this->pt_ = other.pt_;
            }
            return *this;
        } // assignment operator

        ControlFile& operator= ( ControlFile && other )
        {
            if (this != &other)
            {
                BaseInputFile<ControlFile,ControlFileTraits>::operator=(std::move(other));
                this->fileName_ = std::move(other.fileName_);
                this->masterNodeKeys_ = std::move(other.masterNodeKeys_);
                this->pt_ = std::move(other.pt_);
            }
            return *this;
        } // assignment-move operator

    protected:
        // ====================  ACCESSORS     =======================================
        void writeToDisk_(const std::string my_file_name) const;

        // ====================  MUTATORS      =======================================
        void setFileName_(const std::string my_file_name);

        void readPropertyTree_(boost::property_tree::ptree & pt);

        ControlFileTraits::PICKLETYPE pickle_() const;

        void unpickle_(const ControlFileTraits::PICKLETYPE & pickle_obj);

        // ====================  DATA MEMBERS  =======================================

    private:

        // ====================  MUTATORS      =======================================
        
        // ====================  ACCESSORS     =======================================

        // ====================  DATA MEMBERS  =======================================
        ControlFileName fileName_;
        MasterControlFileNodeKeys masterNodeKeys_;
        boost::property_tree::ptree pt_;
        constexpr static char defaultValue_[] = {"default-null-value"};

    public:
}; // -----  end of class ControlFile  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFile_INC  ----- 
