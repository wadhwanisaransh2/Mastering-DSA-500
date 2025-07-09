#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        vector<int> prefix(n), suffix(n);

        prefix[0] = 1;
        suffix[n - 1] = 1;

        // Create prefix product
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Create suffix product
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Final result
        for (int i = 0; i < n; i++) {
            arr[i] = prefix[i] * suffix[i];
        }

        return arr;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution sol;
    vector<int> result = sol.productExceptSelf(nums);

    cout << "Product of array except self: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
