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
    int robUtil(TreeNode *root, unordered_map<TreeNode *, int> &nodeMap) {
        if (root == nullptr)
            return 0;
        if (nodeMap.find(root) != nodeMap.end())
            return nodeMap[root];

        int inclusion = root->val;
        if (root->left != nullptr) {
            inclusion += robUtil(root->left->left, nodeMap) + robUtil(root->left->right, nodeMap);
        }
        if (root->right != nullptr) {
            inclusion += robUtil(root->right->right, nodeMap) + robUtil(root->right->left, nodeMap);
        }
        int exclusion = robUtil(root->left, nodeMap) + robUtil(root->right, nodeMap);
        nodeMap[root] = max(inclusion, exclusion);
        return max(inclusion, exclusion);
    }

    int rob(TreeNode *root) {
        unordered_map<TreeNode *, int> nodeMap;
        return robUtil(root, nodeMap);
    }
};