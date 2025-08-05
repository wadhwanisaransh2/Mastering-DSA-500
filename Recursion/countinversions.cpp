#include <iostream>
#include <vector>
using namespace std;

long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftSub(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightSub(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    long long invCount = 0;

    while (i < leftSub.size() && j < rightSub.size()) {
        if (leftSub[i] <= rightSub[j]) {
            arr[k++] = leftSub[i++];
        } else {
            arr[k++] = rightSub[j++];
            invCount += (leftSub.size() - i); // All remaining elements in leftSub are greater
        }
    }

    while (i < leftSub.size()) arr[k++] = leftSub[i++];
    while (j < rightSub.size()) arr[k++] = rightSub[j++];

    return invCount;
}

long long mergeSortAndCount(vector<int>& arr, int left, int right) {
    long long invCount = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;
        invCount += mergeSortAndCount(arr, left, mid);
        invCount += mergeSortAndCount(arr, mid + 1, right);
        invCount += mergeAndCount(arr, left, mid, right);
    }

    return invCount;
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    long long inversions = mergeSortAndCount(arr, 0, arr.size() - 1);
    cout << "Number of inversions: " << inversions << endl;
    return 0;
}
