class Solution {
public:
    int chalkReplacer(vector<int> &chalk, int k) {
        auto newK = (long long int) k;
        long long int chalkSum = 0;
        for (int tmp:chalk) {
            chalkSum += tmp;
        }
        long long int rounds = floor(newK / chalkSum);
        for (int tmp:chalk) {
            newK = newK - (tmp * rounds);
        }
        int ans = -1;
        for (int i = 0; i < (int) chalk.size(); i++) {
            if (newK < chalk[i]) {
                ans = i;
                break;
            }
            newK = newK - chalk[i];
        }
        return ans;
    }
};