#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    void getallsubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allsubsets) {
        // Har recursive call par current subset ko push karo
        allsubsets.push_back(ans);

        // Loop i se chalu karke har element consider karo
        for (int idx = i; idx < nums.size(); ++idx) {
            // Agar same element pehle aa chuka hai same level pe, toh skip karo
            if (idx > i && nums[idx] == nums[idx - 1]) continue;

            // Element ko subset mein dalo
            ans.push_back(nums[idx]);

            // Next recursion ke liye call karo
            getallsubsets(nums, ans, idx + 1, allsubsets);

            // Backtrack: last element hata do
            ans.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Duplicate ko handle karne ke liye sort karo
        vector<vector<int>> allsubsets;
        vector<int> ans;
        getallsubsets(nums, ans, 0, allsubsets);
        return allsubsets;
    }
};

// Driver code (for testing)
int main() {
    Solution obj;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = obj.subsetsWithDup(nums);

    cout << "Unique Subsets are:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
