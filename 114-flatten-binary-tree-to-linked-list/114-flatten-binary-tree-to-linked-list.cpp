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
    pair<TreeNode *, TreeNode *> flattenUtil(TreeNode *root) {
        if (root == nullptr)
            return make_pair(nullptr, nullptr);
        TreeNode *leftTmp = root->left;
        TreeNode *rightTmp = root->right;
        root->left = nullptr;
        root->right = nullptr;
        pair<TreeNode *, TreeNode *> leftFlattened = flattenUtil(leftTmp);
        pair<TreeNode *, TreeNode *> rightFlattened = flattenUtil(rightTmp);
        if (leftFlattened.first == nullptr && rightFlattened.first == nullptr) {
            return make_pair(root, root);
        } else if (leftFlattened.first == nullptr && rightFlattened.first != nullptr) {
            root->right = rightFlattened.first;
            return make_pair(root, rightFlattened.second);
        } else if (leftFlattened.first != nullptr && rightFlattened.first == nullptr) {
            root->right = leftFlattened.first;
            return make_pair(root, leftFlattened.second);
        } else {
            root->right = leftFlattened.first;
            leftFlattened.second->right = rightFlattened.first;
            return make_pair(root, rightFlattened.second);
        }
        return make_pair(nullptr, nullptr);
    }

    void flatten(TreeNode *root) {
        flattenUtil(root);
    }
};