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

        // A templated constructor which accepts "any" CommandFiles
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

        // The concept. 
        class CommandFilesConcept
        {
            public: 
                virtual ~CommandFilesConcept()=0;
                virtual void readFile() = 0;
        };

        // The model.
        template <typename T>
        class CommandFilesModel : public CommandFilesConcept
        {
            public:
                CommandFilesModel(const T & in_value ) : 
                    value_(in_value)
                {
                    return;
                };

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
