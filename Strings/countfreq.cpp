#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    unordered_map<char, int> freq;

    for (char ch : str) {
        if (ch != ' ')
            freq[ch]++;
    }

    cout << "Character frequencies:\n";
    for (auto pair : freq) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
