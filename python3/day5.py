# cons(a, b) constructs a pair,
# and car(pair) and cdr(pair) returns the first and last element of that pair.
#
# For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

# Given this implementation of cons:
def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

# Implement car and cdr.

def car(pair):
    return pair(lambda x, _: x)

def cdr(pair):
    return pair(lambda _, y: y)

def main():
    assert car(cons(3, 4)) == 3
    assert cdr(cons(3, 4)) == 4

if __name__ == "__main__":
    main()
