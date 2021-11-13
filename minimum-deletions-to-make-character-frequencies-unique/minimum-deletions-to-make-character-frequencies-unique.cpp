
class Solution {
public:
    static bool compare(pair<char, int> p1, pair<char, int> p2) {
        return p2.second < p1.second;
    }

    int minDeletions(string &s) {
        unordered_map<char, int> umap;
        for (char &i : s) {
            if (umap.find(i) != umap.end())
                umap[i] += 1;
            else
                umap[i] = 1;
        }

        vector<pair<char, int>> letters(umap.begin(), umap.end());
        sort(letters.begin(), letters.end(), compare);
        int crntCount = letters.at(0).second;
        int minDel = 0;
        for (int i = 1; i < letters.size(); i++) {
            if (letters.at(i).second < crntCount) {
                crntCount = letters.at(i).second;
                continue;
            } else {
                int reqNum = crntCount-1;
                if(reqNum <= 0) {
                    minDel += letters.at(i).second;
                    crntCount = reqNum;
                }
                else {
                    minDel += (letters.at(i).second - reqNum);
                    crntCount = reqNum;
                }

            }
        }
        return minDel;
    }
};