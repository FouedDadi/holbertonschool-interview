#!/usr/bin/python3
""" script that reads stdin line by line and computes metrics
"""
import sys

code_dct = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }
file_size = 0
def print_status():
    """print status
    """
    print("File size: {:d}".format(file_size))
    for code in sorted(code_dct.keys()):
        if code_dct[code]:
            print("{}: {:d}".format(code, code_dct[code]))
if __name__ == "__main__":
    count = 1
    try:
        for line in sys.stdin:
            if len(line) >= 3:
                words = line.split()
                code = words[-2]
                size = words[-1]
                if code in code_dct.keys():
                    code_dct[code] += 1
            file_size += int(size)
            if count == 10:
                print_status()
                count = 0
            count += 1
    except KeyboardInterrupt:
        print_status()
        raise
    print_status()
