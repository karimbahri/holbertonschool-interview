#!/usr/bin/python3
"""rain"""


def rain(walls):
    """rain function
        take walls(list) as argument
        calculate the sum of of square unit of water
    """
    if not walls:
        return 0

    sum_cube = 0
    length = len(walls) - 1
    for index in range(1, length):
        count = 0
        if walls[index]:
            first_peak = walls[index]
            index += 1
            while(walls[index] == 0 and index < length):
                count += 1
                index += 1
            sum_cube += min(first_peak, walls[index]) * count
    return sum_cube
