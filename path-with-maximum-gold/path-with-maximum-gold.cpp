class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int n, int m, int i, int j){
      if(i>=n || j>=m ||i<0||j<0 || grid[i][j]==-1 || grid[i][j] == 0)return 0;
      int temp =grid[i][j];
      int cost = grid[i][j];
      grid[i][j] = -1;
      cost+=max({dfs(grid,n,m,i+1,j),dfs(grid,n,m,i-1,j),dfs(grid,n,m,i,j+1),dfs(grid,n,m,i,j-1)});
      grid[i][j] = temp;
      return cost;
   }
   int getMaximumGold(vector<vector<int>>& grid) {
      int n = grid.size() ;
      int m = grid[0].size();
      int ans = 0;
      for(int i =0;i<n;i++){
         for(int j =0;j<m;j++){
            if(grid[i][j]){
               //cout << "Start : " << i <<" " << j << endl;
               ans = max(ans,dfs(grid,n,m,i,j));
            }
         }
      }
      return ans;
   }
};