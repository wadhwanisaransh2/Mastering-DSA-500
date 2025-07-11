#include<iostream>
using namespace std;
int main() {
    char str[] = {'a','b','c'};
    int n = sizeof(str)/sizeof(char);
    cout<<str; 
    cout<<" "<<n;
    return 0;
}