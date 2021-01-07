#!/usr/bin/python3
"""Minimum Operations method"""
def minOperations(n):
    count = 0
    while (n > 1):
        if (n % 3 == 0):
            n //= 3
        
        elif (n % 5 == 1):
            n -= 1
        else:
            if (n == 2):
                n -= 1
            else:
                n += 1
        count += 1
    return count