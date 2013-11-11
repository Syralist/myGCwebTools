'''
Created on 11.11.2013

@author: Thomas
'''

class LetterMap(object):
    '''
    classdocs
    '''
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

    def __init__(self, Level):
        '''
        Constructor
        '''
        self.__DebugLevel = Level #0=Silent;1=Errors;2=Warnings;3=Info;4=Verbose
        print self.__MorseCode['a']
        pass