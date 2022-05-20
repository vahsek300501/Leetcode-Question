// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void
    topoSortDFS(vector<vector<int>> &graph, int n, vector<bool> &visited, stack<int> &topoSortedStack, int cntInd) {
        visited[cntInd] = true;
        vector<int> adjacentEdges = graph.at(cntInd);
        for (int edge : adjacentEdges) {
            if (!visited[edge]) {
                topoSortDFS(graph, n, visited, topoSortedStack, edge);
            }
        }
        topoSortedStack.push(cntInd);
    }

    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<vector<int>> graph;
        for (int i = 0; i < V; i++) {
            vector<int> tmp;
            graph.push_back(tmp);
        }
        for (int i = 0; i < V; i++) {
            vector<int> tmpEdges = adj[i];
            for (int edge : tmpEdges)
                graph[i].push_back(edge);
        }
        vector<bool> visited(V, false);
        stack<int> topologicalSortedStack;
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                topoSortDFS(graph, V, visited, topologicalSortedStack, i);
        }
        vector<int> ans;
        while (!topologicalSortedStack.empty()) {
            ans.push_back(topologicalSortedStack.top());
            topologicalSortedStack.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends