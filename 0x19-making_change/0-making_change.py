#!/usr/bin/python3
"""
Given a pile of coins of different values,
determine the fewest number of coins needed to meet a given amount `total`.
"""


def makeChange(coins, total):
    """
    Return: fewest number of coins needed to meet `total`.
        * If total is 0 or less, return 0.
        * If total cannot be met by any number of coins you have, return -1.
    - Your solution’s runtime will be evaluated in this task.
    """
    if total <= 0:
        return 0

    temp = total + 1

    matrix = {0: 0}

    for i in range(1, total + 1):
        matrix[i] = temp

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            matrix[i] = min(matrix[current] + 1, matrix[i])

    if matrix[total] == total + 1:
        return -1

    return matrix[total]
