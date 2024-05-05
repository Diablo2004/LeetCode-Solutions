class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr || node->next == nullptr) {
            return; // Cannot delete if node is null or last node
        }
        
        // Copy the value of the next node into the current node
        node->val = node->next->val;
        
        // Delete the next node by skipping it
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};