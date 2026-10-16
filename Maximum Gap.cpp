// Leetcode Problem 164: Maximum Gap
// C++ CODE
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        
        int minVal = nums[0];
        int maxVal = nums[0];
        for (int num : nums) {
            minVal = std::min(minVal, num);
            maxVal = std::max(maxVal, num);
        }
        
        if (minVal == maxVal) {
            return 0;
        }
        
        // Minimum possible gap between successive elements in sorted order
        int bucketSize = std::max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;
        
        std::vector<int> bucketMin(bucketCount, INT_MAX);
        std::vector<int> bucketMax(bucketCount, INT_MIN);
        
        // Place each number into its respective bucket
        for (int num : nums) {
            int idx = (num - minVal) / bucketSize;
            bucketMin[idx] = std::min(bucketMin[idx], num);
            bucketMax[idx] = std::max(bucketMax[idx], num);
        }
        
        int maxGap = 0;
        int prevMax = minVal;
        
        // Scan buckets to find the maximum gap between non-empty buckets
        for (int i = 0; i < bucketCount; ++i) {
            if (bucketMin[i] == INT_MAX) {
                continue; // Empty bucket
            }
            maxGap = std::max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }
        
        return maxGap;
    }
};