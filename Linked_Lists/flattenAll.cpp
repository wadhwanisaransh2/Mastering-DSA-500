#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        flattenDFS(head);
        return head;
    }

private:
    // Returns tail after flattening
    Node* flattenDFS(Node* node) {
        Node* curr = node;
        Node* last = nullptr;

        while (curr) {
            Node* next = curr->next;

            // if child exists → flatten it
            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = flattenDFS(childHead);

                // connect current node with child
                curr->next = childHead;
                childHead->prev = curr;

                // if next exists, connect child tail with next
                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }

                // remove child pointer
                curr->child = nullptr;
                last = childTail;
            } else {
                last = curr;
            }
            curr = next;
        }
        return last;
    }
};
