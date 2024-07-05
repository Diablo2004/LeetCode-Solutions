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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        int position=0;
        while(curr!=nullptr && curr->next!=nullptr){
            if(prev!=nullptr && curr->next!=nullptr){
                if((curr->val>prev->val && curr->val>curr->next->val) || (curr->val<prev->val && curr->val<curr->next->val)){
                    critical.push_back(position);
                }
            }
            prev=curr;
            curr=curr->next;
            position++;
        }
    
        
        if(critical.size()<2) return {-1,-1};
        int max_dist=critical.back()-critical.front();
        int min_dist=INT_MAX;
        for(int i=1;i<critical.size();i++){
            min_dist=min(min_dist,critical[i]-critical[i-1]);
        }
        vector<int> ans;
        ans.push_back(min_dist);
        ans.push_back(max_dist);
        return ans;
    }
};