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
    seen = [0]
    if boxes[0] == [] or type(boxes[0]) is not list:
        return False
    for i, box in boxes:
        index.append(i)
        for k in box:
            if k in range(1, len(boxes) - 1) and k not in index and k not in seen:
                seen.append(k)
    return True
