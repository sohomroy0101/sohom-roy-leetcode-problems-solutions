// Leetcode Problem 52: N-Queens II
// C++ CODE
class Solution {
public:
    int count = 0;

    void solve(int row, int n, vector<bool>& cols,
               vector<bool>& diag1, vector<bool>& diag2) {

        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {

            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
                continue;

            cols[col] = true;
            diag1[row + col] = true;
            diag2[row - col + n - 1] = true;

            solve(row + 1, n, cols, diag1, diag2);

            cols[col] = false;
            diag1[row + col] = false;
            diag2[row - col + n - 1] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        solve(0, n, cols, diag1, diag2);

        return count;
    }
};