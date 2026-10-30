# Leetcode Problem 174: Dungeon Game
# PYTHON CODE
from typing import List

class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])
        
        # Initialize DP table with infinity, adding an extra row and column as a buffer
        dp = [[float('inf')] * (n + 1) for _ in range(m + 1)]
        
        # Base case settings for the virtual cells right and below the bottom-right corner
        dp[m][n - 1] = 1
        dp[m - 1][n] = 1
        
        # Traverse backwards from bottom-right to top-left
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                min_health_needed = min(dp[i + 1][j], dp[i][j + 1])
                dp[i][j] = max(1, min_health_needed - dungeon[i][j])
                
        return dp[0][0]