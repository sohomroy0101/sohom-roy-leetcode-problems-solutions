// Leetcode Problem 131: Palindrome Partitioning
// C++ CODE
#include <vector>
#include <string>

class Solution {
private:
    bool isPalindrome(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void backtrack(int start, const std::string& s, std::vector<std::string>& path, std::vector<std::vector<std::string>>& result) {
        if (start == s.length()) {
            result.push_back(path);
            return;
        }

        for (int end = start; end < s.length(); ++end) {
            // Only recurse if s[start...end] is a palindrome
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1)); // Choose
                backtrack(end + 1, s, path, result);              // Explore
                path.pop_back();                                  // Backtrack
            }
        }
    }

public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> path;
        backtrack(0, s, path, result);
        return result;
    }
};