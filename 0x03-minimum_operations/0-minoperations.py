#!/usr/bin/python3
"""Minimum Operations method"""


def min_divider(n):
    """Helper method that returns minimum divider of n int"""
    for divider in range(2, n+1):
        if n % divider == 0:
            return divider


def minOperations(n):
    if not isinstance(n, int):
        return 0
    result = 0
    while n > 1:
        result += min_divider(n)
        n = int(n / min_divider(n))
    return result
