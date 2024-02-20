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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL){
            return NULL;
        }
        ListNode*p=head;
        ListNode*q=p->next;
        ListNode* r=q;
        
        while(q!=NULL && q->next!=NULL ){
            p->next=q->next;
            p=p->next;
            q->next=p->next;
            q=q->next;
        }
        p->next=r;
        return head;
    }
};