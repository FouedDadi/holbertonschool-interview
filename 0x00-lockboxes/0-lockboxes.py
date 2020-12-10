#!/usr/bin/python3
"""
[summary]
"""
def canUnlockAll(boxes):
    """[summary]

    Args:
        boxes ([type]): [description]
    """
    index = [0]
    keys = [0]
    for i, box in boxes:
        index.append(i)
        for k in box:
            if k in range(1, len(boxes) - 1):
                keys.append(k)
            if len(keys) <= len(index) or k[i] != i:
                return False
    return True
