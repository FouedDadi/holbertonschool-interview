#!/usr/bin/python3
"""[The N queens puzzle solution]"""
import sys
n = sys.argv[1]


def under_attack(col, queens):
    """[check if a queen is under attack]

    Args:
        col ([type]): [description]
        queens ([type]): [description]

    Returns:
        [type]: [description]
    """
    return col in queens or any(abs(col - x) == len(queens) - i
                                for i, x in enumerate(queens))


def solve(n):
    """[summary]

    Args:
        n ([type]): [description]

    Returns:
        [type]: [description]
    """
    if not len(sys.argv) == 2:
        print("Usage: nqueens N")
        exit(1)
    if not (sys.argv[1]).isdigit():
        print("N must be a number")
        exit(1)
    n = int(sys.argv[1])
    if n < 4:
        print("N must be at least 4")
        exit(1)
    solutions = [[]]
    for row in range(n):
        solutions = [solution+[i]
                     for solution in solutions
                     for i in range(n)
                     if not under_attack(i, solution)]
    return solutions
for answer in solve(n):
    print(list(enumerate(answer)))
