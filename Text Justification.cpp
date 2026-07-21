// Leetcode Problem 68: Text Justification
// C++ CODE
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLength = 0;

            while (j < n && lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            // Last line or single word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    if (k > i) line += " ";
                    line += words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            }
            // Fully justify
            else {
                int totalSpaces = maxWidth - lineLength;
                int evenSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];
                    line += string(evenSpaces + (k - i < extraSpaces ? 1 : 0), ' ');
                }
                line += words[j - 1];
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};