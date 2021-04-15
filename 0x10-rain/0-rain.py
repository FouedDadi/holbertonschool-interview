#!/usr/bin/python3
"""[summary]"""


def rain(walls):
    """[summary]

    Args:
        walls ([type]): [description]

    Returns:
        [type]: [description]
    """
    stack = []
    n = len(walls)
    ans = 0
    for i in range(n):
        while (len(stack) != 0 and (walls[stack[-1]] < walls[i])):
            pop_walls = walls[stack[-1]]
            stack.pop()
            if(len(stack) == 0):
                break
            distance = i - stack[-1] - 1
            min_walls = min(walls[stack[-1]], walls[i]) - pop_walls
            ans += distance * min_walls
        stack.append(i)
    return ans
