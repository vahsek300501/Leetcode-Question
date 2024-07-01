class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int counter = 0;
        for(int num:arr){
            if(counter == 3)
                return true;
            if(num %2 == 0)
                counter = 0;
            else
                counter++;
        }
        if(counter == 3)
            return true;
        return false;
    }
};