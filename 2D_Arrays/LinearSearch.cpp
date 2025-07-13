#include<iostream>
using namespace std;
pair<int,int> LinearSearch(int matrix[][3],int r,int c,int key){
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(matrix[i][j] == key) {
                return {i, j};
            }
        }
    }
    return {-1,-1};
}
int main() {
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int key = 20;
   pair<int,int> pos= LinearSearch(matrix,3,3,key);
    cout << "Element found at (" << pos.first << ", " << pos.second << ")\n";
    return 0;
}