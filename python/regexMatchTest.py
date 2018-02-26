#!/usr/bin/python

import re

def main():
    exprs = [ '[0-9]+', '[a-z]+', '[0-9a-z]+' ]
    rexes = [ re.compile(x, re.I) for x in exprs ]
    strings = [ 'sldkfjsldkjf', '239847', '928374asdkjLSDKFJSDL', '--$#' ]

    for t in strings:
        print("testing: " + t)
        tests = [ x.match(t) for x in rexes ]
        print(tests)
        if any(tests):
            print("any check succeeds")

if __name__ == '__main__':
    main()
