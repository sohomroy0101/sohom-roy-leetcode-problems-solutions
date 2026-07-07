# Leetcode Problem 6: Zigzag Conversion
# Python Code
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s

        rows = [''] * numRows
        currentRow = 0
        goingDown = True

        for c in s:
            rows[currentRow] += c

            if currentRow == 0:
                goingDown = True
            elif currentRow == numRows - 1:
                goingDown = False

            currentRow += 1 if goingDown else -1

        return ''.join(rows)