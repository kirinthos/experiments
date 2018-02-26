#!/usr/bin/env python

import math

def digitsProduct(product):
    l = []
    i = 9
    while product > 1 and i > 0:
        print(product, i, l)
        if product % i == 0:
            l.append(i)
            product = product // i
        else:
            i = i - 1
    print(product, i, l)
    return sum([x * math.pow(10, i) for i, x in enumerate(l)])

def messageFromBinaryCode(code):
    def s2(s):
        c = 0
        l = len(s)
        for i in range(l):
            if s[l - i - 1] == '1':
                c = c + math.pow(2, i)
        return c
    
    def itern(s, n):
        while s:
            yield s[:n]
            s = s[n:]
    
    bs = itern(code, 8)
    return "".join([chr(s2(a)) for a in bs])

print(digitsProduct(12))
