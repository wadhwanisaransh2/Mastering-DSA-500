#include<iostream>
using namespace std;
class Node{
    public:
    int data ;
     Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};
class DoublyLL {
    public:
    
    Node *head;
    Node *tail;
    DoublyLL() {
        head = tail = NULL;
    }

};
int main() {

    return 0;
}