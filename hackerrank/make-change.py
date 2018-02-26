#!/usr/bin/python

import sys

def make_change(coins, n):
    m = [0] * (n + 1)
    l = len(m)

    m[0] = 1
    for c in coins:
        for j in range(c, l):
            m[j] += m[j - c]
    return m[n]


n,m = raw_input().strip().split(' ')
n,m = [int(n),int(m)]
coins = map(int,raw_input().strip().split(' '))
print make_change(coins, n)

