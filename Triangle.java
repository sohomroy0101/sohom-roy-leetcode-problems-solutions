// Leetcode Problem 120: Triangle
// JAVA CODE
import java.util.List;

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();

        // Traverse upwards starting from the second-to-last row
        for (int row = n - 2; row >= 0; row--) {
            List<Integer> currRow = triangle.get(row);
            List<Integer> nextRow = triangle.get(row + 1);

            for (int col = 0; col <= row; col++) {
                // Add the minimum of the two adjacent children below
                int minPath = currRow.get(col) + Math.min(nextRow.get(col), nextRow.get(col + 1));
                currRow.set(col, minPath);
            }
        }

        // Top element contains the minimum path sum
        return triangle.get(0).get(0);
    }
}