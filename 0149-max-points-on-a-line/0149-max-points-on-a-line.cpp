class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }

    int maxPoints(vector<vector<int>> &points) {
        int n = (int) points.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopePointMap;
            for (int j = i + 1; j < n; j++) {
                int numerator = points[j][1] - points[i][1];
                int denominator = points[j][0] - points[i][0];
                int numGcd = gcd(numerator, denominator);
                numerator = numerator / numGcd;
                denominator = denominator / numGcd;
                string slope = to_string(numerator) + "_" + to_string(denominator);
                if (slopePointMap.find(slope) != slopePointMap.end())
                    slopePointMap[slope] += 1;
                else
                    slopePointMap[slope] = 2;
            }
            for(auto & itr : slopePointMap) {
                if(itr.second > maxi)
                    maxi = itr.second;
            }
        }
        if(maxi == INT_MIN)
            return 1;
        return maxi;
    }
};