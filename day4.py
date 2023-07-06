def get_first_missing_positive(l: list[int]) -> int:
    # N.B.: Modifies l in-place
    n = len(l)
    
    # We simply don't care about non-positive values
    # Also the answer must be one of 
    # {1, 2, 3, ..., n+1} (They can't all be present)
    # So we can set all don't-cares to (n+1). (Larger values also work)
    for i, x in enumerate(l):
        if x <= 0:
            l[i] = n + 1

    # We use the sign bit of each element of the list as a bitmap.
    # l[i] > 0  <=>  i is not present
    # l[i] < 0  <=>  i is present
    # There are some off-by-one corrections 
    # because we are studying positive integers (which are 1-indexed).
    for x in l:
        x = abs(x)
        if x >= 1 and x <= n:
            if l[x-1] > 0:
                l[x-1] *= -1
    
    # The first positive term is the missing integer.
    # If all are present then (n+1) must be missing.
    for i, x in enumerate(l):
        if x > 0:
            return i + 1
    return n + 1

def main():
    while True:
        l = list(map(int, input().split()))
        print(get_first_missing_positive(l))

if __name__ == "__main__":
    main()