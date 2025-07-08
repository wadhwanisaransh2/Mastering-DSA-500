#include<iostream>
#include<algorithm> // for sort()
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 1, 1};
    int n = sizeof(arr) / sizeof(int); 
    int target = 3;

    sort(arr, arr + n); // Sorting is essential for two-pointer technique

    int i = 0, j = n - 1;
    bool found = false;

    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == target) {
            cout << "Pair found: " << arr[i] << " + " << arr[j] << " = " << target << endl;
            found = true;
            break;
        }
        else if (sum > target) {
            j--;
        }
        else {
            i++;
        }
    }

    if (!found) {
        cout << "No pair found with sum " << target << endl;
    }

    return 0;
}
