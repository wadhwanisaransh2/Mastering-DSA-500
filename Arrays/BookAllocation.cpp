#include<iostream>
using namespace std;
bool isValid(int arr[],int n,int m,int maxallowages) {
    int student = 1;
    int pages = 0;
    for(int i=0;i<n;i++) {
         if(arr[i]>maxallowages) {
            return false;
        }
        if(pages+arr[i]<=maxallowages) {
            pages+=arr[i];
        }
        else{
            student++;
            pages = arr[i];
        }
    }
    if(student>m) {
        return false;
    }
    else{
        return true;
    }
}
int allocatebooks (int arr[],int n,int m) {
    if(m>n) return -1;
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += arr[i];
    }
    int st = 0;
   int end = sum,answer=-1;
while(st<=end) {
    int mid = st+(end-st)/2;
    if(isValid(arr,n,m,mid)) {
        answer = mid;
        end = mid-1;

    }
    else{
        st = mid+1;
    }
}
return answer;
}
int main() {
int arr [ ] = {2,1,3,4};
    int n = 4,m=2;

cout<<allocatebooks(arr,n,m);
    return 0;
}