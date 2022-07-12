class Solution {
public:
    bool canReachUtil(vector<int> & arr,int start,bool * checkArr,int n) {
        if(arr.at(start) == 0)
            return true;

        int pos1 = start+arr.at(start);
        int pos2 = start-arr.at(start);
        vector<int> possiblePos;
        if(pos1 >=0 && pos1<arr.size())
            possiblePos.push_back(pos1);
        if(pos2 >=0 && pos2<arr.size())
            possiblePos.push_back(pos2);

        if(possiblePos.size() == 0) {
            return false;
        }
        if(possiblePos.size() == 1 && checkArr[possiblePos.at(0)] == true) {
            return false;
        }
        if(possiblePos.size() == 2 && checkArr[possiblePos.at(0)] == true && checkArr[possiblePos.at(1)] == true) {
            return false;
        }

        if(possiblePos.size() == 1 && checkArr[possiblePos.at(0)] == false) {
            checkArr[possiblePos.at(0)] = true;
            return canReachUtil(arr,possiblePos.at(0),checkArr,n);
        }

        if(possiblePos.size() == 2 && checkArr[possiblePos.at(0)] == false && checkArr[possiblePos.at(1)] == false) {
            checkArr[possiblePos.at(0)] = true;
            checkArr[possiblePos.at(1)] = true;
            return canReachUtil(arr,possiblePos.at(0),checkArr,n) || canReachUtil(arr,possiblePos.at(1),checkArr,n);
        }
        if(possiblePos.size() == 2 && checkArr[possiblePos.at(0)] == true && checkArr[possiblePos.at(1)] == false) {
            checkArr[possiblePos.at(1)] = true;
            return canReachUtil(arr,possiblePos.at(1),checkArr,n);
        }
        if(possiblePos.size() == 2 && checkArr[possiblePos.at(0)] == false && checkArr[possiblePos.at(1)] == true) {
            checkArr[possiblePos.at(0)] = true;
            return canReachUtil(arr,possiblePos.at(0),checkArr,n);
        }

        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        bool * checkArr = new bool[arr.size()];
        for(int i=0;i<arr.size();i++)
            checkArr[i] = false;
        checkArr[start] = true;
        bool found = canReachUtil(arr,start,checkArr,arr.size());
        return found;
    }
};