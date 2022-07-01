class Solution {
public:
    static bool compare(vector<int> b1,vector<int> b2) {
        return b1.at(1) > b2.at(1);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int maxUnits = 0;
        for(int i=0;i<boxTypes.size();i++) {
            if(truckSize <= 0)
                break;
            
            if(truckSize >= boxTypes.at(i).at(0)) {
                maxUnits += (boxTypes.at(i).at(0) * boxTypes.at(i).at(1));
                truckSize = truckSize - boxTypes.at(i).at(0);
            }
            else {
                maxUnits += (truckSize * boxTypes.at(i).at(1));
                truckSize = 0;
            }
        }
        return maxUnits;
    }
};