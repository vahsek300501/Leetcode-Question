class Solution {
public:
    vector<int> findMaximumBefore(vector<int> arr, int n) {
        reverse(arr.begin(), arr.end());
        vector<int> ans;
        set<int> s;
        set<int>::iterator it;

        for (int i = 0; i < n; i++) {

            s.insert(arr[i]);

            it = s.lower_bound(arr[i]);

            if (it == s.begin()) {
                ans.push_back(INT_MIN);
            } else {
                it--;
                ans.push_back(*it);
            }
        }
        // ans.at(n-1) = INT_MIN;
        reverse(ans.begin(),ans.end());
        return ans;
    }


    bool find132pattern(vector<int> &nums) {
        vector<int> smallestElement;
        smallestElement.push_back(INT_MIN);
        int cntSmallestElement = nums.at(0);
        for (int i = 1; i < (int) nums.size(); i++) {
            if (cntSmallestElement < nums.at(i)) {
                smallestElement.push_back(cntSmallestElement);
            } else {
                smallestElement.push_back(INT_MIN);
                cntSmallestElement = nums.at(i);
            }
        }
        vector<int> nextSmallestFromRight = findMaximumBefore(nums, (int)nums.size());
        
        for(int i = 0;i<nums.size();i++) {
            cout<<smallestElement.at(i)<<" ";
        }
        cout<<endl;
        for(int i = 0;i<nums.size();i++) {
            cout<<nextSmallestFromRight.at(i)<<" ";
        }
        cout<<endl;

        for (int i = 0; i < nums.size(); i++) {
            if (smallestElement.at(i) == INT_MIN || nextSmallestFromRight.at(i) == INT_MIN)
                continue;
            if (nextSmallestFromRight.at(i) > smallestElement.at(i))
                return true;
        }
        return false;
    }
};