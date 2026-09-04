// Leetcode Problem 115: Distinct Subsequences
// JAVA CODE
class Solution {
    public int numDistinct(String s, String t) {
        int m = s.length();
        int n = t.length();

        if (m < n) {
            return 0;
        }

        // dp[j] stores the number of distinct subsequences of t.substring(0, j) in s
        int[] dp = new int[n + 1];
        dp[0] = 1; // Base case: an empty string t can always be formed 1 way

        for (int i = 1; i <= m; i++) {
            // Traverse backwards to avoid overwriting previous state values needed for current calculation
            for (int j = Math.min(i, n); j >= 1; j--) {
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
}