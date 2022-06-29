class Solution {
public:
    bool canJump(vector<int> &nums) {
        int minJumpsReq = 0;
        for (int i = (int) nums.size() - 2; i >= 0; i--) {
            minJumpsReq++;
            if (nums[i] >= minJumpsReq) {
                minJumpsReq = 0;
            }
        }
        if (minJumpsReq == 0)
            return true;
        return false;
    }
};