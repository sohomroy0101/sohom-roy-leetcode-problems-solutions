// Leetcode Problem 149: Max Points on a Line
// JAVA CODE
import java.util.HashMap;
import java.util.Map;

class Solution {

    public int maxPoints(int[][] points) {
        int n = points.length;
        if (n <= 2) {
            return n;
        }

        int maxPoints = 1;

        for (int i = 0; i < n; i++) {
            Map<String, Integer> slopes = new HashMap<>();
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                // Reduce fraction using GCD to avoid float division inaccuracies
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Standardize direction so equivalent slopes share the exact same string representation
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                String slopeKey = dy + "/" + dx;
                slopes.put(slopeKey, slopes.getOrDefault(slopeKey, 0) + 1);
            }

            // Find max points collinear with anchor point i
            int currentMax = 0;
            for (int count : slopes.values()) {
                currentMax = Math.max(currentMax, count);
            }

            // Include the anchor point itself (+1)
            maxPoints = Math.max(maxPoints, currentMax + 1);
        }

        return maxPoints;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}