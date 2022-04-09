class Solution {
public:
    static bool comparator (pair<int,int> o1,pair<int,int> o2) {
        return o2.second < o1.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;
        vector<pair<int,int>> sortMap;
        for(int i=0;i<nums.size();i++) {
            if(freqMap.find(nums.at(i)) != freqMap.end()) {
                freqMap[nums.at(i)] += 1;
            } else {
                freqMap[nums.at(i)] = 1;
            }
        }
        
        auto itr = freqMap.begin();
        while(itr != freqMap.end()) {
            sortMap.push_back(make_pair(itr->first,itr->second));
            itr++;
        }
        sort(sortMap.begin(),sortMap.end(),comparator);
        vector<int> ans;
        for(int i=0;i<k;i++) {
            ans.push_back(sortMap.at(i).first);
        }
        return ans;
    }
};