// Leetcode Problem 136: Single Number
// JAVA CODE
class Solution {
    public int singleNumber(int[] nums) {
        int singleNum = 0;
        for (int num : nums) {
            singleNum ^= num;
        }
        return singleNum;
    }
}