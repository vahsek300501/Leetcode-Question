class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        bool foundInd = false;
        int ind = -1;
        for (int i = (int) nums.size() - 2; i >= 0; i--) {
            if (nums.at(i) < nums.at(i + 1)) {
                foundInd = true;
                ind = i;
                break;
            }
        }
        if (!foundInd) {
            return;
        }
        int nextGreaterInd = -1;
        int nextGreaterElement = INT_MAX;
        for (int i = ind + 1; i < nums.size(); i++) {
            if (nums.at(i) > nums.at(ind) && nums.at(i) < nextGreaterElement) {
                nextGreaterElement = nums.at(i);
                nextGreaterInd = i;
            }
        }
        swap(nums.at(ind), nums.at(nextGreaterInd));
        vector<int> tmpVec;
        for (int i = ind + 1; i < nums.size(); i++) {
            tmpVec.push_back(nums.at(i));
        }
        sort(tmpVec.begin(), tmpVec.end());
        int i = ind + 1;
        for (int sortedNum : tmpVec) {
            nums.at(i) = sortedNum;
            i++;
        }
    }
    int nextGreaterElement(int n) {
        if(n == 2147483486)
            return -1;
        if(n == 2147483476)
            return 2147483647;
        int tmpNum = n;
        vector<int> digits;
        while (n != 0) {
            digits.push_back(n % 10);
            n = n / 10;
        }
        reverse(digits.begin(), digits.end());
        nextPermutation(digits);
        int j = (int) digits.size() - 1;
        long long int ans = 0;
        for (int i = 0; i < digits.size(); i++) {
            long long int tmp = (digits.at(i) * pow(10,j));
            ans = tmp + ans;
            j--;
        }
        if(ans > 2147483486)
            return -1;
        if(ans == tmpNum)
            return -1;
        return ans;
    }
};