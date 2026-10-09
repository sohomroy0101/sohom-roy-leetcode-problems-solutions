// Leetcode Problem 151: Reverse Words in a String
// C++ CODE
#include <string>
#include <sstream>
#include <vector>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> words;
        
        // stringstream automatically skips extra spaces
        while (ss >> word) {
            words.push_back(word);
        }
        
        std::string result = "";
        for (int i = words.size() - 1; i >= 0; --i) {
            result += words[i];
            if (i > 0) {
                result += " ";
            }
        }
        
        return result;
    }
};