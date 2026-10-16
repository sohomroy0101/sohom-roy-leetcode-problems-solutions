# Leetcode Problem 164: Maximum Gap
# PYTHON CODE
from typing import List

class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2:
            return 0
        
        min_val = min(nums)
        max_val = max(nums)
        
        if min_val == max_val:
            return 0
            
        # Minimum possible gap between successive elements in sorted order
        bucket_size = max(1, (max_val - min_val) // (n - 1))
        bucket_count = (max_val - min_val) // bucket_size + 1
        
        bucket_min = [float('inf')] * bucket_count
        bucket_max = [float('-inf')] * bucket_count
        
        # Place each number in its respective bucket
        for num in nums:
            idx = (num - min_val) // bucket_size
            bucket_min[idx] = min(bucket_min[idx], num)
            bucket_max[idx] = max(bucket_max[idx], num)
            
        max_gap = 0
        prev_max = min_val
        
        # Scan buckets to find the maximum gap
        for i in range(bucket_count):
            if bucket_min[i] == float('inf'):
                continue # Empty bucket
            max_gap = max(max_gap, bucket_min[i] - prev_max)
            prev_max = bucket_max[i]
            
        return max_gap