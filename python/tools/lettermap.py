'''
Created on 11.11.2013

@author: Thomas
'''

class LetterMap(object):
    '''
    classdocs
    '''
    __Tables = {}
    __TablesReverse = {} 
    __MorseCode = {'a':'.-',
                   'b':'-...',
                   'c':'-.-.',
                   'd':'-..',
                   'e':'.',
                   'f':'..-.',
                   'g':'--.',
                   'h':'....',
                   'i':'..',
                   'j':'.---',
                   'k':'-.-',
                   'l':'.-..',
                   'm':'--',
                   'n':'-.',
                   'o':'---',
                   'p':'.--.',
                   'q':'--.-',
                   'r':'.-.',
                   's':'...',
                   't':'-',
                   'u':'..-',
                   'v':'...-',
                   'w':'.--',
                   'x':'-..-',
                   'y':'-.--',
                   'z':'--..'}
    __MorseCodeReverse = {}

    def __init__(self, Level):
        '''
        Constructor
        '''
        self.__DebugLevel = Level #0=Silent;1=Errors;2=Warnings;3=Info;4=Verbose
        for k, v in self.__MorseCode.iteritems():
            self.__MorseCodeReverse[v] = k
        self.__Tables['Morse'] = self.__MorseCode
        self.__TablesReverse['Morse'] = self.__MorseCodeReverse
        #print self.__MorseCodeReverse['.-']
        pass
    
    def LetterToSymbol(self,Letters,Table):
        ReturnString = []
        try:
            self.__Tables[Table].keys()
        except:
            return "Table not found."
        for l in Letters:
            try:
                ReturnString.append(self.__Tables[Table][l])
            except KeyError:
                ReturnString.append(' ')
        return ' '.join(ReturnString)
        pass
    
    def SymbolToLetter(self,Symbols,Table):
        ReturnString = []
        try:
            self.__TablesReverse[Table].keys()
        except:
            return "Table not found."
        for l in Symbols.split(' '):
            try:
                ReturnString.append(self.__TablesReverse[Table][l])
            except KeyError:
                ReturnString.append(' ')
        return ' '.join(ReturnString)
        pass
    
    
    
    
    
    
    