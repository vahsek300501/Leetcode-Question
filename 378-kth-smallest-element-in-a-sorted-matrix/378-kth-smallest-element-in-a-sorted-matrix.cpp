class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size();
        
        if(k>n*n)   return -1;
        if(k==1)    return matrix[0][0];
        
        vector <int> ans;
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<n ; j++)
                ans.push_back(matrix[i][j]);
        
        sort(ans.begin(),ans.end());
    
    return ans[k-1];
    }
};