#!/usr/bin/python3
"""
Given a list of non-negative integers representing walls of width 1,
calculate how much water will be retained after it rains.
"""


def rain(walls):
    """
    * walls is a list of non-negative integers.
    * Return: Integer indicating total amount of rainwater retained.
    * Assume that the ends of the list (before index 0 and
    after index walls[-1]) are not walls,
    meaning they will not retain water.
    * If the list is empty return 0.
    """
    if type(walls) is not list or walls is []:
        return 0
    rainwater = 0
    for rain in range(1, len(walls) - 1):
        left = max(walls[:rain])
        right = max(walls[rain + 1:])
        minimum = min(left, right)
        if walls[rain] < minimum:
            rainwater += minimum - walls[rain]
    return rainwater
