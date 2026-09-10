# Leetcode Problem 121: Best Time to Buy and Sell Stock
# PYTHON CODE
class Solution:

    def maxProfit(self, prices: list[int]) -> int:
        min_price = float("inf")
        max_profit = 0

        for price in prices:
            if price < min_price:
                min_price = price  # Update the lowest buy price
            elif price - min_price > max_profit:
                max_profit = price - min_price  # Update maximum profit

        return max_profit