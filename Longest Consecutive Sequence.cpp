// Leetcode Problem 128: Longest Consecutive Sequence
// C++ CODE
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(const std::vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : numSet) {
            // Check if 'num' is the start of a consecutive sequence
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                // Measure sequence length upwards
                while (numSet.count(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = std::max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};