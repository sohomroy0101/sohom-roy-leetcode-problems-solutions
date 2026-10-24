# Leetcode Problem 168: Excel Sheet Column Title
# PYTHON CODE
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        res = []
        
        while columnNumber > 0:
            columnNumber -= 1  # Shift to 0-indexed (0 to 25)
            remainder = columnNumber % 26
            res.append(chr(ord('A') + remainder))
            columnNumber //= 26
            
        return "".join(reversed(res))