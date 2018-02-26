#!/usr/bin/python

import sys, os

def main():
    path = os.getcwd()
    os.mkdir('test')
    os.chdir('test')
    print(os.getcwd())
    os.chdir('..')
    print(os.getcwd())



if __name__ == '__main__':
    main()
