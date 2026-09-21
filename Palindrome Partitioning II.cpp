// Leetcode Problem 132: Palindrome Partitioning II
// C++ CODE
#include <string>
#include <vector>
#include <algorithm>

class Solution {
private:
    void expandAroundCenter(int left, int right, const std::string& s, std::vector<int>& dp) {
        int n = s.length();
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (left == 0) {
                dp[right] = 0;
            } else {
                dp[right] = std::min(dp[right], dp[left - 1] + 1);
            }
            left--;
            right++;
        }
    }

public:
    int minCut(std::string s) {
        int n = s.length();
        if (n <= 1) {
            return 0;
        }

        // dp[i] stores the minimum cuts for prefix s[0...i]
        std::vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            // Odd length palindromes centered at i
            expandAroundCenter(i, i, s, dp);
            // Even length palindromes centered between i and i + 1
            expandAroundCenter(i, i + 1, s, dp);
        }

        return dp[n - 1];
    }
};