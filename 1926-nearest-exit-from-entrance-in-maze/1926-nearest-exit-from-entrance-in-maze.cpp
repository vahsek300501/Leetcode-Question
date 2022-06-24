class Solution {
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        int n = (int) maze.size();
        int m = (int) maze.at(0).size();
        vector<vector<int>> distance(n, vector<int>(m, -1));
        queue<pair<int, pair<int, int>>> traversalQueue;
        traversalQueue.push(make_pair(0, make_pair(entrance[0], entrance[1])));
        distance[entrance[0]][entrance[1]] = 0;
        bool isStartingNode = true;
        int mini = INT_MAX;
        vector<int> xPos = {1, -1, 0, 0};
        vector<int> yPos = {0, 0, 1, -1};


        while (!traversalQueue.empty()) {
            pair<int, pair<int, int>> top = traversalQueue.front();
            traversalQueue.pop();
            for (int i = 0; i < 4; i++) {
                int newX = top.second.first + xPos[i];
                int newY = top.second.second + yPos[i];
                if (newX < 0 || newY < 0 || newX >= n || newY >= m) {
                    if (!isStartingNode)
                        mini = min(mini, top.first);
                    continue;
                }
                if (distance[newX][newY] != -1)
                    continue;
                if (maze[newX][newY] == '+')
                    continue;
                traversalQueue.push(make_pair(top.first + 1, make_pair(newX, newY)));
                distance[newX][newY] = top.first + 1;
            }
            if (isStartingNode)
                isStartingNode = false;
        }
        if(mini == INT_MAX)
            return -1;
        return mini;
    }
};