// Leetcode Problem 29: Divide Two Integers
// JAVA CODE
class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        long dvd = Math.abs((long) dividend);
        long dvs = Math.abs((long) divisor);

        long ans = 0;

        while (dvd >= dvs) {
            long temp = dvs;
            long multiple = 1;

            while ((temp << 1) <= dvd) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            ans += multiple;
        }

        if ((dividend < 0) ^ (divisor < 0)) {
            ans = -ans;
        }

        return (int) ans;
    }
}