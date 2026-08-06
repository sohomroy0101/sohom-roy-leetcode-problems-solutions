# Leetcode Problem 85: Maximal Rectangle
# PYTHON CODE
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0

        cols = len(matrix[0])
        heights = [0] * cols
        max_area = 0

        for row in matrix:
            for j in range(cols):
                if row[j] == "1":
                    heights[j] += 1
                else:
                    heights[j] = 0

            stack = []
            for i in range(cols + 1):
                curr_height = 0 if i == cols else heights[i]

                while stack and heights[stack[-1]] > curr_height:
                    height = heights[stack.pop()]
                    width = i if not stack else i - stack[-1] - 1
                    max_area = max(max_area, height * width)

                stack.append(i)

        return max_area