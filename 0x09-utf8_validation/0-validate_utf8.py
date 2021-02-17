#!/usr/bin/python3
"""
utf-8 validator
"""


def validUTF8(data):
    """method that determines if a given data set represents a valid UTF-8 encoding

    Returns:
        boolean: returns true if the set of data is UTF-8 valid or false if not
    """
    num_of_byts = 0
    for num in data:
        repres = format(num, '#010b')[-8:]
        if num_of_byts == 0:
            for bit in repres:
                if bit == '0':
                    break
                num_of_byts += 1
            if num_of_byts == 0:
                continue
            if num_of_byts == 1 or num_of_byts > 4:
                return False
        else:
            if (repres[0] != '1' and repres[1] != '0'):
                return False
        num_of_byts = num_of_byts - 1
    if not num_of_byts:
        return True
    else:
        return False
