class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0])   return a[0] < b[0];
        if (a[2] == 0 and b[2] == 0)    return a[1] > b[1];
        if (a[2] == 1 and b[2] == 1)    return a[1] < b[1];
        return true;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int i, j, n;
        n = buildings.size();
        vector<vector<int>> data(2 * n, vector<int>(3));
        for (i = j = 0; i < n; ++i) {
            data[j++] = {buildings[i][0], buildings[i][2], 0};
            data[j++] = {buildings[i][1], buildings[i][2], 1};
        }
        sort(data.begin(), data.end(), comp);
        // for (auto &d: data) {
        //     cout << d[0] << ' ' << d[1] << ' ' << d[2] << '\n';
        // }
        // Key = Height
        // Value = Count of that Height
        map<int, int> m;
        m[0] = 1;
        int prevMaxHt = 0;
        vector<vector<int>> res;
        for (auto &d: data) {
            if (d[2] == 0) {
                if (m.find(d[1]) != m.end()) {
                    ++m[d[1]];
                } else {
                    m[d[1]] = 1;
                }
            } else {
                --m[d[1]];
                if (m[d[1]] == 0)   m.erase(d[1]);
            }
            
            int currMaxHt = m.rbegin() -> first;
            
            if (currMaxHt != prevMaxHt) {
                res.push_back({d[0], currMaxHt});
                prevMaxHt = currMaxHt;
            }
        }
        return res;
    }
};