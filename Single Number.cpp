// Leetcode Problem 136: Single Number
// C++ CODE
#include <vector>
#include <numeric>
#include <functional>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int singleNum = 0;
        for (int num : nums) {
            singleNum ^= num;
        }
        return singleNum;
    }
};