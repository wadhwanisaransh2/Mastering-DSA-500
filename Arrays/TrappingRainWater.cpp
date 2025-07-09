#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftmax(n), rightmax(n), wT(n);
        int sum = 0;

        // Fill leftmax array
        leftmax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftmax[i] = max(leftmax[i - 1], height[i]);
        }

        // Fill rightmax array
        rightmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightmax[i] = max(rightmax[i + 1], height[i]);
        }

        // Calculate trapped water
        for (int i = 0; i < n; i++) {
            wT[i] = min(leftmax[i], rightmax[i]) - height[i];
            if (wT[i] > 0) {
                sum += wT[i];
            }
        }

        return sum;
    }
};

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution obj;
    int result = obj.trap(height);
    cout << "Total Trapped Water: " << result << " units" << endl;
    return 0;
}

