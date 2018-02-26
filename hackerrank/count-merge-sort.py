#!/usr/bin/python

import sys

def countInversions(arr):
    cache = dict()
    l = len(arr)
    inv = 0
    for i, a in reversed(list(enumerate(arr))):
        for b in range(i+1, l):
            if a > arr[b]:
                c = cache.setdefault(a, 0)
                cache[a] = c + 1
                inv += 1
    return inv

if __name__ == "__main__":
    t = int(raw_input().strip())
    for a0 in xrange(t):
        n = int(raw_input().strip())
        arr = map(int, raw_input().strip().split(' '))
        result = countInversions(arr)
        print result

