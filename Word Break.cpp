// Leetcode Problem 139: Word Break
// C++ CODE
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        // Convert vector to unordered_set for O(1) average lookup time
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
        
        int n = s.length();
        // dp[i] represents whether s[0...i-1] can be segmented using wordDict
        std::vector<bool> dp(n + 1, false);
        
        // Base case: empty string prefix can always be formed
        dp[0] = true;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                // If prefix s[0...j-1] is valid and substring s[j...i-1] is in wordDict
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // Move to the next index once a valid split is found
                }
            }
        }
        
        return dp[n];
    }
};