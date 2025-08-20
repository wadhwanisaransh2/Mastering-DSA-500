#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Stack{
    vector<int> v;
 public:
    void push(int val) {
       
    }
    void pop() {
       
    }
    int top() {
        
    }
    bool isempty() {
       
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.isempty() ) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}