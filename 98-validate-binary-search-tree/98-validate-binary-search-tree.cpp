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

class NodeUtilClass {
public:
    bool foundBST;
    long long int minimumVal;
    long long int maximumVal;

    NodeUtilClass() {
        foundBST = false;
        minimumVal = LONG_LONG_MAX;
        maximumVal = LONG_LONG_MIN;
    }
};

class Solution {
public:
   NodeUtilClass isValidBSTUtil(TreeNode *root) {
        if (root == nullptr) {
            NodeUtilClass tmp;
            tmp.foundBST = true;
            return tmp;
        }

        NodeUtilClass leftVal = isValidBSTUtil(root->left);
        NodeUtilClass rightVal = isValidBSTUtil(root->right);

        NodeUtilClass cntNodeIsBST;
        if (leftVal.foundBST && rightVal.foundBST && root->val > leftVal.maximumVal &&
            root->val < rightVal.minimumVal) {
            cntNodeIsBST.foundBST = true;
            cntNodeIsBST.minimumVal = min(leftVal.minimumVal, min(rightVal.minimumVal, (long long int)root->val));
            cntNodeIsBST.maximumVal = max(leftVal.maximumVal, max(rightVal.maximumVal, (long long int)root->val));
            return cntNodeIsBST;
        }

        cntNodeIsBST.foundBST = false;
        cntNodeIsBST.minimumVal = min(leftVal.minimumVal, min(rightVal.minimumVal, (long long int)root->val));
        cntNodeIsBST.maximumVal = max(leftVal.maximumVal, max(rightVal.maximumVal, (long long int)root->val));
        return cntNodeIsBST;
    }

    bool isValidBST(TreeNode *root) {
        return isValidBSTUtil(root).foundBST;
    }
};