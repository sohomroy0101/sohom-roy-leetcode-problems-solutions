# Leetcode Problem 118: Pascal's Triangle
# PYTHON CODE
class Solution:

    def generate(self, numRows: int) -> list[list[int]]:
        triangle = []

        for i in range(numRows):
            # First element of every row is always 1
            row = [1] * (i + 1)

            # Fill in the middle elements using the previous row
            for j in range(1, i):
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]

            triangle.append(row)

        return triangle