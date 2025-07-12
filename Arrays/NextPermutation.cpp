#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& A) {
        // TC: O(n), SC: O(1)

        // Step 1: Find the pivot (first decreasing element from end)
        int pivot = -1;
        int n = A.size();
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot, reverse the entire array
        if (pivot == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // Step 3: Find the next larger element to the pivot from the end
        for (int i = n - 1; i > pivot; i--) {
            if (A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;
            }
        }

        // Step 4: Reverse the suffix after pivot
        reverse(A.begin() + pivot + 1, A.end());
    }
};

int main() {
    Solution obj;
    vector<int> A = {1, 2, 3};

    obj.nextPermutation(A);

    cout << "Next Permutation: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
