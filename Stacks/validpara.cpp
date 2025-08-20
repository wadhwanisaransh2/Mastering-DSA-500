#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            // If it's an opening bracket, push it
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } 
            else {
                // If closing bracket comes but stack is empty -> invalid
                if (st.empty()) return false;

                // Check if top of stack matches the current closing bracket
                if ((s[i] == ')' && st.top() == '(') ||
                    (s[i] == ']' && st.top() == '[') ||
                    (s[i] == '}' && st.top() == '{')) {
                    st.pop(); // matched pair, pop it
                } 
                else {
                    return false; // mismatch
                }
            }
        }
        // Valid only if no unmatched opening brackets remain
        return st.empty();
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << boolalpha; // print true/false instead of 1/0
    cout << sol.isValid("()") << endl;        // true
    cout << sol.isValid("()[]{}") << endl;    // true
    cout << sol.isValid("(]") << endl;        // false
    cout << sol.isValid("([)]") << endl;      // false
    cout << sol.isValid("{[]}") << endl;      // true
    cout << sol.isValid("(((") << endl;       // false

    return 0;
}
