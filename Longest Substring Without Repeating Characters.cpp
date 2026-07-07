//Leetcode Problem 3: Longest Substring Without Repeating Characters
// C++ Code
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            if (mp.find(s[right]) != mp.end() && mp[s[right]] >= left) {
                left = mp[s[right]] + 1;
            }

            mp[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};