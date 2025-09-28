# Anansi Environmental Variables {#AnansiEnvironmentalVariables}

## Anansi Core Environmental Variables

`ANANSI_OFF`=0 <br>
A convenience environmental variable for setting a compile '-D' macro to
0\. For `Anansi`, a '-D' compile macro set equal to 'ANANSI_OFF' has the semantics of
disabling.

`ANANSI_ON`=1 <br>
A convenience environmental variable for setting a compile `-D` macro to
1\. For `Anansi`, a `-D` compile macro set equal to `ANANSI_ON` has the semantics of enabling.

`MOUSEION_OFF`=0 <br>
A convenience environmental variable for setting a compile `-D` macro to
0. For the Mouseion library, a '-D' compile macro set equal to `MOUSEION_OFF` has the semantics of disabling.

`MOUSEION_ON`=1 <br>
A convenience environmental variable for setting a compile `-D` macro to
1\. For the Mouseion library, a '-D' compile macro set equal to `MOUSEION_ON` has the semantics of enabling.

`ANANSI_DATA_STORAGE_CPU`=1 <br>
A convenience environmental variable for setting the compile macro `-D ANANSI_DATA_CENTRIC_POLICY` storage
policy macro to 1\. Setting the data storage policy equal to `ANANSI_DATA_STORAGE_CPU`
has the semantics of storing data in a CPU centric manner.

`ANANSI_DATA_STORAGE_GPU`=2 <br>
A convenience environmental variable for setting the compile macro `-D ANANSI_DATA_CENTRIC_POLICY` storage
policy macro to 2\. Setting the data storage policy equal to `ANANSI_DATA_STORAGE_GPU`
has the semantics of storing data in a GPU centric manner.

`ANANSI_LOW_COMPUTE_PRECISION`=1 <br>
A convenience environmental variable for setting the compile macro `-D ANANSI_PRECISION_POLICY`
to 1\. Setting the compute precision policy equal to `ANANSI_LOW_COMPUTE_PRECISION`
has the semantics of computing in a low precision manner.

`ANANSI_MEDIUM_COMPUTE_PRECISION`=2 <br>
A convenience environmental variable for setting the compile macro `-D ANANSI_PRECISION_POLICY`
to 2\. Setting the compute precision policy equal to `ANANSI_MEDIUM_COMPUTE_PRECISION`
has the semantics of computing in a medium precision manner.

`ANANSI_HIGH_COMPUTE_PRECISION`=3 <br>
A convenience environmental variable for setting the compile macro `-D ANANSI_PRECISION_POLICY`
to 3\. Setting the compute precision policy equal to 'ANANSI_HIGH_COMPUTE_PRECISION'
has the semantics of computing in a high precision manner.

`ANANSI_BUILD_DEBUG`="Debug" <br>
A convenience variable for the `CMake` standard configuration Debug.

`ANANSI_BUILD_RELAESE`="Release" <br>
A convenience variable for the `CMake` standard configuration Release.

`ANANSI_BUILD_RELAESE_WITH_DEBUG_INFO`="RelWithDebInfo" <br>
A convenience variable for the `CMake` standard configuration RelWithDebInfo.  

`ANANSI_BUILD_RELAESE_WITH_MIN_SIZE`="MinSizeRel" <br>
A convenience variable for the `CMake` standard configuration MinSizeRel.


## Anansi Target Architecture Environmental Variables

`ANANSI_TOP_LEVEL` :<br>
The file path to the top level of the `Anansi` software package. The default value
of this variable is the user's home directory. It is highly recommended that this
variable be set - do not rely on the default value.

`ANANSI_TARGET_ARCHITECTURE` : <br>
The suffix of the target architecture. This
file corresponds to the file <EM>${ANANSI_TOP_LEVEL}/configurations/${ANANSI_TARGET_ARCHITECTURE}.sh</EM>

When this file is sourced from any working directory, the runtime programming environment for `Anansi` 
shall be fully set up. There are several sample architecture configurations that can serve as
starting points for your machine.

`ANANSI_BUILD_TYPE` : <br>
The CMake build type. This variable can take one of the values Debug, RelWithDebInfo, Release, or MinSizeRel.

`ANANSI_CMAKE_CXX_COMPILER` :<br>
Sets the CMake variable `CMAKE_CXX_COMPILER` via `-D` on the command line.

`ANANSI_CMAKE_C_COMPILER` :<br>
Sets the CMake variable `CMAKE_C_COMPILER` via `-D` on the command line.

`ANANSI_MPICH_DIR` :<br>
Sets the directory file path to the  `MPI` directory. The `MPI`  `bin`, `lib`, `include`,  `etc`
and `share` directories are located at 
<em>${ANANSI_MPICH_DIR}/bin</em>,
<em>${ANANSI_MPICH_DIR}/lib</em>,
<em>${ANANSI_MPICH_DIR}/include</em>,
<em>${ANANSI_MPICH_DIR}/etc</em> and 
<em>${ANANSI_MPICH_DIR}/share</em> respectively.

`ANANSI_MPI_RUN_COMMAND` :<br>
Sets the command to launch `MPI` jobs for your target architecture. This variable is
needed if one plans to run the unit tests.

`ANANSI_INSTALL_PREFIX` :<br>
The file path to install `Anansi` binaries.

`ANANSI_INSTALL_INCLUDE_DIRECTORY` :<br>
The file path to install `Anansi` header files.

`ANANSI_INSTALL_LIB_DIRECTORY` :<br>
The file path to install `Anansi` libraries.

`ANANSI_DATA_CENTRIC_POLICY` :<br>
The data centric computational policy setting of `Anansi`. The variable can take only the following values of
`$ANANSI_DATA_STORAGE_CPU` or `$ANANSI_DATA_STORAGE_GPU`.

`ANANSI_TEST_LOG_BASE_DIRECTORY`:<br>
Sets the directory file path to write the unit tests results and log files. This variable is
needed if one plans to run the unit tests.

`ANANSI_BOOST_TOP_LEVEL`:<br>
Sets the directory file path to the Boost library. The Boost `lib', 'include' , and 'share' directories must be located at
<em>${ANANSI_BOOST_TOP_LEVEL}/boost/lib</em>,
<em>${ANANSI_BOOST_TOP_LEVEL}/boost/include</em>,
<em>${ANANSI_BOOST_TOP_LEVEL}/boost/share</em>.
