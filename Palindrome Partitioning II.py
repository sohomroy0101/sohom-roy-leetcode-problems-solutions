# Leetcode Problem 132: Palindrome Partitioning II
# PYTHON CODE
class Solution:

    def minCut(self, s: str) -> int:
        n = len(s)
        if n <= 1:
            return 0

        # dp[i] stores the minimum cuts for prefix s[0...i]
        dp = [i for i in range(n)]

        def expand_around_center(left: int, right: int) -> None:
            while left >= 0 and right < n and s[left] == s[right]:
                if left == 0:
                    dp[right] = 0
                else:
                    dp[right] = min(dp[right], dp[left - 1] + 1)
                left -= 1
                right += 1

        for i in range(n):
            # Odd length palindromes centered at i
            expand_around_center(i, i)
            # Even length palindromes centered between i and i + 1
            expand_around_center(i, i + 1)

        return dp[n - 1]