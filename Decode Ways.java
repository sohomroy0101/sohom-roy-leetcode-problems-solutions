// Leetcode Problem 91: Decode Ways
// JAVA CODE
class Solution {
    public int numDecodings(String s) {
        int n = s.length();

        if (s.charAt(0) == '0') {
            return 0;
        }

        int prev2 = 1;
        int prev1 = 1;

        for (int i = 1; i < n; i++) {
            int curr = 0;

            // Decode the current digit individually
            if (s.charAt(i) != '0') {
                curr += prev1;
            }

            // Decode the current and previous digits together
            int twoDigit = (s.charAt(i - 1) - '0') * 10
                         + (s.charAt(i) - '0');

            if (twoDigit >= 10 && twoDigit <= 26) {
                curr += prev2;
            }

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
}