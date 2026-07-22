// Leetcode Problem 69: Sqrt(x)
// C++ CODE
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }

        int left = 1, right = x / 2;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long square = 1LL * mid * mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};