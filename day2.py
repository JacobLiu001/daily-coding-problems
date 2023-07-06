# Given an array of integers, return a new array such that 
# each element at index i of the new array is the product of 
# all the numbers in the original array except the one at i.

# For example, if our input was [1, 2, 3, 4, 5], 
# the expected output would be [120, 60, 40, 30, 24]. 

# If our input was [3, 2, 1], 
# the expected output would be [2, 3, 6].

# Follow-up: what if you can't use division?

def with_div(l: list[int]) -> list[int]:
    cntZero, idxZero = 0, None
    total_prod = 1
    
    for i, x in enumerate(l):
        if x:
            total_prod *= x
        else:
            cntZero, idxZero = cntZero + 1, i
    
    res = [0] * len(l)
    if cntZero >= 2:
        return res
    
    if cntZero == 1:
        res[idxZero] = total_prod
        return res
    
    for i, x in enumerate(l):
        res[i] = total_prod // x
    
    return res


def without_div(l: list[int]):
    # ans[i] = product(l[:i]) * product(l[i+1:])
    res = [1] * len(l)
    prod = 1

    # res[i] == the product of numbers of index [0:i]
    for i, x in enumerate(l):
        res[i] = prod
        prod *= x

    # now we multiply res[i] by numbers [i+1:]
    # we start at the back of the list for efficiency
    prod = 1
    # Why is there nothing for a reveresed enumerate that is O(1)
    for i in range(len(l) - 1, -1, -1):
        x = l[i]
        res[i] *= prod
        prod *= x
    
    return res

def test_random(reps: int = 100, n: int = 50, low: int = 0, high: int = 100):
    """
    Tests on random data that with_div and without_div agree.
    
    params:
        - reps (int): defualts to 100. Number of datapoints to test
        - n (int): defaults to 50. Size of the array
        - low (int): minimum value generated by the RNG.
        - high (int): max value generated by the RNG.
    """
    from random import randint
    for _ in range(reps):
        l = [randint(low, high) for _ in range(n)]
        a = with_div(l)
        b = without_div(l)
        assert a == b, (a, b, l)
    return

def main():
    test_random()

if __name__ == "__main__":
    main()