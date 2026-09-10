// Leetcode Problem 121: Best Time to Buy and Sell Stock
// C++ CODE
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price; // Update lowest buying price seen so far
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice; // Update highest profit
            }
        }

        return maxProfit;
    }
};