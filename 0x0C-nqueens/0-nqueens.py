#!/usr/bin/python3
import sys
"""N Queens challenge"""

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
if not sys.argv[1].isdigit():
    print("N must be a number")
    exit(1)
if int(sys.argv[1]) < 4:
    print("N must be at least 4")
    exit(1)
N = int(sys.argv[1])
board = [[0 for row in range(N)]for column in range(N)]
print(board)
