// Leetcode Problem 8: String to Integer (atoi)
// C++ Code
#include <limits.h>
#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        // Skip leading whitespace
        while (s[i] == ' ') {
            i++;
        }

        // Check for sign
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        // Convert digits to integer
        long long result = 0;
        while (i < s.length() && std::isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            // Check for overflow
            if (result > INT_MAX) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            i++;
        }

        result *= sign;
        return static_cast<int>(result);
    }
};