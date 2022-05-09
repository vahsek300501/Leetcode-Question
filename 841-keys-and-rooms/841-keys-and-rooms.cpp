using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        vector<bool> visited(rooms.size(), false);
        queue<int> bfsQueue;
        bfsQueue.push(0);

        while (!bfsQueue.empty()) {
            int index = bfsQueue.front();
            bfsQueue.pop();
            visited[index] = true;
            for (int roomNum:rooms[index]) {
                if(!visited[roomNum])
                    bfsQueue.push(roomNum);
            }
        }

        for(bool found:visited)
            if(!found)
                return false;
        return true;
    }
};