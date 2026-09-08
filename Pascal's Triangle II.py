# Leetcode Problem 119: Pascal's Triangle II
# PYTHON CODE
class Solution:

    def getRow(self, rowIndex: int) -> list[int]:
        # Initialize the row with 1s of size (rowIndex + 1)
        row = [1] * (rowIndex + 1)

        for i in range(2, rowIndex + 1):
            # Update backwards to avoid overwriting values from previous iteration
            for j in range(i - 1, 0, -1):
                row[j] += row[j - 1]

        return row