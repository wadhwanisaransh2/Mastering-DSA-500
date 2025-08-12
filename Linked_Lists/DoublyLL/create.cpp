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
class DLL {
    public:
    Node *head;
    Node *tail;
    DLL() {
        head = tail = NULL;
    }
    void push_front(int val) {
        Node *newNode = new Node(val);
        if(head==NULL) {
            head =tail = newNode; 
        }
        else{
            newNode ->next = head; 
            head->prev = newNode;
            head = newNode;

        }
    }
    void printLL() {
        Node *temp = head;
        while(temp!=NULL) {
            cout<<temp->data<<"<=>";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};
int main() {
    DLL mylist; // Create an object of the DLL class
    mylist.push_front(1);
    mylist.push_front(2);
    mylist.push_front(3);
    mylist.printLL();
    return 0;
}