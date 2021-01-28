#!/usr/bin/python3
import sys

if __name__ == "__main__":
    code_dct = {"200": 0,
                "301": 0,
                "400": 0,
                "401": 0,
                "403": 0,
                "404": 0,
                "405": 0,
                "500": 0}
    count = 0
    file_size = 0
    try:
        for line in sys.stdin:
            if len(line) > 2:
                words = line.split()
                code = words[-2]
                if code in code_dct.keys():
                    code_dct[code] += 1
            count += 1
            if count == 10:
                file_size += int(words[-1])
                print("file size = {}".format(file_size))
                for code in sorted(code_dct):
                    if code_dct[code] != 0:
                        print("{}: {}".format(code, code_dct[code]))
                count = 0
    except KeyboardInterrupt:
        print("file size = {}".format(file_size))
        for code in sorted(code_dct):
            if code_dct[code] != 0:
                print("{}: {}".format(code, code_dct[code]))
        raise
    print("file size = {}".format(file_size))
    for code in sorted(code_dct):
        if code_dct[code] != 0:
            print("{}: {}".format(code, code_dct[code]))