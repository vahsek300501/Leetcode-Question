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
    void recoverTreeInorder(TreeNode *root, vector<int> &traversal) {
        if (root == nullptr)
            return;
        recoverTreeInorder(root->left, traversal);
        traversal.push_back(root->val);
        recoverTreeInorder(root->right, traversal);
    }

    void recoverTreeUpdate(TreeNode *root, vector<int> &traversal, int &i) {
        if (root == nullptr)
            return;
        recoverTreeUpdate(root->left, traversal, i);
        root->val = traversal.at(i);
        i++;
        recoverTreeUpdate(root->right, traversal, i);
    }

    void recoverTree(TreeNode *root) {
        if (root == nullptr)
            return;
        vector<int> traversal;
        recoverTreeInorder(root, traversal);
        int firstCorrectionPosition = -1;
        int secondCorrectionPosition = -1;
        for (int i = 1; i < traversal.size(); i++) {
            if (traversal.at(i) < traversal.at(i - 1)) {
                if (firstCorrectionPosition == -1)
                    firstCorrectionPosition = i - 1;
                else
                    secondCorrectionPosition = i;
            }
        }
        if (firstCorrectionPosition != -1 && secondCorrectionPosition != -1) {
            int tmp = traversal.at(firstCorrectionPosition);
            traversal.at(firstCorrectionPosition) = traversal.at(secondCorrectionPosition);
            traversal.at(secondCorrectionPosition) = tmp;
        }
        if (secondCorrectionPosition == -1 && firstCorrectionPosition != -1) {
            int tmp = traversal.at(firstCorrectionPosition);
            traversal.at(firstCorrectionPosition) = traversal.at(firstCorrectionPosition + 1);
            traversal.at(firstCorrectionPosition + 1) = tmp;
        }
        int ind = 0;
        recoverTreeUpdate(root, traversal, ind);
    }
};