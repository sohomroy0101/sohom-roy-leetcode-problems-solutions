//Leetcode Problem 51: N-Queens
//JAVA CODE
class Solution {
    List<List<String>> ans = new ArrayList<>();

    public List<List<String>> solveNQueens(int n) {
        char[][] board = new char[n][n];

        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');
        }

        boolean[] cols = new boolean[n];
        boolean[] diag1 = new boolean[2 * n - 1]; // row + col
        boolean[] diag2 = new boolean[2 * n - 1]; // row - col + n - 1

        backtrack(0, board, cols, diag1, diag2, n);

        return ans;
    }

    private void backtrack(int row, char[][] board, boolean[] cols,
                           boolean[] diag1, boolean[] diag2, int n) {

        if (row == n) {
            List<String> temp = new ArrayList<>();
            for (char[] r : board) {
                temp.add(new String(r));
            }
            ans.add(temp);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
                continue;

            board[row][col] = 'Q';
            cols[col] = true;
            diag1[row + col] = true;
            diag2[row - col + n - 1] = true;

            backtrack(row + 1, board, cols, diag1, diag2, n);

            board[row][col] = '.';
            cols[col] = false;
            diag1[row + col] = false;
            diag2[row - col + n - 1] = false;
        }
    }
}