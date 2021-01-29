#!/usr/bin/python3

"""
Script that reads stdin line by line and displays metrics.
Example:
    File size: <total size>
    <status code>: <number>
"""

import sys


def log_parser():
    """Log parsing function"""
    file_size = 0
    iterator = 0
    status_codes = {'200', '301', '400', '401', '403', '404', '405', '500'}
    stat_codes_dict = {'200': 0, '301': 0,
                       '400': 0, '401': 0,
                       '403': 0, '404': 0,
                       '405': 0, '500': 0}

    try:
        for line in sys.stdin:
            newlines = line.split(" ")
            if len(newlines) > 2:
                stat_code = newlines[-2]
                f_size = newlines[-1]
                if stat_code in status_codes:
                    stat_codes_dict[stat_code] += 1
                file_size += int(f_size)
                iterator += 1

            if iterator == 10:
                print("File size: {:d}".format(file_size))
                for k, v in sorted(stat_codes_dict.items()):
                    if v != 0:
                        print("{}: {:d}".format(k, v))
                    iterator = 0

    except KeyboardInterrupt:
        raise
    finally:
        print("File size: {}".format(file_size))
        for k, v in sorted(stat_codes_dict.items()):
            if v != 0:
                print("{}: {}".format(k, v))

if __name__ == "__main__":
    log_parser()
