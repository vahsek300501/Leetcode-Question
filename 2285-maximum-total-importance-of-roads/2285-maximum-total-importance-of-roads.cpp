class GraphNode {
public:
    int nodeVal;
    int value;
    int roads;

    GraphNode(int p_nodeVal, int p_roads) {
        nodeVal = p_nodeVal;
        roads = p_roads;
    }
};

struct Comp {
    bool operator()(const GraphNode &g1, const GraphNode &g2) {
        return g1.roads > g2.roads;
    }
};

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>> &roads) {
        vector<int> adjNodes(n, 0);
        for (auto &road : roads) {
            adjNodes[road[0]]++;
            adjNodes[road[1]]++;
        }

        vector<GraphNode> graph;
        for (int i = 0; i < n; i++) {
            GraphNode tmp(i, adjNodes[i]);
            graph.push_back(tmp);
        }

        priority_queue<GraphNode, vector<GraphNode>, Comp> pq;
        for (GraphNode gn : graph) {
            pq.push(gn);
        }
        int nodeValCount = 1;
        while (!pq.empty()) {
            GraphNode tmp = pq.top();
            pq.pop();
            graph[tmp.nodeVal].value = nodeValCount;
            nodeValCount++;
        }

        long long int total = 0;
        for (vector<int> edge : roads) {
            int first = edge[0];
            int second = edge[1];
            long long int tmpSum = graph[first].value + graph[second].value;
            total += tmpSum;
        }
        return total;
    }
};