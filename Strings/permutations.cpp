class Solution {
public:
    // Function to compare frequency arrays
    bool isfreqsame(int freq[], int win[]) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] != win[i])
                return false;
        }
        return true;
    }

    // Main function to check inclusion
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int freq[26] = {0};  // Frequency of characters in s1
        int win[26] = {0};   // Frequency of current window in s2
        int winSize = s1.length();

        // Count frequency of each character in s1
        for (char ch : s1) {
            freq[ch - 'a']++;
        }

        // Initialize the first window in s2
        for (int i = 0; i < winSize; i++) {
            win[s2[i] - 'a']++;
        }

        // Slide the window over s2
        for (int i = winSize; i < s2.length(); i++) {
            if (isfreqsame(freq, win)) return true;

            // Slide: remove the leftmost character and add the next one
            win[s2[i - winSize] - 'a']--; // Remove outgoing character
            win[s2[i] - 'a']++;           // Add incoming character
        }

        // Final check for the last window
        return isfreqsame(freq, win);
    }
};
