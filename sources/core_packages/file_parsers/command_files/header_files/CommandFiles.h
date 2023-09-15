#ifndef ANANSI_CommandFiles_INC
#define ANANSI_CommandFiles_INC
//! \file CommandFiles.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

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
                virtual CommandFilesConcept* clone() const=0;
                virtual void debugWriteToDisk(const std::string filename) const=0;
                virtual void pickleFile() const=0;
                virtual void unPickleFile() const=0;

                // ====================  MUTATORS      =======================================
                virtual void setFileName()=0;
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
                    value_()
                {
                    return;
                };

                CommandFilesModel(const  CommandFilesModel & other) :
                    CommandFilesConcept(other),
                    value_(other.value_)
                {
                    if (this != &other)
                    {
                    }
                };

                CommandFilesModel(CommandFilesModel && other) :
                    CommandFilesConcept(std::move(other)),
                    value_(std::move(other.value_))
                {
                    if (this != &other)
                    {
                    }
                };

                CommandFilesModel(const T & in_value ) : 
                    value_(in_value)
                {
                    return;
                };

                // ====================  OPERATORS     =======================================
                CommandFilesModel& operator=(const CommandFilesModel & other) 
                {
                    if (this != &other)
                    {
                        CommandFilesConcept::operator=(other);
                        this->value_ = other.value;
                    }
                    return *this;
                }

                CommandFilesModel& operator=( CommandFilesModel && other) 
                {
                    if (this != &other)
                    {
                        CommandFilesConcept::operator=(std::move(other));
                        this->value_ = std::move(other.value);
                    }
                    return *this;
                }

                CommandFilesModel* clone() const
                {
                    return new CommandFilesModel(*this);
                }

                // ====================  ACCESSORS     =======================================
                
                // ====================  MUTATORS      =======================================
                void readFile() override
                {
                    this->value.readFile();
                    return;
                }
                T value_;
        };

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::unique_ptr<CommandFilesConcept> valuePtr_;

}; // -----  end of class CommandFiles  -----


}; // namespace ANANSI

#endif // ANANSI_CommandFiles_INC
