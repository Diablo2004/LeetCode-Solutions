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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        int sum=0;
        solve(root,targetSum,result,path,sum);
        return result;

        
    }
private:
    void solve(TreeNode* root,int targetSum,vector<vector<int>> &result, vector<int> path,int sum){
        if (!root){
            return;
        }
        sum+=root->val;
        path.push_back(root->val);
        
        
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                result.push_back(path);
            }
            else{
                return;
            }
        }
        solve(root->left,targetSum,result,path,sum);
        solve(root->right,targetSum,result,path,sum);
      
    }
};