# -*- coding: UTF-8 -*-
'''
Created on 17.10.2013

@author: thomas
'''

from tools import coordinate
from tools import lettermap

if __name__ == '__main__':
    test = coordinate.Coordinate(4)
    print test
    test.fromString("N53°05.227', E008°47.509'")
    print test.toDegrees()
    print test.toDegreesMinutes()
    print test.toDegreesMinutesSeconds()
    pass
    test2 = lettermap.LetterMap(4)
    print test2.LetterToSymbol('ab c', 'Morse')
    print test2.SymbolToLetter('.- -... -.-.', 'Morse')