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
    void flattenUtil(TreeNode *root, queue<TreeNode *>& preorderQueue) {
        if (root == nullptr)
            return;
        preorderQueue.push(root);
        flattenUtil(root->left, preorderQueue);
        flattenUtil(root->right, preorderQueue);
    }

    void flatten(TreeNode *root) {
        if (root == nullptr)
            return;
        queue<TreeNode *> preorderQueue;
        flattenUtil(root, preorderQueue);

        TreeNode *front = preorderQueue.front();
        TreeNode *tail = preorderQueue.front();
        front->right = nullptr;
        front->left = nullptr;
        preorderQueue.pop();

        while (!preorderQueue.empty()) {
            TreeNode *tmp = preorderQueue.front();
            preorderQueue.pop();
            tmp->left = nullptr;
            tmp->right = nullptr;
            tail->right = tmp;
            tail = tmp;
        }
        root = front;
    }
};