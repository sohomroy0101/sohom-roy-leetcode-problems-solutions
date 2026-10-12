# Leetcode Problem 154: Find Minimum in Rotated Sorted Array II
# PYTHON CODE
from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        
        while left < right:
            mid = (left + right) // 2
            
            if nums[mid] > nums[right]:
                # Minimum is in the right half
                left = mid + 1
            elif nums[mid] < nums[right]:
                # Minimum is in the left half including mid
                right = mid
            else:
                # Duplicates found; shrink the right boundary safely
                right -= 1
                
        return nums[left]