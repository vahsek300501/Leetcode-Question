class Solution {
public:
    bool isPossibleToConstruct(vector<int> bloomDay,int m,int k,int d) {
        vector<bool> bloomedArr;
        for(int i = 0;i<bloomDay.size();i++) {
            if(bloomDay.at(i) <= d){
                bloomedArr.push_back(true);
            }
            else {
                bloomedArr.push_back(false);
            }
        }

        int constructed = 0;
        bool isConsecutive = false;
        int tmpK = 0;
        int n = bloomedArr.size();

        for(int i=0;i<n;i++) {
            if(!isConsecutive && bloomedArr.at(i)){
                isConsecutive = true;
                tmpK = 1;
            }
            else if(isConsecutive && bloomedArr.at(i)) {
                tmpK ++;
            }
            else if(isConsecutive && !bloomedArr.at(i)) {
                tmpK = 0;
                isConsecutive = false;
            }

            if(tmpK == k){
                constructed++;
                tmpK = 0;
                isConsecutive = false;
            }
        }

        if(constructed >= m)
            return true;
        return false;
    }

    int minDays(vector<int> &bloomDay, int m, int k) {
        if (bloomDay.size() < (m * k))
            return -1;

        int s = 0;
        int e = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay.at(i) > e)
                e = bloomDay.at(i);
        }
        int ans = -1;

        while (s <= e) {
            int mid = s + ((e - s) / 2);
            bool isFound = isPossibleToConstruct(bloomDay,m,k,mid);
            if(isFound) {
                ans = mid;
                e = mid -1;
            }
            else {
                s = mid+1;
            }
        }

        return ans;
    }
};