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
    int widthOfBinaryTree(TreeNode* root) 
{
	long result=1;
	queue<pair<TreeNode*,long>> q;
	q.push({root,0});
	while (!q.empty())
	{
		int s=q.size(); // the size of current level nodes
		long current=0;
		for (int i=0; i<s; i++) // all nodes in the current level
		{
			pair<TreeNode*,long> p=q.front();
			q.pop();
			if (i==0) current=p.second; // the index of the leftmost node (eg. use bfs, so the first node is the leftmost one)
			else result=max(result,p.second-current+1); // the distance between current node and the leftmost node

			if(p.first->left) q.push({p.first->left,p.second*2-current}); // the index for next level
			if(p.first->right) q.push({p.first->right,p.second*2-current+1}); // the index for next level
		}
	}
	return result;
}
};