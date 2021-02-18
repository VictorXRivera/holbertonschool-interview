#!/usr/bin/python3
"""
Script/Method that determines if a
given data set represents a valid UTF-8 encoding.
Key points:
    Prototype: def validUTF8(data)
    Return: True if data is a valid UTF-8 encoding, else return False
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    The data will be represented by a list of integers
    Each integer represents 1 byte of data, therefore you
    only need to handle the 8 least significant bits of each integer
"""


def validUTF8(data):
    successful_data = 0
    for d in data:
        d = bin(d).replace('0b', '').rjust(8, '0')
        if successful_data != 0:
            successful_data -= 1
            if not d.startswith('10'):
                return False
        elif d[0] == '1':
            successful_data = len(d.split('0')[0]) - 1
    return True
