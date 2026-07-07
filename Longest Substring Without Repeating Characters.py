#Leetcode Problem 3: Longest Substring Without Repeating Characters
# Python Code
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = {}
        left = 0
        maxLength = 0

        for right, ch in enumerate(s):
            if ch in mp and mp[ch] >= left:
                left = mp[ch] + 1

            mp[ch] = right
            maxLength = max(maxLength, right - left + 1)

        return maxLength