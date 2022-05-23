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
#define MOD 1000000007
class Solution {
public:
    void treeNodeSum(TreeNode *root, long long int &sum) {
        if (root == nullptr)
            return;
        treeNodeSum(root->left, sum);
        sum += root->val;
        treeNodeSum(root->right, sum);
    }

    long long int maximumProduct = 0;

    long long int maxProductUtil(TreeNode *root, long long int totalSum) {
        if (root == nullptr)
            return 0;

        long long int leftSubTreeSum = maxProductUtil(root->left, totalSum);
        long long int rightSubTreeSum = maxProductUtil(root->right, totalSum);
        long long int cntSubtreeSum = leftSubTreeSum + rightSubTreeSum + root->val;
        int remainingSum = totalSum - cntSubtreeSum;
        maximumProduct = max(maximumProduct,(remainingSum * cntSubtreeSum));

        return cntSubtreeSum;
    }

    int maxProduct(TreeNode *root) {
        long long int totalSum = 0;
        treeNodeSum(root, totalSum);
        maxProductUtil(root, totalSum);
        return maximumProduct%MOD;
    }
};