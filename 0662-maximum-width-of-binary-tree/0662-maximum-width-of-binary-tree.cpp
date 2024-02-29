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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
    
    int maxWidth = 0;
    queue<pair<TreeNode*, unsigned long long>> q; // Using unsigned long long to prevent overflow
    q.push({root, 1}); // Start index is 1
    
    while (!q.empty()) {
        int size = q.size();
        unsigned long long left = q.front().second, right = left; // Initializing left and right with first element
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front().first;
            unsigned long long index = q.front().second;
            q.pop();
            
            right = index; // Update right index
            
            if (node->left) q.push({node->left, 2 * index});
            if (node->right) q.push({node->right, 2 * index + 1});
        }
        maxWidth = max(maxWidth, static_cast<int>(right - left + 1));
    }
    
    return maxWidth;
    }
};