class Solution {
public:
    vector<string> arr;
    vector<char> characters = {'a','b','c'};

    void getAllStrings(int n, int cnt, int k, string cntStr) {
        if (cnt >= n) {
            arr.push_back(cntStr);
            return;
        }
        for (int i = 0; i < characters.size(); i++) {
            if (cntStr == "") {
                string tmpStr = cntStr+characters.at(i);
                getAllStrings(n, cnt + 1, k, tmpStr);
                continue;
            }

            if (characters.at(i) == cntStr.at(cnt-1)) {
                continue;
            } else {
                string tmpStr = cntStr+characters.at(i);
                getAllStrings(n, cnt + 1, k, tmpStr);
            }
        }

    }

    string getHappyString(int n, int k) {
        getAllStrings(n,0,k,"");
        sort(arr.begin(),arr.end());
        if(k-1>=arr.size()) {
            return "";
        }
        return arr.at(k-1);
    }
};