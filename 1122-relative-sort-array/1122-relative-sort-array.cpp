class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        vector<int> ans;
        unordered_map<int, int> freqMap;
        for (int val: arr1) {
            if (freqMap.find(val) != freqMap.end()) {
                freqMap[val]++;
            } else
                freqMap[val] = 1;
        }
        for (int arr2Val: arr2) {
            while (freqMap[arr2Val] != 0) {
                ans.push_back(arr2Val);
                freqMap[arr2Val]--;
            }
        }
        vector<int> remainingElements;
        auto itr = freqMap.begin();
        while (itr != freqMap.end()) {
            if (itr->second != 0) {
                int num = itr->first;
                while(freqMap[num] != 0) {
                    remainingElements.push_back(itr->first);
                    freqMap[num]--;
                }
                
            }
            itr++;
        }
        sort(remainingElements.begin(), remainingElements.end());
        for (int val: remainingElements)
            ans.push_back(val);
        return ans;
    }
};