# Building Anansi {#BuildingAnansi}

## Overview of building Anansi

We first provide an overview of building *Anansi*.

Building *Anansi* can be broadly separated into 3 stages. The first stage is to
satisfy the library prerequisites.  The second stage is to set the build
runtime environment which consists of setting critical environmental variables.
The last stage to run the *Anansi* build command.

The mandatory library prerequisites 

    Software | Version Requirements
    -------- | --------------------
    CMake    | >= 3.26.4
    Boost    | >= 1.89.0
    MPI      | supports mpi 1, 2 and 3 standard 
    C++,     | supports c++20 
    Python   | >= 3.7

are needed to build *Anansi*. The optional prerequisite

    Software | Version Requirements
    -------- | --------------------
    Doxygen  | >= 1.10.0

is only needed for building documentation.

## Building Library Prerequisites

### Boost Libraries
The *Boost* library, *https://boost.org*, has excellent documentation. For
*Anansi* we install all *Boost* libraries except *mpi*, *coroutine* and
*coroutine2*. This is easily accomplished by using the *B2* app. For
Unix/Linux variants the typical build commands are

    ./bootstrap.sh --prefix=${installation_path} \
               --without-libraries=mpi,coroutine,couroutine2 \
               --with-toolset=gcc
  
where *installation_path* is the top level *Boost* installation directory.

Even though we install nearly all *Boost* libraries, many are superfluous to
the building and running *Anansi*. Therefore if a *Boost* library is failing to
install one may be able to omit it and still be able to run and build *Anansi*.

After installing *Boost*, set the environmental variable *ANANSI_BOOST_TOP_LEVEL*
equal to the installation path of the *Boost* libraries.
*ANANSI_BOOST_TOP_LEVEL* is used by *Anansi* CMake files to locate the *Boost*
libraries.

## Setting Runtime environment

## Running the Build Command 
