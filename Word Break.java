// Leetcode Problem 139: Word Break
// JAVA CODE
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        // Convert list to set for O(1) average lookup time
        Set<String> wordSet = new HashSet<>(wordDict);
        
        int n = s.length();
        // dp[i] represents if s[0...i-1] can be segmented into dictionary words
        boolean[] dp = new boolean[n + 1];
        
        // Base case: empty string prefix can always be formed
        dp[0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // If the prefix s[0...j-1] is valid and the remaining substring s[j...i-1] is in wordDict
                if (dp[j] && wordSet.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break; // Move to the next outer loop iteration once a valid split is found
                }
            }
        }
        
        return dp[n];
    }
}