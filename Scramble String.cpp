// Leetcode Problem 87: Scramble String
// C++ CODE
class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(string a, string b) {
        if (a == b) {
            return true;
        }

        string key = a + "#" + b;

        if (memo.count(key)) {
            return memo[key];
        }

        string x = a;
        string y = b;

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if (x != y) {
            return memo[key] = false;
        }

        int n = a.size();

        for (int i = 1; i < n; i++) {

            // No swap
            if (solve(a.substr(0, i), b.substr(0, i)) &&
                solve(a.substr(i), b.substr(i))) {

                return memo[key] = true;
            }

            // Swap
            if (solve(a.substr(0, i), b.substr(n - i)) &&
                solve(a.substr(i), b.substr(0, n - i))) {

                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};