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
    void insertattail(int val) {
          Node *newnode = new Node(val);
        if(head==NULL) {
            head = tail = newnode;
            tail -> next  = head;
        }
        else{
            newnode->next = head;
            tail ->next = newnode;
            tail = newnode;
        }
    }
    void deleteathead() {
        if(head ==NULL) {
            return;
        }
        else if(head==tail) {
            delete head;
            head = tail = NULL;
        }
        else{
            Node *temp = head;
            head=head->next;
            tail ->next = head;
            temp ->next= NULL;
            delete temp;
        }
    }
};
int main() {
    CircularLL ll;
    ll.InsertatHead(1);
    ll.InsertatHead(2);
    ll.InsertatHead(3);
    ll.insertattail(4);
    ll.insertattail(5);
    ll.insertattail(6);
    ll.deleteathead();
    ll.print();
    return 0;
}