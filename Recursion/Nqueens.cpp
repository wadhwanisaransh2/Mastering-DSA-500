class Solution {
public:
    // Function to check if placing queen at (row, col) is safe
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Check vertically upwards
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    // Recursive backtracking function
    void solve(int row, vector<string>& board, vector<vector<string>>& solutions, int n) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q'; // Place queen
                solve(row + 1, board, solutions, n); // Recur to next row
                board[row][col] = '.'; // Backtrack
            }
        }
    }

    // Main function
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.')); // Initialize board with '.'
        solve(0, board, solutions, n);
        return solutions;
    }
};
