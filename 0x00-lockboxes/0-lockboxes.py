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

    if length < 2:
        return True

    for i in range(length):
        for ls in boxes:
            if i in ls and i not in boxes[i]:
                nb += 1
                break

    if nb == length - 1:
        return True
    return False
