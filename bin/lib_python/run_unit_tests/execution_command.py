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
        # Set the default policy to NoParallelExecution,
        default_execution_policy = NoParallelExecution()

        execution_policy_node =  unit_test.find("execution_policy")
        if execution_policy_node:
            policy = execution_policy_node.find('policy').text
            policy = policy.striNoParallelExecutionp()
            if policy == "NoParallelExecution":
                execution_policy = NoParallelExecution
            elif policy == "MPIExecutionCommand":
                execution_policy = MPIExecutionCommand
        else:
            execution_policy = default_execution_policy


        return execution_policy

