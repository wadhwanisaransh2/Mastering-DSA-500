#include<iostream>
using namespace std;
int main() {
    int matrix[4][3];
 for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            cin>>matrix[i][j];
        }
        
    }
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
