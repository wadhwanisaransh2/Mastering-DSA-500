#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findMinDiff(vector<int>& arr, int m) {
        int n = arr.size();
        if (m == 0 || n == 0) return 0;
        if (m > n) return -1; 
        sort(arr.begin(), arr.end()); 

        int mindiff = INT_MAX;

        for (int i = 0; i <= n - m; i++) {
            int diff = arr[i + m - 1] - arr[i];
            mindiff = min(mindiff, diff);
        }

        return mindiff;
    }
};

int main() {
    vector<int> chocolates = {12, 4, 7, 9, 2, 23};
    int m = 3; // Number of students

    Solution sol;
    int result = sol.findMinDiff(chocolates, m);
    
    if (result != -1)
        cout << "Minimum difference is: " << result << endl;
    else
        cout << "Not enough packets to distribute!" << endl;

    return 0;
}
