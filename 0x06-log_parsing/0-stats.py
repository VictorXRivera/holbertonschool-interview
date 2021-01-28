#!/usr/bin/python3
""" Script that reads stdin line by line and computes metrics."""

import sys

formatString = {"size": 0,
                "lines": 1}

statusCodes = {"200": 0, "301": 0, "400": 0, "401": 0,
               "403": 0, "404": 0, "405": 0, "500": 0}


def printf():
    """Helper function to print string"""
    print("File size: {}".format(formatString["size"]))
    for key in sorted(statusCodes.keys()):
        if statusCodes[key] != 0:
            print("{}: {}".format(key, statusCodes[key]))


def datasize(data):
    """ Count file codes and size"""
    formatString["size"] += int(data[-1])
    if data[-2] in statusCodes:
        statusCodes[data[-2]] += 1


if __name__ == "__main__":
    try:
        for line in sys.stdin:
            try:
                datasize(line.split(" "))
            except:
                pass
            if formatString["lines"] % 10 == 0:
                printf()
            formatString["lines"] += 1
    except KeyboardInterrupt:
        printf()
        raise
    printf()
