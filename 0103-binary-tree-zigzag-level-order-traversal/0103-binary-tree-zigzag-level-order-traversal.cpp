/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root){
            return result;
        }
        queue<TreeNode*> q;
        int level=0;
        q.push(root);
        while(!q.empty()){
            int levelSize=q.size();
            vector<int> current;
            reverseQueue(q);
            if(level%2==1){
                for (int i = 0; i < levelSize; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    current.push_back(node->val);

                    if (node->right)
                        q.push(node->right);
                    if (node->left)
                        q.push(node->left);
                }
            }else{
                for (int i = 0; i < levelSize; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    current.push_back(node->val);

                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
                
            }
            level++;
            result.push_back(current);
        }
        return result;
    }
    void reverseQueue(queue<TreeNode*>& q) {
        stack<TreeNode*> s;
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
    }
};