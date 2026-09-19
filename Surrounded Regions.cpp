// Leetcode Problem 130: Surrounded Regions
// C++ CODE
#include <vector>

class Solution {
private:
    void dfs(std::vector<std::vector<char>>& board, int r, int c, int rows, int cols) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') {
            return;
        }

        // Mark cell as connected to border (Safe)
        board[r][c] = 'E';

        // Traverse 4-directionally
        dfs(board, r + 1, c, rows, cols);
        dfs(board, r - 1, c, rows, cols);
        dfs(board, r, c + 1, rows, cols);
        dfs(board, r, c - 1, rows, cols);
    }

public:
    void solve(std::vector<std::vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        int rows = board.size();
        int cols = board[0].size();

        // Step 1: Run DFS from 'O's on the left and right boundaries
        for (int r = 0; r < rows; ++r) {
            if (board[r][0] == 'O') {
                dfs(board, r, 0, rows, cols);
            }
            if (board[r][cols - 1] == 'O') {
                dfs(board, r, cols - 1, rows, cols);
            }
        }

        // Step 1: Run DFS from 'O's on the top and bottom boundaries
        for (int c = 0; c < cols; ++c) {
            if (board[0][c] == 'O') {
                dfs(board, 0, c, rows, cols);
            }
            if (board[rows - 1][c] == 'O') {
                dfs(board, rows - 1, c, rows, cols);
            }
        }

        // Step 2 & 3: Sweep matrix to capture enclosed 'O's and restore 'E's
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X'; // Surrounded region -> capture
                } else if (board[r][c] == 'E') {
                    board[r][c] = 'O'; // Border-connected region -> restore
                }
            }
        }
    }
};