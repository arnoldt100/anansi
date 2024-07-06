# Command Files {#CommandFilesConcept}

Many of Anansi input files have a corresponding concrete class which use a TypeErasure design
pattern to provide a value-based abstraction. The classes used to implement the
TypeErasure design pattern are files

- CommandFiles
- CommandFilesConcept
- CommandFilesModel

The class `CommandFiles` nests classes and `CommandFilesConcept` and
`CommandFilesModel`. The class `CommandFilesModel` inherits from class
`CommandFilesConcept`.

## CommandFilesConcept

The class `CommandFilesConcept`  implements the semantics for the concrete input files. The primary
behaviors the interface `CommandFilesConcept` requires of the concrete input files are

- read the input file from disk
- for a key, get the corresponding input file value

### Read the Input File from Disk Behaviors

The virtual method 

    virtual void CommandFilesConcept::readFile() = 0;

sets the semantics for the corresponding concrete input files that implement the
"Read the Input File from Disk Behavior".

The expected behavior is that after a CommandFiles class is instantiated,
one can read the input file by invoking

    friend std::string CommandFiles::read_CommandFile(CommandFiles & command_file)

where `command_file` is a TypeErasure class.

### Get Input File Value with Respect to the Corresponding Key Behavior

The virtual method 

    virtual std::string CommandFilesConcept::getValue(const std::string &key)

The expected behavior is that after the input files are read from disk
and a TypeErasure CommandFiles class is instantiated, one
can obtain data/values by invoking 

    friend std::string CommandFiles::get_value_CommandFile(CommandFiles const & command_file,const std::string &key)

where `command_file` is the TypeErasure class and `key` is the tag for the corresponding value that
is returned as a `std::string`.

## CommandFilesModel

The class `CommandFilesModel` is the one and only implementation of the `CommandFilesConcept` class.
`CommandFilesModel` inherits form `CommandFilesConcept` and must implement `CommandFilesConcept`
pure virtual methods.

## CommandFiles

The class `CommandFiles` wraps the `CommandFilesConcept` and `CommandFilesModel` external hierarchies.
Note that `CommandFiles` is a templated class

    template <typename PICKLETYPE_t = std::map<std::string, std::string>> class CommandFiles;

where the template parameter `PICKLETYPE_t` is the class type for the pickled (serialization) of
the `CommandFiles` concrete input files. The CommandFiles constructor is a templated constructor

    template <typename T> CommandFiles(T &&value);

where the argument `T` is any `CommandFiles` concrete input file that implements the
`CommandFilesConcept` semantics. We store the concrete class in the
member attribute `valuePtr_` as a pointer to the `CommandFilesConcept`

    std::unique_ptr<CommandFilesConcept> valuePtr_;

Lastly `CommandFiles` provides hidden friends `CommandFiles::get_value_CommandFile`,
`CommandFiles::read_CommandFile`, etc.



