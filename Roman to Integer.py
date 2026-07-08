# Leetcode Problem 13: Roman to Integer
# Python CODE
class Solution:
    def romanToInt(self, s: str) -> int:
        romanValues = {
            'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000
        }

        result = 0
        prevValue = 0

        for i in range(len(s) - 1, -1, -1):
            currentValue = romanValues[s[i]]
            if currentValue < prevValue:
                result -= currentValue
            else:
                result += currentValue
            prevValue = currentValue

        return result