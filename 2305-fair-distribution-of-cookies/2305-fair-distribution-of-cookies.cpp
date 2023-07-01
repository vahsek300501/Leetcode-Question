class Solution {
public:
    void distributeCookiesUtil(vector<int> &cookies, int cntCookieIndex, int k, vector<long long int> &cookiesDivision,
                               long long int &minimumUnfairness) {
        if (cntCookieIndex >= cookies.size()) {
            long long int maxCookiesObtained = LONG_LONG_MIN;
            for (long long int cookieCountForChild: cookiesDivision) {
                maxCookiesObtained = max(maxCookiesObtained, cookieCountForChild);
            }
            minimumUnfairness = min(minimumUnfairness, maxCookiesObtained);
            return;
        }
        int cntCookiesInJar = cookies[cntCookieIndex];
        for (int i = 0; i < k; i++) {
            cookiesDivision[i] += cntCookiesInJar;
            distributeCookiesUtil(cookies,cntCookieIndex+1,k,cookiesDivision,minimumUnfairness);
            cookiesDivision[i] -= cntCookiesInJar;
        }
    }

    int distributeCookies(vector<int> &cookies, int k) {
        long long int minimumUnfairness = LONG_LONG_MAX;
        vector<long long int> cookiesDivision( k, 0);
        distributeCookiesUtil(cookies,0,k,cookiesDivision,minimumUnfairness);
        return (int)minimumUnfairness;
    }
};