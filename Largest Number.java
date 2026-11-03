// Leetcode Problem 179: Largest Number
// JAVA CODE
import java.util.Arrays;

class Solution {
    public String largestNumber(int[] nums) {
        // Convert integers to strings
        String[] strNums = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            strNums[i] = String.valueOf(nums[i]);
        }
        
        // Custom sort: compare concatenated combinations to find optimal ordering
        Arrays.sort(strNums, (a, b) -> (b + a).compareTo(a + b));
        
        // Edge case: if the highest value is "0", the entire number is 0
        if (strNums[0].equals("0")) {
            return "0";
        }
        
        // Build the final result
        StringBuilder sb = new StringBuilder();
        for (String s : strNums) {
            sb.append(s);
        }
        
        return sb.toString();
    }
}