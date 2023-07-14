def count_decodings(encoded: str) -> int:
    # dp[i] === the number of ways to decode s[:i]
    dp = [0] * (1 + len(encoded))
    def in_range(substr: str) -> bool:
        if substr.startswith("0"):
            return False  # Assume leading zeros are significant.
        x = int(substr)
        return (1 <= x) and (x <= 26)

    dp[0] = 1

    for i in range(1, len(encoded) + 1):
        if encoded[i-1] != '0':
            dp[i] = dp[i-1]
        if i - 2 >= 0:
            if in_range(encoded[i-2:i]):
                dp[i] += dp[i-2]

    return dp[-1]


def main():
    while True:
        s = input()
        assert s.isdigit(), f"Expected a digit string, got: '{s}'"
        print(count_decodings(s))

if __name__ == "__main__":
    main()
