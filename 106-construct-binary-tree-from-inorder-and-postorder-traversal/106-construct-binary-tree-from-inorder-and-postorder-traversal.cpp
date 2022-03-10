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
    TreeNode *buildTreeFromPostorderInorder(vector<int> &postorder, vector<int> inorder, int inorderS, int inorderE,
                                            int postOrderS, int postOrderE) {
        if (inorderS > inorderE || postOrderS > postOrderE)
            return nullptr;

        auto *root = new TreeNode(postorder.at(postOrderE));
        int rootIndexInInorder = -1;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder.at(i) == root->val) {
                rootIndexInInorder = i;
                break;
            }
        }

        int leftIndexBeginIn = inorderS;
        int leftIndexEndIn = rootIndexInInorder - 1;
        int leftIndexBeginPost = postOrderS;
        int leftIndexEndPost = postOrderS + (leftIndexEndIn - leftIndexBeginIn + 1) - 1;

        int rightIndexBeginIn = rootIndexInInorder + 1;
        int rightIndexEndIn = inorderE;
        int rightIndexBeginPost = leftIndexEndPost + 1;
        int rightIndexEndPost = postOrderE - 1;

        root->left = buildTreeFromPostorderInorder(postorder, inorder, leftIndexBeginIn, leftIndexEndIn,
                                                   leftIndexBeginPost, leftIndexEndPost);
        root->right = buildTreeFromPostorderInorder(postorder, inorder, rightIndexBeginIn, rightIndexEndIn,
                                                    rightIndexBeginPost, rightIndexEndPost);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int inorderLen = inorder.size();
        int postorderLen = postorder.size();
        return buildTreeFromPostorderInorder(postorder, inorder, 0, inorderLen - 1, 0, postorderLen - 1);
    }
};