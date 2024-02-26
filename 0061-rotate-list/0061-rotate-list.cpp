class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        
        // Find the length of the list
        int length = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }
        
        // Make k valid
        k = k % length;
        
        // If k is zero, no rotation needed
        if (k == 0) {
            return head;
        }
        
        // Find the new head and new tail positions
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }
        
        // Update pointers to create the rotated list
        ListNode* newHead = newTail->next;
        tail->next = head; // Make the original list circular
        newTail->next = nullptr; // Set the new tail's next pointer to null
        
        return newHead;
    }
};
