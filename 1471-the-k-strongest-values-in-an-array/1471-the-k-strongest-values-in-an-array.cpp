class Solution {
public:
    vector<int> getStrongest(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int n = (int) arr.size();
        int median = arr.at((n - 1) / 2);
        int i = 0;
        int j = n - 1;
        vector<int> ans;
        while (i <= j) {
            if (k == 0)
                break;
            if (abs(arr.at(i) - median) > abs(arr.at(j) - median)) {
                ans.push_back(arr.at(i));
                i++;
            } else {
                ans.push_back(arr.at(j));
                j--;
            }
            k--;
        }
        return ans;
    }
};