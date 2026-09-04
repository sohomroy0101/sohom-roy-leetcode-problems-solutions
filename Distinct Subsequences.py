# Leetcode Problem 115: Distinct Subsequences
# PYTHON CODE
class Solution:

    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)

        # Optimization: If s is shorter than t, it can't contain t as a subsequence
        if m < n:
            return 0

        # dp[j] stores the number of distinct subsequences of t[:j] in s
        # Size n + 1 initialized to 0; dp[0] = 1 for the empty string base case
        dp = [0] * (n + 1)
        dp[0] = 1

        for i in range(1, m + 1):
            # Traverse backwards to use values from the previous iteration without overwriting
            for j in range(min(i, n), 0, -1):
                if s[i - 1] == t[j - 1]:
                    dp[j] += dp[j - 1]

        return dp[n]