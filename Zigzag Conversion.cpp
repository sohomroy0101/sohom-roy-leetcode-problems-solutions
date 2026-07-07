// Leetcode Problem 6: Zigzag Conversion
// C++ Code
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);
        int currentRow = 0;
        bool goingDown = true;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0) {
                goingDown = true;
            } else if (currentRow == numRows - 1) {
                goingDown = false;
            }

            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};