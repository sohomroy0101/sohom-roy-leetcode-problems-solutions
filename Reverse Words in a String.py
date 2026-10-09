# Leetcode Problem 151: Reverse Words in a String
# PYTHON CODE
class Solution:
    def reverseWords(self, s: str) -> str:
        # split() without arguments automatically handles extra spaces
        words = s.split()
        
        # Reverse the list of words and join them with a single space
        return " ".join(words[::-1])