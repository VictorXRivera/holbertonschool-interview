#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes.

Write a method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Details:
    boxes is a list of lists
    A key with the same number as a box opens that box
    You can assume all keys will be positive integers
    There can be keys that do not have boxes
    The first box boxes[0] is unlocked
    Return True if all boxes can be opened, else return False
    """
    k_chain = [0]
    for key in k_chain:
        for h_key in boxes[key]:
            if h_key not in k_chain and h_key < len(boxes):
                k_chain.append(h_key)
    if len(k_chain) == len(boxes):
        return True
    return False
