# Leetcode Problem 139: Word Break
# PYTHON CODE
from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)  # O(1) lookups
        dp = [False] * (len(s) + 1)
        dp[0] = True  # Base case: empty prefix is valid

        for i in range(1, len(s) + 1):
            for j in range(i):
                if dp[j] and s[j:i] in word_set:
                    dp[i] = True
                    break  # Found a valid breakdown for prefix of length i

        return dp[len(s)]