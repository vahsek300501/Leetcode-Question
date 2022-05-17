// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepByKnight(int cntX, int cntY, int targetX, int targetY, int n) {

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
        queue<pair<int, pair<int, int>>> traversalQueue;
        traversalQueue.push(make_pair(0, make_pair(cntX, cntY)));
        visited[cntX][cntY] = true;
        int count = INT_MAX;

        vector<int> xPos = {1, 1, -1, -1, 2, 2, -2, -2};
        vector<int> yPos = {2, -2, 2, -2, 1, -1, 1, -1};

        while (!traversalQueue.empty()) {
            pair<int, pair<int, int>> top = traversalQueue.front();
            traversalQueue.pop();
            if (top.second.first == targetX && top.second.second == targetY)
                count = min(count, top.first);

            for (int i = 0; i < 8; i++) {
                int newX = top.second.first + xPos[i];
                int newY = top.second.second + yPos[i];

                if (newX < 0 || newY < 0 || newX >= n || newY >= n)
                    continue;
                if (visited[newX][newY])
                    continue;

                visited[newX][newY] = true;
                traversalQueue.push(make_pair(top.first + 1, make_pair(newX, newY)));
            }
        }
        if (count == INT_MAX)
            return -1;
        return count;
    }

    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N) {
        int count = minStepByKnight(KnightPos.at(0) - 1, KnightPos.at(1) - 1, TargetPos.at(0) - 1, TargetPos.at(1) - 1,
                                    N);
        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends