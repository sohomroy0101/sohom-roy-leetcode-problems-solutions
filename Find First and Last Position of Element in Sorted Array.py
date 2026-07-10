# Leetcode Problem 34: Find First and Last Position of Element in Sorted Array
# PYTHON CODE
import bisect

class Solution:
    def searchRange(self, nums, target):
        left = bisect.bisect_left(nums, target)
        right = bisect.bisect_right(nums, target) - 1

        if left < len(nums) and nums[left] == target:
            return [left, right]

        return [-1, -1]