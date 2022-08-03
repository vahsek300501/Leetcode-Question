class Solution {
public:
    static bool comparator(pair<int, int> &first, pair<int, int> &second) {
        if (first.second < second.second)
            return true;
        if (first.second == second.second && first.first < second.first)
            return true;
        return false;
    }

    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int n = (int) arr.size();
        vector<pair<int, int>> distanceArr;
        distanceArr.reserve(n);
        for (int i = 0; i < n; i++) {
            distanceArr.emplace_back(arr[i], abs(arr[i] - x));
        }
        sort(distanceArr.begin(), distanceArr.end(), comparator);
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(distanceArr[i].first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};