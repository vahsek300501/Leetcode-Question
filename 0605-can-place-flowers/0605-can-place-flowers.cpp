class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int maxi = 0;
        
        for(int i = 0;i<flowerbed.size();i++) {
            bool possible = true;
            if(flowerbed[i] == 1)
                continue;
            if(flowerbed[i] == 0) {
                if(i+1 < flowerbed.size() && flowerbed[i+1] == 1)
                    possible = false;
                if(i-1 >= 0 && flowerbed[i-1] == 1)
                    possible = false;
            }
            if(possible) {
                maxi += 1;
                flowerbed[i] = 1;
            }
        }
        
        return maxi >= n;
    }
};