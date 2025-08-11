// Reverse a Linked List - Iterative Method
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr != NULL) {
        ListNode* nextNode = curr->next; // store next
        curr->next = prev;              // reverse pointer
        prev = curr;                    // move prev forward
        curr = nextNode;                 // move curr forward
    }
    return prev;
}
