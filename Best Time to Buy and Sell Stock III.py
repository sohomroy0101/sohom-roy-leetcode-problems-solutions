# Leetcode Problem 123: Best Time to Buy and Sell Stock III
# PYTHON CODE
class Solution:

    def maxProfit(self, prices: list[int]) -> int:
        if not prices:
            return 0

        first_buy = float("-inf")
        first_sell = 0
        second_buy = float("-inf")
        second_sell = 0

        for price in prices:
            # Max profit after buying the 1st stock
            first_buy = max(first_buy, -price)
            # Max profit after selling the 1st stock
            first_sell = max(first_sell, first_buy + price)
            # Max profit after buying the 2nd stock using profit from the 1st
            second_buy = max(second_buy, first_sell - price)
            # Max profit after selling the 2nd stock
            second_sell = max(second_sell, second_buy + price)

        return second_sell