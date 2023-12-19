#! /usr/bin/env python3
## @package execution_command

# System imports
import abc

class BaseExecutionCommand(abc.ABC):

    @abc.abstractmethod
    def command(self,binary_name,args):
        return;

class NoParallelExecution(BaseExecutionCommand):
    def __init__(self):
        self._myCommand = "{my_binary_name} {my_args}"

    def command(self,binary_name,args=None):
        if args == None:
            args = " "
        return self._myCommand.format(my_binary_name=binary_name,
                                      my_args=args);

class MPIExecutionCommand(BaseExecutionCommand):

    def __init__(self,nm_procs):
        import os
        self._numberOfProcessors = nm_procs
        mpiruncommand = os.getenv("ANANSI_MPI_RUN_COMMAND")
        self._myCommand = mpiruncommand + " {my_nm_mpi_threads} {my_binary_name} {my_args}"

    def command(self,binary_name,args=None):
        if args == None:
            args = " "       
        return self._myCommand.format(my_nm_mpi_threads=self._numberOfProcessors,
                                      my_binary_name=binary_name,
                                      my_args=args);

class ExecutionPolicyFactory:
    def __init__(self):
        pass

    @classmethod
    def create(cls,unit_test):
        parallel_test = unit_test.find('parallel')
        run_policy = NoParallelExecution()
        if parallel_test:
                parallel_type = parallel_test.find('type').text
                parallel_type = parallel_type.strip()
                if parallel_type == "mpi":
                    nm_mpi_threads = (parallel_test.find('nm_mpi_threads').text).strip()
                    run_policy = MPIExecutionCommand(nm_mpi_threads)
        else:
            run_policy = NoParallelExecution()
        return run_policy

