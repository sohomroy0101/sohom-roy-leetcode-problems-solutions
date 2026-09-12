// Leetcode Problem 123: Best Time to Buy and Sell Stock III
// JAVA CODE
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }

        int firstBuy = Integer.MIN_VALUE;
        int firstSell = 0;
        int secondBuy = Integer.MIN_VALUE;
        int secondSell = 0;

        for (int price : prices) {
            // Max profit after buying the 1st stock
            firstBuy = Math.max(firstBuy, -price);
            // Max profit after selling the 1st stock
            firstSell = Math.max(firstSell, firstBuy + price);
            // Max profit after buying the 2nd stock using profit from the 1st
            secondBuy = Math.max(secondBuy, firstSell - price);
            // Max profit after selling the 2nd stock
            secondSell = Math.max(secondSell, secondBuy + price);
        }

        return secondSell;
    }
}