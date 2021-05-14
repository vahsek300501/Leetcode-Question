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
    int getMaxIndex(vector<int> &arr, int s, int e) {
        int maxInd = INT_MIN;
        int maxVal = INT_MIN;
        for (int i = s; i <= e; i++) {
            if (arr.at(i) > maxVal) {
                maxInd = i;
                maxVal = arr.at(i);
            }
                
        }
        return maxInd;
    }
    TreeNode* constructMaximumBinaryTreeUtil(vector<int>&nums,int s,int e) {
        if(s > e) {
            return nullptr;
        }
        int maxInd = getMaxIndex(nums,s,e);
        TreeNode * newNode = new TreeNode(nums.at(maxInd));
        if(s == e)
            return newNode;
        newNode->left = constructMaximumBinaryTreeUtil(nums,s,maxInd-1);
        newNode->right = constructMaximumBinaryTreeUtil(nums,maxInd+1,e);
        return newNode;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        if(nums.size() == 0)
            return nullptr;
        return constructMaximumBinaryTreeUtil(nums,0,nums.size()-1);
    }
};