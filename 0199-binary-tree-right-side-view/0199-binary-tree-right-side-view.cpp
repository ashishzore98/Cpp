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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> r;
        if (root == nullptr) {
            return r;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int ls = q.size();
            for (int i = 0; i < ls; i++) {
                TreeNode* c = q.front();
                q.pop();
                if (c->left != nullptr) {
                    q.push(c->left);
                }
                if (c->right != nullptr) {
                    q.push(c->right);
                }
                if (i == ls - 1) {
                    r.push_back(c->val);
                }
            }
        }
        return r;
    }
};