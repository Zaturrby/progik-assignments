"""
Fifteen.py

Programmeren IK
Robert-Jan Korteschiel
st. nr. 10399143

Usage: python fifteen.py size

Python implementation of fifteen.c. Uses a one-dimensional approach to
save a few loops, at the cost of some modulo transformations.
"""

import sys


def main():
    # get arguments
    if len(sys.argv) is not 2 or int(sys.argv[1]) < 0 or int(sys.argv[1]) > 9:
        exit("usage: python fifteen.py size")
    size = int(sys.argv[1])
    # init the board
    board = init(size)
    # game loop
    while not won(board, size):
        draw(board, size)
        currTile = int(input("Tile to move: "))
        if currTile >= 0 and currTile < pow(size, 2):
            move(board, currTile, size)
        else:
            return 0
    # draw winning board and victory message
    draw(board, size)
    return 0


def init(size):
    # init board as simple reversed range of numbers
    board = list(reversed(range(pow(size, 2))))
    # reverse 2 and 1 if even
    if not size % 2:
        board[-3], board[-2] = 1, 2
    return board


def draw(board, size):
    # print as matrix
    for i, tile in enumerate(board):
        print(f'{tile:02}', end=" ") if tile else print(f'__', end=" ")
        if not (i + 1) % size:
            print()


def move(board, currTile, size):
    # get the tile positions
    currPos, emptyPos = board.index(currTile), board.index(0)

    # measure straight 2D distance and move if needed
    distance = abs((currPos % size) - (emptyPos % size)) + abs(int(currPos / size) - int(emptyPos / size))
    if distance == 1:
        board[emptyPos], board[currPos] = board[currPos], 0


def won(board, size):
    # check wether array is in ascending order
    for i in range(0, pow(size, 2) - 2):
        if board[i] > board[i + 1] or not board[0]:
            return False
    return True


main()
