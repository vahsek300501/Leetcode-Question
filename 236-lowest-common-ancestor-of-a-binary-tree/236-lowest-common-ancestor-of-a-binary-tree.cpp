/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr)
            return nullptr;
        if (root->val == p->val || root->val == q->val)
            return root;

        TreeNode *leftSubTreeAns = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightSubTreeAns = lowestCommonAncestor(root->right, p, q);

        if (leftSubTreeAns == nullptr && rightSubTreeAns == nullptr)
            return nullptr;
        if (leftSubTreeAns == nullptr && rightSubTreeAns != nullptr)
            return rightSubTreeAns;
        if (leftSubTreeAns != nullptr && rightSubTreeAns == nullptr)
            return leftSubTreeAns;
        if (leftSubTreeAns != nullptr && rightSubTreeAns != nullptr)
            return root;
        return nullptr;
    }
};