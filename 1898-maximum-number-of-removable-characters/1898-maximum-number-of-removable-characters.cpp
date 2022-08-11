class Solution {
public:
    bool isPossibleToDelete(string &s, string &p, vector<int> &removable, int positions) {
        vector<bool> positionStringArr(s.length(), true);
        for (int i = 0; i < positions; i++) {
            positionStringArr[removable[i]] = false;
        }
        string newString;
        for (int i = 0; i < (int) s.length(); i++) {
            if (positionStringArr[i]) {
                newString += s[i];
            }
        }

        int i = 0;
        int j = 0;
        while (i < (int) newString.length() && j < p.length()) {
            if (newString[i] == p[j])
                j++;
            i++;
        }
        if (j >= (int) p.length())
            return true;
        return false;
    }

    int maximumRemovals(string &s, string &p, vector<int> &removable) {
        int start = 0;
        int end = (int) removable.size();
        int ans = 0;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            bool found = isPossibleToDelete(s, p, removable, mid);
            if (found) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};