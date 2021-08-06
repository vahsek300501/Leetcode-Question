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
//     void invertTree(TreeNode* root, TreeNode * newRoot) {
//         if(root == NULL)
//             return;
        
//         newRoot = newNode;
//         invertTree(root->left,newRoot->right);
//         invertTree(root->right,newRoot->left);
//     }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        TreeNode* newNode = new TreeNode(root->val);
        newNode->right = invertTree(root->left);
        newNode->left = invertTree(root->right);
        return newNode;
    }
};