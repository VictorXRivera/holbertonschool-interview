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
    key_chain = [0]
    for key in key_chain:
        for hidden_key in boxes[key]:
            if hidden_key not in key_chain and hidden_key < len(boxes):
                key_chain.append(hidden_key)
    if len(key_chain) == len(boxes):
        return True
    return False

