class Solution {
public:
    static bool comparator(string &str1, string &str2) {
        return str1.length() < str2.length();
    }
    
    int longestStrChain(vector<string> &words) {
        sort(words.begin(), words.end(), comparator);
        unordered_map<string, int> umap;
        int maxAns = 1;

        for (string &str : words) {
            umap[str] = 1;
            for (int i = 0; i < str.length(); i++) {
                string tmpStr = str.substr(0, i) + str.substr(i + 1, str.length());
                if (umap.find(tmpStr) != umap.end()) {
                    umap[str] = max(umap[str], umap[tmpStr] + 1);
                }
            }
        }

        auto itr = umap.begin();
        while (itr != umap.end()) {
            maxAns = max(maxAns, itr->second);
            itr++;
        }
        return maxAns;
    }
};