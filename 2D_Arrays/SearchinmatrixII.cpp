#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();        // number of rows
        int n = matrix[0].size();     // number of columns

        int r = 0, c = n - 1;         // start from top-right corner

        while (r < m && c >= 0) {
            if (matrix[r][c] == target) {
                return true;          // target found
            } 
            else if (matrix[r][c] > target) {
                c--;                  // move left
            } 
            else {
                r++;                  // move down
            }
        }

        return false;                 // target not found
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {12, 15, 18, 20},
        {23, 26, 30, 34},
        {36, 40, 45, 50}
    };
    int target = 30;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Target found in matrix." << endl;
    } else {
        cout << "Target not found in matrix." << endl;
    }
    return 0;
}
