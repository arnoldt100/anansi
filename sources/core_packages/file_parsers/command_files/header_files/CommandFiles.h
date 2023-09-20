#ifndef ANANSI_CommandFiles_INC
#define ANANSI_CommandFiles_INC
//! \file CommandFiles.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <string>
#include <map>
// #include <boost/property_tree/ptree.hpp> // Why do I need this header.
// #include <boost/property_tree/xml_parser.hpp> // Why do I need this header.

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandFileName.h"

namespace ANANSI
{

//! \brief A typerasure for files command input files.
//! 
//! The command files have the general abstraction of 
//! commands in file that have the form (command key, command parameters).
class CommandFiles
{
    public:
        // ====================  LIFECYCLE     =======================================

        CommandFiles ();   // constructor

        CommandFiles (const CommandFiles & other);   // copy constructor

        template<typename T> 
        CommandFiles(T && value) :
            valuePtr_{new CommandFilesModel<T>(std::forward<T>(value))}
        {
            return;
        }

        CommandFiles (CommandFiles && other);   // copy-move constructor

        ~CommandFiles ();  // destructor

        // ====================  ACCESSORS     =======================================
        CommandFiles clone () const;

        // ====================  MUTATORS      =======================================

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

                // ====================  MUTATORS      =======================================
                virtual void setFileName(CommandFileName filename)=0;
                virtual void readCommandFile()=0;

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

                CommandFilesModel(const T & in_value ) : 
                    object_(in_value)
                {
                    return;
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
                    return std::make_unique<CommandFilesModel>(*this);
                }

                // ====================  MUTATORS      =======================================

                void setFileName(CommandFileName filename) override
                {
                    set_file_name(object_,filename);
                    return;
                }
                void readCommandFile() override
                {
                    read_file(object_);
                }

                T object_;
        };

        friend void set_file_name(CommandFiles && command_file, CommandFileName filename)
        {
            command_file.valuePtr_->setFileName(filename);
        }

        friend void set_file_name(CommandFiles & command_file, CommandFileName filename)
        {
            command_file.valuePtr_->setFileName(filename);
        }

        friend void read_file(CommandFiles & command_file)
        {
            command_file.valuePtr_->readCommandFile();
        }

        friend void read_file(CommandFiles && command_file)
        {
            command_file.valuePtr_->readCommandFile();
        }

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::unique_ptr<CommandFilesConcept> valuePtr_;

}; // -----  end of class CommandFiles  -----


}; // namespace ANANSI

#endif // ANANSI_CommandFiles_INC
