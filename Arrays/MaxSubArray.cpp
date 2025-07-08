#include<iostream>
#include<climits>
using namespace std;

int main() {
    int arr[] = {3, -5, 4, -1, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    int maxSum = arr[0];
    int currSum = arr[0];

    for(int i = 1; i < n; i++) {
        // At every step, either start new subarray or extend previous one
        currSum = max(arr[i], currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }

    cout << "Maximum subarray sum is: " << maxSum << endl;

    return 0;
}
