// Leetcode Problem 119: Pascal's Triangle II
// C++ CODE
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row;
        row.reserve(rowIndex + 1);
        row.push_back(1); // C(n, 0) is always 1

        long long val = 1; // Use long long to prevent integer overflow
        for (int j = 1; j <= rowIndex; ++j) {
            val = val * (rowIndex - j + 1) / j;
            row.push_back(static_cast<int>(val));
        }

        return row;
    }
};