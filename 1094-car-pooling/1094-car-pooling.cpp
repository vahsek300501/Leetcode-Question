class Solution {
public:
    class Compare2 {
    public:
        bool operator()(pair<int, int> &first, pair<int, int> &second) {
            return first.first > second.first;
        }
    };

    static bool compareTrips(vector<int> &first, vector<int> &second) {
        return first[1] < second[1];
    }

    bool carPooling(vector<vector<int>> &trips, int capacity) {
        int n = (int) trips.size();
        sort(trips.begin(), trips.end(), compareTrips);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare2> minEndingLocation;
        if (trips[0][0] > capacity)
            return false;
        int cntCapacity = trips[0][0];
        minEndingLocation.push(make_pair(trips[0][2], trips[0][0]));
        for (int i = 1; i < n; i++) {
            vector<int> tmp = trips[i];
            while (!minEndingLocation.empty() && minEndingLocation.top().first <= tmp[1]) {
                cntCapacity = cntCapacity - minEndingLocation.top().second;
                minEndingLocation.pop();
            }
            if (cntCapacity + tmp[0] > capacity)
                return false;
            cntCapacity += tmp[0];
            minEndingLocation.push(make_pair(tmp[2], tmp[0]));
        }
        return true;
    }
};