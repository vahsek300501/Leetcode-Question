class Solution {
public:
    int getValidProduct(string &s1, string &s2, vector<int> &s1Map, vector<int> &s2Map) {
        bool isValid = true;
        for (int i = 0; i < s1Map.size(); i++) {
            if (s1Map[i] == 0)
                continue;
            if (s2Map[i] != 0) {
                isValid = false;
                break;
            }
        }
        if (!isValid)
            return 0;
        return ((int) s1.length()) * ((int) s2.length());
    }

    int maxProduct(vector<string> &words) {
        int n = (int) words.size();
        vector<vector<int>> freqMapList(n, vector<int>(26, 0));

        for (int i = 0; i < n; i++) {
            string tmp = words[i];
            for (char ch : tmp) {
                freqMapList[i][((int) ch) - 'a'] += 1;
            }
        }

        int maximumProd = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int tmpProd = getValidProduct(words[i], words[j], freqMapList[i], freqMapList[j]);
                maximumProd = max(maximumProd, tmpProd);
            }
        }
        return maximumProd;
    }
};