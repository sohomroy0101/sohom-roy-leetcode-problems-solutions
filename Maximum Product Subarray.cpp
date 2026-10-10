// Leetcode Problem 152: Maximum Product Subarray
// C++ CODE
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;
        
        for (size_t i = 1; i < nums.size(); ++i) {
            int curr = nums[i];
            
            // Temporary variable because max_so_far will be updated
            int temp_max = std::max({curr, max_so_far * curr, min_so_far * curr});
            min_so_far = std::min({curr, max_so_far * curr, min_so_far * curr});
            max_so_far = temp_max;
            
            result = std::max(result, max_so_far);
        }
        
        return result;
    }
};