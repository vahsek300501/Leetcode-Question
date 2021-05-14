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
    int sum = 0;
    int getDepthOfTree(TreeNode *root) {
        if (root == nullptr)
            return 0;
        return max(1 + getDepthOfTree(root->left), 1 + getDepthOfTree(root->right));
    }

    void deepestLeavesSumUtil(TreeNode *root,int crntLevel, int d) {
        if(root == nullptr)
            return;
        if(crntLevel >= d){
            sum += root->val;
        }
            
        deepestLeavesSumUtil(root->left,crntLevel+1,d);
        deepestLeavesSumUtil(root->right,crntLevel+1,d);
    }

    int deepestLeavesSum(TreeNode *root) {
        int d = getDepthOfTree(root);
        deepestLeavesSumUtil(root,0,d-1);
        return sum;
    }
};