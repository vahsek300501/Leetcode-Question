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
    int goodNodesCount = 0;
    void goodNodesUtil(TreeNode * root,int parentVal) {
        if(root == nullptr)
            return;
        if(root->val >= parentVal) {
            goodNodesCount++;
            parentVal = root->val;
        }
        
        goodNodesUtil(root->left,parentVal);
        goodNodesUtil(root->right,parentVal);
    }

    int goodNodes(TreeNode* root) {
        goodNodesUtil(root,INT_MIN);
        return goodNodesCount;
    }
};