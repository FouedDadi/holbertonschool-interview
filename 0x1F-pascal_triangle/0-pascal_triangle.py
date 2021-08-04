#!/usr/bin/python3
"""function representing the Pascal’s triangle of n"""


def pascal_triangle(n):
    """[def pascal_triangle(n)]

    Args:
        n ([type]): [description]

    Returns:
        [type]: [description]
    """
    triangle = []
    for row_num in range(n):
        row = [None for _ in range(row_num + 1)]
        row[0], row[-1] = 1, 1
        for j in range(1, len(row) - 1):
            row[j] = triangle[row_num - 1][j - 1] + triangle[row_num - 1][j]
        triangle.append(row)
    return triangle
