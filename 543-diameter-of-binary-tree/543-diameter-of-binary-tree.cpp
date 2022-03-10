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
    pair<int, int> diameterUtil(TreeNode *root) {
        if (root == nullptr)
            return make_pair(0, 0);
        pair<int, int> leftVal = diameterUtil(root->left);
        pair<int, int> rightVal = diameterUtil(root->right);
        
        return make_pair(max(leftVal.first, max(rightVal.first, leftVal.second + rightVal.second)),
                         max(leftVal.second, rightVal.second)+1);
    }

    int diameterOfBinaryTree(TreeNode *root) {
        return diameterUtil(root).first;
    }
};