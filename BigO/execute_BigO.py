

import sys
import os
# sys.path.insert(0, '..')
print('\n\n  dos.getcwd(): \n', os.getcwd())
# from BigO                   import BigO
from modules.dependencies   import *
from modules.CPU_usage      import *
from modules.helpers        import *
from modules.store          import *

from BigO.BigO              import BigO


if __name__ == '__main__':
    cpu_ram_usage   = CPU_RAM_usage()
    n_runs          = 5

    for n in tqdm(range(n_runs)):
        for f in [BigO.O1, BigO.On, BigO.On2, BigO.DifferentTerms, BigO.DropConst, BigO.DropNonDom]:
            try:
                cpu_ram_usage.start()
                FORMATTER = '[%(asctime)s] [%(levelname)8s] : %(platform)s %(architecture)s %(ram)s: %(message)s (%(filename)s:%(lineno)s)'
                log = Helpers.ConfigureLogger('logger.log', LOG_LEVEL=logging.DEBUG, Custom_Filter=Custom_Filter, LOGFORMAT=FORMATTER)
                log.info('Running function: {}'.format(f.__name__))
                value, runtime  = f(n)
                now             = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
                results         = dict(
                    name        = f.__name__,
                    datetime    = now,
                    runtime     = runtime,
                    CPU_RAM     = cpu_ram_usage.device_usage,
                    parameters  = {'params':n},
                    results     = value,
                    operations  = n,
                    language    = "Python"
                )
                cpu_ram_usage.stop()
                cpu_ram_usage.reset_device_usage()
                StoreRun.store_run(results, '../results/{}-{}.json'.format(f.__name__, n))

                    
            except:
                print("Error in function: {}".format(f.__name__))
                cpu_ram_usage.stop()
                cpu_ram_usage.reset_device_usage()
                break

            finally:
                cpu_ram_usage.stop()
                cpu_ram_usage.reset_device_usage()
            
        

            

    
