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

c = 1


def printSolution(board):
    global c
    c = c + 1
    B = []
    for i in range(N):
        for j in range(N):
            if board[i][j] == 1:
                B.append([i, j])
    print(B)


def isSafe(board, row, col):
    for i in range(col):
        if (board[row][i]):
            return False

    i = row
    j = col
    while i >= 0 and j >= 0:
        if(board[i][j]):
            return False
        i -= 1
        j -= 1

    i = row
    j = col
    while j >= 0 and i < N:
        if(board[i][j]):
            return False
        i = i + 1
        j = j - 1

    return True


def solveNQUtil(board, col):
    if (col == N):
        printSolution(board)
        return True
    result = False
    for i in range(N):
        if (isSafe(board, i, col)):
            board[i][col] = 1
            result = solveNQUtil(board, col + 1) or result
            board[i][col] = 0
    return result


def solveNQ():
    board = [[0 for j in range(N)]for i in range(N)]
    if (solveNQUtil(board, 0) is False):
        print("Solution does not exist")
        return
    return

solveNQ()
