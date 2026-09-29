// Leetcode Problem 140: Word Break II
// C++ CODE
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

class Solution {
private:
    std::unordered_map<int, std::vector<std::string>> memo;
    std::unordered_set<std::string> wordSet;

    std::vector<std::string> dfs(const std::string& s, int start) {
        // Base case: if we reach the end of the string, return a vector with an empty string
        if (start == s.length()) {
            return {""};
        }

        // Return cached result if subproblem was already solved
        if (memo.count(start)) {
            return memo[start];
        }

        std::vector<std::string> res;

        for (int end = start + 1; end <= s.length(); ++end) {
            std::string word = s.substr(start, end - start);

            if (wordSet.count(word)) {
                // Recursively get all valid sentence completions for the suffix
                std::vector<std::string> subSentences = dfs(s, end);

                for (const std::string& sub : subSentences) {
                    if (sub.empty()) {
                        res.push_back(word);
                    } else {
                        res.push_back(word + " " + sub);
                    }
                }
            }
        }

        memo[start] = res;
        return res;
    }

public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
        wordSet = std::unordered_set<std::string>(wordDict.begin(), wordDict.end());
        return dfs(s, 0);
    }
};