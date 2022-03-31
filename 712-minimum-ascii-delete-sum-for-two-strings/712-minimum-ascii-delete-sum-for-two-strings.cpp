class Solution {
public:
    static string lcsDP(string str1, string str2) {
        int **dp = new int *[str1.length() + 1];
        for (int i = 0; i <= str1.length(); i++) {
            dp[i] = new int[str2.length() + 1];
        }
        for (int i = 0; i <= str1.length(); i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= str2.length(); i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= str1.length(); i++) {
            for (int j = 1; j <= str2.length(); j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = ((int) str1[i - 1]) + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string ans;
        int i = (int) str1.length();
        int j = (int) str2.length();

        while (i != 0 && j != 0) {
            if (str1.at(i - 1) == str2.at(j - 1)) {
                ans += str1.at(i - 1);
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        string lcs = lcsDP(s1, s2);
        cout<<lcs<<endl;
        int ans = 0;
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < s1.length() && j < s2.length() && k < lcs.length()) {
            if (s1.at(i) != lcs.at(k)) {
                ans += (int) s1.at(i);
                i++;
            } else if (s2.at(j) != lcs.at(k)) {
                ans += (int) s2.at(j);
                j++;
            } else {
                i++;
                j++;
                k++;
            }
        }

        if (i < s1.length()) {
            while (i < s1.length()) {
                ans += (int) s1.at(i);
                i++;
            }
        }
        if (j < s2.length()) {
            while (j < s2.length()) {
                ans += (int) s2.at(j);
                j++;
            }
        }
        return ans;
    }
};