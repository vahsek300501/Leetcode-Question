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

class PathSum {
public:
    int leftSum;
    int rightSum;
    int maxSum;

};
class Solution {
public:
    PathSum maxPathSumUtil(TreeNode *root) {
        if (root == nullptr) {
            PathSum tmpSum{};
            tmpSum.maxSum = INT_MIN;
            tmpSum.leftSum = 0;
            tmpSum.rightSum = 0;
            return tmpSum;
        }

        PathSum leftSubtree = maxPathSumUtil(root->left);
        PathSum rightSubtree = maxPathSumUtil(root->right);

        PathSum ans{};
        int onlyLeftMax = leftSubtree.maxSum;
        int onlyRightMax = rightSubtree.maxSum;
        int leftAndRoot = max(leftSubtree.leftSum + root->val, leftSubtree.rightSum + root->val);
        int rightAndRoot = max(rightSubtree.rightSum + root->val,rightSubtree.leftSum+root->val);
        int leftRootRight = max(leftSubtree.leftSum,leftSubtree.rightSum) + max(rightSubtree.rightSum,rightSubtree.leftSum) + root->val;

        ans.maxSum = max(onlyLeftMax,
                         max(onlyRightMax, max(leftAndRoot, max(rightAndRoot, max(root->val, leftRootRight)))));
        ans.leftSum = max(leftAndRoot, max(root->val, 0));
        ans.rightSum = max(rightAndRoot, max(root->val, 0));
        return ans;
    }

    int maxPathSum(TreeNode *root) {
        return maxPathSumUtil(root).maxSum;
    }
};