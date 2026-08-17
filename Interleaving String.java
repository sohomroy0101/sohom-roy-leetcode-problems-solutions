// Leetcode Problem 97: Interleaving String
// JAVA CODE
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        int m = s1.length();
        int n = s2.length();

        boolean[] dp = new boolean[n + 1];

        dp[0] = true;

        // Using only s2
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1]
                    && s2.charAt(j - 1) == s3.charAt(j - 1);
        }

        for (int i = 1; i <= m; i++) {

            // Using only s1
            dp[0] = dp[0]
                    && s1.charAt(i - 1) == s3.charAt(i - 1);

            for (int j = 1; j <= n; j++) {

                int index = i + j - 1;

                // Take character from s1
                boolean fromS1 =
                        dp[j]
                        && s1.charAt(i - 1) == s3.charAt(index);

                // Take character from s2
                boolean fromS2 =
                        dp[j - 1]
                        && s2.charAt(j - 1) == s3.charAt(index);

                dp[j] = fromS1 || fromS2;
            }
        }

        return dp[n];
    }
}