// Leetcode Problem 168: Excel Sheet Column Title
// C++ CODE
#include <string>
#include <algorithm>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string res = "";
        
        while (columnNumber > 0) {
            columnNumber -= 1; // Shift to 0-indexed (0 to 25)
            int remainder = columnNumber % 26;
            res += static_cast<char>('A' + remainder);
            columnNumber /= 26;
        }
        
        std::reverse(res.begin(), res.end());
        return res;
    }
};