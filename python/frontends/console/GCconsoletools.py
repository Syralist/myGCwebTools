# -*- coding: UTF-8 -*-
'''
Created on 17.10.2013

@author: thomas
'''

from tools import coordinate

if __name__ == '__main__':
    test = coordinate.Coordinate(4)
    print test
    test.fromDegrees("s53,9°e 8.7")
    test.toDegrees()
    pass