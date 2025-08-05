#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Helper function to check if a string is a palindrome
    bool isPalin(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void gap(string s, vector<string>& partition, vector<vector<string>>& ans) {
        if (s.empty()) {
            ans.push_back(partition); // found a valid partition
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1); // prefix substring
            if (isPalin(part)) {
                partition.push_back(part); // choose
                gap(s.substr(i + 1), partition, ans); // explore
                partition.pop_back(); // unchoose (backtrack)
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        gap(s, partition, ans);
        return ans;
    }
};
int main() {
    Solution sol;
    string input;
    cout << "Enter a string: ";
    cin >> input;
    vector<vector<string>> result = sol.partition(input);
    cout << "\nAll Palindrome Partitions:\n";
    for (const auto& partition : result) {
        cout << "[ ";
        for (const string& s : partition) {
            cout << "\"" << s << "\" ";
        }
        cout << "]\n";
    }
         return 0;
}
