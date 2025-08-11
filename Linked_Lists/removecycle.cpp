// Remove Cycle if exists
void removeCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    // No cycle
    if (fast == NULL || fast->next == NULL) return;

    // Find start of cycle
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // Break cycle
    fast->next = NULL;
}
