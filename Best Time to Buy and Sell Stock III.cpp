// Leetcode Problem 123: Best Time to Buy and Sell Stock III
// C++ CODE
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        if (prices.empty()) return 0;

        int firstBuy = INT_MIN;
        int firstSell = 0;
        int secondBuy = INT_MIN;
        int secondSell = 0;

        for (int price : prices) {
            // Max profit after buying the 1st stock
            firstBuy = std::max(firstBuy, -price);
            // Max profit after selling the 1st stock
            firstSell = std::max(firstSell, firstBuy + price);
            // Max profit after buying the 2nd stock using profit from the 1st
            secondBuy = std::max(secondBuy, firstSell - price);
            // Max profit after selling the 2nd stock
            secondSell = std::max(secondSell, secondBuy + price);
        }

        return secondSell;
    }
};