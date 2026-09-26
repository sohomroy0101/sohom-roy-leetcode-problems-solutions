// Leetcode Problem 137: Single Number II
// C++ CODE
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for (int num : nums) {
            // Update 'ones' with current num, excluding bits present in 'twos'
            ones = (ones ^ num) & ~twos;
            // Update 'twos' with current num, excluding bits present in 'ones'
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }
};