#!/usr/bin/python3
"""
[summary]
"""


def canUnlockAll(boxes):
    """[summary]

    Args:
        boxes ([type]): [description]
    """
    seen = [0]
    if not boxes[0] or not isinstance(boxes[0], list):
        return False
    for i, box in enumerate(boxes):
        for k in box:
            if k in range(0, len(boxes)) and k is not i and k not in seen:
                seen.append(k)
    return len(seen) == len(boxes)
