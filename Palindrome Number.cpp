// Leetcode Problem 9: Palindrome Number
// C++ Code
class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) {
            return false;
        }

        // Single digit numbers are palindromes
        if (x < 10) {
            return true;
        }

        // Convert to string and check if it's a palindrome
        std::string s = std::to_string(x);
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};