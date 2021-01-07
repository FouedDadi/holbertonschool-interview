#!/usr/bin/python3
"""
calculates the fewest number of operations needed to result in exactly n H's
"""


def minOperations(n):
    """
    function minimum operations
    """
    NoO = 0
    d = 2
    if n < d or not isinstance(n, int):
        return 0
    while n > 1:
        while n % d == 0:
            NoO = d + NoO
            n = n / d
        d = d + 1
    return NoO
