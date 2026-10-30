// Leetcode Problem 174: Dungeon Game
// C++ CODE
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        std::vector<int> dp(n + 1, INT_MAX);
        dp[n - 1] = 1;
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int minHealthNeeded = std::min(dp[j], dp[j + 1]);
                dp[j] = std::max(1, minHealthNeeded - dungeon[i][j]);
            }
        }
        
        return dp[0];
    }
};