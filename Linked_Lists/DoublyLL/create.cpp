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
    void push_back(int val) {
        Node *newNode = new Node(val);
        if(head==NULL) {
            head =tail = newNode; 
        }
        else{
            tail ->next = newNode;
            newNode->prev  = tail;
            newNode->next  = NULL;
            tail = newNode;
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
   void pop_front() {
    if (head == NULL) {
        // Empty list
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;  // remove link to old head
    } else {
        tail = NULL;        // list is now empty
    }

    delete temp; // free memory
}
void pop_back() {
    if(head==NULL) {
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    temp->prev = NULL;
    tail->next = NULL;
    
    delete temp;
}
};
int main() {
    DLL mylist; // Create an object of the DLL class
    mylist.push_front(1);
    mylist.push_front(2);
    mylist.push_front(3);
    mylist.push_back(3);
    mylist.push_back(4);
    mylist.pop_front();
    mylist.pop_back();
    mylist.printLL();
    return 0;
}