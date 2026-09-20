# Leetcode Problem 131: Palindrome Partitioning
# PYTHON CODE
from typing import List


class Solution:

    def partition(self, s: str) -> List[List[str]]:
        result = []
        n = len(s)

        # Helper function to check if a substring is a palindrome
        def is_palindrome(left: int, right: int) -> bool:
            while left < right:
                if s[left] != s[right]:
                    return False
                left += 1
                right -= 1
            return True

        def backtrack(start: int, path: List[str]) -> None:
            # Base case: reached the end of string
            if start == n:
                result.append(list(path))
                return

            for end in range(start, n):
                # Only proceed if current substring s[start:end+1] is a palindrome
                if is_palindrome(start, end):
                    path.append(s[start : end + 1])  # Choose
                    backtrack(end + 1, path)  # Explore
                    path.pop()  # Backtrack

        backtrack(0, [])
        return result