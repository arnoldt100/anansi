"""Utility module for encapsulation of function dispatching functionality.

"""

def create_function_dispatcher():
    """Returns a FunctionDispatcher object."""
    return FunctionDispatcher()

class _verify_function_and_key_type:
    """Verifies the zero and first positional parameters are the correct type.

    The 0 positional parameter must be of type FunctionDispatcher.
    The first positional parameter must be of type str. If either 
    are of the wrong type a ValueError error is raised.
    """
    def __init__(self,func):
        self.func = func

    def __call__(self,*args,**kargs):

        msg = "arg[0] is not of type FunctionDispatcher"
        assert isinstance(args[0],FunctionDispatcher), msg 

        msg = "arg[1] is not of type str"
        assert isinstance(args[1],str), msg

        self.func(*args,**kargs)

class _verify_callable:
    """Verifies the second positional parameter is the correct type.

    The second  positional parameter must be of a callable type, or 
    a ValueError error is raised.

    Args:
        func : A reference to  a callable object.

    Raises:
        ValueError is func is isn't a callable type.
    """

    def __init__(self,func):
        self.func = func

    def __call__(self,*args,**kargs):

        msg = "arg[2] is not of type callable"
        assert callable(args[2]), msg 

        self.func(*args,**kargs)

@_verify_function_and_key_type
def execute(a_function_dispatcher,key):
    """For object a_function_dispatcher, executes the function that is associated with key.

    The decorator checks the parameters are of the correct type. 

    Args:
        a_function_dispatcher (FunctionDispatcher) : A callable object.
        key (str) : A string that selects which function to call.

    Raises:
        ValueError if *a_function_dispatcher* isn't type of FunctionDispatcher.
        ValueError if *key* is not a string.
    """
    print (f"""Executing _relocate_documentation for {key}.""")

@_verify_callable
@_verify_function_and_key_type
def register_function(a_function_dispatcher,key,ref_to_function):
    """For object a_function_dispatcher, registers function ref_to_function.

    The function *ref_to_function* is registered with value *key*. Note that if
    *key* is already used, an error will be raised.  The decorators checks the
    parameters are of the correct type. 

    Args:
        a_function_dispatcher (FunctionDispatcher) : The object that will store the registration
        of *ref_to_function* to *key*.
        
        key (str) : The key for *ref_to_function*.

    Raises:
        ValueError if *key* is not a string.
        ValueError if *a_function_dispatcher* isn't type of FunctionDispatcher.
        ValueError if *ref_to_function* isn't callable.
    """
    print("Registered function.")

class FunctionDispatcher:
    """A callable class that dispatches function calls."""

    def __init__(self):
        self._functionReference = {}
