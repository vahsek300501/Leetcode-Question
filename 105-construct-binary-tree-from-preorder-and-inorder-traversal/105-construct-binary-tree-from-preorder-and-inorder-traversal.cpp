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
    TreeNode *
    buildTreePreorderInorder(vector<int> &preorder, vector<int> &inorder, int inorderS, int inorderE, int preorderS,
                             int preorderE) {
        if (inorderS > inorderE || preorderS > preorderE)
            return nullptr;

        TreeNode *root = new TreeNode(preorder.at(preorderS));
        int rootIndexInInorder = -1;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder.at(i) == root->val) {
                rootIndexInInorder = i;
                break;
            }
        }

        int leftIndexBeginIn = inorderS;
        int leftIndexEndIn = rootIndexInInorder - 1;
        int leftIndexBeginPre = preorderS + 1;
        int leftIndexEndPre = leftIndexBeginPre + (leftIndexEndIn - leftIndexBeginIn + 1) - 1;

        int rightIndexBeginPre = leftIndexEndPre + 1;
        int rightIndexEndPre = preorderE;
        int rightIndexBeginIn = rootIndexInInorder + 1;
        int rightIndexEndIn = inorderE;

        root->left = buildTreePreorderInorder(preorder, inorder, leftIndexBeginIn, leftIndexEndIn, leftIndexBeginPre,
                                              leftIndexEndPre);
        root->right = buildTreePreorderInorder(preorder, inorder, rightIndexBeginIn, rightIndexEndIn,
                                               rightIndexBeginPre, rightIndexEndPre);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreePreorderInorder(preorder, inorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }
};