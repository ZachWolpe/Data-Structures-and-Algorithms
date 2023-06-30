
from modules.dependencies import *


class StoreRun:
    result_map = {
        'name':         str,
        'datetime':     str,
        'runtime':      float,
        'CPU_RAM':      dict,
        'parameters':   dict,
        'results':      object,
        'operations':   int,
        'language':     str
    }


    @staticmethod
    def check_keys(run):
        """
        Check run format.
        """
        for key in StoreRun.result_map.keys():
            if key not in run.keys():
                return False
        return True
    
    @staticmethod
    def check_types(run):
        """
        Check run types.
        """
        for key, value in run.items():
            if not isinstance(value, StoreRun.result_map[key]):
                return False
        return True
  


    @staticmethod
    def store_run(run, path, **kwargs):
        """
        Store run in json format.
        """
        assert isinstance(run, dict),     "Run is not a dictionary."

        for key in kwargs.keys():
            if key not in StoreRun.result_map.keys():
                raise ValueError("Invalid key: {}.".format(key))
            run[key] = kwargs[key]
 
 

        # keys = "['name', 'datetime', 'runtime', 'parameters', 'results', 'operations', 'language']"
        keys = StoreRun.result_map.keys()
        assert StoreRun.check_keys(run),  "Run keys is are incorrectly specified. Keys should include: {}".format(keys)
        assert StoreRun.check_types(run), "Run types are incorrectly specified. Types should include: {}".format(StoreRun.result_map)
        try:
            with open(path, 'w') as f:
                json.dump(run, f, indent=4)
        except Exception as e:
            print(e)
            return False
        return True
    


# Example Usage ================================================##
# dummy_run = {
#     'name':           "dummy_run!",
#     'datetime':       "dd-mm-yyyy hh:mm:ss",
#     'runtime':        0.0,
#     'parameters':     {},
#     'results':        {},
#     'operations':     1,
#     'language':       "Python"
# }
# StoreRun.store_run(dummy_run, 'dummy_run.json')