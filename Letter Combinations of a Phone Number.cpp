// Leetcode Problem 17: Letter Combinations of a Phone Number
// C++ CODE
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        unordered_map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        string combination = "";
        backtrack(digits, phoneMap, 0, combination, result);
        return result;
    }

private:
    void backtrack(const string& digits, const unordered_map<char, string>& phoneMap, int index, string& combination, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(combination);
            return;
        }

        char digit = digits[index];
        const string& letters = phoneMap.at(digit);

        for (char letter : letters) {
            combination.push_back(letter);
            backtrack(digits, phoneMap, index + 1, combination, result);
            combination.pop_back();
        }
    }
};