#!/usr/bin/python3
"""utf-8 validation"""


def validUTF8(data):
    """a method to check for utf8 validation"""
    if type(data) != list or not len(data):
        return False
    for element in data:
        if type(element) != int:
            return False
        if element > 127:
            return False
    return True
