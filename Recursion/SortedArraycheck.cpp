#include <iostream>
using namespace std;
bool isSorted(int arr[], int n) {
       if(n==1) {
        return true;
       }
    if(arr[n-1]<arr[n-2]) {
        return false;
    }
    return  isSorted(arr,n-1);
}

int main() {
    int arr[] = {1, 2, 3, 15, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSorted(arr, n))
        cout << "Array is sorted\n";
    else
        cout << "Array is NOT sorted\n";

    return 0;
}
