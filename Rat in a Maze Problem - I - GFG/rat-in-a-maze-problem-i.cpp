// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++
#include<bits/stdc++.h>
class Solution{
    public:
    void getPathUtil(vector<vector<int>> &m, bool **visited, int n, vector<string> &ans, string cntPath, int cntX,
                     int cntY) {
        if (cntX < 0 || cntY < 0) {
            return;
        }
        if (cntX >= n || cntY >= n) {
            return;
        }
        if (m.at(cntX).at(cntY) == 0) {
            return;
        }
        if (visited[cntX][cntY]) {
            return;
        }
        if (cntX == n - 1 && cntY == n - 1) {
            ans.push_back(cntPath);
            return;
        }
        visited[cntX][cntY] = true;
        getPathUtil(m, visited, n, ans, cntPath + 'D', cntX + 1, cntY);
        getPathUtil(m, visited, n, ans, cntPath + 'U', cntX - 1, cntY);
        getPathUtil(m, visited, n, ans, cntPath + 'R', cntX, cntY + 1);
        getPathUtil(m, visited, n, ans, cntPath + 'L', cntX, cntY - 1);
        visited[cntX][cntY] = false;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        bool **visited = new bool *[n];
        for (int i = 0; i < n; i++) {
            visited[i] = new bool[n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
        vector<string> ans;
        getPathUtil(m, visited, n, ans, "", 0, 0);
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