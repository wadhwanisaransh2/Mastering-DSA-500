#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(), s.end());  // Step 1: reverse entire string
        string ans;

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') continue;  // skip extra spaces

            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());  // Step 2: reverse individual word
            ans += " " + word;
        }

        return ans.substr(1);  // Remove leading space
    }
};

int main() {
    Solution sol;
    string input = "  hello   world  ";
    cout << '"' << sol.reverseWords(input) << '"' << endl;
    return 0;
}
