// Leetcode Problem 115: Distinct Subsequences
// C++ CODE
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (m < n) {
            return 0;
        }

        // Use unsigned long long to avoid integer overflow during intermediate DP states
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1; // Base case: empty target string can be formed in 1 way

        for (int i = 1; i <= m; ++i) {
            // Traverse backwards to avoid overwriting values needed in the current row
            for (int j = min(i, n); j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};