#ifndef ANANSI_CommandFiles_INC
#define ANANSI_CommandFiles_INC
//! \file CommandFiles.h
//!
//! Command files are have entries that have the general form
//! key value where each key is unique. The key and value are
//! are strings, the key string contains no blank spaces, and the 
//! value is on 1 line in the file. 
//!
//! The class CommandFiles 
//! is a Type Erasure 

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <string>
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandFileName.h"

namespace ANANSI
{

//! \brief An abstraction for the command input files. 
//! 
//! The command files have the general abstraction of 
//! commands in file that have the form (command key, command parameters).
//! Command files when pickeled return PICKLETYPE_t.
template <typename PICKLETYPE_t=std::map<std::string,std::string>>
class CommandFiles
{
    public:

        // ====================  ALIAS         =======================================
        using PICKLETYPE = PICKLETYPE_t;

        // ====================  LIFECYCLE     =======================================

        CommandFiles() :
            valuePtr_(nullptr)
        {
            return;
        }

        CommandFiles(CommandFiles const & other)
        {
            if (this != &other)
            {
                this->valuePtr_ = other.valuePtr_->clone();
            }
            return;
        }

        template<typename T> 
        CommandFiles(T && value) :
            valuePtr_( new CommandFilesModel<T>(std::forward<T>(value)) )
        {
            return;
        }

        CommandFiles(CommandFiles && other)
        {
            if (this != &other)
            {
                this->valuePtr_ = std::move(other.valuePtr_); 
            }
            return;
        }		// -----  end of method CommandFiles::CommandFiles  -----

        ~CommandFiles()
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        CommandFiles clone () const
        {
            return CommandFiles(*this);
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        CommandFiles& operator= ( const CommandFiles &other )
        {
            if (this != &other)
            {
                this->valuePtr_  = other.valuePtr_->clone();
            }
            return *this;
        } // assignment operator

        CommandFiles& operator= ( CommandFiles && other )
        {
            if (this != &other)
            {
                this->valuePtr_ = std::move(other.valuePtr_); 
            }
            return *this;
        } // assignment-move operator

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
                virtual PICKLETYPE_t pickle() const=0;

                // ====================  MUTATORS      =======================================
                virtual void setFileName(CommandFileName filename)=0;
                virtual void readFile()=0;
                virtual void unPickle(const PICKLETYPE_t & pickled_obj)=0;

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

                CommandFilesModel(const CommandFilesModel & other) :
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

                explicit CommandFilesModel(const T & in_value) : 
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

                PICKLETYPE_t pickle() const override
                {
                    return object_.pickle_file(object_);
                }

                // ====================  MUTATORS      =======================================

                void setFileName(CommandFileName filename) override
                {
                    object_.set_file_name(object_,filename);
                    return;
                }

                void readFile() override
                {
                    object_.read_file(object_);
                    return;
                }

                void unPickle(const PICKLETYPE_t & pickled_obj) override
                {
                    object_.unpickle_file(object_,pickled_obj);
                    return;
                }

                T object_;
        };

        friend void set_CommandFile_filename(CommandFiles && command_file, CommandFileName filename)
        {
            command_file.valuePtr_->setFileName(filename);
            return;
        }

        friend void set_CommandFile_filename(CommandFiles & command_file, CommandFileName filename)
        {
            command_file.valuePtr_->setFileName(filename);
            return;
        }

        friend void read_CommandFile(CommandFiles & command_file)
        {
            command_file.valuePtr_->readFile();
            return;
        }

        friend void read_CommandFile(CommandFiles && command_file)
        {
            command_file.valuePtr_->readFile();
            return;
        }

        friend PICKLETYPE_t pickle_CommandFile(CommandFiles & command_file)
        {
            return command_file.valuePtr_->pickle();
        }

        friend PICKLETYPE_t pickle_CommandFile(CommandFiles && command_file)
        {
            return command_file.valuePtr_->pickle();
        }

        friend void unpickle_CommandFile(CommandFiles & command_file, const PICKLETYPE_t & pickled_file)
        {
            return command_file.valuePtr_->unPickle(pickled_file);
        }

        friend void unpickle_CommandFile(CommandFiles & command_file, const PICKLETYPE_t && pickled_file)
        {
            return command_file.valuePtr_->unPickle(pickled_file);
        }

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::unique_ptr<CommandFilesConcept> valuePtr_;

}; // -----  end of class CommandFiles  -----

template<typename T>
CommandFiles<T>::CommandFilesConcept::~CommandFilesConcept()
{
    return;
}


}; // namespace ANANSI

#endif // ANANSI_CommandFiles_INC
