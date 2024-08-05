"""Utility module for encapsulation of function dispatching functionality.

"""

import copy

def create_function_dispatcher():
    """Returns a FunctionDispatcher object."""
    return FunctionDispatcher()

class verify_fdisp_and_key:
    """Verifies the zero and first positional parameters are the correct type.

    The 0 positional parameter must be of type FunctionDispatcher.
    The first positional parameter must be of type str. If either 
    are of the wrong type a FunctionDispatcherAPIError is raised.
    """
    def __init__(self,func):
        self.func = func

    def __call__(self,*args,**kargs):

        msg = "arg[0] is not of type FunctionDispatcher"
        if not isinstance(args[0],FunctionDispatcher):
            raise FunctionDispatcherAPIError

        msg = "arg[1] is not of type str"
        if not isinstance(args[1],str) :
            raise FunctionDispatcherAPIError

        self.func(*args,**kargs)

class _verify_callable:
    """Verifies the second positional parameter is the correct type.

    The second  positional parameter must be of a callable type, or 
    a FunctionDispatcherAPIError is raised.

    Args:
        func : A reference to  a callable object.

    Raises:
        FunctionDispatcherAPIError is *func* is isn't a callable type.
    """

    def __init__(self,func):
        self.func = func

    def __call__(self,*args,**kargs):

        msg = "arg[2] is not of type callable"
        if not callable(args[2]) :
            raise FunctionDispatcherAPIError

        self.func(*args,**kargs)

@verify_fdisp_and_key
def execute(a_function_dispatcher,key):
    """For object a_function_dispatcher, executes the function that is associated with key.

    The decorator checks the parameters are of the correct type. 

    Args:
        a_function_dispatcher (FunctionDispatcher) : Stores the callable functions.
        key (str) : A string that selects which function to call.

    Raises:
        FunctionDispatcherAPIError if *a_function_dispatcher* isn't type of FunctionDispatcher.
        FunctionDispatcherAPIError if *key* is not a string.
    """

    a_function_dispatcher.function_reference[key]()

def register_function(a_function_dispatcher,key,ref_to_function):
    """For object a_function_dispatcher, registers function ref_to_function.

    The function *ref_to_function* is registered with value *key*. Note that if
    *key* is already used, an error will be raised. 

    Args:
        a_function_dispatcher (FunctionDispatcher) : The object that will store the registration
        of *ref_to_function* to *key*.
        
        key (str) : The key for *ref_to_function*.
        
        ref_to_function (a callable object) : The object that *key* maps to.

    Raises:
        FunctionDispatcherAPIError if *key* is not a string.
        FunctionDispatcherAPIError if *a_function_dispatcher* isn't type of FunctionDispatcher.
        FunctionDispatcherAPIError if *ref_to_function* isn't callable.
    """
    a_function_dispatcher.function_reference = (ref_to_function,key)

class FunctionDispatcher:
    """A callable class that dispatches function calls."""

    def __init__(self):
        self._functionReference = {}

    @property
    def function_reference(self):
        return self._functionReference

    @function_reference.setter
    def function_reference(self,values):
        """The setter for property function_reference

        Values are appended to the self._functionReference attribute.

        Args:
            values : A list of len 2.
        """

        # Check if values has 2 and only 2 elements.
        if len(values) != 2:
            raise FunctionDispatcherAPIError

        my_func = values[0]
        my_key = values[1]

        # Check if the elements in values are the correct type.
        if not isinstance(my_key,str) :
            raise FunctionDispatcherAPIError

        if not callable(my_func):
            raise FunctionDispatcherAPIError

        # Check if the key is not already used.
        if  my_key in self._functionReference:
            raise DuplicateKeyError

        self._functionReference[my_key] = my_func

class DuplicateKeyError(Exception):
    def __init__(self,a_message=""):
        self._message = a_message 

class FunctionDispatcherAPIError(ValueError):
    def __init__(self,a_message=""):
        self._message = a_message 

