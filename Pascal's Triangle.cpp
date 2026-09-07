// Leetcode Problem 118: Pascal's Triangle
// C++ CODE
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;

        for (int i = 0; i < numRows; ++i) {
            // Allocate current row initialized with size (i + 1) and values set to 1
            std::vector<int> row(i + 1, 1);

            // Compute inner values from index 1 to i - 1
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};