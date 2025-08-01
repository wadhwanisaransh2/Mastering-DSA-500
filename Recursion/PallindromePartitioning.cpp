class Solution {
public:
    // Helper function to check if a string is a palindrome
    bool isPalin(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;}
        return true;
    }

    // Backtracking function to generate partitions
    void gap(string s, vector<string>& partition, vector<vector<string>>& ans) {
        if (s.size() == 0) {
            ans.push_back(partition);
            return;
        }
        int n = s.size();
        for (int i = 0; i < n; i++) {
            string part = s.substr(0, i + 1);
            if (isPalin(part)) {
                partition.push_back(part);
                gap(s.substr(i + 1), partition, ans);
                partition.pop_back(); // backtrack
            }
        }
    }

    // Main function to be called
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        gap(s, partition, ans);
        return ans;
    }
};
