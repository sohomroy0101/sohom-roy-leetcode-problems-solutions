//Leetcode Problem 51: N-Queens
//C++ CODE
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    vector<bool> cols, diag1, diag2;

    void backtrack(int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1]) {
                continue;
            }

            board[row][col] = 'Q';
            cols[col] = true;
            diag1[row + col] = true;
            diag2[row - col + n - 1] = true;

            backtrack(row + 1, n);

            board[row][col] = '.';
            cols[col] = false;
            diag1[row + col] = false;
            diag2[row - col + n - 1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        cols = vector<bool>(n, false);
        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);

        backtrack(0, n);
        return ans;
    }
};