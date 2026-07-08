# Leetcode Problem 16: 3Sum Closest
# Python CODE
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        closest = nums[0] + nums[1] + nums[2]

        for i in range(n - 2):
            left = i + 1
            right = n - 1

            while left < right:
                sum = nums[i] + nums[left] + nums[right]

                if abs(sum - target) < abs(closest - target):
                    closest = sum

                if sum == target:
                    return sum
                elif sum < target:
                    left += 1
                else:
                    right -= 1

        return closest