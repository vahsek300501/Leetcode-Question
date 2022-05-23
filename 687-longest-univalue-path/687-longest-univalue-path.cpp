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
    int longestPath = 1;

    pair<int, int> longestUniValuePathUtil(TreeNode *root) {
        if (root == nullptr)
            return make_pair(INT_MIN, INT_MIN);
        pair<int, int> leftLongestUniVal = longestUniValuePathUtil(root->left);
        pair<int, int> rightLongestUniVal = longestUniValuePathUtil(root->right);
        pair<int, int> rootData = make_pair(root->val, 1);
        int tmp = 1;
        if (leftLongestUniVal.first == root->val) {
            tmp += leftLongestUniVal.second;
        }
        if (rightLongestUniVal.first == root->val) {
            tmp += rightLongestUniVal.second;
        }
        longestPath = max(longestPath,max(tmp, max(leftLongestUniVal.second, rightLongestUniVal.second)));
        if (leftLongestUniVal.first == root->val) {
            rootData.second = max(rootData.second, 1 + leftLongestUniVal.second);
        }
        if (rightLongestUniVal.first == root->val) {
            rootData.second = max(rootData.second, 1 + rightLongestUniVal.second);
        }
        return rootData;
    }

    int longestUnivaluePath(TreeNode *root) {
        pair<int, int> rootData = longestUniValuePathUtil(root);
        return longestPath-1;
    }
};