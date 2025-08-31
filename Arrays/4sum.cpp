#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixCount; 
        prefixCount[0] = 1; // prefix sum zero exists once

        int prefixSum = 0, count = 0;
        for (int num : nums) {
            prefixSum += num;

            // check if (prefixSum - k) was seen before
            if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
                count += prefixCount[prefixSum - k];
            }

            prefixCount[prefixSum]++;
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    int k = 3;

    cout << "Count of subarrays with sum " << k << " = " 
         << s.subarraySum(nums, k) << "\n";
    return 0;
}
