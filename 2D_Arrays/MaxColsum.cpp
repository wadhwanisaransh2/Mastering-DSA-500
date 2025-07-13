#include<iostream>
using namespace std;
int MaxrowSum(int matrix[][3],int r,int c){
    int sum ;
    int maxsum = INT8_MIN;
    for(int j=0;j<c;j++) {
        sum = 0;
        for(int i=0;i<r;i++) {
           sum += matrix[i][j];
        }
        maxsum = max(sum,maxsum);
    }
return maxsum;
}
int main() {
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int key = 20;
   int pos= MaxrowSum(matrix,3,3);
   cout<<pos;
    return 0;
}