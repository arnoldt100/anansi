# Command Files {#CommandFilesConcept}

Many of Anansi input files have a corresponding concrete class which use a TypeErasure design pattern 
to provide a value-based abstraction. The classes used to implement the
TypeErasure design pattern are files

- CommandFiles
- CommandFilesConcept
- CommandFilesModel

The class `CommandFiles` nests classes and `CommandFilesConcept` and
`CommandFilesModel`. The class `CommandFilesModel` inherits from class
`CommandFilesConcept`.

## CommandFilesConcept 

The class `CommandFilesConcept`  implements the interface for the concrete classes.
The primary behaviors the interface `CommandFilesConcept` requires by the concrete classes are

- read the input file from disk
- for a key, get the corresponding input file value
- pickle and unpickle an input file to a class data structure

### Read the Input File from Disk Behaviors

The virtual function 

    virtual void readFile() = 0;

mandates the `CommandFileModel` class impler

