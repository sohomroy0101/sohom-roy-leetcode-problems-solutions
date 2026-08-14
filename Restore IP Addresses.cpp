// Leetcode Problem 93: Restore IP Addresses
// C++ CODE
class Solution {
public:
    vector<string> result;

    void backtrack(string& s, int start, vector<string>& parts) {
        // If 4 parts are formed
        if (parts.size() == 4) {
            if (start == s.size()) {
                result.push_back(
                    parts[0] + "." +
                    parts[1] + "." +
                    parts[2] + "." +
                    parts[3]
                );
            }
            return;
        }

        // Remaining characters
        int remaining = s.size() - start;
        int partsLeft = 4 - parts.size();

        // Pruning
        if (remaining < partsLeft || remaining > 3 * partsLeft) {
            return;
        }

        // Try segment lengths from 1 to 3
        for (int len = 1; len <= 3; len++) {
            if (start + len > s.size()) {
                break;
            }

            string part = s.substr(start, len);

            // Leading zero is not allowed
            if (part.size() > 1 && part[0] == '0') {
                break;
            }

            // Value must be between 0 and 255
            int value = stoi(part);

            if (value > 255) {
                continue;
            }

            parts.push_back(part);

            backtrack(s, start + len, parts);

            parts.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> parts;

        backtrack(s, 0, parts);

        return result;
    }
};