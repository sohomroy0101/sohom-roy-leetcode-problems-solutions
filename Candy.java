// Leetcode Problem 135: Candy
// JAVA CODE
import java.util.Arrays;

class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        if (n == 0) {
            return 0;
        }

        // Base allocation: Every child gets at least 1 candy
        int[] candies = new int[n];
        Arrays.fill(candies, 1);

        // Pass 1: Left to Right
        // Ensure child has more candies than left neighbor if rating is higher
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Pass 2: Right to Left
        // Ensure child has more candies than right neighbor while keeping left-pass constraints
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = Math.max(candies[i], candies[i + 1] + 1);
            }
        }

        // Sum total candies distributed
        int totalCandies = 0;
        for (int candyCount : candies) {
            totalCandies += candyCount;
        }

        return totalCandies;
    }
}