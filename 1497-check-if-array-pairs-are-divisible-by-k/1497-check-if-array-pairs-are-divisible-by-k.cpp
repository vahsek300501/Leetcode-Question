class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> remainderCountMap;
        for(int num : arr) {
            int remainder =  ((num % k) + k) % k;;
            if(remainderCountMap.find(remainder) != remainderCountMap.end())
                remainderCountMap[remainder]++;
            else
                remainderCountMap[remainder]=1;
        }
        for(auto itr = remainderCountMap.begin();itr != remainderCountMap.end();itr++) {
            
            int cntRemainder = itr->first;
            if(cntRemainder == 0)
                continue;
            int requiredRemainder = abs(k-cntRemainder);
            cout<<cntRemainder<<"   "<<requiredRemainder<<endl;
            if(remainderCountMap.find(requiredRemainder) != remainderCountMap.end() && remainderCountMap[cntRemainder] == remainderCountMap[requiredRemainder])
                continue;
            return false;
        }
        if(remainderCountMap.find(0) != remainderCountMap.end() && remainderCountMap[0]%2 != 0)
            return false;
        return true;        
    }
};