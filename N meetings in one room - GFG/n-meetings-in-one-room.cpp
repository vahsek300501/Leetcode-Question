// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool compareMeetings(pair<int, int> &first, pair<int, int> &second) {
        if (first.second < second.second)
            return true;
        if (first.second == second.second && first.first < second.first)
            return true;
        return false;
    }

    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> meetings;
        meetings.reserve(n);
        for (int i = 0; i < n; i++) {
            meetings.emplace_back(start[i], end[i]);
        }
        sort(meetings.begin(), meetings.end(), compareMeetings);
        int cntTime = 0;
        int maxCount = 0;
        for (int i = 0; i < n; i++) {
            if (meetings.at(i).first > cntTime) {
                maxCount++;
                cntTime = meetings.at(i).second;
            }
        }
        return maxCount;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends