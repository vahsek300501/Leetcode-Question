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
   pair<bool, int> isBalancedUtil(TreeNode *root) {
        if (root == nullptr) {
            return make_pair(true, 0);
        }

        pair<bool, int> leftSubtree = isBalancedUtil(root->left);
        pair<bool, int> rightSubtree = isBalancedUtil(root->right);

        if (leftSubtree.first && rightSubtree.first && abs(leftSubtree.second - rightSubtree.second) <= 1)
            return make_pair(true, max(leftSubtree.second, rightSubtree.second) + 1);
        return make_pair(false, max(leftSubtree.second, rightSubtree.second) + 1);
    }

    bool isBalanced(TreeNode *root) {
        return isBalancedUtil(root).first;
    }
};