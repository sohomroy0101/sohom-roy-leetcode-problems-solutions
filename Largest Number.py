# Leetcode Problem 179: Largest Number
# PYTHON CODE
from functools import cmp_to_key
from typing import List

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Convert integers to strings
        str_nums = [str(num) for num in nums]
        
        # Custom comparator: checks whether a+b or b+a forms a larger number
        def compare(a: str, b: str) -> int:
            if a + b > b + a:
                return -1  # 'a' comes before 'b'
            elif a + b < b + a:
                return 1   # 'b' comes before 'a'
            else:
                return 0
                
        # Sort using the custom key
        str_nums.sort(key=cmp_to_key(compare))
        
        # Edge case: if the largest number is '0', return '0'
        if str_nums[0] == '0':
            return '0'
            
        return "".join(str_nums)