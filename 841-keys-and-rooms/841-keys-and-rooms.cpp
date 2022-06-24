class Solution {
public:
    void canVisitAllRoomsUtil(vector<vector<int>> &rooms, vector<bool> &visited, int cntIndex) {
        if (visited[cntIndex])
            return;
        visited[cntIndex] = true;
        vector<int> roomKeys = rooms[cntIndex];
        for (int foundKey : roomKeys) {
            canVisitAllRoomsUtil(rooms, visited, foundKey);
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int n = (int) rooms.size();
        vector<bool> visited(n, false);
        canVisitAllRoomsUtil(rooms, visited, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }
};