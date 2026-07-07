# Leetcode Problem 9: Palindrome Number
# Python Code
class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Negative numbers are not palindromes
        if x < 0:
            return False

        # Single digit numbers are palindromes
        if x < 10:
            return True

        # Convert to string and check if it's a palindrome
        s = str(x)
        left = 0
        right = len(s) - 1

        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1

        return True