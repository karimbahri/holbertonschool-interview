#!/usr/bin/python3
"""0-pascal_triangle"""
from math import factorial


def pascal_triangle(n):
    """
    pascal_triangle:
        a function that returns a list of lists of
        integers representing the Pascal’s triangle

        if n <= 0:
            it returns an empty array
    """
    if n <= 0:
        return []

    triangle_p = []
    row = []

    for i in range(n):
        for j in range(i + 1):
            row.append(int(factorial(i) / (factorial(j) * factorial(i-j))))
        triangle_p.append(row)
        row = []
    return triangle_p
