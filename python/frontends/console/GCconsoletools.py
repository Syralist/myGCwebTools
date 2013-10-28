# -*- coding: UTF-8 -*-
'''
Created on 17.10.2013

@author: thomas
'''

from tools import coordinate

if __name__ == '__main__':
    test = coordinate.Coordinate(4)
    print test
    test.fromString("s53°9'9.360\" e 8°7'6.9\"")
    print test.toDegrees()
    print test.toDegreesMinutes()
    print test.toDegreesMinutesSeconds()
    pass