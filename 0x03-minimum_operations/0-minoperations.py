#!/usr/bin/python3
"""
interview question: minimum operation
"""

def minOperations(n):
    """
    method that calculates the 
    fewest number of operations 
    needed to result in exactly 
    n H characters in the file.
    """
    i = 0
    nb = 2
    while n >= 2:
        while not n % nb:
            i += nb
            n /= nb
        nb += 1
    return i
