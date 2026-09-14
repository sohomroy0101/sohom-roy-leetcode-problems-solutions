// Leetcode Problem 125: Valid Palindrome
// C++ CODE

#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(const std::string& s) {
        int left = 0;
        int right = static_cast<int>(s.length()) - 1;

        while (left < right) {
            // Skip non-alphanumeric characters from the left
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[left]))) {
                left++;
            }
            // Skip non-alphanumeric characters from the right
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[right]))) {
                right--;
            }

            // Compare characters ignoring case
            if (std::tolower(static_cast<unsigned char>(s[left])) != 
                std::tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};