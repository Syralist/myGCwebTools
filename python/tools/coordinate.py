'''
Created on 16.10.2013

@author: thomas
'''

class Coordinate(object):
    '''
    classdocs
    '''


    def __init__(self):
        '''
        Constructor
        '''
        self.LetterNorth = "N"
        self.LetterSouth = "S"
        self.LetterWest = "W"
        self.LetterEast = "E"
    
    @classmethod
    def fromDegrees(cls, DegreeString):
        "Set coordinates from degrees in decimal form."
        pass