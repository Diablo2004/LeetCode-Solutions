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
    unordered_map<long,int> map;
    int count=0;
    
public:
    void helper(TreeNode* root,int target, long sum){
        if(!root)
            return;
        sum+=root->val;
        if(sum==target) count++;
        if(map.find(sum-target)!=map.end()){
            count+=map[sum-target];
        }
        map[sum]++;
        helper(root->left,target,sum);
        helper(root->right,target,sum);
        map[sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        helper(root,targetSum,0);
        return count;
    }
};