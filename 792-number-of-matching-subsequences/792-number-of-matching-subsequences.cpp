class Solution {
public:
    bool isMatchFound(string &str1, string &str2) {
        int i = 0;
        int j = 0;
        while (i < (int) str1.length() && j < (int) str2.length()) {
            if (str1[i] == str2[j])
                j++;
            i++;
        }
        if (j >= str2.length())
            return true;
        return false;
    }

    int numMatchingSubseq(string s, vector<string> &words) {
        int count = 0;
        unordered_map<string,bool> umap;
        for (string &tmpWord : words) {
            if(umap.find(tmpWord) != umap.end()) {
                if(umap[tmpWord])
                    count++;
                continue;
            }
            umap[tmpWord] = false;
            if (isMatchFound(s, tmpWord)) {
                count++;
                umap[tmpWord] = true;
            }
                
        }
        return count;
    }
};