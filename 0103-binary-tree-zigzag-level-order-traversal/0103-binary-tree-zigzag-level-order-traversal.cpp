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
        if (!root) {
            return result;
        }
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            deque<int> currentLevel;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (level % 2 == 0) {
                    currentLevel.push_back(node->val);
                } else {
                    currentLevel.push_front(node->val);
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            vector<int> currentLevelVec;
            for (auto& val : currentLevel) {
                currentLevelVec.push_back(val);
            }
            result.push_back(currentLevelVec);
            level++;
        }
        return result;
    }
};