#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next= NULL;
    }
};
class CircularLL{
    Node *head ;
    Node *tail;
public :
    CircularLL() {
        head = tail = NULL;
    }
    void InsertatHead(int val) {
        Node *newnode = new Node(val);
        if(head==NULL) {
            head = tail = newnode;
            tail -> next  = head;
        }
        else{
            newnode->next = head;
            head = newnode;
            tail ->next = head;
        }
    }

    void print() {
        if(head == NULL) {
            return;
        }
        cout<<head->data<<"<=>";
        Node *temp = head->next;
        while(temp!=head) {
            cout<<temp->data<<"<=>";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};
int main() {
    CircularLL ll;
    ll.InsertatHead(1);
    ll.InsertatHead(2);
    ll.InsertatHead(3);
    ll.print();
    return 0;
}