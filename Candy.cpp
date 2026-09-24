// Leetcode Problem 135: Candy
// C++ CODE
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        // Base allocation: Every child gets at least 1 candy
        std::vector<int> candies(n, 1);

        // Pass 1: Left to Right
        // Satisfy the left neighbor condition
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Pass 2: Right to Left
        // Satisfy the right neighbor condition while keeping left-pass valid
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        // Sum all candies allocated
        return std::accumulate(candies.begin(), candies.end(), 0);
    }
};