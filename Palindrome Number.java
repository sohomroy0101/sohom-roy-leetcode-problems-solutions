// Leetcode Problem 9: Palindrome Number
// Java Code
class Solution {
    public boolean isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) {
            return false;
        }

        // Single digit numbers are palindromes
        if (x < 10) {
            return true;
        }

        // Convert to string and check if it's a palindrome
        String s = String.valueOf(x);
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
}