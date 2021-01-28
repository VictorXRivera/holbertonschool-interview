#!/usr/bin/python3

"""
A script that reads stdin line by line and computes metrics
"""

import sys

if __name__ == "__main__":

    number, cout = 0, 0
    fileSize = 0
    Dict = {"200": 0,
            "301": 0,
            "400": 0,
            "401": 0,
            "403": 0,
            "404": 0,
            "405": 0,
            "500": 0}

    def setDict(key):
        if key in Dict.keys():
            Dict[key] += 1
        else:
            pass
    try:
        for line in sys.stdin:
            number += 1
            word = line.split(" ")
            try:
                fileSize += int(word[-1])
                setDict(word[-2])
            except BaseException:
                pass
            if number % 10 == 0:
                print("File size: {}".format(fileSize))
                for i, j in sorted(Dict.items()):
                    if j:
                        print("{}: {}".format(i, j))
        print("File size: {}".format(fileSize))
        for i, j in sorted(Dict.items()):
            if j:
                print("{}: {}".format(i, j))

    except KeyboardInterrupt:
        for i, j in sorted(Dict.items()):
            if j:
                print("{}: {}".format(i, j))
        raise

