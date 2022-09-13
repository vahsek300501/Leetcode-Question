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
    bool isSymmetricUtil(TreeNode * leftSubtree, TreeNode * rightSubtree) {
        if(leftSubtree == nullptr && rightSubtree == nullptr)
            return true;
        if(leftSubtree == nullptr && rightSubtree != nullptr)
            return false;
        if(leftSubtree != nullptr && rightSubtree == nullptr)
            return false;
        
        bool isLeftTrue = isSymmetricUtil(leftSubtree->left,rightSubtree->right);
        bool isRightTrue = isSymmetricUtil(leftSubtree->right,rightSubtree->left);
        
        if(leftSubtree->val == rightSubtree->val && isLeftTrue && isRightTrue)
            return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetricUtil(root,root);
    }
};