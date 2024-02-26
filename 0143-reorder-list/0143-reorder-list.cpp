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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            head=temp->next;
            temp->next=prev;
            prev=temp;
            temp=head;
        }
        return prev;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode * p=head;
        ListNode* s=middleNode(p);
        ListNode* q=reverseList(s->next);
        
        s->next=NULL;
        while(q!=NULL){
            ListNode* r=q->next;
            q->next=p->next;
            p->next=q;
            p=q->next;
            q=r;
        }
    }
    
};