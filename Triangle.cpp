// Leetcode Problem 120: Triangle
// C++ CODE
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int n = triangle.size();

        // Traverse upwards starting from the second-to-last row
        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col <= row; ++col) {
                // Add the minimum of the two adjacent children below
                triangle[row][col] += std::min(triangle[row + 1][col], triangle[row + 1][col + 1]);
            }
        }

        // Top element contains the minimum path sum
        return triangle[0][0];
    }
};