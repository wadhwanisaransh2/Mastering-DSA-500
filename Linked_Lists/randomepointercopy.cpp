// Copy List with Random Pointer
struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(NULL), random(NULL) {}
};

Node* copyRandomList(Node* head) {
    if (!head) return NULL;

    // Step 1: Create new nodes
    Node* curr = head;
    while (curr) {
        Node* newNode = new Node(curr->val);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }

    // Step 2: Set random pointers
    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // Step 3: Separate two lists
    curr = head;
    Node* newHead = head->next;
    Node* copy = newHead;
    while (curr) {
        curr->next = curr->next->next;
        if (copy->next)
            copy->next = copy->next->next;
        curr = curr->next;
        copy = copy->next;
    }
    return newHead;
}
