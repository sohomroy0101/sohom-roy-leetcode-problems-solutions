# Leetcode Problem 140: Word Break II
# PYTHON CODE
from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        word_set = set(wordDict)
        memo = {}

        def dfs(start: int) -> List[str]:
            # If we've already computed results for this substring start position
            if start in memo:
                return memo[start]

            # Base case: reached end of string, return list with empty string
            if start == len(s):
                return [""]

            res = []
            # Try forming words starting from index `start`
            for end in range(start + 1, len(s) + 1):
                word = s[start:end]
                if word in word_set:
                    # Recursively get all valid sentences for remaining suffix
                    sub_sentences = dfs(end)
                    for sentence in sub_sentences:
                        if sentence:
                            res.append(word + " " + sentence)
                        else:
                            res.append(word)

            memo[start] = res
            return res

        return dfs(0)