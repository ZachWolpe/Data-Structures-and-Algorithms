
import sys
sys.path.insert(0, '..')
from modules.dependencies   import *
from modules.helpers        import *
from modules.store          import *

class BigO:

    @Helpers.timeit
    @staticmethod
    def O1(n):
        n+n+n
        return True
    
    @Helpers.timeit
    @staticmethod
    def On(n):
        res = []
        for i in range(n):
            res.append(i)
        return True
    
    @Helpers.timeit
    @staticmethod
    def On2(n):
        res = []
        for i in range(n):
            for j in range(n):
                res.append((i,j))
        return True
        
    @Helpers.timeit
    @staticmethod
    def DifferentTerms(a,b=3):
        res = []
        for i in range(a):
            res.append(i)
        for j in range(b):
            res.append(j)
        return True
    
    @Helpers.timeit
    @staticmethod
    def DropConst(n):
        res = []
        for i in range(n):
            res.append(i)
        for j in range(n):
            res.append(j)
        return True
    
    @Helpers.timeit
    @staticmethod
    def DropNonDom(n):
        res = []
        for i in range(n):
            for j in range(n):
                res.append((i,j))
        for k in range(n):
            res.append(k)
        return True
    

