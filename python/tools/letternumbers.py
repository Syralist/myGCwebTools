'''
Created on 17.11.2013

@author: Thomas
'''

class LetterNumbers(object):
    '''
    classdocs
    '''
    __String = ''
    __Numbers = []
    __NumbersReverse = []
    __LetterSum = 0
    __LetterSumReverse = 0
    __LetterSumCrossSum = 0
    __LetterSumCrossSumReverse = 0
    __LetterSumCrossSumIter = 0
    __LetterSumCrossSumIterReverse = 0


    def __init__(self, Level):
        '''
        Constructor
        '''
        self.__DebugLevel = Level #0=Silent;1=Errors;2=Warnings;3=Info;4=Verbose
        
    def SetString(self, String):
        self.__String = String
        for l in String:
            n = ord(l) - 96
            if n in range(1, 27):
                self.__Numbers.append(n)
            n = (ord(l) - 96 - 27) * -1
            if n in range(1, 27):
                self.__NumbersReverse.append(n)
                
    def Calculate(self):
        self.__LetterSum = 0
        self.__LetterSumReverse = 0
        for n in self.__Numbers:
            self.__LetterSum += n
        for n in self.__NumbersReverse:
            self.__LetterSumReverse += n
        
        self.__LetterSumCrossSum = sum(map(int,str(self.__LetterSum)))
        self.__LetterSumCrossSumReverse = sum(map(int,str(self.__LetterSumReverse)))
        
        Cond = True
        self.__LetterSumCrossSumIter = sum(map(int,str(self.__LetterSumCrossSum)))
        while Cond:
            self.__LetterSumCrossSumIter = sum(map(int,str(self.__LetterSumCrossSumIter)))
            if self.__LetterSumCrossSumIter < 10:
                Cond = False
        Cond = True
        self.__LetterSumCrossSumIterReverse = sum(map(int,str(self.__LetterSumCrossSumReverse)))
        while Cond:
            self.__LetterSumCrossSumIterReverse = sum(map(int,str(self.__LetterSumCrossSumIterReverse)))
            if self.__LetterSumCrossSumIterReverse < 10:
                Cond = False
        
    
    def Numbers(self, Direction):
        if Direction == 1:
            Nums = self.__Numbers
        elif Direction == -1:
            Nums = self.__NumbersReverse
        ReturnString = ''
        for n in Nums:
            ReturnString += str(n) + ' '
        return ReturnString
        
    def LetterSum(self, Direction):
        if Direction == 1:
            return self.__LetterSum
        elif Direction == -1:
            return self.__LetterSumReverse
    
    def LetterSumCrossSum(self, Direction):
        if Direction == 1:
            return self.__LetterSumCrossSum
        elif Direction == -1:
            return self.__LetterSumCrossSumReverse
        
    def LetterSumCrossSumIter(self, Direction):
        if Direction == 1:
            return self.__LetterSumCrossSumIter
        elif Direction == -1:
            return self.__LetterSumCrossSumIterReverse
        
    
    
    
    
    
    