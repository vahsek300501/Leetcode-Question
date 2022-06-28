// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool platformComparator(pair<int, int> &p1, pair<int, int> &p2) {
        return p1.first < p2.first;
    }

    int findPlatform(int arr[], int dep[], int n) {
        vector<pair<int, int>> trains;
        trains.reserve(n);
        for (int i = 0; i < n; i++) {
            trains.emplace_back(arr[i], dep[i]);
        }
        sort(trains.begin(), trains.end(), platformComparator);
        priority_queue<int, vector<int>, greater<>> minEndingTime;
        minEndingTime.push(trains[0].second);
        int count = 1;
        int maxi = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> tmpTrain = trains[i];
            int cntEndingTime = minEndingTime.top();
            if (tmpTrain.first <= cntEndingTime) {
                count++;
                maxi = max(maxi, count);
                minEndingTime.push(tmpTrain.second);
            } else {
                minEndingTime.pop();
                minEndingTime.push(tmpTrain.second);
            }
        }
        return maxi;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends