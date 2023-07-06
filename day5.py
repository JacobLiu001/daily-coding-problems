def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

def car(pair):
    return pair(lambda x, _: x)

def cdr(pair):
    return pair(lambda _, y: y)

def main():
    assert car(cons(3, 4)) == 3
    assert cdr(cons(3, 4)) == 4

if __name__ == "__main__":
    main()
