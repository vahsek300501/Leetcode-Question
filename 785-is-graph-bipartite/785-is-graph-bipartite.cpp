class Solution {
public:
    bool dfs(vector<vector<int>> &graph,bool * visited, int * color,int cntNum,int cntIndex) {
        visited[cntIndex] = true;
        color[cntIndex] = cntNum;
        
        for(int child:graph[cntIndex]) {
            if(!visited[child]) {
                bool foundDfs = dfs(graph,visited,color,cntNum^1,child);    
                if(!foundDfs)
                   return false;
            } else{
                if(color[child] == color[cntIndex])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        bool * visited = new bool[graph.size()];
        int * color = new int[graph.size()];
        for(int i = 0; i < n; i++) {
            visited[i] = false;
            color[i] = -1;
        }
        for(int i = 0;i<n;i++) {
            if(!visited[i] && !dfs(graph,visited,color,0,i))
                return false;
        }
        return true;
    }
};