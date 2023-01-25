class Solution {
public:
    void
    closestMeetingNodeUtil(vector<int> &edges, vector<bool> &visited, int cntNode, int cntDistance,
                           unordered_map<int, int> &distanceMap) {
        if (visited[cntNode])
            return;
        if (edges[cntNode] == -1) {
            distanceMap[cntNode] = cntDistance;
            return;
        }
        visited[cntNode] = true;
        distanceMap[cntNode] = cntDistance;
        closestMeetingNodeUtil(edges, visited, edges[cntNode], cntDistance + 1, distanceMap);
        visited[cntNode] = false;
    }

    int closestMeetingNode(vector<int> &edges, int node1, int node2) {
        int n = (int) edges.size();
        unordered_map<int, int> distanceMapNode1;
        unordered_map<int, int> distanceMapNode2;
        vector<bool> visitedNode1(n, false);
        vector<bool> visitedNode2(n, false);
        closestMeetingNodeUtil(edges, visitedNode1, node1, 0, distanceMapNode1);
        closestMeetingNodeUtil(edges, visitedNode2, node2, 0, distanceMapNode2);
        auto itr = distanceMapNode1.begin();
        int minimumMaxDistance = INT_MAX;
        int meetingNode = -1;
        while (itr != distanceMapNode1.end()) {
            if (distanceMapNode2.find(itr->first) != distanceMapNode2.end()) {
                int tmpMaxDistance = max(itr->second, distanceMapNode2[itr->first]);
                if (tmpMaxDistance < minimumMaxDistance) {
                    minimumMaxDistance = tmpMaxDistance;
                    meetingNode = itr->first;
                }
                if(tmpMaxDistance == minimumMaxDistance) {
                    if(itr->first < meetingNode)
                        meetingNode = itr->first;
                }
            }
            itr++;
        }
        if (minimumMaxDistance == INT_MAX)
            return -1;
        return meetingNode;
    }
};