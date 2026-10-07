# Leetcode Problem 149: Max Points on a Line
# Python CODE
import math
from collections import defaultdict
from typing import List

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        if n <= 2:
            return n

        max_pts = 1

        for i in range(n):
            slopes = defaultdict(int)
            x1, y1 = points[i]

            for j in range(i + 1, n):
                x2, y2 = points[j]
                dx = x2 - x1
                dy = y2 - y1

                # Reduce fraction by Greatest Common Divisor
                g = math.gcd(dx, dy)
                dx //= g
                dy //= g

                # Normalize signs to maintain consistency for parallel/identical direction vectors
                if dx < 0 or (dx == 0 and dy < 0):
                    dx = -dx
                    dy = -dy

                slope = (dx, dy)
                slopes[slope] += 1

            # Current point counts as 1, so add 1 to the max frequency found from point i
            current_max = max(slopes.values(), default=0) + 1
            max_pts = max(max_pts, current_max)

        return max_pts