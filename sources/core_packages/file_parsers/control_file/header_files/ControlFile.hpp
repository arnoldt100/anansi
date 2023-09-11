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
#include <boost/algorithm/string.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlFilePickle.h"
#include "ControlFileTraits.h"
#include "MasterControlFileNodeKeys.h"
#include "ControlFileName.h"
#include "BaseInputFile.h"
#include "add_values_to_property_tree.h"
#include "pickle_ControlFile_property_tree.h"
#include "unpickle_to_property_tree.h"
#include "verify_controlfile_keys_are_valid.h"

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
        void writeToDisk_(const std::string my_filename) const
        {
            // Write property tree to XML file
            boost::property_tree::write_xml(my_filename, this->pt_);
            return;
        }

        ControlFileTraits::PICKLETYPE pickle_() const
        {
            ControlFileTraits::PICKLETYPE pobj;

            // Pickle the file name to std::map.
            pobj[std::string("filename")] = this->fileName_();

            pickle_ControlFile_property_tree();

            return pobj; 
        }

        // ====================  MUTATORS      =======================================
        void setFileName_(const std::string my_file_name)
        {
            this->fileName_ = ANANSI::ControlFileName(my_file_name);
            return;
        }

        void readPropertyTree_(boost::property_tree::ptree & pt)
        {
            // Verify all keys in pt are valid keys.
            verify_controlfile_keys_are_valid(this->masterNodeKeys_,pt);

            // Fill in this->pt_ from pt. The pt values come from the control file on disk.
            add_values_to_property_tree(this->masterNodeKeys_,
                                        pt,
                                        std::string(this->defaultValue_),
                                        this->pt_);    
           
            return;
        }

        //! \brief Unpickles "pickle_obj" and reforms the ControlFile's property tree,
        //!        and other data members.
        //!
        //! Iterate through the keys of this->masterNodeKeys. Check if a
        //! matching is found in the pickle_obj, and if a matching key is found
        //! the add key-value pair to boost::property_tree "this->pt_". If the
        //! key is not found then add the key value pair with
        //! "default-null-value" as the key's value.
        void unpickle_(const ControlFileTraits::PICKLETYPE & pickle_obj) 
        {
            this->pt_.clear();

            this->writeToDisk_(std::string("debug.controlFile.before"));

            // Unpickle the filename.
            this->fileName_ = ControlFileName(pickle_obj.at("filename")); 

            this->pt_ = PicklingPolicy:: template unpickle<ControlFileTraits::INTERNALREPRESENTATION,
                                                           ControlFileTraits::PICKLETYPE,
                                                           ControlFileTraits::DEFAULTVALUE
                                                           >(this->masterNodeKeys_,
                                                             pickle_obj);

            this->writeToDisk_(std::string("debug.controlFile.after"));
            return;
        }


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
