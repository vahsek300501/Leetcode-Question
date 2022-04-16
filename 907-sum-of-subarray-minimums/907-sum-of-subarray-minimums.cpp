#define MOD 1000000007
class Solution {
public:
    
    vector<int> getNextMinFromRight(vector<int> &arr) {
        vector<int> ans(arr.size(), -1);
        stack<pair<int, int>> minStack;
        for (int i = (int) arr.size() - 1; i >= 0; i--) {
            while (!minStack.empty() && minStack.top().first >= arr.at(i)) {
                minStack.pop();
            }
            if (minStack.empty()) {
                minStack.push(make_pair(arr.at(i), i));
                ans.at(i) = -1;
            } else {
                ans.at(i) = minStack.top().second;
                minStack.push(make_pair(arr.at(i), i));
            }
        }
        return ans;
    }

    vector<int> getNextMinFromLeft(vector<int> &arr) {
        vector<int> ans(arr.size(), -1);
        stack<pair<int, int>> minStack;
        for (int i = 0; i < arr.size(); i++) {
            while (!minStack.empty() && minStack.top().first > arr.at(i)) {
                minStack.pop();
            }
            if (minStack.empty()) {
                minStack.push(make_pair(arr.at(i), i));
                ans.at(i) = -1;
            } else {
                ans.at(i) = minStack.top().second;
                minStack.push(make_pair(arr.at(i), i));
            }
        }
        return ans;
    }

    int sumSubarrayMins(vector<int> &arr) {
        vector<int> nextMinFromLeft = getNextMinFromLeft(arr);
        vector<int> nextMinFromRight = getNextMinFromRight(arr);
//        for (int i = 0; i < nextMinFromRight.size(); i++) {
//            cout << nextMinFromRight[i] << " ";
//        }
//        cout << endl;
//        for (int i = 0; i < nextMinFromLeft.size(); i++) {
//            cout << nextMinFromLeft[i] << " ";
//        }
//        cout << endl;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            int left = 0;
            int right = 0;
            if (nextMinFromLeft.at(i) != -1)
                left = i - nextMinFromLeft.at(i) - 1;
            else
                left = i;
            if (nextMinFromRight.at(i) != -1)
                right = nextMinFromRight.at(i) - i - 1;
            else
                right = arr.size() - 1 - i;
            long long int tmp1 = (((left+1)%MOD)*((right+1)%MOD))%MOD;
            long long int tmp = ((tmp1%MOD)*(arr.at(i)%MOD))%MOD;
            ans = ((ans%MOD)+(tmp%MOD))%MOD;
        }
        return ans;
    }
};