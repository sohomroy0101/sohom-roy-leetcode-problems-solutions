# Leetcode Problem 136: Single Number
# PYTHON CODE
from functools import reduce
from typing import List


class Solution:

    def singleNumber(self, nums: List[int]) -> int:
        single_num = 0
        for num in nums:
            single_num ^= num
        return single_num


# Alternative one-liner using functools.reduce
class SolutionFunctional:

    def singleNumber(self, nums: List[int]) -> int:
        return reduce(lambda x, y: x ^ y, nums)