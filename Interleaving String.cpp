// Leetcode Problem 97: Interleaving String
// C++ CODE
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        int m = s1.size();
        int n = s2.size();

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        // Using only s2
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1] &&
                    s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i <= m; i++) {

            // Using only s1
            dp[0] = dp[0] &&
                    s1[i - 1] == s3[i - 1];

            for (int j = 1; j <= n; j++) {

                int index = i + j - 1;

                // Take character from s1
                bool fromS1 =
                    dp[j] &&
                    s1[i - 1] == s3[index];

                // Take character from s2
                bool fromS2 =
                    dp[j - 1] &&
                    s2[j - 1] == s3[index];

                dp[j] = fromS1 || fromS2;
            }
        }

        return dp[n];
    }
};