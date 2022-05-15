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
    int treeDepth(TreeNode * root) {
        if(root == nullptr)
            return 0;
        return 1 + max(treeDepth(root->left),treeDepth(root->right));
    }
    void getSum(TreeNode * root, int & sum,int cntDepth,int maxDepth) {
        if(root == nullptr)
            return;
        if(cntDepth == maxDepth)
            sum += root->val;
        getSum(root->left,sum,cntDepth+1,maxDepth);
        getSum(root->right,sum,cntDepth+1,maxDepth);
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int maxDepth = treeDepth(root);
        // cout<<maxDepth<<endl;
        getSum(root,sum,1,maxDepth);
        return sum;
    }
};