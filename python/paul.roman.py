#!/usr/bin/python

import math
char = "IVXLCDMxx"
f = ["", "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix"]
def rom(x):
    if x > 0:
        d = int(math.floor(math.log10(x)))
        k = int(x / math.pow(10, d))
        return f[k].replace("i", char[2*d]).replace("v", char[2*d+1]).replace("x", char[2*d+2]) + rom(x - k * math.pow(10, d))
    return ""

print(rom(1024))
print(rom(888))
print(rom(169))
print(rom(999))
print(rom(448))
