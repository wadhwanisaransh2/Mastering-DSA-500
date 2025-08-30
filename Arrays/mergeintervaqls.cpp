#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (auto interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            else {
                // Overlapping → merge by updating end
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }}
        return merged;
    }
};