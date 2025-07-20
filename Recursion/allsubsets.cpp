#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int>& arr, vector<int>& subset, int index) {
    if (index == arr.size()) {
        // Print current subset
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
        return;
    }

    // Exclude the current element
    printSubsets(arr, subset, index + 1);

    // Include the current element
    subset.push_back(arr[index]);
    printSubsets(arr, subset, index + 1);

    // Backtrack
    subset.pop_back();
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> subset;

    cout << "All subsets:\n";
    printSubsets(arr, subset, 0);

    return 0;
}
