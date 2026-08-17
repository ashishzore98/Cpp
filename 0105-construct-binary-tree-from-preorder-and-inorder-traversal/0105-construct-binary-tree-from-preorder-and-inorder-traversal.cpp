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
    unordered_map<int, int> ioi;
    int poi = 0;
    TreeNode* build(vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }
        int rv = preorder[poi++];
        TreeNode* r = new TreeNode(rv);
        int ri = ioi[rv];
        r->left = build(preorder, inStart, ri - 1);
        r->right = build(preorder, ri + 1, inEnd);
        return r;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            ioi[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }
};