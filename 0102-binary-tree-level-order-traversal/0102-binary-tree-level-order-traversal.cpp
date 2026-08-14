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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> r;
        if (root == nullptr) {
            return r;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int ls = q.size();
            vector<int> cl;
            for (int i = 0; i < ls; i++) {
                TreeNode* n = q.front();
                q.pop();
                cl.push_back(n->val);
                if (n->left != nullptr) {
                    q.push(n->left);
                }
                if (n->right != nullptr) {
                    q.push(n->right);
                }
            }
            r.push_back(cl);
        }
        return r;
    }
};