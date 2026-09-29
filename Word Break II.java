// Leetcode Problem 140: Word Break II
// JAVA CODE
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

class Solution {
    private Map<Integer, List<String>> memo = new HashMap<>();
    private Set<String> wordSet;

    public List<String> wordBreak(String s, List<String> wordDict) {
        wordSet = new HashSet<>(wordDict);
        return dfs(s, 0);
    }

    private List<String> dfs(String s, int start) {
        // Base case: if we reach the end of the string, return a list with an empty string
        if (start == s.length()) {
            List<String> base = new ArrayList<>();
            base.add("");
            return base;
        }

        // Return cached result if subproblem was already solved
        if (memo.containsKey(start)) {
            return memo.get(start);
        }

        List<String> res = new ArrayList<>();

        for (int end = start + 1; end <= s.length(); end++) {
            String word = s.substring(start, end);
            
            if (wordSet.contains(word)) {
                // Recursively get all valid sentence completions for the suffix
                List<String> subSentences = dfs(s, end);
                
                for (String sub : subSentences) {
                    if (sub.isEmpty()) {
                        res.add(word);
                    } else {
                        res.add(word + " " + sub);
                    }
                }
            }
        }

        memo.put(start, res);
        return res;
    }
}