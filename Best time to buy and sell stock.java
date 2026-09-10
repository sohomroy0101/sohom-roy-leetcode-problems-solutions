// Leetcode Problem 121: Best Time to Buy and Sell Stock
// JAVA CODE
class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = Integer.MAX_VALUE;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price; // Update the lowest buying price
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice; // Update maximum profit
            }
        }

        return maxProfit;
    }
}