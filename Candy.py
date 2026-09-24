# Leetcode Problem 135: Candy
# PYTHON CODE
from typing import List


class Solution:

    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        if n == 0:
            return 0

        # Base allocation: every child gets at least 1 candy
        candies = [1] * n

        # Pass 1: Left to Right
        # Satisfy left-neighbor condition
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1

        # Pass 2: Right to Left
        # Satisfy right-neighbor condition while preserving left-pass constraints
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candies[i] = max(candies[i], candies[i + 1] + 1)

        return sum(candies)