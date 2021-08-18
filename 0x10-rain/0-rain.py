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
    for index in range(length):
        count = 0
        if walls[index]:
            first_peak = walls[index]
            index += 1
            bottom = walls[index]
            while(walls[index] <= bottom and index < length):
                count += 1
                index += 1
                if walls[index] < bottom:
                    bottom = walls[index]
            depth = min(first_peak, walls[index]) - bottom
            print('depth', depth)
            sum_cube += depth * count
    return sum_cube
