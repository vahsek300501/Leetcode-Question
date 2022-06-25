class Solution {
public:
    bool canReach(vector<int> &arr, int start) {
        int n = (int) arr.size();
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n; i++) {
            if (i + arr[i] >= 0 && i + arr[i] < n)
                graph[i].push_back(i + arr[i]);
            if (i - arr[i] >= 0 && i - arr[i] < n)
                graph[i].push_back(i - arr[i]);
        }
        vector<bool> visited(n, false);
        queue<int> traversalQueue;
        traversalQueue.push(start);
        visited[start] = true;
        while (!traversalQueue.empty()) {
            int top = traversalQueue.front();
            traversalQueue.pop();
            if (arr[top] == 0)
                return true;
            for (int &i : graph[top]) {
                if (visited[i])
                    continue;
                visited[i] = true;
                traversalQueue.push(i);
            }
        }
        return false;
    }
};