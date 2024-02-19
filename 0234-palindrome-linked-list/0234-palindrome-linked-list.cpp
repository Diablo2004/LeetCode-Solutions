/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        // Find the middle of the list and reverse the first half
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        
        // Adjust pointers for odd-length lists
        ListNode* firstHalf = prev;
        ListNode* secondHalf = (fast == nullptr) ? slow : slow->next;
        
        // Compare the first half with the reversed second half
        while (secondHalf != nullptr) {
            if (firstHalf->val != secondHalf->val)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true;
        
    }
};