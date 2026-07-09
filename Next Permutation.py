# Leetcode Problem 31: Next Permutation
# PYTHON CODE
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        i = n - 2

        # Step 1: Find the first decreasing element
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1

        # Step 2: Find the next greater element and swap
        if i >= 0:
            j = n - 1
            while nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]

        # Step 3: Reverse the remaining suffix
        left, right = i + 1, n - 1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1