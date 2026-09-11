// Leetcode Problem 122: Best Time to Buy and Sell Stock II
// JAVA CODE
class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;

        // Collect profit from every upward price movement
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }

        return maxProfit;
    }
}