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
    void getAllNumbers(TreeNode *root, vector<long long int> &numbers, long long int cntNum) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            long long int tmp = (cntNum * 10) + root->val;
            numbers.push_back(tmp);
            return;
        }
        getAllNumbers(root->left, numbers, (cntNum * 10) + root->val);
        getAllNumbers(root->right, numbers, (cntNum * 10) + root->val);
    }

    int sumNumbers(TreeNode *root) {
        vector<long long int> numbers;
        getAllNumbers(root, numbers, 0);
        long long int finalAns = 0;
        for (long long int num: numbers) {
            finalAns += num;
        }
        return finalAns;
    }
};