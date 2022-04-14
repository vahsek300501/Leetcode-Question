// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev(string s) {
        stack<int> revStack;
        int i = 0;
        int countRev = 0;
        int tmpCount = 0;
        while (i<s.length() && s.at(i) != '{') {
            tmpCount++;
            i++;
        }
        if (tmpCount % 2 == 0)
            countRev += (tmpCount / 2);
        else {
            countRev += ((tmpCount - 1) / 2);
            countRev++;
            revStack.push('{');
        }
        for (int j = i; j < s.length(); j++) {
            if (s.at(j) == '{') {
                revStack.push('{');
            } else {
                if (revStack.empty()) {
                    countRev++;
                    revStack.push('{');
                } else {

                    revStack.pop();
                }
            }
        }
        if (!revStack.empty() && revStack.size() % 2 != 0)
            return -1;
        if (!revStack.empty() && revStack.size() % 2 == 0)
            countRev += (revStack.size() / 2);
        return countRev;
    }