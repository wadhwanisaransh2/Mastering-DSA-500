#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class List {
    Node *head;
    Node *tail;
    public:
    List() {
        head=tail=NULL;
    }
    //Create a new Node
    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head==NULL) {
            head = tail=newNode;
            return;
        }
    }
};
int main() {
    List ll;
    return 0;
}