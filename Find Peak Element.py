# Leetcode Problem 162: Find Peak Element
# PYTHON CODE
from typing import List

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        
        while left < right:
            mid = (left + right) // 2
            
            # If the element is greater than its right neighbor, peak is on the left
            if nums[mid] > nums[mid + 1]:
                right = mid
            else:
                # Otherwise, peak is on the right
                left = mid + 1
                
        return left