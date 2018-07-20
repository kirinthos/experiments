#!/usr/bin/env python

def p(**kwargs):
    for v in kwargs:
        print(v, kwargs[v])


if __name__ == '__main__':
    t = { 'one': 1, 'two': 2, 'three': ('a', 'tuple') }
    p(**t)
