#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Check if it's valid to place 'c' at board[row][col]
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check the row
            if (board[row][i] == c) return false;

            // Check the column
            if (board[i][col] == c) return false;

            // Check the 3x3 sub-grid
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == c) return false;
        }
        return true;
    }

    // Recursive backtracking function to solve Sudoku
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, row, col, c)) {
                            board[row][col] = c;

                            if (solve(board)) return true; // Proceed if correct

                            board[row][col] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid digit found
                }
            }
        }
        return true; // All cells are filled
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// ---------- Main Function ----------
int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution solver;
    solver.solveSudoku(board);

    // Output the solved Sudoku
    cout << "Solved Sudoku Board:\n";
    for (const auto& row : board) {
        for (const auto& ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}
