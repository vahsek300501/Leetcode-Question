class Solution {
public:
    vector<int> avoidFlood(vector<int> &rains) {
        unordered_map<int, int> floodIndexMap;
        set<int> dryDayIndex;
        vector<int> ans;
        bool isPossible = true;

        for (int i = 0; i < rains.size(); i++) {
            int cntIsland = rains.at(i);
            if (cntIsland != 0) {
                if (floodIndexMap.find(cntIsland) == floodIndexMap.end()) {
                    floodIndexMap[cntIsland] = i;
                    ans.push_back(-1);
                } else {
                    int previousInd = floodIndexMap[cntIsland];
                    auto itr = dryDayIndex.lower_bound(previousInd);
                    if (itr == dryDayIndex.end()) {
                        isPossible = false;
                        break;
                    }
                    floodIndexMap[cntIsland] = i;
                    ans[*itr] = cntIsland;
                    dryDayIndex.erase(*itr);
                    ans.push_back(-1);
                }
            } else {
                dryDayIndex.insert(i);
                ans.push_back(1);
            }
        }

        if (!isPossible) {
            vector<int> tmp;
            return tmp;
        }
        return ans;
    }
};