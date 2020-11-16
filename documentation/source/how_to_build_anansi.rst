===================
How to Build Anansi
===================

We first provide an overview of building Anansi. Building Anansi can be
broadly separted into 3 stages. The first stage is to satisfy the
library prerequisites.

The second stage is to set the build runtime environment which consists
of setting critical environmental variables.

The last stage to run the Anansi build commands.

###########################
Library Prerequisites Stage
###########################

The following are the library prerequisites for building Anansi.

-----
CMake
-----

An implementation > 3.16

---
MPI
---
An implementation that supports MPI standard > 3.0.

------------------
C++ and C compiler
------------------
The following compilers are supported:

    * GCC > 9.0


-----
Boost
-----
An implementation > 1.72. The following Boost library components are
required

    * Boost Unit Tests
    * Program Options

------
Sphinx
------
An implementation > 3.1.0


------
Python
------
An implementation > 3.6

###########################################
Setting the Build Runtime Environment Stage
###########################################

------
Step 1
------

The first step is to set the environmental variable **ANANSI_TOP_LEVEL**,
modify your PATH environmental variable to include Anansi's software
package bin dire3ctory, and modify your PYTHONPATH environmental
variable to include Anansi's python packages directory. 

**ANANSI_TOP_LEVEL** is the fully qualified path
the Anansi software package. A utility Bash script,
*set_env_var_anansi.sh*, is provided to perform these tasks.
The script must be sourced while the current working directory is the
Anansi software package top level.

**source ./bin/set_env_var_anansi.sh**

------
Step 2
------

The second step is to set the following primary critical environmental
variables:

* **ANANSI_CMAKE_CXX_COMPILER** - The binary name of the C++ compiler. The 
  binary should be in your bin PATH and is used to compile C++
  MPI programs.

* **ANANSI_CMAKE_CXX_COMPILER** - The binary name of the C compiler. The 
  binary should be in your bin PATH and is used to compile C
  MPI programs.

* **ANANSI_INSTALL_PREFIX** - The fully qualified path to the top level
  directory to where to install the Anansi software package. This path
  must be writable by the user building and installing Anansi.

* **ANANSI_BOOST_TOP_LEVEL** - The fully qualified path to the boost
  software package. For example, the fully qualified path to the boost
  header file *program_options.hpp* is
  *${ANANSI_BOOST_TOP_LEVEL}/include/boost/program_options.hpp*

Sample bash scripts are provided in the *configurations* directory that
are to be sourced to set these primary critical environmental variables.
Copy a configuration to an appropiate name, modify to suit your needs,
then source. Once the file is sourced, other secondary critical
environmental variables are defined.

To check that primary critical environmental variables are defined,
execute the python program named *check_environment_variables.py*.

**check_environment_variables.py \--env-config-file ${ANANSI_TOP_LEVEL}/etc/mandatory_environmental_variables.ini**

The program will print the critical environmental variables and their values.

------
Step 3
------
The last step is to run the command to build Anansi:

**build_anansi_md.sh**

Anansi will be install under the directory *${ANANSI_INSTALL_PREFIX}*.