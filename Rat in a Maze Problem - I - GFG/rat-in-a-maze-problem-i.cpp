// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void getPaths(vector<vector<int>> &mat, int n, string &cntAns, int cntX, int cntY, int targetX, int targetY,
                  vector<string> &ans, vector<vector<bool>> &visited) {
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= n)
            return;
        if (mat[cntX][cntY] == 0)
            return;
        if (visited[cntX][cntY])
            return;
        if (cntX == targetX && cntY == targetY) {
            ans.push_back(cntAns);
        }
        visited[cntX][cntY] = true;
        cntAns.push_back('L');
        getPaths(mat, n, cntAns, cntX, cntY - 1, targetX, targetY, ans, visited);
        cntAns.pop_back();
        cntAns.push_back('R');
        getPaths(mat, n, cntAns, cntX, cntY + 1, targetX, targetY, ans, visited);
        cntAns.pop_back();
        cntAns.push_back('D');
        getPaths(mat, n, cntAns, cntX + 1, cntY, targetX, targetY, ans, visited);
        cntAns.pop_back();
        cntAns.push_back('U');
        getPaths(mat, n, cntAns, cntX - 1, cntY, targetX, targetY, ans, visited);
        cntAns.pop_back();
        visited[cntX][cntY] = false;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool>> visited;
        for (int i = 0; i < n; i++) {
            vector<bool> tmp;
            visited.push_back(tmp);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i].push_back(false);
            }
        }
        string cntAns;
        getPaths(m, n, cntAns, 0, 0, n - 1, n - 1, ans, visited);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends