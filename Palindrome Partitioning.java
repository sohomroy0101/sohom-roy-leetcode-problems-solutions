// Leetcode Problem 131: Palindrome Partitioning
// JAVA CODE
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        List<String> path = new ArrayList<>();
        backtrack(0, s, path, result);
        return result;
    }

    private void backtrack(int start, String s, List<String> path, List<List<String>> result) {
        if (start == s.length()) {
            result.add(new ArrayList<>(path));
            return;
        }

        for (int end = start; end < s.length(); end++) {
            // Only recurse if s[start...end] is a palindrome
            if (isPalindrome(s, start, end)) {
                path.add(s.substring(start, end + 1)); // Choose
                backtrack(end + 1, s, path, result);    // Explore
                path.remove(path.size() - 1);           // Backtrack
            }
        }
    }

    private boolean isPalindrome(String s, int left, int right) {
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