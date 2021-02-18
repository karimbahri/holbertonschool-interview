#!/usr/bin/python3
"""utf-8 validation"""


def validUTF8(data):
    """a method to check for utf8 validation"""
    try:
        bytes(data).decode('UTF-8')
        return True
    except:
        return False
