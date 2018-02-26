#!/usr/bin/python

import sys

def printIt(*args):
    print('called with ' + str(len(args)) + ' arguments: ', args)

def main():
    args = sys.argv[1:]
    printIt(*args)


if __name__ == '__main__':
    main()
