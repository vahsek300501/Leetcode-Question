// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool sortItem(pair<Item, double> itm1, pair<Item, double> itm2) {
        if (itm1.second > itm2.second)
            return true;
        return false;
    }

    double fractionalKnapsack(int W, Item arr[], int n) {
        vector<pair<Item, double>> items;
        for (int i = 0; i < n; i++) {
            double valPerUnit = (double) arr[i].value / (double) arr[i].weight;
            items.emplace_back(arr[i], valPerUnit);
        }
        sort(items.begin(), items.end(), sortItem);
        double cntWeight = 0;
        double amount = 0;
        for (int i = 0; i < n; i++) {
            if (cntWeight + items[i].first.weight <= W) {
                amount += ((double) items[i].first.value);
                cntWeight += ((double) items[i].first.weight);
                continue;
            } else {
                double remainingWeight = (double) W - (double) cntWeight;
                double valueRemaining = (items[i].second) * ((double) remainingWeight);
                amount += valueRemaining;
                cntWeight = W;
                break;
            }
        }
        return amount;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends