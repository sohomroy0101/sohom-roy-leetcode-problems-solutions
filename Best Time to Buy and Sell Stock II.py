# Leetcode Problem 122: Best Time to Buy and Sell Stock II
# PYTHON CODE
class Solution:

    def maxProfit(self, prices: list[int]) -> int:
        max_profit = 0

        # Accumulate profit from every positive daily price change
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                max_profit += prices[i] - prices[i - 1]

        return max_profit