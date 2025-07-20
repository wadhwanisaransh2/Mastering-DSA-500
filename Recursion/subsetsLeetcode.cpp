#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to generate all subsets
    void backtrack(vector<int>& nums, vector<int>& subset, int index, vector<vector<int>>& result) {
        result.push_back(subset);  // Add current subset to result

        for (int i = index; i < nums.size(); ++i) {
            subset.push_back(nums[i]);                // Choose element
            backtrack(nums, subset, i + 1, result);   // Recurse
            subset.pop_back();                        // Backtrack
        }
    }

    // Main function to return all subsets
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(nums, subset, 0, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};  // You can change input here

    vector<vector<int>> allSubsets = sol.subsets(nums);

    cout << "All subsets:\n";
    for (const auto& subset : allSubsets) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
