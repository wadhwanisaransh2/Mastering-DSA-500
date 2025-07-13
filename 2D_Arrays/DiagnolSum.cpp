#include<iostream>
using namespace std;
int DiagnolSum(int matrix[][3],int r,int c){
    int sum =0;
    for(int i=0;i<r;i++) {
        
        sum += matrix[i][i];
        if(i!=r-i-1)
            sum += matrix[i][r-1-i];
    }

return sum;
}
int main() {
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int key = 20;
   int pos= DiagnolSum(matrix,3,3);
   cout<<pos;
    return 0;
}