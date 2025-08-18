#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class with swapPairs function
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node to simplify edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (head && head->next) {
            // Nodes to be swapped
            ListNode* first = head;
            ListNode* second = head->next;

            // Swapping
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Move pointers
            prev = first;
            head = first->next;
        }

        return dummy.next;
    }
};

// Helper function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create list from vector
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Main function to test
int main() {
    vector<int> vals = {1, 2, 3, 4};
    ListNode* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.swapPairs(head);

    cout << "After swapping in pairs: ";
    printList(head);

    return 0;
}
