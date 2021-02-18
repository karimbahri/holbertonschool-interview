#!/usr/bin/python3
"""utf-8 validation"""


def validUTF8(data):
    """a method to check for utf8 validation"""
    if type(data) != list:
        return False
    for element in data:
        if type(element) != int:
            return False
        #if <= element <= or <= element <=
        if element > 191:
            return False
    return True
