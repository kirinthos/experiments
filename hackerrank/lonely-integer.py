#!/usr/bin/python

import sys

def lonely_integer(a):
    s = 0
    for b in a:
        s ^= b
    return s

n = int(raw_input().strip())
a = map(int,raw_input().strip().split(' '))
print lonely_integer(a)
