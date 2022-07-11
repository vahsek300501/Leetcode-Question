class Solution {
public:
    int reverse(int x) {
        string tmpStr = to_string(x);
        bool isNegative = false;
        if (x < 0) {
            tmpStr = tmpStr.substr(1);
            isNegative = true;
        }
        std::reverse(tmpStr.begin(), tmpStr.end());
        long long int ans = stoll(tmpStr);
        if(ans >= (pow(2,31)-1))
            return 0;
        if(isNegative)
            return -1*ans;
        return ans;
    }
};