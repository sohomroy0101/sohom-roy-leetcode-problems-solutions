// Leetcode Problem 132: Palindrome Partitioning II
// JAVA CODE
class Solution {
    public int minCut(String s) {
        int n = s.length();
        if (n <= 1) {
            return 0;
        }

        // dp[i] stores the minimum cuts for prefix s[0...i]
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = i;
        }

        for (int i = 0; i < n; i++) {
            // Odd length palindromes centered at i
            expandAroundCenter(i, i, s, dp);
            // Even length palindromes centered between i and i + 1
            expandAroundCenter(i, i + 1, s, dp);
        }

        return dp[n - 1];
    }

    private void expandAroundCenter(int left, int right, String s, int[] dp) {
        int n = s.length();
        while (left >= 0 && right < n && s.charAt(left) == s.charAt(right)) {
            if (left == 0) {
                dp[right] = 0;
            } else {
                dp[right] = Math.min(dp[right], dp[left - 1] + 1);
            }
            left--;
            right++;
        }
    }
}