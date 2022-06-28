// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comparator(pair<int, int> &first, pair<int, int> &second) {
        return first.second < second.second;
    }

    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> meetings;
        meetings.reserve(n);
        for (int i = 0; i < n; i++) {
            meetings.emplace_back(start[i], end[i]);
        }
        sort(meetings.begin(), meetings.end(), comparator);
        int cntTime = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (meetings[i].first > cntTime) {
                cntTime = meetings[i].second;
                count++;
            }
        }
        return count;
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