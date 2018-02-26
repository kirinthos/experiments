#!/usr/bin/python


import sys

def twoPluses(grid):

if __name__ == "__main__":
    n, m = raw_input().strip().split(' ')
    n, m = [int(n), int(m)]
    grid = []
    grid_i = 0
    for grid_i in xrange(n):
        grid_t = str(raw_input().strip())
        grid.append(grid_t)
    result = twoPluses(grid)
    print result
