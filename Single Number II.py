# Leetcode Problem 137: Single Number II
# PYTHON CODE
from typing import List


class Solution:

    def singleNumber(self, nums: List[int]) -> int:
        ones, twos = 0, 0

        for num in nums:
            # Update 'ones' with current num, excluding bits present in 'twos'
            ones = (ones ^ num) & ~twos
            # Update 'twos' with current num, excluding bits present in 'ones'
            twos = (twos ^ num) & ~ones

        return ones