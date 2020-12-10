#!/usr/bin/python3
"""
[summary]
"""


def canUnlockAll(boxes):
    """[summary]

    Args:
        boxes ([type]): [description]
    """
    seen = [False] * len(boxes)
    seen[0] = True
    stack = [0]
    while stack:
        node = stack.pop()
        for nei in boxes[node]:
            if not seen[nei]:
                seen[nei] = True
                stack.append(nei)
    return all(seen)