#! /usr/bin/env python3
## @package execution_command

# System imports
import abc

class BaseExecutionCommand(abc.ABC):

    @property
    @abc.abstractmethod
    def command(self):
        return;

class NoParallelExecution(BaseExecutionCommand):
    def __init__(self,binary_name):
        self._binaryName = binary_name
        self._myCommand = f"""{self._binaryName}"""

    @property
    def command(self):
        return self._myCommand;

class MPIExecutionCommand(BaseExecutionCommand):

    def __init__(self,binary_name,nm_procs):
        self._numberOfProcessors = nm_procs
        self._binaryName = binary_name
        self._myCommand = f""" mpirun -np {self._numberOfProcessors} {self._binaryName} """

    @property
    def command(self):
        return self._myCommand;


