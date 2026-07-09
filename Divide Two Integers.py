# Leetcode Problem 29: Divide Two Integers
# PYTHON CODE
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        if dividend == INT_MIN and divisor == -1:
            return INT_MAX

        negative = (dividend < 0) != (divisor < 0)

        dividend = abs(dividend)
        divisor = abs(divisor)

        ans = 0

        while dividend >= divisor:
            temp = divisor
            multiple = 1

            while (temp << 1) <= dividend:
                temp <<= 1
                multiple <<= 1

            dividend -= temp
            ans += multiple

        return -ans if negative else ans