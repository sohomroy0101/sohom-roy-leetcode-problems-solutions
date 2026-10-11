# Leetcode Problem 153: Find Minimum in Rotated Sorted Array
# PYTHON CODE
from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        
        while left < right:
            mid = (left + right) // 2
            
            # If mid element is greater than the rightmost element,
            # the minimum must be in the right half.
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                # Otherwise, the minimum is in the left half including mid.
                right = mid
                
        return nums[left]