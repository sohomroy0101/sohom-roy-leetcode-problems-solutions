// Leetcode Problem 174: Dungeon Game
// JAVA CODE
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int m = dungeon.length;
        int n = dungeon[0].length;
        
        int[] dp = new int[n + 1];
        for (int j = 0; j <= n; j++) {
            dp[j] = Integer.MAX_VALUE;
        }
        
        dp[n - 1] = 1;
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int minHealthNeeded = Math.min(dp[j], dp[j + 1]);
                dp[j] = Math.max(1, minHealthNeeded - dungeon[i][j]);
            }
        }
        
        return dp[0];
    }
}