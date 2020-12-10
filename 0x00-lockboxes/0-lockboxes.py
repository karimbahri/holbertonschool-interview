#!/usr/bin/python3
"""
solving Lockboxes problem
"""


def canUnlockAll(boxes):
    """
    check if boxes can be unlocked
    """
    length = len(boxes)
    nb = 0

    for i in range(1, length):
        j = 0
        for ls in boxes:
            if i in ls and i != j:
                nb += 1
                break
            j += 1

    if nb == length - 1:
        return True
    return False
