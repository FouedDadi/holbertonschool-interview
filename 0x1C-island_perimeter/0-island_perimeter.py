#!/usr/bin/python3
"""island perimeter problem"""


def island_perimeter(grid):
    """function that returns the perimeter of the island described in grid

    Args:
        grid ([type]): [description]

    Returns:
        [type]: [description]
    """
    count = 0
    m = len(grid)
    if m == 0:
        return 0
    n = len(grid[0])
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                count += 4
                if i - 1 >= 0 and grid[i-1][j] == 1:
                    count -= 2
                if j - 1 >= 0 and grid[i][j-1] == 1:
                    count -= 2
    return count
