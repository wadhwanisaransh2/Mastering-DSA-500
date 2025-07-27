class Solution {
public:
    void solve(int index, vector<int>& candidates, int target, vector<int>& combine, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(combine); // found a valid combination
            return;
        }
        if (index == candidates.size() || target < 0) return;

        // Include the current number
        combine.push_back(candidates[index]);
        solve(index, candidates, target - candidates[index], combine, ans);  // not index + 1, because we can reuse the same number
        combine.pop_back(); // backtrack

        // Exclude the current number and move to next
        solve(index + 1, candidates, target, combine, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        solve(0, candidates, target, combine, ans);
        return ans;
    }
};
    