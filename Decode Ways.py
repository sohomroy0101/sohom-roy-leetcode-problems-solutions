# Leetcode Problem 91: Decode Ways
# PYTHON CODE
class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)

        if s[0] == '0':
            return 0

        prev2 = 1
        prev1 = 1

        for i in range(1, n):
            curr = 0

            # Decode current digit individually
            if s[i] != '0':
                curr += prev1

            # Decode current and previous digits together
            two_digit = int(s[i - 1:i + 1])

            if 10 <= two_digit <= 26:
                curr += prev2

            prev2 = prev1
            prev1 = curr

        return prev1