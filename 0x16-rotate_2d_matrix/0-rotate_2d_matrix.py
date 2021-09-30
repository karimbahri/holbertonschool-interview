#!/usr/bin/python3
"""interview task:
    rotate matrix
"""


def rotate_2d_matrix(matrix):
    """
    rotate_2d_matrix:
        a function that rotate 2d matrix 90 deg
    """
    rev_grid = matrix[0].copy()
    matrix_tmp = matrix.copy()
    matrix_tmp.reverse()
    for i in range(len(matrix_tmp[0])):
        j = 0
        for element in matrix_tmp:
            rev_grid[j] = element[i]

            j += 1
        matrix[i] = rev_grid.copy()
