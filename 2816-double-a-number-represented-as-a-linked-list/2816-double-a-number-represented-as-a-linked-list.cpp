class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        MyPair result = func(head);
        if (result.first != 0) {
            ListNode* new_head = new ListNode(result.first);
            new_head->next = result.second;
            return new_head;
        }
        return result.second;
    }
    
private:
    struct MyPair {
        int first;
        ListNode* second;
    };
    
    MyPair func(ListNode* head) {
        int a = head->val * 2;
        if (head->next) {
            MyPair next_result = func(head->next);
            a += next_result.first;
        }
        head->val = a % 10;
        return {a / 10, head};
    }
};