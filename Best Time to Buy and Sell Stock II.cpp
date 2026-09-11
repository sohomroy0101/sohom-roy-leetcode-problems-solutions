// Leetcode Problem 122: Best Time to Buy and Sell Stock II
// C++ CODE
#include <vector>

class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        int maxProfit = 0;

        // Accumulate profit from every positive daily increase
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }

        return maxProfit;
    }
};