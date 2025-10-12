# Anansi's Command Design Pattern {#CommandDesignPattern}
Molecular dynamics algorithms can be viewed as a set of sequenceable and
composable tasks, and correspondingly, Anansi's design is task-themed. To
facilitate a task themed design, Anansi makes extensive use of the Command
design pattern [3]. In Anansi, the use of the terms task and command are
interchangeable.

The Command UML diagram is depicted below:

![UMLCommandDesignPattern](command_design_pattern.png)

Anansi uses the command design pattern combined with a TypeErasure and
traditional hierarchical inheritances. These design elements will be explained
in the context of the task of reading Anansi's master control file. The master
control file contains simulation parameters like time-step size, restart save
frequency, etc.

At a high level, Anansi's decomposes reading the control file into 2
algorithmic tasks: (1) A single MPI task reading the control file
data/information and (2) broadcasting the data/information to the remaining MPI
tasks. These 2 commands are aggregated together to form a macro command. 

Let us start by discussing the Anansi's task/command design structure within
the context of the step (1) algorithmic task of reading the control file.

Anansi defines the abstract base class `AnansiTask`. `AnansiTask` employs the
non-virtual interface pattern - interfaces are non-virtual and public, while
the implementations are nonpublic and virtual. `AnansiTask` should contain no
data members - it sole purpose is serving as an interface class. All concrete
Anansi tasks inherit from `AnansiTask`, and `AnansiTask` is the foundational
class for all concrete Anansi tasks.

Every algorithmic task has a corresponding parent task class which inherits from
`AnansiTask`. The parent task class is an abstract base class that doesn't
implement/override any virtual methods in `AnansiTask`. The parent task class
only implements the default constructor, copy constructor, assignment operator,
and virtual destructor are implemented. The parent task classes should contain
no data members. The parent task class purpose is to facilitate implementing
a generic abstract factory of related tasks. This will be later explained in
the Anansi's section on task factory design patterns. The parent task class 
for ste (1) is class `ControlFileTask`.

Finally, the last derived class of `AnansiTask` is the concrete implementation
the command. The concrete command implementation is an instance of the
templated class `GenericMDTask` which inherits from the parent task class.
`GenericMDTask` first template is is a policy template parameter that
corresponds to the receiver of the command. The second template is reserved for
future, defaults to class `DefaukltFunctorImpl` and is currently not used. The
template parameter Receiver will be explained later is the section on Anansi's
section on receiver design patterns. 

A UML diagram of the `AnansisTask`, the parent class, and concrete command class
is depicted below:









