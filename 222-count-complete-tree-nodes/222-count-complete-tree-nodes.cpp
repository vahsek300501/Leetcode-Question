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
    int postorderUtil(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left = postorderUtil(root->left);
        int right = postorderUtil(root->right);
        return left + right + 1;
    }

    int countNodes(TreeNode *root) {
        return postorderUtil(root);
    }
};