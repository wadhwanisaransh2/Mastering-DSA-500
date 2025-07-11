#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int count = 0;

        // Step 1: Convert to lowercase and keep only valid characters in-place
        for (int i = 0; i < n; i++) {
            if (s[i] >= 65 && s[i] <= 90) {
                s[i] = s[i] - 'A' + 'a';  // Convert uppercase to lowercase
            }
            if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)) {
                s[count++] = s[i];  // Keep valid character
            }
        }

        // Step 2: Check for palindrome
        int st = 0, end = count - 1;
        while (st <= end) {
            if (s[st] != s[end]) {
                return false;
            }
            st++;
            end--;
        }

        return true;
    }
};

// Optional: main function for testing
int main() {
    Solution sol;
    string test = "A man, a plan, a canal: Panama";
    cout << (sol.isPalindrome(test) ? "true" : "false") << endl;
    return 0;
}
