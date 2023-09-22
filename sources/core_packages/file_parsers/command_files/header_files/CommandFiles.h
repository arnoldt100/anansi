#ifndef ANANSI_CommandFiles_INC
#define ANANSI_CommandFiles_INC
//! \file CommandFiles.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <string>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandFileName.h"

namespace ANANSI
{

namespace
{
    struct DefaultValue {
        static std::string VALUE;
    };
    std::string DefaultValue::VALUE = {"default-null-value"};
    using InternalRepresentation = boost::property_tree::ptree;
    using PICKLETYPE = std::map<std::string,std::string>;
};

class CommandFiles
{
    public:
        // ====================  LIFECYCLE     =======================================

        CommandFiles ();   // constructor

        CommandFiles (const CommandFiles & other);   // copy constructor

        template<typename T> 
        CommandFiles(T && value)
        {
            this->valuePtr_ = std::make_unique<CommandFilesModel<T>>(std::move(value));
        }

        CommandFiles (CommandFiles && other);   // copy-move constructor

        ~CommandFiles ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================
        void read();

        // ====================  OPERATORS     =======================================

        CommandFiles& operator= ( const CommandFiles &other ); // assignment operator

        CommandFiles& operator= ( CommandFiles && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        class CommandFilesConcept
        {
            public: 
                // ====================  LIFECYCLE     =======================================
                CommandFilesConcept() = default;
                CommandFilesConcept(const CommandFilesConcept & other) = default;
                CommandFilesConcept(CommandFilesConcept && other) = default;
                virtual ~CommandFilesConcept()=0;

                // ====================  OPERATORS     =======================================
                CommandFilesConcept& operator=(const CommandFilesConcept & other)=default;
                CommandFilesConcept& operator=(CommandFilesConcept && other)=default;

                // ====================  ACCESSORS     =======================================
                virtual std::unique_ptr<CommandFilesConcept> clone() const=0;
                virtual void debugWriteToDisk(std::string filename) const=0;
                virtual InternalRepresentation getInternalRepresentation () const=0;
                virtual PICKLETYPE pickle() const=0;

                // ====================  MUTATORS      =======================================
                virtual void unPickle(const PICKLETYPE & pickle_obj)=0;
                virtual void setFileName(CommandFileName filename)=0;
                virtual void readFile()=0;
        };

        // The model.
        template <typename T>
        class CommandFilesModel : public CommandFilesConcept
        {
            public:
                // ====================  LIFECYCLE     =======================================
                CommandFilesModel() :
                    CommandFilesConcept(),
                    object_()
                {
                    return;
                };

                CommandFilesModel(const  CommandFilesModel & other) :
                    CommandFilesConcept(other),
                    object_(other.object_)
                {
                    if (this != &other)
                    {
                    }
                };

                CommandFilesModel(CommandFilesModel && other) :
                    CommandFilesConcept(std::move(other)),
                    object_(std::move(other.object_))
                {
                    if (this != &other)
                    {
                    }
                };

                // ====================  OPERATORS     =======================================
                CommandFilesModel& operator=(const CommandFilesModel & other) 
                {
                    if (this != &other)
                    {
                        CommandFilesConcept::operator=(other);
                        this->object_ = other.value;
                    }
                    return *this;
                }

                CommandFilesModel& operator=( CommandFilesModel && other) 
                {
                    if (this != &other)
                    {
                        CommandFilesConcept::operator=(std::move(other));
                        this->object_ = std::move(other.value);
                    }
                    return *this;
                }

                // ====================  ACCESSORS     =======================================
                std::unique_ptr<CommandFilesConcept> clone () const override
                {
                    return std::make_unique<CommandFilesConcept>(*this);
                }

                void  debugWriteToDisk(const std::string filename) const override
                {
                    debug_write_to_disk(this->object_);
                    return;
                }

                InternalRepresentation getInternalRepresentation( ) const override
                {
                    get_internal_representation(this->object_);
                }

                // ====================  MUTATORS      =======================================
                void readFile() override
                {
                    read_file(this->object_);
                    return;
                }

                void setFileName(CommandFileName filename) override
                {
                    set_file_name(this->object_);
                    return;
                }

                void unPickle( const PICKLETYPE & pickle_obj) override
                {
                    unpickle_file(this->object_);
                }

                T object_;
        };

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::unique_ptr<CommandFilesConcept> valuePtr_;

}; // -----  end of class CommandFiles  -----


}; // namespace ANANSI

#endif // ANANSI_CommandFiles_INC
