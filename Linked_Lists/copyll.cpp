#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // Step 1: Clone each node and insert it right after the original node
        Node* curr = head;
        while (curr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        // Step 2: Assign random pointers to cloned nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate original list and cloned list
        curr = head;
        Node* newHead = head->next;
        Node* copy = newHead;

        while (curr) {
            curr->next = curr->next->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            curr = curr->next;
            copy = copy->next;
        }

        return newHead;
    }
};

// 🔹 Helper function to print list (val + random)
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << "Node(" << curr->val << ")";
        if (curr->random) {
            cout << " [random -> " << curr->random->val << "]";
        } else {
            cout << " [random -> NULL]";
        }
        cout << endl;
        curr = curr->next;
    }
}

int main()
 {    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->next = n3;

    n1->random = n3; // 1 -> 3
    n2->random = n1; // 2 -> 1
    n3->random = n2; 

    cout << "Original List:\n";
    printList(n1);

    Solution sol;
    Node* copiedHead = sol.copyRandomList(n1);

    cout << "\nCopied List:\n";
    printList(copiedHead);

    return 0;
}
