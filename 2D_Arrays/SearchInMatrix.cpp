#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Binary search in a particular row
    bool searchinrow(vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();
        int st = 0, end = n - 1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (target == matrix[row][mid]) {
                return true;
            }
            else if (target > matrix[row][mid]) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return false;
    }

    // Main function to search in matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sr = 0, endr = m - 1;

        while (sr <= endr) {
            int mid = sr + (endr - sr) / 2;

            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                return searchinrow(matrix, target, mid);
            }
            else if (target > matrix[mid][n - 1]) {
                sr = mid + 1;
            }
            else {
                endr = mid - 1;
            }
        }
        return false;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Target found in matrix." << endl;
    } else {
        cout << "Target not found in matrix." << endl;
    }

    return 0;
}
