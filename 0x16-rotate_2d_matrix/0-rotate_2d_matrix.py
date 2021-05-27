#!/usr/bin/python3
"""[rotate a 2D matrix 90 degrees clockwise]"""


def rotate_2d_matrix(matrix):
    """[function to rotate the matrix]

    Args:
        matrix ([type]): [description]
    """

    N = len(matrix[0])
    for i in range(N // 2):
        for j in range(i, N - i - 1):
            temp = matrix[i][j]
            matrix[i][j] = matrix[N - 1 - j][i]
            matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j]
            matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i]
            matrix[j][N - 1 - i] = temp


def printMatrix(matrix):
    """[function to print the rotated matrix]

    Args:
        matrix ([type]): [description]
    """
    N = len(matrix[0])
    for i in range(N):
        print(matrix[i])
