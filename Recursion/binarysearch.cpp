#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid]==key) {
            return mid;
        }
        if(arr[mid]>key) {
          return  binarySearch(arr,low,mid-1,key);
        }
        else {
           return binarySearch(arr,mid+1,high,key);
        }   
}
 return -1;
}
int main() {
    int arr[] = {2, 4, 6, 8, 10, 14, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
   int key = 10;
    cout<<binarySearch(arr, 0, n - 1, key);
    return 0;
}
