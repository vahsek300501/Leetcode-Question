class Solution {
public:
    bool isPossibleToDistributeCandies(vector<int> &candies, long long int requiredCandies, long long int k) {
        long long int possibleChildren = 0;
        for (int candy : candies) {
            possibleChildren += (candy / requiredCandies);
        }
        if (possibleChildren >= k)
            return true;
        return false;
    }

    int maximumCandies(vector<int> &candies, long long k) {
        long long int start = 1;
        long long int end = *max_element(candies.begin(), candies.end());
        long long int ans = 0;

        while (start <= end) {
            long long int mid = start + ((end - start) / 2);
            if(mid == 0)
                break;
            bool found = isPossibleToDistributeCandies(candies, mid, k);
            if (found) {
                // cout<<mid<<"  "<<endl;
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return (int) ans;
    }
};