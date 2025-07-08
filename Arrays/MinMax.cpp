#include <iostream>
#include <vector>
#include <climits> 
using namespace std;
class Solution {
public:
    pair<int, int> getMinMax(vector<int> arr) {
        int max = INT_MIN, min = INT_MAX;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return {min, max};
    }
};
int main() {
    Solution sol;
    vector<int> arr;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    pair<int, int> result = sol.getMinMax(arr);
    cout << "Minimum element: " << result.first << endl;
    cout << "Maximum element: " << result.second << endl;
    return 0;
}
