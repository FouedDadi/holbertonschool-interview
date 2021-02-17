#!/usr/bin/python3
"""
utf-8 validator
"""


def validUTF8(data):
    """method that determines if a given data set represents a valid UTF-8 encoding

    Returns:
        boolean: returns true if the set of data is UTF-8 valid or false if not
    """
    if not data or len(data) == 0:
        return True
    suc_10 = 0
    for b in data:
        b = bin(b).replace('0b', '').rjust(8, '0')
        if suc_10 != 0:
            suc_10 -= 1
            if not b.startswith('10'):
                return False
        elif b[0] == '1':
                suc_10 = len(b.split('0')[0]) - 1
    return True
