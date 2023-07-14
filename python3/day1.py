# This problem was recently asked by Google.
#
# Given a list of numbers and a number k, 
# return whether any two numbers from the list add up to k.
# 
# For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
# 
# Bonus: Can you do this in one pass?

# O(N) time and O(N) space!
def day1(l: list, k: int) -> bool:
    encountered: set[int] = set()
    for x in l:
        # Since Python Sets are hash tables, lookups are O(1)
        if (k - x) in encountered:
            return True
        encountered.add(x)
    return False

def main():
    while True:
        l = list(map(int, input().split()))
        k = int(input())
        print(day1(l, k))

if __name__ == "__main__":
    main()
