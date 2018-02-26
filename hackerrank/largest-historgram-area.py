#!/usr/bin/python

import sys

def largestRectangle(h):
    area = 0
    pstack = list()
    hstack = list()
    for i, b in enumerate(h):
        if len(hstack) == 0 or b > hstack[-1]:
            hstack.append(b)
            pstack.append(i)
        elif b < hstack[-1]:
            lastp = pstack[-1]
            while len(hstack) > 0 and b < hstack[-1]:
                area = max(hstack[-1] * (i - pstack[-1]), area)
                lastp = pstack[-1]
                hstack.pop()
                pstack.pop()
            hstack.append(b)
            pstack.append(lastp)

    while len(hstack) > 0:
        area = max(hstack[-1] * (len(h) - pstack[-1]), area)
        hstack.pop()
        pstack.pop()
    return area
        

if __name__ == "__main__":
    n = int(raw_input().strip())
    h = map(int, raw_input().strip().split(' '))
    result = largestRectangle(h)
    print result

