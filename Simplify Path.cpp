// Leetcode Problem 71: Simplify Path
// C++ CODE
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string part;
        stringstream ss(path);

        while (getline(ss, part, '/')) {
            if (part.empty() || part == ".") {
                continue;
            } else if (part == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(part);
            }
        }

        if (stack.empty()) {
            return "/";
        }

        string result;
        for (string &dir : stack) {
            result += "/" + dir;
        }

        return result;
    }
};