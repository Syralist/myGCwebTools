# -*- coding: UTF-8 -*-
'''
Created on 16.10.2013

@author: thomas
'''

import re

class Coordinate(object):
    '''
    classdocs
    '''       
    __LetterNorth = "N"
    __LetterSouth = "S"
    __LetterWest = "W"
    __LetterEast = "E"
    __RePatternDegrees = "([nNsS])\s*([0-9]{1,3}[.,][0-9]+)[\s°]*([wWeE])\s*([0-9]{1,3}[.,][0-9]+)[\s°]*"

    def __init__(self, Level):
        '''
        Constructor
        '''
        self.__DebugLevel = Level #0=Silent;1=Errors;2=Warnings;3=Info;4=Verbose
        self.__North = 0
        self.__East = 0
        pass
    
    def fromDegrees(self, DegreeString):
        "Set coordinates from degrees in decimal form."
        if self.__DebugLevel >= 4:
            print "Reading coordinates in degreeform."
        pattern = re.compile(self.__RePatternDegrees)
        match = pattern.match(DegreeString)
        if match:
            if self.__DebugLevel >= 3:
                print "found these matches:"
                print match.groups()
                self.__North = float(match.group(2).replace(",","."))
                if match.group(1).lower() == "s":
                    self.__North *= -1
                self.__East = float(match.group(4).replace(",","."))
                if match.group(3).lower() == "w":
                    self.__East *= -1
        else:
            if self.__DebugLevel >=1:
                print "String is not formated properly."
            self.__North = 0
            self.__East = 0
    
    def toDegrees(self):
        self.__NorthString = ""
        if self.__North < 0:
            self.__NorthString += self.__LetterSouth
            self.__NorthString += str(self.__North * -1)
        else:
            self.__NorthString += self.__LetterNorth
            self.__NorthString += str(self.__North)
        
        self.__EastString = ""
        if self.__East < 0:
            self.__EastString += self.__LetterWest
            self.__EastString += str(self.__East * -1) 
        else:
            self.__EastString += self.__LetterEast
            self.__EastString += str(self.__East) 
        print " ".join([self.__NorthString, self.__EastString])
        pass