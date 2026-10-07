// Leetcode Problem 149: Max Points on a Line
// C++ CODE
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int maxPoints = 1;

        // Custom hash function for std::pair<int, int> to use in unordered_map
        struct PairHash {
            size_t operator()(const pair<int, int>& p) const {
                return hash<int>()(p.first) ^ (hash<int>()(p.second) << 16);
            }
        };

        for (int i = 0; i < n; ++i) {
            unordered_map<pair<int, int>, int, PairHash> slopes;
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                // Reduce fraction using Greatest Common Divisor
                int g = std::gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Standardize direction so equivalent slopes share the exact same key
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                slopes[{dy, dx}]++;
            }

            int currentMax = 0;
            for (const auto& [slope, count] : slopes) {
                currentMax = max(currentMax, count);
            }

            // Include the anchor point itself (+1)
            maxPoints = max(maxPoints, currentMax + 1);
        }

        return maxPoints;
    }
};