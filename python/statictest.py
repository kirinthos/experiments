#!/usr/bin/python

def static_var(**kwargs):
    def decorator(function):
        for k in kwargs:
            setattr(function, k, kwargs[k])
        return function
    return decorator

@static_var(counter=0)
def yeah():
    yeah.counter += 1
    print (yeah.counter)

def main():
    for x in range(20):
        yeah()

if __name__ == '__main__':
    main()
