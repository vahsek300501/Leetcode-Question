class Solution {
public:
    vector<vector<int>> pathSumAns;

    void getAllPathSum(TreeNode * root,int targetSum,vector<int>& tmpArr,int cntSum) {
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr) {
            if(cntSum+root->val == targetSum){
                tmpArr.push_back(root->val);
                pathSumAns.push_back(tmpArr);
                tmpArr.pop_back();
            }
            return;
        }

        tmpArr.push_back(root->val);
        getAllPathSum(root->left,targetSum,tmpArr,cntSum+root->val);
        getAllPathSum(root->right,targetSum,tmpArr,cntSum+root->val);
        tmpArr.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> tmpArr;
        getAllPathSum(root,targetSum,tmpArr,0);
        return pathSumAns;
    }
};