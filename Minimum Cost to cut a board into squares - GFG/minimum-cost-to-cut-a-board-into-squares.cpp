// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> x, vector<int> y, int M, int N) {
        sort(x.begin(), x.end(), greater<>());
        sort(y.begin(), y.end(), greater<>());
        int cntVerticalPieces = 1;
        int cntHorizontalPieces = 1;
        int cntCost = 0;
        int i = 0;
        int j = 0;
        while (i < M && j < N) {
            if (x[i] >= y[j]) {
                cntCost += (cntHorizontalPieces * x[i]);
                cntVerticalPieces++;
                i++;
            } else {
                cntCost += (cntVerticalPieces * y[j]);
                cntHorizontalPieces++;
                j++;
            }
        }

        if (i == M) {
            while (j < N) {
                cntCost += (cntVerticalPieces * y[j]);
                cntHorizontalPieces++;
                j++;
            }
        }
        if (j == N) {
            while (i < M) {
                cntCost += (cntHorizontalPieces * x[i]);
                cntVerticalPieces++;
                i++;
            }
        }
        return cntCost;
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m - 1, n - 1);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends