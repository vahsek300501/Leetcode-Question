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
    int ans = 0;

    void countPseudoPalindromicPaths(TreeNode *root, unordered_map<int, int> &freqMap) {
        if(root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            if (freqMap.find(root->val) != freqMap.end())
                freqMap[root->val] += 1;
            else
                freqMap[root->val] = 1;
            int countSingles = 0;
            auto itr = freqMap.begin();
            while (itr != freqMap.end()) {
                if (itr->second == 0) {
                    itr++;
                    continue;
                }
                if (itr->second % 2 != 0)
                    countSingles++;
                itr++;
            }
            if(countSingles == 1 || countSingles == 0)
                ans++;
            freqMap[root->val] -= 1;
            return;
        }


        if (freqMap.find(root->val) != freqMap.end())
            freqMap[root->val] += 1;
        else
            freqMap[root->val] = 1;

        countPseudoPalindromicPaths(root->left, freqMap);
        countPseudoPalindromicPaths(root->right, freqMap);

        freqMap[root->val] -= 1;
    }

    int pseudoPalindromicPaths(TreeNode *root) {
        unordered_map<int, int> freqMap;
        countPseudoPalindromicPaths(root, freqMap);
        return ans;
    }
};