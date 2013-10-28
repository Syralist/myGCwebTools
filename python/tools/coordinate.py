# -*- coding: UTF-8 -*-
'''
Created on 16.10.2013

@author: thomas
'''

import re
import math

class Coordinate(object):
    '''
    classdocs
    '''       
    __LetterNorth = "N"
    __LetterSouth = "S"
    __LetterWest = "W"
    __LetterEast = "E"
    __RePatternDegrees = "([nNsS])\s*([0-9]{1,3}[.,][0-9]+)[\s°]*([wWeE])\s*([0-9]{1,3}[.,][0-9]+)[\s°]*"
    __RePatternDegreesMinutes = "([nNsS])\s*([0-9]{1,3})[\s°]*([0-9]+[.,][0-9]+)[\s']*([wWeE])\s*([0-9]{1,3})[\s°]*([0-9]+[.,][0-9]+)[\s']*"
    __RePatternDegreesMinutesSeconds = "([nNsS])\s*([0-9]{1,3})[\s°]*([0-9]+)[\s']*([0-9]+[.,][0-9]+)[\s\"]*([eEwW])\s*([0-9]{1,3})[\s°]*([0-9]+)[\s']*([0-9]+[.,][0-9]+)[\s\"]*"

    def __init__(self, Level):
        '''
        Constructor
        '''
        self.__DebugLevel = Level #0=Silent;1=Errors;2=Warnings;3=Info;4=Verbose
        self.__North = 0
        self.__East = 0
        pass
            
    def fromString(self, InputString):
        if self.__DebugLevel >= 4:
            print "Try to read in degree form..."
        pattern = re.compile(self.__RePatternDegrees)
        match = pattern.match(InputString)
        if match:
            #groups: 1=N/S, 2=degree N/S, 3=E/W, 4=degree E/W
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
            if self.__DebugLevel >= 4:
                print "Try to read in degree and minute form..."
            pattern = re.compile(self.__RePatternDegreesMinutes)
            match = pattern.match(InputString)
            if match:
                #groups: 1=N/S, 2=degree N/S, 3=minute N/S, 4=E/W, 5=degree E/W, 6=minute E/W
                if self.__DebugLevel >= 3:
                    print "found these matches:"
                    print match.groups()
                self.__North = float(match.group(2))
                self.__North += float(match.group(3).replace(",","."))/60.0
                if match.group(1).lower() == "s":
                    self.__North *= -1
                self.__East = float(match.group(5))
                self.__East += float(match.group(6).replace(",","."))/60.0
                if match.group(4).lower() == "w":
                    self.__East *= -1
            else:
                if self.__DebugLevel >= 4:
                    print "Try to read in degree, minute and second form..."
                pattern = re.compile(self.__RePatternDegreesMinutesSeconds)
                match = pattern.match(InputString)
                if match:
                    #groups: 1=N/S, 2=degree N/S, 3=minute N/S, 4=second N/S, 5=E/W, 6=degree E/W, 7=minute E/W, 8=second E/W
                    if self.__DebugLevel >= 3:
                        print "found these matches:"
                        print match.groups()
                    self.__North = float(match.group(2))
                    self.__North += float(match.group(3))/60.0
                    self.__North += float(match.group(4).replace(",","."))/60.0/60.0
                    if match.group(1).lower() == "s":
                        self.__North *= -1
                    self.__East = float(match.group(6))
                    self.__East += float(match.group(7))/60.0
                    self.__East += float(match.group(8).replace(",","."))/60.0/60.0
                    if match.group(5).lower() == "w":
                        self.__East *= -1
                else:
                    if self.__DebugLevel >=1:
                        print "String could not be read."
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
        return " ".join([self.__NorthString, self.__EastString])
    
    def toDegreesMinutes(self):
        self.__NorthString = ""
        (decimal, integer) = math.modf(self.__North)
        if self.__North < 0:
            self.__NorthString += self.__LetterSouth
            decimal *= -1
            integer *= -1
        else:
            self.__NorthString += self.__LetterNorth
        self.__NorthString += str(int(integer))
        self.__NorthString += "° "
        self.__NorthString += str(decimal*60.0)
        self.__NorthString += "'"
        
        self.__EastString = ""
        (decimal, integer) = math.modf(self.__East)
        if self.__East < 0:
            self.__EastString += self.__LetterWest
            decimal *= -1
            integer *= -1
        else:
            self.__EastString += self.__LetterEast
        self.__EastString += str(int(integer))
        self.__EastString += "° "
        self.__EastString += str(decimal*60.0)
        self.__EastString += "'"
        return " ".join([self.__NorthString, self.__EastString])
    
    def toDegreesMinutesSeconds(self):
        self.__NorthString = ""
        (decimal, integer) = math.modf(self.__North)
        if self.__North < 0:
            self.__NorthString += self.__LetterSouth
            decimal *= -1
            integer *= -1
        else:
            self.__NorthString += self.__LetterNorth
        (mdecimal, minteger) = math.modf(decimal*60.0)
        self.__NorthString += str(int(integer))
        self.__NorthString += "° "
        self.__NorthString += str(int(minteger))
        self.__NorthString += "'"
        self.__NorthString += str(mdecimal*60.0)
        self.__NorthString += "\""
        
        self.__EastString = ""
        (decimal, integer) = math.modf(self.__East)
        if self.__East < 0:
            self.__EastString += self.__LetterWest
            decimal *= -1
            integer *= -1
        else:
            self.__EastString += self.__LetterEast
        (mdecimal, minteger) = math.modf(decimal*60.0)
        self.__EastString += str(int(integer))
        self.__EastString += "° "
        self.__EastString += str(int(minteger))
        self.__EastString += "'"
        self.__EastString += str(mdecimal*60.0)
        self.__EastString += "\""
        return " ".join([self.__NorthString, self.__EastString])
    
    