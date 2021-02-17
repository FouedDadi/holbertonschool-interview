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
    num_bits = 8
    max_ones = 4
    index = 0
    while index < len(data):
        number = data[index] & (2 ** 7)
        number >>= (num_bits - 1)
        if number == 0:
            index += 1
            continue
        number_of_ones = 0
        while True:
            number = data[index] & (2 ** (7 - number_of_ones))
            number >>= (num_bits - number_of_ones - 1)
            if number == 1:
                number_of_ones += 1
            else:
                break
            if number_of_ones > max_ones:
                return False
        if number_of_ones == 1:
            return False
        index += 1
        if index >= len(data) or index >= (index + number_of_ones - 1):
            return False
        for i in range(index, index + number_of_ones - 1):
            number = data[i]
            number >>= (num_bits - 1)
            if number != 1:
                return False
            number >>= (num_bits - 1)
            if number != 0:
                return False
            index += 1
    return True
