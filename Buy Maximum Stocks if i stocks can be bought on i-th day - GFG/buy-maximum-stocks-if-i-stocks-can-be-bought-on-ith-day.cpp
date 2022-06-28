// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    static bool sortPriceStock(pair<int, int> &s1, pair<int, int> &s2) {
        if (s1.first < s2.first)
            return true;
        if (s1.first == s2.first && s1.second > s2.second)
            return true;
        return false;
    }

    int buyMaximumProducts(int n, int k, int price[]) {
        vector<pair<int, int>> priceDayArr;
        priceDayArr.reserve(n);
        for (int i = 0; i < n; i++) {
            priceDayArr.emplace_back(price[i], i + 1);
        }
        sort(priceDayArr.begin(), priceDayArr.end(), sortPriceStock);
        int cntAmount = 0;
        int totalStocks = 0;
        for (pair<int, int> cntStock : priceDayArr) {
            if (cntStock.first * cntStock.second + cntAmount <= k) {
                cntAmount += (cntStock.first * cntStock.second);
                totalStocks += cntStock.second;
            } else {
                int remainingAmt = k - cntAmount;
                int possiblePurchase = floor((double) remainingAmt / (double) cntStock.first);
                totalStocks += possiblePurchase;
                cntAmount += (possiblePurchase * cntStock.first);
                break;
            }
        }
        return totalStocks;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends