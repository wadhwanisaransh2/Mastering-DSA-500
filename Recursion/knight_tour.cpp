#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        // Step 1: Store the position of each step number
        vector<pair<int, int>> pos(n * n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[grid[i][j]] = {i, j};
            }
        }

        // Check knight moves from step i to i+1
        for (int i = 0; i < n * n - 1; ++i) {
            int x1 = pos[i].first, y1 = pos[i].second;
            int x2 = pos[i + 1].first, y2 = pos[i + 1].second;
            int dx = abs(x1 - x2);
            int dy = abs(y1 - y2);

            if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2))) {
                return false;
            }
        }

        // Step 0 should always be at (0, 0)
        return pos[0] == make_pair(0, 0);
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {0, 11, 16, 5, 20},
        {17, 4, 19, 10, 15},
        {12, 1, 8, 21, 6},
        {3, 18, 23, 14, 9},
        {24, 13, 2, 7, 22}
    };
    vector<vector<int>> grid2 = {
        {0, 3, 6},
        {5, 8, 1},
        {2, 7, 4}
    };

    cout << "Grid 1 is a valid knight tour: " << (sol.checkValidGrid(grid1) ? "true" : "false") << endl;
    cout << "Grid 2 is a valid knight tour: " << (sol.checkValidGrid(grid2) ? "true" : "false") << endl;
    return 0;
}
