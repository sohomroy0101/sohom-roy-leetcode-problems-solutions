// Leetcode Problem 65: Valid Number
// C++ CODE
class Solution {
public:
    bool isNumber(string s) {
        regex pattern(R"(^[+-]?((\d+(\.\d*)?)|(\.\d+))([eE][+-]?\d+)?$)");

        int start = 0;
        while (start < s.size() && s[start] == ' ')
            start++;

        int end = s.size() - 1;
        while (end >= start && s[end] == ' ')
            end--;

        s = s.substr(start, end - start + 1);

        return regex_match(s, pattern);
    }
};