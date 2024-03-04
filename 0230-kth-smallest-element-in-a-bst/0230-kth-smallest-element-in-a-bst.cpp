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
private:
    TreeNode* findRoot(TreeNode*root,int& i,int k){
        if(!root){
            return nullptr;    
        }
        
        TreeNode* left=findRoot(root->left,i,k);
        if(left){
            return left;
        }
        i++;
        if(i==k){
            return root;
        }
        return findRoot(root->right,i,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root){
            return -1;
        }
        int i=0;
        TreeNode* final=findRoot(root,i,k);
        return final ? final->val : -1;
    }
};