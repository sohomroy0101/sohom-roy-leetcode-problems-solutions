// Leetcode Problem 162: Find Peak Element
// C++ CODE
#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If the element is greater than its right neighbor, peak is on the left
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                // Otherwise, peak is on the right
                left = mid + 1;
            }
        }
        
        return left;
    }
};