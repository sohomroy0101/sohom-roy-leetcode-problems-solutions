// Leetcode Problem 171: Excel Sheet Column Number
// C++ CODE
#include <string>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        int result = 0;
        for (char ch : columnTitle) {
            result = result * 26 + (ch - 'A' + 1);
        }
        return result;
    }
};