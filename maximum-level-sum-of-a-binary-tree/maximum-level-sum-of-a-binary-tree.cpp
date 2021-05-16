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
    int maxLevelSum(TreeNode* root) {
        unordered_map<int,int> umap;
        queue<pair<TreeNode *,int>> q;
        q.push(make_pair(root,1));

        while(!q.empty()) {
            pair<TreeNode*,int> tmp = q.front();
            q.pop();
            if(umap.find(tmp.second) != umap.end()){
                umap[tmp.second] += tmp.first->val;
            }
            else {
                umap[tmp.second] = tmp.first->val;
            }
            if(tmp.first->left != nullptr){
                q.push(make_pair(tmp.first->left,tmp.second+1));
            }
            if(tmp.first->right != nullptr){
                q.push(make_pair(tmp.first->right,tmp.second+1));
            }
        }
        int maxSum = INT_MIN;
        int ind = 0;
        auto itr = umap.begin();
        while(itr!=umap.end()) {
            if(itr->second > maxSum) {
                maxSum = itr->second;
                ind = itr->first;
            }
            else if(itr->second == maxSum && itr->first < ind) {
                maxSum = itr->second;
                ind = itr->first;
            }
            itr++;
        }
        return ind;
    }
};