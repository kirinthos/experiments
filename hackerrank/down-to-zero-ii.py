#!/usr/bin/python

import sys


Q = int(raw_input().strip())
ns = list()
for a0 in xrange(Q):
    ns.append(int(raw_input().strip()))

MAX = max(ns)
print(MAX)

l = [0] + [MAX] * (MAX + 1)
for i in range(MAX - 1):
    l[i + 1] = min(l[i + 1], l[i] + 1)
    for j in range(1, i + 1):
        if i * j > MAX:
            break
        l[i * j] = min(l[i * j], l[i] + 1)

for n in ns:
    print(l[n])
