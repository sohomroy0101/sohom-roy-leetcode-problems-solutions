# Leetcode Problem 120: Triangle
# PYTHON CODE
class Solution:

    def minimumTotal(self, triangle: list[list[int]]) -> int:
        # Traverse from the second-to-last row up to the top
        for row in range(len(triangle) - 2, -1, -1):
            for col in range(len(triangle[row])):
                # Pick the minimum of the two adjacent numbers directly below
                triangle[row][col] += min(
                    triangle[row + 1][col], triangle[row + 1][col + 1]
                )

        # The top node now holds the minimum path sum for the whole triangle
        return triangle[0][0]