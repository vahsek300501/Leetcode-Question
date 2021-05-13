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
    TreeNode * sortedArrayToBSTUtil(vector<int>& nums,int sInd,int eInd) {
        if(sInd > eInd)
            return nullptr;
        if(sInd == eInd) {
            TreeNode * newNode = new TreeNode(nums.at(sInd));
            return newNode;
        }
        int mid = (sInd) + ((eInd-sInd)/2);
        TreeNode* newNode = new TreeNode(nums.at(mid));
        TreeNode* newNode1 = sortedArrayToBSTUtil(nums,sInd,mid-1);
        TreeNode* newNode2 = sortedArrayToBSTUtil(nums,mid+1,eInd);
        if(newNode1!=nullptr && newNode1->val > newNode->val) {
            newNode->right = newNode1;
            newNode->left = newNode2;
        }
        else {
            newNode->left = newNode1;
            newNode->right = newNode2;
        }
        return newNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()){
            return nullptr;
        }
        return sortedArrayToBSTUtil(nums,0,nums.size()-1);
    }
};