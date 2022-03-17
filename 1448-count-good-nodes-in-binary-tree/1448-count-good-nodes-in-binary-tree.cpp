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
    int countGoodNodes(TreeNode *root, int cntMax) {
        if (root == nullptr)
            return 0;
        int tmpCount = 0;
        if (root->val >= cntMax)
            tmpCount++;
        if (root->val > cntMax) {
            tmpCount += countGoodNodes(root->left, root->val);
            tmpCount += countGoodNodes(root->right, root->val);
        } else {
            tmpCount += countGoodNodes(root->left, cntMax);
            tmpCount += countGoodNodes(root->right, cntMax);
        }

        return tmpCount;
    }

    int goodNodes(TreeNode *root) {
        if (root == nullptr)
            return 0;
        return countGoodNodes(root, root->val);
    }
};