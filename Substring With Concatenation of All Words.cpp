// Leetcode Problem 30: Substring With Concatenation of All Words
// C++ CODE
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (s.empty() || words.empty())
            return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();

        unordered_map<string, int> target;
        for (string &word : words)
            target[word]++;

        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int count = 0;
            unordered_map<string, int> window;

            for (int right = offset; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if (target.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > target[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};