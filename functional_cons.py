"""
cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element
of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:
"""

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

def car(pair):
    def first(a, b):
        return a
    return pair(first)

def cdr(pair):
    def second(a, b):
        return b
    return pair(second)

print car(cons(3,4))
print cdr(cons(3,4))


